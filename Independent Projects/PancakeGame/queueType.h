#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>
#include <cassert>

using namespace std;

template<class Type>
class queueType
{
public:
    const queueType<Type>& operator=(const queueType<Type>&); 

    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    void destroyQueue();

    Type front() const;
    Type back() const;

    void addQueue(const Type& queueElement);
    void deleteQueue();

    queueType(int queueSize = 100);
    queueType(const queueType<Type>& otherQueue); 
    ~queueType(); 

private:
    int maxQueueSize; 
    int count;        
    int queueFront;   
    int queueRear;    
    Type *list; 
};

template<class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
    queueRear = maxQueueSize - 1;
	count = 0;
}

template<class Type>
void queueType<Type>::destroyQueue()
{
	queueFront = 0;
    queueRear = maxQueueSize - 1;
	count = 0;
}


template<class Type>
bool queueType<Type>::isEmptyQueue() const
{
   return(count == 0);
}

template<class Type>
bool queueType<Type>::isFullQueue() const
{
   return(count == maxQueueSize);
}


template<class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
   if (!isFullQueue())
   {   
		queueRear = (queueRear + 1) % maxQueueSize; //use mod operator 
						 //to advance queueRear because 
 						 //the array is circular
   		count++;
   		list[queueRear] = newElement;
   }
   else
  		cout << "Cannot add to a full queue." << endl; 
}


template<class Type>
Type queueType<Type>::front() const
{
   assert(!isEmptyQueue());
   return list[queueFront]; 
}


template<class Type>
Type queueType<Type>::back() const
{
     assert(!isEmptyQueue());
     return list[queueRear];
}


template<class Type>
void queueType<Type>::deleteQueue()
{
   if (!isEmptyQueue())
   {   
		count--;
   		queueFront = (queueFront + 1) % maxQueueSize; //use the mod 
						//operator to advance queueFront 
 						//because the array is circular 
   }
   else
		cout << "Cannot remove from an empty queue" << endl;
}


//constructor
template<class Type>
queueType<Type>::queueType(int queueSize)   
{
    if (queueSize <= 0)
    {
		cout << "Size of the array to hold the queue must "
			 << "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxQueueSize = 100;
    }
    else
   		maxQueueSize = queueSize;  //set maxQueueSize to queueSize

    queueFront = 0; 	   		   //initialize queueFront
    queueRear = maxQueueSize - 1; 	   //initialize queueRear
    count = 0;
    list = new Type[maxQueueSize];  //create the array to
				            //hold the queue elements
	assert(list != NULL);
}


template<class Type>
queueType<Type>::~queueType()   //destructor
{
   delete [] list;
}

template<class Type>
const queueType<Type>& queueType<Type>::operator=
	                   (const queueType<Type>& otherQueue)
{
    if (this != &otherQueue)
    {
        delete [] list;
        maxQueueSize = otherQueue.maxQueueSize;
        count = otherQueue.count;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        list = new Type[maxQueueSize];
        for (int i=0; i<maxQueueSize; i++)
            list[i] = otherQueue.list[i];
    }
    return *this;
}

template<class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue)
{
    maxQueueSize = otherQueue.maxQueueSize;
    count = otherQueue.count;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    list = new Type[maxQueueSize];
    for (int i=0; i<maxQueueSize; i++)
        list[i] = otherQueue.list[i];
}


#endif