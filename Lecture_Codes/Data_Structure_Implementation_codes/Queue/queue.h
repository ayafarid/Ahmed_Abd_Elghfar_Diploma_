#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Platform_Types.h"
#define QUEUE_DEBUG
typedef struct queue_t{
    void **QueueArray;
    uint32 QueueMaxSize;
    sint32 numberOfActualElements;
    sint32 QueueFront;
    sint32 QueueRear;
}Queue;

typedef enum{
    QUEUE_NOK=0,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER
}QueueStatus_e;
/**
  *@brief creating queue object
  *@param the maxsize of my queue (maxSize)
  *@param pointer to the queue state (state)
  *@retval the pointer of the queue object would created or NULL if the process faild
  */
Queue * creatQueue(uint32 maxSize,QueueStatus_e* state);
/**
  *@brief push element from front of queue
  *@param pointer to my queue object (queueObj)
  *@param pointer to the element would added to the queue from the rear side (ptrItem)
  *@retval the state of my queue
  */
QueueStatus_e enqueue(Queue* queueObj,void* ptrItem);
/**
  *@brief pop element from the front side of the queue
  *@param pointer to my queue object (queueObj)
  *@param pointer to the state of the queue (state)
  *@retval the state of my queue
  */
void* dequeue(Queue* queueObj,QueueStatus_e* state);
/**
  *@brief retrive the element at the front of the queue
  *@param pointer to my queue object (queueObj)
  *@param pointer to the state of the queue (state)
  *@retval pointer to the returned front
  */
void* queueFront(Queue* queueObj,QueueStatus_e* state);
/**
  *@brief retrive the element at the Rear of the queue
  *@param pointer to my queue object (queueObj)
  *@param pointer to the state of the queue (state)
  *@retval pointer the returned Rear
  */
void* queueRear(Queue* queueObj,QueueStatus_e* state);
/**
  *@brief get the count element of the queue
  *@param pointer to my queue object (queueObj)
  *@param pointer the count var (queueCount)
  *@retval return the state of the queue
  */
QueueStatus_e GetQueueCount(Queue* queueObj,uint32* queueCount);
/**
  *@brief check if the queue is empty or not
  *@param pointer to my queue object (queueObj)
  *@retval return 1 if queue is empty , 0 if not empty
  */
static uint8 queueIsEmpty(Queue* queueObj);
/**
  *@brief check if the queue is full or not
  *@param pointer to my queue object (queueObj)
  *@retval return 1 if queue is full , 0 if not full
  */
static uint8 queueIsFull(Queue* queueObj);
#endif // _QUEUE_H_
