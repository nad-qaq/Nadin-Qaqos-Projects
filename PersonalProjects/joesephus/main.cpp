#include <iomanip>
#include <iostream>
#include "josephus.h"
#include "exception.h"

using namespace std; 
using namespace myNameSpace;

int main() {

    try {
        int totalPeople;
        cout << "How many people are in the circle?  ";
        cin >> totalPeople;

        int start; 
        cout << "Which person would you like to start at? ";
        cin >> start;

        // k is the number of people getting skipped. 
        // if we are killing every other person then 
        // we are skipping one person
        int k = 1; 

        Josephus<int> group1(totalPeople); 

        // creates a vector of the number of people the person picked 
        vector<int> tempVec;
        for (int i = 1; i <= totalPeople; ++i) {
            tempVec.push_back(i);
        }

        // starts the killing process 
        group1.kill(tempVec, start, k);
    } catch (exception& e){
        cout << "Error: " << e.what() << endl; 
    }
    
    return 0; 
}
