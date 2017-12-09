#include "copyright.h"
#include "producer.h"
#include "system.h"

const int SIZE = 9;
int buffer[SIZE];
int front = 0;
int rear = 0;
int curr = 0;
Lock *lock = new Lock("lock");
Condition *full = new Condition("full");
Condition *empty = new Condition("empty");

void
producer::ProducerProduce(void *info)
{
  int changer=0;

  while(1){
    changer+=1;
    producerInfo* pInfo = (producerInfo*)info;
    lock->Acquire();
    for(int p=0;p<rand()%4530+100000000;p++){

    }
    while(curr == SIZE) {
	full->Wait(lock);
    }

    buffer[front] = pInfo->producedNum+changer+rand()%7;
    printf("[Producer thread]: %s has produced : %d\n",pInfo->name,buffer[front]);
    curr++;
    front = (front + 1) % SIZE;
    printf("current: %d || remaining: %d\n\n", curr, SIZE - curr );
    if(curr == 0) {
	empty->Signal(lock);
	printf("%s is notifying all waiting consumers\n",pInfo->name);
    }
    lock->Release();
  }

}
