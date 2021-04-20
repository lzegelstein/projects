#pragma once
#include <_stdio.h>
#include <vector>

class Data {
    public:

    struct Pairs {
        char other_airport;
        int distance;
    };

    struct Node {
        Node();
        char name;
        std::vector<Pairs> destinations;
        int latitude;
        int longitude;
    };

    private:
    

};