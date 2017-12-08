#include "copyright.h"
#include "producer.h"
#include "system.h"
#include "time.h"

const int SIZE = 9;
int buffer[SIZE];
int length = 0;
int front = 0;
int rear = 0;
Lock *lock = new Lock("lock");
Condition *full = new Condition("full");
Condition *empty = new Condition("empty");

void
producer::ProducerFunction(void *info)
{
    producerInfo* pi = (producerInfo*)info;
    lock->Acquire();
    for(int p=0;p<10000000;p++){

    }
    while(length == SIZE) {
	full->Wait(lock);
    }

    buffer[front] = pi->no;
    printf("Producer thread: %s has produced : %d\n",pi->name,pi->no);
    length++;
    front = (front + 1) % SIZE;
    printf("current: %d | remaining: %d\n", length, SIZE - length );
    if(length == 0) {
	empty->Signal(lock);
	printf("%s is notifying all waiting consumers\n",pi->name);
    }
    lock->Release();
  }
