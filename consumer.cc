#include "copyright.h"
#include "consumer.h"
#include "system.h"

void
consumer::ConsumerConsume(void *name)
{
  while(1){
    char* threadName = (char*)name;
    lock->Acquire();
    for(int p=0;p<rand()%40000+100000000;p++){

    }
    while(curr == 0){
	empty->Wait(lock);
    }
    int popped = buffer[rear];
    printf("[Consumer thread]: %s has consumed : %d\n",threadName,popped);
    curr--;
    printf("current: %d || remaining: %d\n\n", curr, SIZE - curr );
    rear = (rear + 1) % SIZE;
    if(curr == SIZE-1) {
	full->Signal(lock);
	printf("%s is notifying all waiting producers\n",threadName);
    }
    lock->Release();
}
}
