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

#define MAX_NUMBER 20


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
// 	Set up a ping-pong between two threads, by forking a thread
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


 consumer *c = new consumer;

 producer *p = new producer;

 for(int k = 1; k<=MAX_NUMBER; k++)
 {
  producerInfo *pi = new producerInfo;
  sprintf(pi->name, "Producer %c", (k%MAX_NUMBER)+64);
  pi->no = k%MAX_NUMBER;
  Thread* newThread = new Thread (pi->name);
       newThread->Fork (p->ProducerFunction, (void*)pi);
 }
 for(int k = 1; k<=MAX_NUMBER; k++)
 {
  char* threadname = new char[100];
       sprintf(threadname, "Consumer %d", k);
  Thread* newThread = new Thread (threadname);
       newThread->Fork (c->ConsumerFunction, (void*)threadname);
 }

    //t->Fork(SimpleThread, 1);
    //SimpleThread(0);
}
