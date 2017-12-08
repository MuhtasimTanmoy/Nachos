#include "copyright.h"
#include "consumer.h"
#include "system.h"
#include "time.h"

void
consumer::ConsumerFunction(void *name)
{
    char* threadName = (char*)name;
    lock->Acquire();
    while(length == 0){
	empty->Wait(lock);
    }
    int m = buffer[rear];
    printf("Consumer thread: %s has consumed : %d\n",threadName,m);
    length--;
    rear = (rear + 1) % SIZE;
    if(length == SIZE-1) {
	full->Broadcast(lock);
	printf("%s is notifying all waiting producers\n",threadName);
    }
    lock->Release();
}
