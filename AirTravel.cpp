#include <_stdio.h>
#include <vector>
#include <string>
#include "AirTravel.h"
//#include "parse.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

using std::string;

AirTravel::AirTravel(){
    //TODO
}

AirTravel::AirTravel(std::string Airport_File, std::string Routes_File){
    //TODO
}

AirTravel::AirTravel(AirTravel& other){
    //TODO
}   

AirTravel::~AirTravel(){
    //TODO
}

AirTravel::AirTravel& AirTravel::operator=(const AirTravel& other){
    //TODO
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
    
    // struct Airport {
    //     std::string name;
    //     std::string country;
    //     std::string city;
    //     std::string IATA;
    //     double latitude;
    //     double longitude;
    //     };
    
    Airport* airport = new Airport;
    
    for (int x = 0; x < str_size; x++) {
        
        if (input[x] == ',') {
            num_commas ++;
            std::cout <<"We found a comma at location " << x << std::endl;
            temp.append(input, begin_index, x - begin_index);
            std::cout<<"field: "<<field_num<<", <"<<temp<<">"<<std::endl;
            begin_index = x + 1;
            
            if ((field_num == 0) && !AirportLineCheck(field_num, temp)) {
                return;
            }
            
            if (field_num == 1) {
                if (AirportLineCheck(field_num, temp)) {
                    airport->name = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 2) {
                if (AirportLineCheck(field_num, temp)) {
                    airport->city = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 3) {
                if (AirportLineCheck(field_num, temp)) {
                    airport->country = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 4) {
                if (AirportLineCheck(field_num, temp)) {
                    airport->IATA = temp;
                }
                else{
                    delete airport;
                    return;
                }
            }
            else if (field_num == 6) {
                double latitude = std::stod(temp);
                if ((latitude <= 90) && (latitude >= -90)) {
                    airport->latitude = latitude;
                }
                else {
                    delete airport;
                    return; //ignore line
                }
            }
            else if (field_num == 7) {
                double longitude = std::stod(temp);
                if ((longitude <= 180) && (longitude >= -180)) {
                    airport->longitude = longitude;
                }
                else {
                    delete airport;
                    return; //ignore line
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
        return true;
    }
    return false;
}

void AirTravel::addAirport(Airport* Airport){
    //TODO
}

AirTravel::Airport* AirTravel::findAirport(std::string Airport){
    //TODO
}

