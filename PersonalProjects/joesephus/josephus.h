#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>
#include "exception.h"

using namespace std;

namespace myNameSpace {

    template <class t>
    class Josephus {

        public:
            Josephus(int n); 
            t kill(vector<int> people, int start, int k ); 

        private:
    };

    // this is where the built exception is used. 
    // we have to know if we have enough people in the circle first 
    template <class t>
    Josephus<t>::Josephus(int n ){
        try{
            if (n <= 0) {
                throw numberOfPeople();
            }
        } catch(numberOfPeople error) {
            cout << error.what() << endl; 
        }

    } 

    // where the killing happens
    template <class t>
    t Josephus<t>::kill(vector<int> people, int start, int k ){

        // checks to see if your starting poing is less than the
        // number of people in your circle. If not, an exception occurs. 
        if (start > people.size()){
            throw out_of_range("You can't start there. That's more than the amount of people you picked.");
        }
        
        // go through the vector until there is one thing in there 
        if (people.size() >= 1){

            // this prints what's in the vector
            typename vector<t>::const_iterator iter;
            for(iter = people.begin(); iter != people.end(); iter++){
                cout << *iter << ' ';
            }   
            cout << "\n----------------------" << endl;

            // this is the algorithm I found online to solve this problem
            start = ((start + k) % people.size()); // find the start of first person which will die
            people.erase(people.begin() + start); // remove the first person which is going to be killed
            kill(people, start, k); // recursive call
        }

        // print who the last person in the circle is
        if (people.size() == 1) {
            cout << "The last person standing is: " << people[0] << endl;
        }
    } 

}

#endif

