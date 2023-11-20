#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>

using namespace std;

template<class Type>
class stackType
{
public:
    const stackType<Type>& operator=(const stackType<Type>&); 

    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void destroyStack();

    void push(const Type& newItem);
    Type top() const;
    void pop();

    stackType(int stackSize = 100); 
    stackType(const stackType<Type>& otherStack); 
    ~stackType(); 

private:
    int maxStackSize; 
    int stackTop;    
    Type *list;      

    void copyStack(const stackType<Type>& otherStack); 
};


template<class Type>
void stackType<Type>::initializeStack()
{
   stackTop = 0;
}//end initializeStack

template<class Type>
void stackType<Type>::destroyStack()
{
   stackTop = 0;
}//end destroyStack

template<class Type>
bool stackType<Type>::isEmptyStack() const
{
   return(stackTop == 0);
}//end isEmptyStack

template<class Type>
bool stackType<Type>::isFullStack() const
{
   return(stackTop == maxStackSize);
} //end isFullStack

template<class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
      list[stackTop] = newItem;    //add newItem to the 
                //top of the stack
      stackTop++;   //increment stackTop
    }
    else
      cout << "Cannot add to a full stack." << endl;
}//end push

template<class Type>
Type stackType<Type>::top() const
{
   assert(stackTop != 0);              //if stack is empty, 
                               //terminate the program
   return list[stackTop - 1];         //return the element of the 
                              //stack indicated by 
                                 //stackTop - 1
}//end top

template<class Type>
void stackType<Type>::pop()
{
   if (!isEmptyStack())
       stackTop--;             //decrement stackTop 
    else
      cout << "Cannot remove from an empty stack." << endl;
}//end pop

template<class Type>
stackType<Type>::stackType(int stackSize) 
{
   if(stackSize <= 0)
   {
      cout << "Size of the array to hold the stack must "
          << "be positive." << endl;
      cout << "Creating an array of size 100." << endl;

      maxStackSize = 100;
   }
   else
      maxStackSize = stackSize;  //set the stack size to 
                          //the value specified by 
                        //the parameter stackSize

   stackTop = 0;               //set stackTop to 0
   list = new Type[maxStackSize]; 
   assert(list != NULL);
}//end constructor

template<class Type>
stackType<Type>::~stackType() //destructor
{
   delete [] list; //deallocate the memory occupied 
                   //by the array
}//end destructor

template<class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{ 

   delete [] list;               
   maxStackSize = otherStack.maxStackSize;         
   stackTop = otherStack.stackTop;            
     
   list = new Type[maxStackSize];         
   assert(list != NULL);            

             //copy otherStack into this stack
   for (int j = 0; j < stackTop; j++)  
       list[j] = otherStack.list[j];
} //end copyStack


template<class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
   list = NULL;

   copyStack(otherStack);
}//end copy constructor

template<class Type>
const stackType<Type>& stackType<Type>::operator=
                  (const stackType<Type>& otherStack)
{ 
   if (this != &otherStack) //avoid self-copy
      copyStack(otherStack);

   return *this; 
} //end operator=         

#endif