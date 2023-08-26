#ifndef _STACK_H_
#define _STACK_H_

#define STACK_DEBUG
typedef struct stack_t{
    void **StackDArray;
    uint32 MaxSizeOfStack;
    uint32 ActualSize;
    sint32 StackTop;
}Stack;
typedef enum{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_NOT_FULL,
    STACK_EMPTY,
    STACK_NOT_EMPTY,
    STACK_NULL_POINTER
}Stack_Status_e;

Stack* creatStack(uint32 maxSize,Stack_Status_e* retStatus);
Stack* DestroyStack(Stack* stack_Obj,Stack_Status_e* retStatus);
Stack_Status_e PushStack(Stack* stack_obj,void* itemPtr);
void * PopStack(Stack* stack_obj,Stack_Status_e* retStatus);
void * StackTop(Stack* stack_obj,Stack_Status_e* retStatus);
Stack_Status_e StackCount(Stack* stack_obj,uint32* stackCount);
static Stack_Status_e Stack_isEmpty(Stack* stack_obj);
static Stack_Status_e Stack_isFull(Stack* stack_obj);
#endif // _STACK_H_
