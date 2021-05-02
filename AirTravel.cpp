#include <stdio.h>
#include <vector>
#include <string>
#include "AirTravel.h"
#include "Airport.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <math.h>
#include <queue>
#include <float.h>

using std::string;

/*
 Perhaps, we need to create different print routines i.e. print all the destinations of _______ airport
 Be able to pass it in a 3 letter code
 */

/**
 * This file includes all the usable functions from AirTravel.h
 */

/**
 * This file includes all the parseing functions used by AirTravel.h
 */

//-------------------------------------------------------------
//                  Public Member Functions
//-------------------------------------------------------------

AirTravel::AirTravel(){
}

AirTravel::AirTravel (std::string Airport_File, std::string Routes_File) {
    readInAirportData(Airport_File);
    readInRoutesData(Routes_File);
}

Airport* AirTravel::IATAsearch(std::string code) {
    return AirportList[code];
}

Airport* AirTravel::findBusiestAirport() {
    Airport* current_busiest = AirportList.begin()->second;
    std::map<std::string, Airport*>::iterator it;
    for (it = AirportList.begin(); it != AirportList.end(); it++) {
        if (it->second->destinations.size() >= current_busiest->destinations.size()){
            current_busiest = it->second;
        }
    }
    return current_busiest;
}

bool AirTravel::isDirectFlight(std::string start, std::string end) {
    Airport* source = AirportList[start];
    Airport* dest = AirportList[end];
    for (unsigned int i = 0; i< source->destinations.size(); i++){
        if(source->destinations[i].other_airport->IATA == dest->IATA){
            return true;
        }
    }
    return false;
}

/**
 * TODO: change to return a PNG pointer for performance reasons
 */
cs225::PNG AirTravel::createGraph(std::map<std::string, Airport*> list){
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    int distx_max = 0;
    int distx_min = 0;
    int disty_max = 0;
    int disty_min = 0;

    //find current max/min size of image
    for(auto it: list){
        Airport air_curr = *(it.second);
        if(air_curr.latitude > distx_max){
            distx_max = air_curr.latitude;
        }
        if(air_curr.latitude < distx_min){
            distx_min = air_curr.latitude;
        }
        if(air_curr.longitude > disty_max){
            disty_max = air_curr.longitude;
        }
        if(air_curr.longitude < disty_min){
            disty_min = air_curr.longitude;
        }
    }

    //create image PNG
    cs225::PNG image((distx_max - distx_min), (disty_max - disty_min));

    //populate nodes and edges
    for(auto it: list){
        Airport air_curr = *(it.second);
        int x = air_curr.latitude - distx_min;
        int y = air_curr.longitude - disty_min;
        Node node_curr(x, y, air_curr.destinations.size());
        nodes.push_back(node_curr);

        for(auto j : air_curr.destinations){
            int x = j.other_airport->latitude - distx_min;
            int y = j.other_airport->longitude - disty_min;
            Node other(x, y, j.other_airport->destinations.size());
            Edge edge_curr(node_curr, other, j.distance);
            edges.push_back(edge_curr);
        }  
    }

    for(auto it: nodes){
        drawNode(it, image);
    }

    for(auto it: edges){
        drawEdge(it, image);
    }

    return image;
}

double AirTravel::Dijkstras(std::map<std::string, Airport*> airportList, Airport* source) { //TODO
        struct Vertex {
        double source_distance = DBL_MAX;
        Vertex * previous = NULL;
        Airport * data = NULL; //i think this should be a Vertex * and the source needs a previous to point at itself
        bool visited = false;
    };
    
    std::priority_queue<Vertex, std::greater<double> > pq;
//we need a vector of verticies
    
    std::map<std::string, Airport *>::iterator it;
    Vertex * current;

    for (it = airportList.begin(); it != airportList.end(); it ++) {
        Vertex vertex;
        vertex.data = it->second;

        if (vertex.data == source) {
            vertex.source_distance = 0;
            vertex.previous = &vertex;
            pq.push(vertex);
        }
    }
    
    Vertex* start;
    start->source_distance = 0;
    start->previous = start;
    start->data = source;
    pq.push(start);
    
    while (!pq.empty()) {
        current = pq.top();
        pq.pop();
        unsigned long num_destinations = current->data->destinations.size();
        for (auto i = 0; i < num_destinations; i ++) {
            if (current->visited == false) {            //this means we haven't seen this node before
                current->visited = true;
                //mark it as visited, find the distance to the source
                current->source_distance = current->data->destinations[i].distance + current->previous->source_distance;
                //Now, need to see where else you can get to, and push those vertices to the pq
                unsigned long other_vertices_inreach = current->data->destinations.size();
                for (auto j = 0; j < other_vertices_inreach; j ++) {
                    
                }
            }
        }
    }
    
    return 0;

 
}

//-------------------------------------------------------------
//                 Private Member Functions
//-------------------------------------------------------------

void AirTravel::readInAirportData(std::string fileName) {
    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);
    for (int x = 0; x < 25; x++) {
        
        if (data_file.is_open()) {
            getline(data_file, trial);
            AirportParseLine(trial);
        }
        else {
            std::cout<<"open failed"<<std::endl;
        }
    }
    data_file.close();
}

