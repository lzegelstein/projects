//
//  main.cpp
//  cs225FinalProject
//
//  Created by Lyla Zegelstein on 4/19/21.
//

#include <_stdio.h>
#include <vector>
#include <string>
//#include "AirTravel.h"
//#include "parse.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

/*
This file contains a simplified version of some data parsing function.
The functions are in need of debugging and aren't complete yet.
WIP -> last touched at 10:18 pm by LZ
Will be touched again tomorrow @6:30 am, so push any further changes before then plz :)
*/
void parse_line(std::string input);
void readData(std::string fileName);
bool line_check(int field_num, std::string value);

int main(int argc, char** argv) {
    
    readData("/Users/lylazegelstein/Desktop/airportnames.csv");
    
    return 0;
}

void readData(std::string fileName) {
    std::cout<<"entered readData()"<<std::endl;
    std::fstream data_file;
    std::string trial;
    data_file.open(fileName, std::ios::in);
    for (int x = 0; x < 25; x++) {
        if (data_file.is_open()) {
            getline(data_file, trial);
            std::cout<<"from data_file: "<<trial<<std::endl;
            parse_line(trial);
        }
        else {
            std::cout<<"open failed"<<std::endl;
        }
    }
    data_file.close();
    std::cout<<"finished readInAirportData"<<std::endl;

}

/*
 Takes a line of code
 Goes through character by character looking for a comma
 As we parse, build the data structure -> be populating the map
 field_num #1: airport name
 field_num #2: city
 field_num #3: country
 field_num #4: 3 letter code
 field_num #6: latitude
 field_num #7: longitude
 */

void parse_line(std::string input) { //TODO
    int str_size = (int)input.size();
    std::string temp;
    int begin_index = 0;
    int field_num = 0;
    int num_commas = 0;
    
    struct Airport {
        std::string name;
        std::string country;
        std::string city;
        std::string IATA;
        double latitude;
        double longitude;
        };
    
    Airport airport;
    
    for (int x = 0; x < str_size; x++) {
        
        if (input[x] == ',') {
            num_commas ++;
            std::cout <<"We found a comma at location " << x << std::endl;
            temp.append(input, begin_index, x - begin_index);
            std::cout<<"field: "<<field_num<<", <"<<temp<<">"<<std::endl;
            begin_index = x + 1;
            
            if ((field_num == 0) && !line_check(field_num, temp)) {
                return;
            }
            
            if (field_num == 1) {
                if (line_check(field_num, temp)) {
                    airport.name = temp;
                }
                else{
                    return;
                }
            }
            else if (field_num == 2) {
                if (line_check(field_num, temp)) {
                    airport.city = temp;
                }
                else{
                    return;
                }
            }
            else if (field_num == 3) {
                if (line_check(field_num, temp)) {
                    airport.country = temp;
                }
                else{
                    return;
                }
            }
            else if (field_num == 4) {
                if (line_check(field_num, temp)) {
                    airport.IATA = temp;
                }
                else{
                    return;
                }
            }
            else if (field_num == 6) {
                double latitude = std::stod(temp);
                if ((latitude <= 90) && (latitude >= -90)) {
                    airport.latitude = latitude;
                }
                else {
                    temp.erase(); //TODO - see if it works without this line :)
                    return; //ignore line
                }
            }
            else if (field_num == 7) {
                double longitude = std::stod(temp);
                if ((longitude <= 180) && (longitude >= -180)) {
                    airport.longitude = longitude;
                }
                else {
                    temp.erase();
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
}



bool line_check(int field_num, std::string value) {
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


/* Map
 Key is airport code
 the value would be everything in the airport class
 */


