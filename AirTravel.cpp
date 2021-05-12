#include <stdio.h>
#include <vector>
#include <string>
#include "AirTravel.h"
#include "Airport.h"
#include "dijkstras.h"
#include "traversal/DFS.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <cmath>
#include <queue>
#include <float.h>

using std::string;

/**
 * This file includes all the usable functions from AirTravel.h
 */

//-------------------------------------------------------------
//                  Public Member Functions
//-------------------------------------------------------------

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

        if (it->second->destinations.size() >= current_busiest->destinations.size()) {
            current_busiest = it->second;
        }
    }
    return current_busiest;
}

bool AirTravel::isDirectFlight(std::string start, std::string end) {
    Airport* source = AirportList[start];
    Airport* dest = AirportList[end];

    for (unsigned int i = 0; i< source->destinations.size(); i++) {

        if (source->destinations[i].other_airport->IATA == dest->IATA) {
            return true;
        }
    }
    return false;
}


Dijkstras* AirTravel::Air_Dijkstras(Airport* source) {

    if (!AirportList.empty()) {
        Dijkstras* dij = new Dijkstras(AirportList, source);
        return dij;
    }
    else {
        return nullptr;
    }    
}

DFS* AirTravel::DepthFirstSearch(Airport* source){

    if (!AirportList.empty()) {
        DFS* dfs = new DFS(AirportList, *source);
        return dfs;
    }
    else {
        return nullptr;
    }
}

Graph* AirTravel::worldMap(unsigned int h, unsigned int w) {

    if (!AirportList.empty()) {
        Airport* busy = findBusiestAirport();
        Graph* gph = new Graph(AirportList, h, w, busy);
        return gph;
    }
    else {
        return nullptr;
    }
}

//-------------------------------------------------------------
//                 Private Member Functions
//-------------------------------------------------------------

void AirTravel::readInAirportData(std::string fileName) {
    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);

    if (data_file.is_open()) {

        while (std::getline(data_file, trial)) {

            AirportParseLine(trial);
        }
        data_file.close();
    }
    else {
        std::cout<<"could not read in airport data, check your spelling"<<std::endl;
    }
}

void AirTravel::AirportParseLine(std::string input) { //TODO
    int str_size = (int)input.size();
    int begin_index, field_num, num_commas;
    bool open_quote = false;
    begin_index = field_num = num_commas = 0;
    std::string temp;
    Airport* airport = new Airport;

       for (int x = 0; x < str_size; x++) {

           if (input[x] == '\"') {
               open_quote = !open_quote;
           }

           if (input[x] == ',' && !open_quote) {
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
    
    if (field_num == 0) { //Checking for an integer value
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

    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);

    if (data_file.is_open()) {
        while (std::getline(data_file, trial)) {
            RoutesParseLine(trial);
        }
        data_file.close();
    }
    else {
        std::cout<<"could not read in routes data, check your spelling"<<std::endl;
    }
 
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
            temp.append(input, begin_index, x - begin_index);
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


void AirTravel::roundTrip(std::string airportOne, std::string airportTwo) {
    Airport * source = IATAsearch(airportOne);
    Airport * destination = IATAsearch(airportTwo);

    std::list<Airport*> toThere = Air_Dijkstras(source)->getShortestRoute(destination);
    std::list<Airport*> fromThere = Air_Dijkstras(destination)->getShortestRoute(source);

    printList(toThere);
    fromThere.pop_front();
    printList(fromThere);

}

void AirTravel::printList(std::list<Airport*> list) {
   // std::list<Airport*>::iterator it = list.begin();
    for (auto it = list.begin(); it != list.end(); it ++) {
        std::cout<<list.front()->name<<std::endl;
        list.pop_front();
    }
    return;
}

bool AirTravel::underThreeFlights(std::string airportOne, std::string airportTwo) {

    Airport * source = IATAsearch(airportOne);
    Airport * destination = IATAsearch(airportTwo);
    std::list<Airport*> stops = Air_Dijkstras(source)->getShortestRoute(destination);
    
    return stops.size() < 4;
}