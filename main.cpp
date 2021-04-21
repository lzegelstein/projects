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


void readData();
void parse_line(std::string input);
bool data_check (std::string input, int count);

int main(int argc, char** argv) {
    
    readData();
    
    return 0;
}

void readData() {
    std::cout<<"entered readData()"<<std::endl;
    std::fstream data_file;
    data_file.open("/Users/lylazegelstein/Desktop/airportnames.csv", std::ios::in);
    if (data_file.is_open()) {
        std::string trial;
        getline(data_file, trial);
        std::cout<<"from data_file: "<<trial<<std::endl;
    }
    else {
        std::cout<<"open failed"<<std::endl;
    }
    data_file.close();
    std::cout<<"finished readInAirportData"<<std::endl;
}

/*
 Takes a line of code
 Goes through character by character looking for what is the delimiter
 When it comes across a double quote, it treats everything between the pair of double quotes as a single field of data.
 TODO -> TONIGHT!
 Check to make sure all of the columns are there that we care about it, otherwise skip it -> put in a test case with bad data
 Check types -> ex: 1 must be a numeric field
 then the longitude and latitude we can also make sure it type matches
 Make sure it stops parsing at the end of the line
 As we parse, build the data structure -> be populating the map
 */

//1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"
//std::string airport_name, three_letter_code, city, country;
//double longitude, latitude;
//Columns we care about when starting at a zero index: 1, 2, 3, 4, 6, 7

void parse_line(std::string input) { //TODO
    // you know the length (size) of the string
    // You can iterate via operator [] through the string
    int str_size = (int)input.size();
    std::string temp;
    int begin_index = 0;
    int field_num = 0;
    
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
            std::cout <<"We found a comma at location " << x << std::endl;
            temp.append(input, begin_index, x - begin_index);
            std::cout<<"field: "<<field_num<<", <"<<temp<<">"<<std::endl;
            begin_index = x + 1;
            
            if (field_num == 0) {
                int some_num = std::stoi(temp);
                std::cout<<"found num: " << some_num << std::endl;
            }
            else if (field_num == 6) {
                double some_dbl = std::stod(temp);
                airport.latitude = some_dbl;
            }
            else if (field_num == 7) {
                double some_dbl = std::stod(temp);
                airport.longitude = some_dbl;
            }
            /*
             field_num #1: airport name
             field_num #2: city
             field_num #3: country
             field_num #4: 3 letter code
             field_num #6: latitude
             field_num #7: longitude
             */
            field_num++;
            temp.erase();
        }
    }
    //Took care of the no trailing comma case
    temp.append(input, begin_index, str_size - begin_index);
    std::cout<<"emp: " <<temp<<std::endl;
    temp.erase();
}
/* Map
 Key is airport code
 the value would be everything in the airport class
 */

