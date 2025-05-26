#include "Queue.h"

#include <iostream>

Queue::Queue(int length) {
    beg = 0;
    end = -1;
    this->length = length;
    data = new char[length];
    for (int i = 0; i < length; i++)
        data[i] = '\0';
}

Queue::~Queue() {
    delete data;
    data = nullptr;
}

bool Queue::empty() {
    return end == -1;
}

void Queue::print(std::ostream &ostream) {
    if (empty()) {
        ostream << "Queue is empty";
        return;
    }

    for (int i = 0; i < length; i++)
        ostream << data[i] << " ";
}

char Queue::pop() {
    char buffedElement = data[beg];
    data[beg] = '\'';

    if (beg == end) {
        beg = 0;
        end = -1;
    } else {
        beg++;
    }
    return buffedElement;
}

bool Queue::pop(char &out) {
    if (empty())
        return 0;

    out = pop();
    return 1;
}

bool Queue::push(char value) {
    if (end == length - 1) {
        // in case of pseudo-fulness
        if (beg != 0) {
            for (int i = beg; i < length; i++) {
                char buffer = data[i];
                data[i] = '\0';
                data[i - beg] = buffer;
            }
            end -= beg;
            beg = 0;
        } else
            return 0;
    }
    data[++end] = value;
    return 1;
}

void Queue::clear() {
    for (int i = 0; i < length; i++)
        data[i] = '\0';

    beg = 0;
    end = -1;
}