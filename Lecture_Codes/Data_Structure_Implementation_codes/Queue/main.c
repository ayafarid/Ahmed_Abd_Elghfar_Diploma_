#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
Queue* myQueue=NULL;
QueueStatus_e state;
uint32 var1=10;
uint32 var2=20;
uint8 var3='A';
uint32 count=0;
int main()
{
    myQueue=creatQueue(5,&state);
    void* returnVal=NULL;
    enqueue(myQueue,&var1);
    enqueue(myQueue,&var2);
    enqueue(myQueue,&var3);
    enqueue(myQueue,&var1);
    enqueue(myQueue,&var2);
    GetQueueCount(myQueue,&count);
    printf("Queue Count: %d\n",count);
    returnVal=dequeue(myQueue,&state);
    printf("%d\n",*((uint32*)returnVal));
    returnVal=dequeue(myQueue,&state);
    printf("%d\n",*((uint32*)returnVal));
    returnVal=dequeue(myQueue,&state);
    printf("%c\n",*((uint8*)returnVal));
    returnVal=queueFront(myQueue,&state);
    printf("Queue Front: %d\n",*((uint32*)returnVal));
    returnVal=queueRear(myQueue,&state);
    printf("Queue Rear: %d\n",*((uint32*)returnVal));
    DestroyQueue(myQueue);
    return 0;
}
