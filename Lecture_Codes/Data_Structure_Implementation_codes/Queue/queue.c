#include <stdio.h>
#include "Platform_Types.h"
#include "queue.h"
Queue * creatQueue(uint32 maxSize,QueueStatus_e* state){
    Queue* ptrQueue=NULL;
    if(state==NULL){
        ptrQueue=NULL;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG

    }else{
        ptrQueue=(Queue*)malloc(sizeof(Queue));
        if(ptrQueue==NULL){
            *state=QUEUE_NOK;
            #ifdef QUEUE_DEBUG
            printf("Error while creating Object using malloc function!\n");
            #endif // QUEUE_DEBUG
        }
        else{
            ptrQueue->QueueMaxSize=maxSize;
            ptrQueue->QueueFront=-1;
            ptrQueue->QueueRear=-1;
            ptrQueue->numberOfActualElements=0;
            ptrQueue->QueueArray=(void**)malloc(sizeof(void*)*ptrQueue->QueueMaxSize);
            if(ptrQueue->QueueArray==NULL){
                ptrQueue=NULL;
                #ifdef QUEUE_DEBUG
                printf("Error while creating array!\n");
                #endif // QUEUE_DEBUG
            }else{
                *state=QUEUE_OK;
                #ifdef QUEUE_DEBUG
                printf("Creating Queue is Done successfully!\n");
                #endif // QUEUE_DEBUG
            }
        }
    }
    return ptrQueue;
}
QueueStatus_e enqueue(Queue* queueObj,void* ptrItem){
    QueueStatus_e Local_Status=QUEUE_NOK;
    if(queueObj==NULL || ptrItem==NULL){
        Local_Status=QUEUE_NULL_POINTER;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG
    }else{
        if(queueIsFull(queueObj)==0){
            ++(queueObj->QueueRear);
            if(queueObj->QueueRear==queueObj->QueueMaxSize){
                queueObj->QueueRear=0;
            }
            queueObj->QueueArray[queueObj->QueueRear]=ptrItem;
            if(queueObj->numberOfActualElements==0){
                (queueObj->QueueFront)++;
            }
            (queueObj->numberOfActualElements)++;
            Local_Status=QUEUE_OK;
            #ifdef QUEUE_DEBUG
            printf("Element Added successfully!\n");
            #endif // QUEUE_DEBUG
        }else{
            Local_Status=QUEUE_FULL;
            #ifdef QUEUE_DEBUG
            printf("Queue is full and you can't add item to it!\n");
            #endif // QUEUE_DEBUG
        }
    }
    return Local_Status;
}
void* dequeue(Queue* queueObj,QueueStatus_e* state){
    void* ptrElement;
    if(queueObj==NULL || state==NULL){
        ptrElement=NULL;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG
    }
    else{
        if(queueIsEmpty(queueObj)==1){
            *state=QUEUE_EMPTY;
            ptrElement=NULL;
            #ifdef QUEUE_DEBUG
            printf("Queue is empty and you can't enqueue element from it!\n");
            #endif // QUEUE_DEBUG
        }
        else{
            ptrElement=queueObj->QueueArray[(queueObj->QueueFront)++];
            if(queueObj->QueueFront==queueObj->QueueMaxSize)
                queueObj->QueueFront=0;
            if(queueObj->numberOfActualElements==1){
                queueObj->QueueFront=-1;
                queueObj->QueueRear=-1;
            }
            (queueObj->numberOfActualElements)--;
            *state=QUEUE_OK;
            #ifdef QUEUE_DEBUG
            printf("Dequeue operation is done successfully!\n");
            #endif // QUEUE_DEBUG
        }
    }
    return ptrElement;
}

void* queueFront(Queue* queueObj,QueueStatus_e* state){
    void* ptrElement=NULL;
    if(queueObj==NULL || state==NULL){
        ptrElement=NULL;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG
    }else{
        ptrElement=queueObj->QueueArray[queueObj->QueueFront];
        *state=QUEUE_OK;
        #ifdef QUEUE_DEBUG
        printf("Element at front returned successfully!\n");
        #endif // QUEUE_DEBUG
    }
    return ptrElement;
}
void* queueRear(Queue* queueObj,QueueStatus_e* state){
    void* ptrElement=NULL;
    if(queueObj==NULL || state==NULL){
        ptrElement=NULL;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG
    }else{
        ptrElement=queueObj->QueueArray[queueObj->QueueRear];
        *state=QUEUE_OK;
        #ifdef QUEUE_DEBUG
        printf("Element at rear returned successfully!\n");
        #endif // QUEUE_DEBUG
    }
    return ptrElement;
}
QueueStatus_e GetQueueCount(Queue* queueObj,uint32* queueCount){
    QueueStatus_e Local_Status=QUEUE_NOK;
    if(queueCount==NULL || queueObj==NULL){
        Local_Status=QUEUE_NULL_POINTER;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG
    }else{
        *queueCount=queueObj->numberOfActualElements;
        Local_Status=QUEUE_OK;
        #ifdef QUEUE_DEBUG
        printf("Count returned successfully!\n");
        #endif // QUEUE_DEBUG
    }
    return Local_Status;
}
QueueStatus_e DestroyQueue(Queue* queueObj){
    QueueStatus_e Local_Status=QUEUE_NOK;
    if(queueObj==NULL){
        Local_Status=QUEUE_NULL_POINTER;
        #ifdef QUEUE_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // QUEUE_DEBUG
    }else{
        free(queueObj->QueueArray);
        free(queueObj);
        Local_Status=QUEUE_OK;
        #ifdef QUEUE_DEBUG
        printf("Destroy Queue done successfully!\n");
        #endif // QUEUE_DEBUG
    }
    return Local_Status;
}
static uint8 queueIsEmpty(Queue* queueObj){
    return (queueObj->numberOfActualElements==0);
}
static uint8 queueIsFull(Queue* queueObj){
    return (queueObj->numberOfActualElements==queueObj->QueueMaxSize);
}
