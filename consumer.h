#ifndef CONSUMER_H
#define CONSUMER_H

#include "synch.h"

extern const int SIZE;
extern int buffer[];
extern int front;
extern int rear;
extern Lock *lock;
extern int curr;
extern Condition *full;
extern Condition *empty;

class consumer {
  public:
    static void ConsumerConsume(void *name);
};

#endif // CONSUMER_H
