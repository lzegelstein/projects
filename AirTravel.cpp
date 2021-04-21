#include <_stdio.h>
#include <vector>
#include <string>
#include "AirTravel.h"
#include "parse.h"
#include <iostream>
#include <fstream>

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

void AirTravel::readInAirportData(){
    //TODO
    std::fstream data_file;
    data_file.open("airport.csv", std::ios::in);
    if (data_file.is_open()) {
        string trial;
        getline(data_file, trial);
        std::cout<<"from data_file: "<<trial<<std::endl;
    }
    data_file.close();
    std::cout<<"finished readInAirportData"<<std::endl;
}  

void AirTravel::addAirport(Airport* Airport){
    //TODO
}

AirTravel::Airport* AirTravel::findAirport(std::string Airport){
    //TODO
}

