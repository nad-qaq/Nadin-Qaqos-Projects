//Name: 
//Due Date: 1/23/23
//Description: converting infix expression into postfix while evaluating it as well. 

#include <iostream>
#include <iomanip>
#include <string>
#include "queueType.h"
#include "stackType.h"
#include "token.h"


using namespace std;
void convert(queueType<Token>& infixQueue,  queueType<Token>& postfixQueue, stackType<Token>& stk);
void evaluate(queueType<Token>& postfixQueue, stackType<Token>& stk);


int main(){

    Token input; 
    Token outputPostfix;
    queueType<Token> infix; 
    queueType<Token> postfix;
    stackType<Token> stack; 

    cout << "enter an expression: "; 
    cin >> input;
    cout << "The expression in infix: "; 
    while(input.Valid() && !infix.isFullQueue()){ //outputs what the user inputted while also putting it in a queue
        cout << input << " "; 
        infix.addQueue(input);
        cin >> input; 
    }
    cout <<  endl; 
    convert(infix, postfix, stack);
    
    //check to see if it goes in the queue right (this is used for testing purposes)
    // while(!infix.isEmptyQueue()) {
    //     cout << infix.front() << " "; 
    //     infix.deleteQueue();
        
    // }

    cout << "The expression in postfix: "; 
    queueType<Token> tempQ = postfix;   //creates temp queue to print the result of postfix
    while(!tempQ.isEmptyQueue()) {
        cout << tempQ.front() << " "; 
        tempQ.deleteQueue();
    }

    cout << endl; 
    evaluate(postfix, stack);

    return 0; 
}

//function that converts from infix to postfix. 
void convert(queueType<Token>& infixQueue,  queueType<Token>& postfixQueue, stackType<Token>& stk){

    while (!infixQueue.isEmptyQueue()){
        Token tempToken = infixQueue.front();

        if (tempToken.IsOperand()){ //if the token is an operand, add it to the postfix queue
            postfixQueue.addQueue(tempToken);
        }
    
        else if(tempToken.IsLeftParen()){   //if the token is a LEFTPAREN, push it on the stack
            stk.push(tempToken);
        }

        else if(tempToken.IsRightParen()){  //f the token is a RIGHTPAREN
            while(!stk.top().IsLeftParen()){ //pop operators from the stack and add them to the postfix queue until a LEFTPAREN is popped
                postfixQueue.addQueue(stk.top());
                stk.pop();  
            }
        stk.pop(); //LEFTPAREN is popped
        }

        else if(tempToken.IsOperator()){    //pop operators from the stack and add them to the postfix queue until one of the following is true: 
            while(!(tempToken.Operator() == '^') && (!stk.isEmptyStack()) && (!stk.top().IsLeftParen()) && !(tempToken.Precedence() >= stk.top().Precedence())){
                Token temp = stk.top(); 
                postfixQueue.addQueue(temp); 
                stk.pop(); 
            }
            stk.push(tempToken); //push the token on the stack
        }
        infixQueue.deleteQueue(); //delete the queue
            
    }
    while (!stk.isEmptyStack()){    //pop operators from the stack and add them to the postfix queue until stack is empty
        Token temp = stk.top(); 
        postfixQueue.addQueue(temp); 
        stk.pop();
    }
   
}

//function evaluates the expression
void evaluate(queueType<Token>& postfixQueue, stackType<Token>& stk){

    while (!postfixQueue.isEmptyQueue()){
        Token tempToken = postfixQueue.front();

        if (tempToken.IsOperand()){ //if the token is an operand, push it on the stack
            stk.push(tempToken);
        } 
        else if (tempToken.IsOperator()){   //if the token is an operator
            Token o1 = stk.top();       //pop the top two operands
            stk.pop();
            Token o2 = stk.top(); 
            stk.pop();
            if (tempToken.Operator() == '+')
                stk.push(o2 + o1); 
            if (tempToken.Operator() == '-')
                stk.push(o2 - o1); 
            if (tempToken.Operator() == '*')
                stk.push(o2 * o1); 
            if (tempToken.Operator() == '/')
                stk.push(o2 / o1); 
            if (tempToken.Operator() == '^')
                stk.push(o2 ^ o1); 
        }
        postfixQueue.deleteQueue();
    }

    cout << "The final result is: " << stk.top() << endl;  //pop the final result off the stack
    
}
