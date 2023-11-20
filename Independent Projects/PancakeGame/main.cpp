#include <iostream>
#include <iomanip>
#include <string>
#include "queueType.h"
#include "stackType.h"

using namespace std;

void rotate(queueType<stackType<string>>& tempQueue);
void decorate(stackType<string>& tempPersonalStack, string& tempPhrase);
void get(queueType<stackType<string>>& tempQueue, stackType<string>& tempPersonalStack, int tableMax);
void put(queueType<stackType<string>>& tempQueue, stackType<string>& tempPersonalStack, int tableMax);
void eat(stackType<string>& tempPersonalStack);

int main() {

    int choice;
    int tableMax; 
    
    cout << "You enter the restaurant and sit down at a 'Lazy Susan' table. " << endl
         << endl
         << "Each member of your party has their own plate, and there are the same number of plates on the rotating table. " << endl
         << "Each plate on the Lazy Susan starts with 2 pancakes!" << endl
         << endl
         << "Your plate also starts with 2 pancakes!" << endl
         << endl
         << "Enter how many people are at the table: ";
    cin >> tableMax; 
    cout << "You have a party of " << tableMax << "!" << endl << endl;
    // create our lazy susan according to how many people the user wanted 
    queueType<stackType<string>> lazySusan; 
    for (int i = 0; i < tableMax; i++){        // creates a stack puts two strings/pancakes on it
        stackType<string> lazyPlate;
        lazyPlate.push("");
        lazyPlate.push("");
        lazySusan.addQueue(lazyPlate);
    }

    stackType<string> personalPlate;
    personalPlate.push("");
    personalPlate.push("");

    while (choice != 6){
        cout << "Select an option: " << endl		//options
             << "1. Rotate the table " << endl
             << "2. Decorate a pancake " << endl
             << "3. Get a pancake" << endl
             << "4. Put a pancake back " << endl
             << "5. Eat a pancake " << endl
             << "6. exit " << endl
             << "Enter your choice (1-6): " ;
             cin >> choice;
   
        if (choice == 1){       //rotate
            rotate(lazySusan);

        }else if (choice == 2){      //decorate
            string phrase; 
            cout << "Enter a decorative phrase: ";
            cin >> phrase; 
            decorate(personalPlate, phrase);

        }else if (choice == 3){     //get
            get(lazySusan, personalPlate, tableMax);
                
        }else if (choice == 4){     //put
            put(lazySusan, personalPlate, tableMax);

        }else if (choice == 5){     //eat
            eat(personalPlate);
                
        }else if (choice == 6){     //exit
            cout << "GOODBYE! :( " << endl;	
                
        } else {
            cout << "Invalid option, please pick a correct option. " << endl << endl;	//if they insert something other than what is listed 
        }
    }
    
    return 0;
}

//get the first item, delete it, add it to the back? 
void rotate(queueType<stackType<string>>& tempQueue){

    if (!tempQueue.isEmptyQueue()){
        stackType<string> tempLazyPlate = tempQueue.front();    // create a temp variable that holds the stack at the front of the queue
        tempQueue.deleteQueue();                                // delete the front
        tempQueue.addQueue(tempLazyPlate);                      // add temporary to the back
    }
    cout << "Table rotated! " << endl << endl; 
}

// find what is said on top of the personal plate, add the phrase user wants
void decorate(stackType<string>& tempPersonalStack, string& tempPhrase){

    if (tempPersonalStack.isEmptyStack()){                  // if stack is empty 
        cout << "Sorry, your plate is empty. "
             << "Nothing to decorate :( " << endl << endl; 
    }

    else if(!tempPersonalStack.isEmptyStack()){                     // if stack is not empty

        string currentPhrase = tempPersonalStack.top() ;            // gets the current phrase on pancake 
        string exString = currentPhrase + " " + tempPhrase;         // concatonates what is on the current pankcake with what the user wants to add
        tempPersonalStack.pop();                                    // delete pancake on personal plate
        tempPersonalStack.push(exString);                           // add the new phrase to the personal plate          
        cout << "Pancake Decorated! " << endl << endl;
    }
}

// delete pancake from stack in front of you, add pancake to your personal plate,
void get(queueType<stackType<string>>& tempQueue, stackType<string>& tempPersonalStack,int tableMax){

    if (!tempQueue.isEmptyQueue()){                                 // if serving table is not empty

        stackType<string> tempLazyPlate = tempQueue.front();        // creates temporary serving plate of what is on top of the queue
        if (!tempLazyPlate.isEmptyStack()){                         // if serving plate is not empty
            string topPancake = tempLazyPlate.top();                // stores what the top pancake has written on it 
            tempLazyPlate.pop();                                    // pop off the first thing on the plate
            tempPersonalStack.push(topPancake);                     // add a pancake to personal plate with the phrase 
            tempQueue.deleteQueue();                                // delete the first stack in the queue
            tempQueue.addQueue(tempLazyPlate);                      // adds a new updated stack to the end 

            for ( int i = 0; i < tableMax - 1; i++){                // since we added the new updated stack to the end we 
                                                                    // have to rotate it so that it becomes at the front. 
                stackType<string> temp = tempQueue.front();         // create a temp variable and put front in
                tempQueue.deleteQueue();                            // delete the front
                tempQueue.addQueue(temp);                           // add temp to the back
            }
            cout << "You got a pancake! " << endl << endl;

        } else {
             cout << "Sorry, the plate on the serving table is empty. "<< endl << endl; 
        }
    }
}


// delete pancake from personal plate, add pancake to the plate on serving plate
void put(queueType<stackType<string>>& tempQueue, stackType<string>& tempPersonalStack, int tableMax){

    if (!tempQueue.isEmptyQueue()){                                 // if the serving table is not empty

        stackType<string> tempLazyPlate = tempQueue.front();        // create temporary serving plate that has what is on top of the queue
        if (!tempPersonalStack.isEmptyStack()){                     // if personal plate is not empty 
            string topPancake = tempPersonalStack.top();            // stores what the top pancake of the personal plate has written on it 
            tempPersonalStack.pop();                                // pop off a pancake from personal plate
            tempLazyPlate.push(topPancake);                         // add a pancake to the top of the serving plate with the phrase
            tempQueue.deleteQueue();                                // delete the first stack in the queue    
            tempQueue.addQueue(tempLazyPlate);                      // adds the lazy plate onto the queue

            for ( int i = 0; i < tableMax - 1; i++){                // same part as above

                stackType<string> temp = tempQueue.front();    
                tempQueue.deleteQueue();                                
                tempQueue.addQueue(temp); 
            }

            cout << "You put back a pancake! " << endl << endl;
            
        } else if (tempQueue.isEmptyQueue()) {
             cout << "Sorry, your personal plate is empty. " << endl << endl; 
        }
    }
}

//print out what is on the top of personal plate, then delete the top
void eat(stackType<string>& tempPersonalStack){

    if(!tempPersonalStack.isEmptyStack()){                                      // if personal plate is not empty

        if (tempPersonalStack.top() == ""){                                     // if the string on the top pancake says ""
            cout << "The pancake is empty. Its not decorated :(" << endl ;      // say there is nothing decorated
        } else{     
            cout << "The pancake says: " << tempPersonalStack.top() << endl;    // if it is decorated, say what it says                                       
        }
        tempPersonalStack.pop();                                                // then pop it from the personal stack 
        cout << "You ate a pancake! " << endl << endl;
    } else if (tempPersonalStack.isEmptyStack()){                               // if personal stack is empty
        cout << "Sorry, your personal plate is empty. "<< endl << endl;         // say it is
    }
}


