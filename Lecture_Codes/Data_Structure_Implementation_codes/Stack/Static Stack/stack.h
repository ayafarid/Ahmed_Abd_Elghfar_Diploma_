#ifndef _STACK_H_
#define _STACK_H_
#include "Platform_Types.h"
#define STACK_MAX_SIZE   5
#define EMPTY_INDEX      -1
#if 0
#define STACK_DEBUG      1
#endif // 0


typedef struct stack_ds{
    sint32 stack_size;
    sint32 stack_top; /// stack top
    uint32 data[STACK_MAX_SIZE];
}Stack;
typedef enum stack_status{
    STACK_EMPTY       ,
    STACK_FULL        ,
    STACK_NOT_FULL    ,
    STACK_POINTER_NULL,
    STACK_NOT_EMPTY
}Stack_Status_e;

/**
  *@brief initialize the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the initialization process
  */
Return_Status_e Stack_Init(Stack* my_stack);
/**
  *@brief Push element to the stack
  *@param my_stack Pointer to the stack
  *@param the value will pushed to the stack
  *@retval Status of the Pushing process
  */
Return_Status_e Stack_Push(Stack* my_stack,uint32 value);
/**
  *@brief Pop element from the stack
  *@param my_stack Pointer to the stack
  *@param pointer to the value that will poped from stack
  *@retval Status of the pop process
  */
Return_Status_e Stack_Pop(Stack* my_stack,uint32* value);
/**
  *@brief Get Top of the stack
  *@param my_stack Pointer to the stack
  *@param pointer to the value
  *@retval Status of the getting top value process
  */
Return_Status_e Stack_Top(Stack* my_stack,uint32* value);
/**
  *@brief Get Size of the stack
  *@param my_stack Pointer to the stack
  *@param pointer to size of the stack
  *@retval Status of the getting size process
  */
Return_Status_e Stack_Size(Stack* my_stack,uint32* stackSize);
/**
  *@brief check empty of the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the checking Empty process
  */
static Stack_Status_e Stack_isEmpty(Stack* my_stack);
/**
  *@brief Check Full of the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the checking Full process
  */
static Stack_Status_e Stack_isFull(Stack* my_stack);
/**
  *@brief Displaying elements of the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the Displaying Elements process
  */
Return_Status_e Stack_Diplay_Elements(Stack* my_stack);


#endif // _STACK_H_
