#ifndef QUEUE_H
#define QUEUE_H
#include "../IOperations.h"

class Queue : public IOperations {
   private:
    int beg = 0;
    int end = -1;
    int length;
    char *data;

   public:
    Queue(int length);
    ~Queue();

    bool empty() override;
    void print(std::ostream &ostream);
    bool pop(char &out);
    char pop();
    bool push(char value);
    void clear() override;
};

#endif