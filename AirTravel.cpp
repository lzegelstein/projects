#include <stdio.h>
#include <vector>
#include <string>
//#include "air_travel.hpp"
#include "AirTravel.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <math.h>

//added for DFS
#include <iterator>
#include <cmath>
#include <list>
#include <queue>
#include <stack>


using std::string;

AirTravel::AirTravel(std::string Airport_File, std::string Routes_File){
    readInAirportData(Airport_File);
    readInRoutesData(Routes_File);
}

AirTravel::Airport* AirTravel::IATAsearch(std::string code){
    return AirportList[code];
}

void AirTravel::readInAirportData(std::string fileName){
    std::cout<<"entered readData()"<<std::endl;
    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);
    for (int x = 0; x < 25; x++) {
        if (data_file.is_open()) {
            getline(data_file, trial);
            std::cout<<"from data_file: "<<trial<<std::endl;
            AirportParseLine(trial);
        }
        else {
            std::cout<<"open failed"<<std::endl;
        }
    }
    data_file.close();
    std::cout<<"finished readInAirportData"<<std::endl;
}

void AirTravel::AirportParseLine(std::string input) { //TODO
    int str_size = (int)input.size();
    std::string temp;
    int begin_index = 0;
    int field_num = 0;
    int num_commas = 0;
    Airport* airport = new Airport;
    
    for (int x = 0; x < str_size; x++) {
        
        if (input[x] == ',') {
            num_commas ++;
            //std::cout <<"We found a comma at location " << x << std::endl;
            temp.append(input, begin_index, x - begin_index);
            //std::cout<<"field: "<<field_num<<", <"<<temp<<">"<<std::endl;
            begin_index = x + 1;
            
            if ((field_num == 0) && !AirportLineCheck(field_num, temp)) {
                return;
            }
             
            if (field_num == 1) {
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->name = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 2) {
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->city = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 3) {
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->country = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 4) {
                if (AirportLineCheck(field_num, temp)) {
                    temp = removeQuotes(temp);
                    airport->IATA = temp;
                }
                else{
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
                if (!temp.empty()){
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
    //std::cout<<"emp: " <<temp<<std::endl;
    temp.erase();

    addAirport(airport);
}

std::string AirTravel::removeQuotes(std::string temp){
    temp.erase(0, 1); //removing the first quotation
    temp.pop_back(); //removing the last quotation
    return temp;
}

bool AirTravel::AirportLineCheck(int field_num, std::string value) {
    char first_char = value[0];
    
    if (field_num == 0) { //Checking for an integer value
        if ((first_char > 0x2F) && (first_char < 0x3A)) {
            return true;
        }
    }
    first_char = value[1];
   //else case: checking for upper case first letter
    if ((first_char > 0x40) && (first_char < 0x5B)){
        if(first_char == 'N'){
            first_char = value[0];
            if(!((first_char > 0x40) && (first_char < 0x5B))){
               return false;
            }
        }
        return true;
    }
    return false;
}

void AirTravel::addAirport(Airport* Airport){
    AirportList[Airport->IATA] = Airport;
}

/* ************************************************* */

void AirTravel::readInRoutesData(std::string fileName){
    std::cout<<"entered readInRoutesData()"<<std::endl;
    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);
    for (int x = 0; x < 25; x++) {
        if (data_file.is_open()) {
            getline(data_file, trial);
            std::cout<<"from data_file: "<<trial<<std::endl;
            RoutesParseLine(trial);
        }
        else {
            std::cout<<"open failed"<<std::endl;
        }
    }
    data_file.close();
    std::cout<<"finished readInRoutesData"<<std::endl;
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
            std::cout<<"field: "<<field_num<<", <"<<temp<<">"<<std::endl;
            begin_index = x + 1;
            
            
            //We do not need to check for line validity since all routes have a source and destination
            if ((field_num != 2) && (field_num != 4)) {
                //do nothing
            }
            else if (field_num == 2) {
                auto it = AirportList.find(temp);
                    //if it is not found
                    if (it == AirportList.end()){
                        //field_num++;
                        //temp.erase();
                        return;
                    }
                    else {
                        //if it is found
                        source = AirportList.find(temp)->second;
                    }
            }
            else if (field_num == 4) {
                auto it = AirportList.find(temp);
                    //if it is not found
                    if (it == AirportList.end()) {
                        //field_num++;
                        //temp.erase();
                        return;
                    }
                    else {
                        //if it is found
                        destination = AirportList.find(temp)->second;
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
    source->addDestination(destination);
}
/*
void AirTravel::addRoutes(Airport* start, Airport* arrive){

    AirportList[start->IATA]->destinations.push_back(AirportList[arrive->IATA], );
We need a function inside of the airport struct to create the flight struct!
     
}
*/

void AirTravel::Airport::addDestination(Airport* that){
    double lat_diff = this->latitude - that->latitude;
    double lon_diff = this->longitude - that->longitude;

    //Math
    lat_diff *= lat_diff;
    lon_diff *= lon_diff;
    
    Flights route;
    route.other_airport = that;
    route.distance = sqrt(lat_diff + lon_diff);
    
    this->destinations.push_back(route);
}

//populate the std::vector graph
void AirTravel::createGraph(){
    std::map<std::string, Airport*>::iterator it = AirportList.begin();
    while (it != AirportList.end())
    {
        // Accessing VALUE from element pointed by it.
        Airport* count = it->second;
        graph.push_back(count);
        it++;
    }
    visited = new bool[graph.size()]; //instatiate visited


    //our attempt to have output of some kind
    for(int i=0; i < graph.size(); i++){
        std::cout<<graph[i]<<" ";
    }
    std::cout<<std::endl;
}
//maybe change something other than a int for choosing starting node
void AirTravel::DFS(int vertex){
    int numNodes = AirportList.size();
    visited[vertex] = true;

    for (int i = 0; i < graph[vertex].destination.size(); i++){
        Airport* temp = graph[vertex].destination[i].other_airport;
        int index = findIndex(temp);
        if(index == -1){
            continue;
        }
        if (!visited[index]){
            DFS(index);
        }
    }
}

int AirTravel::findIndex(Airport* item) {
    for (int i = 0; i < (int) graph.size(); ++i) {
        if (graph[i] == item)
            return i;
    }
    return -1;
}