#ifndef STACK_H
#define STACK_H
#include "../IOperations.h"

class Stack : public IOperations {
   private:
    int top;
    int length;
    char *data;

   public:
    Stack(int length);
    ~Stack();

    bool empty() override;
    void print(std::ostream &ostream) override;
    bool pop(char &out) override;
    char pop() override;
    bool push(char value) override;
    void clear() override;
};

#endif