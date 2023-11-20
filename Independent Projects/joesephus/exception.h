#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

// this exception checks to see if there is at least one person in the circle
// and if not there is an error. 
class numberOfPeople {
    public:
        string what() {
            return "Error: Please pick at least one person. ";
        }
    
};

#endif 
