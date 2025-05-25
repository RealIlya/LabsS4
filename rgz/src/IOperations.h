#ifndef IOPERATIONS_H
#define IOPERATIONS_H
#include <ostream>

// concrete receiver, will be inherited by sequences for implementation
class IOperations {
   public:
    virtual bool empty() = 0;
    virtual void print(std::ostream &ostream) = 0;
    virtual char pop() = 0;
    virtual bool pop(char &out) = 0;
    virtual bool push(char value) = 0;
    virtual void clear() = 0;
};

#endif