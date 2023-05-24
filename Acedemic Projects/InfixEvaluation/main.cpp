//Name:
//Due Date: 3/20/23
//Description: taking an infix expression and evaluating it using polymorphism and trees.  

#include <iostream>
#include <stack>
#include <string>
#include "ch12-1.cpp"
#include "token.h"

using namespace std;

// function to parse the input string and build an expression tree
AbstractNode* buildTree(stack<Token>& expressionToks) {
  
    stack<AbstractNode*> nodeStack; //operands - numbers
    stack<Token> opStack; //operator --

    while (!expressionToks.empty()) {
        Token tempToken = expressionToks.top();
        cout << "going through this token: " << tempToken << endl; 
        expressionToks.pop();
        if (tempToken.IsOperand()) {
            AbstractNode* node = new LeafNode(tempToken.Operand());
            nodeStack.push(node);

        } else if (tempToken.IsOperator()) {
            while (!opStack.empty() && !(tempToken.Precedence() >= opStack.top().Precedence())) {
                Token op = opStack.top();
                opStack.pop();
                AbstractNode* right = nodeStack.top();
                nodeStack.pop();
                AbstractNode* left = nodeStack.top();
                nodeStack.pop();
                BinaryNode* node = new BinaryNode(right, left, op.Operator());
                nodeStack.push(node);
            }
            opStack.push(tempToken); 
            
        } else if (tempToken.IsLeftParen()){
            opStack.push(tempToken.Operator());
        } else if (tempToken.IsRightParen()){
            while(!opStack.top().IsLeftParen()){
                Token op = opStack.top();
                opStack.pop();
                AbstractNode* right = nodeStack.top();
                nodeStack.pop();
                AbstractNode* left = nodeStack.top();
                nodeStack.pop();
                BinaryNode* node = new BinaryNode(right, left, op.Operator());
                nodeStack.push(node);
            }
            opStack.pop(); 

        }
        else {
            throw runtime_error("Invalid character in expression");
        }
    }
    while (!opStack.empty()) {
        Token op = opStack.top();
        opStack.pop();
        AbstractNode* right = nodeStack.top();
        nodeStack.pop();
        AbstractNode* left = nodeStack.top();
        nodeStack.pop();
        BinaryNode* node = new BinaryNode(right, left, op.Operator());
        nodeStack.push(node);
    }
    if (nodeStack.empty()) {
        throw runtime_error("No nodes in expression");
    }
    AbstractNode* root = nodeStack.top();
    return root;
}

int main() {
    stack<Token> expressionToks;
    Token token;
    cout << "Enter an expression: ";
    cin >> token; 

    while (token.Valid()) {
        expressionToks.push(token);
        cin >> token; 
    } try {
        AbstractNode* expr = buildTree(expressionToks);
        cout << "Result: " << expr->eval() << endl;
        //delete expr;
    } catch (exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
    return 0;
}
