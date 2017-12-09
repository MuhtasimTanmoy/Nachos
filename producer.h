#ifndef PRODUCER_H
#define PRODUCER_H

#include "synch.h"

extern const int SIZE;
extern int buffer[];
extern int front;
extern int rear;
extern int curr;
extern Lock *lock;
extern Condition *full;
extern Condition *empty;

class producerInfo {

  public:
    char * name = new char[50];
    int producedNum;

};

class producer {

  public:
    static void ProducerProduce(void *info);
};

#endif // PRODUCER_H
