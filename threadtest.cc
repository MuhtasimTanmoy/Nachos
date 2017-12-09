// threadtest.cc
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield,
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "Abul.h"
#include "producer.h"
#include "consumer.h"

#define MAX_NUMBER 4


//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
  //   int num;
  //
  //   for (num = 0; num < 5; num++) {
	// printf("*** thread %d looped %d times\n", which, num);
  //       currentThread->Yield();
  //   }
}

//----------------------------------------------------------------------
// ThreadTest
// 	Set up a pInfong-pong between two threads, by forking a thread
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest()
{

    // Thread *t = new Thread("forked thread");
//
 //     Abul myAbul;
 //     //myAbul.getAbul();
 //    // printf("%s\n","Hello" );
 // printf("%s\n",myAbul.getAbul());


 consumer *cons = new consumer;

 producer *prod = new producer;

 for(int i = 0; i<MAX_NUMBER; i++)
 {
  producerInfo *pInfo = new producerInfo;
  sprintf(pInfo->name, "Producer %c", (i%MAX_NUMBER)+65);
  pInfo->producedNum = i%MAX_NUMBER;
  Thread* thread = new Thread (pInfo->name);
  thread->Fork (prod->ProducerProduce, (void*)pInfo);
 }
 for(int j = 1; j<=MAX_NUMBER; j++)
 {
  char* threadname = new char[100];
  sprintf(threadname, "Consumer %d", j);
  Thread* thread= new Thread (threadname);
  thread->Fork (cons->ConsumerConsume, (void*)threadname);
 }

    //t->Fork(SimpleThread, 1);
    //SimpleThread(0);
}
