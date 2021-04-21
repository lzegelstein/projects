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

void parse_line(std::string & input) {
    //int count = 0;
    std::vector<std::string> separate_strings;
    std::string airport_name;
    std::string temp;
    int count = 0;
    
    while (!input.empty()) {
        
        char first = input.front();
        char comma = ',';
        if (first != comma) {
            temp.append(first); //I'm having issues on this line. Will look again at it in the morning. There's a type error
        }
        else {
            separate_strings[count] = temp;
            count ++;
        }
    }
}
/*
 This function will be a helper to check if the string that is read in is acceptable or not for our program. If the columns we care about are filled in, then data_check returns true.
 */
bool data_check (std::string & input, int & count) {
    if (count == 0) {
        
    }
    return true;
}

/* Map
 Key is airport code
 the value would be everything in the airport class
 */

