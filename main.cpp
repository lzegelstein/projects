#include <_stdio.h>
#include <vector>
#include <string>
//#include "air_travel.hpp"
#include "AirTravel.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

/*
This file name is for debugging in xcode!
*/

int main(int argc, char** argv) {
    AirTravel ourmap("/Users/lylazegelstein/Desktop/airportnames.csv", "/Users/lylazegelstein/Desktop/routes-short.csv");
    return 0;
}