void AirTravel::AirportParseLine(std::string input) { //TODO
    int str_size = (int) input.size();
    int begin_index, field_num, num_commas;
    begin_index = field_num = num_commas = 0;
    std::string temp;
    Airport* airport = new Airport;
    
    for (int x = 0; x < str_size; x++) {
        
        if (input[x] == ',') {
            num_commas ++;
            temp.append(input, begin_index, x - begin_index);
            begin_index = x + 1;
            
            if ((field_num == 0) && !AirportLineCheck(field_num, temp)) {
                return;
            }
             
            if (field_num == 1) {
                
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->name = temp;
                }
                else {
                    delete airport;
                    return;
                }
            }
            else if (field_num == 2) {
                
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->city = temp;
                }
                else {
                    delete airport;
                    return;
                }
            }
            else if (field_num == 3) {
                
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->country = temp;
                }
                else {
                    delete airport;
                    return;
                }
            }
            else if (field_num == 4) {
                
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->IATA = temp;
                }
                else {
                    delete airport;
                    return;
                }
            }
            else if (field_num == 6) {
                
                if (!temp.empty()) {
                    double latitude = std::stod(temp);
                    
                    if ((latitude <= 90) && (latitude >= -90)) {
                        airport->latitude = latitude;
                    }
                    else {
                        delete airport;
                        return; //ignore line
                    }
                }
                else {
                    delete airport;
                    return;
                }
                
            }
            else if (field_num == 7) {
                
                if (!temp.empty()) {
                    double longitude = std::stod(temp);
                    
                    if ((longitude <= 180) && (longitude >= -180)) {
                        airport->longitude = longitude;
                    }
                    else {
                        delete airport;
                        return; //ignore line
                    }
                }
                else {
                    delete airport;
                    return;
                }
               
            }
            field_num++;
            temp.erase();
        }
    }
    //Took care of the no trailing comma case
    temp.append(input, begin_index, str_size - begin_index);
    temp.erase();

    addAirport(airport);
}

std::string AirTravel::removeQuotes(std::string temp) {
    temp.erase(0, 1); //removing the first quotation
    temp.pop_back(); //removing the last quotation
    return temp;
}

bool AirTravel::AirportLineCheck(int field_num, std::string value) {
    char first_char = value[0];
    
    if (field_num == 0) {                                  //Checking for an integer value
        if ((first_char > 0x2F) && (first_char < 0x3A)) {
            return true;
        }
    }
    //else case: checking for upper case first letter
    first_char = value[1];

    if ((first_char > 0x40) && (first_char < 0x5B)) {

        return true;
    }
    return false;
}

void AirTravel::addAirport(Airport* Airport) {
    AirportList[Airport->IATA] = Airport;
}

void AirTravel::readInRoutesData(std::string fileName) {
    //std::cout<<"entered readInRoutesData()"<<std::endl;
    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);
    
    for (int x = 0; x < 28; x++) {
        
        if (data_file.is_open()) {
            getline(data_file, trial);
         //   std::cout<<"from data_file: "<<trial<<std::endl;
            RoutesParseLine(trial);
        }
        else {
            std::cout<<"open failed"<<std::endl;
        }
    }
    data_file.close();
    //std::cout<<"finished readInRoutesData"<<std::endl;
}

void AirTravel::RoutesParseLine(std::string input){
    int str_size = (int)input.size();
    std::string temp;
    int begin_index = 0;
    int field_num = 0;
    int num_commas = 0;
    Airport* source = NULL;
    Airport* destination = NULL;
    for (int x = 0; x < str_size; x++) {
        
        if (input[x] == ',') {
            num_commas ++;
            //std::cout <<"We found a comma at location " << x << std::endl;
            temp.append(input, begin_index, x - begin_index);
           //std::cout<<"field: "<<field_num<<", <"<<temp<<">"<<std::endl;
            begin_index = x + 1;
            
            if ((field_num != 2) && (field_num != 4)) { //do nothing
            }
            else if (field_num == 2) {
                std::map<std::string, Airport*>::iterator it = AirportList.find(temp);
                                                    
                    if (it == AirportList.end()) { //if it is not found
                        return;
                    }
                    else {
                        source = AirportList.find(temp)->second;  //if it is found
                        // TODO - verify that source was found, otherwise, print error and skip line
                    }
            }
            else if (field_num == 4) {
                std::map<std::string, Airport*>::iterator it = AirportList.find(temp);
                    
                    if (it == AirportList.end()) { //if it is not found
                        return;
                    }
                    else {
                        //if it is found
                        destination = AirportList.find(temp)->second;
                        // TODO - verify that destination was found, otherwise, print error and skip line
                    }
            }
        field_num++;
        temp.erase();
        }
    }
    //Took care of the no trailing comma case
    temp.append(input, begin_index, str_size - begin_index);
    //std::cout<<"emp: " <<temp<<std::endl;
    temp.erase();
    if (source == NULL) {
        std::cout<<"source is NULL in RoutesParseLine(), error"<<std::endl;
        return;
    }
    source->addDestination(destination); //Add in check to make sure
}
