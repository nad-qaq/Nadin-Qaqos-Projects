#ifndef H_TOKEN
#define H_TOKEN
#include <iostream>

using namespace std;

class Token
{
    public: 
        Token();
        Token(double d);
        Token(int i);
        Token(char c); 

        bool Valid() const; 
        bool IsOperand() const; 
        bool IsOperator() const; 
        bool IsLeftParen() const; 
        bool IsRightParen() const;
        double Operand() const; 
        char Operator() const; 
        int Precedence() const; 

        Token operator + (const Token & arg) const;
        Token operator - (const Token& arg) const;
        Token operator * (const Token& arg) const;
        Token operator / (const Token& arg) const ;
        Token operator % (const Token& arg) const;
       // Token operator ^ (const Token& arg) const ;
        friend ostream& operator << (ostream&o,const Token&t);

    private: 
        static bool unary;
        bool valid; 
        double value;
        char ch; 
        bool isnumber; 
};
istream& operator >> (istream&i,Token&t);

#endif