#include "stdio.h"
#include "stack.h"
#include "Platform_Types.h"

/**
  *@brief initialize the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the initialization process
  */
Return_Status_e Stack_Init(Stack* my_stack){
    Return_Status_e Local_ReturnStatus=Return_NOK;
    if(my_stack!=NULL){
        my_stack->stack_top=EMPTY_INDEX;
        my_stack->stack_size=0;
        Local_ReturnStatus=Return_OK;
        #ifdef STACK_DEBUG
        printf("Stack init is Done\n");
        #endif
    }else{
        Local_ReturnStatus=Return_NULL_Error;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_ReturnStatus;
}
/**
  *@brief Push element to the stack
  *@param my_stack Pointer to the stack
  *@param the value will pushed to the stack
  *@retval Status of the Pushing process
  */
Return_Status_e Stack_Push(Stack* my_stack,uint32 value){
    Return_Status_e Local_ReturnStatus=Return_NOK;
    uint32 FullCheck=(Stack_isFull(my_stack)==STACK_FULL);
    if(my_stack!=NULL && FullCheck==0){
        my_stack->data[++my_stack->stack_top]=value;
        my_stack->stack_size++;
        Local_ReturnStatus=Return_OK;
        #ifdef STACK_DEBUG
        printf("The element added successfully!!!\n");
        #endif
    }else if(FullCheck==1){
        Local_ReturnStatus=STACK_FULL;
        #ifdef STACK_DEBUG
        printf("The element can't add to the stack because stack is full!!!\n");
        #endif
    }else{
        Local_ReturnStatus=Return_NULL_Error;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_ReturnStatus;
}
/**
  *@brief Pop element from the stack
  *@param my_stack Pointer to the stack
  *@param pointer to the value that will poped from stack
  *@retval Status of the pop process
  */
Return_Status_e Stack_Pop(Stack* my_stack,uint32* value){
    Return_Status_e Local_ReturnStatus=Return_NOK;
    uint32 Emptycheck=(Stack_isEmpty(my_stack)==STACK_EMPTY);
    if(my_stack!=NULL && value!=NULL && Emptycheck==0){
        *value=my_stack->data[my_stack->stack_top];
        my_stack->stack_top--;
        my_stack->stack_size--;
        Local_ReturnStatus=Return_OK;
        #ifdef STACK_DEBUG
        printf("The Top is popped successfully!\n");
        #endif
    }else if(Emptycheck==1){
        Local_ReturnStatus=Return_NOK;
        *value=-1;
        #ifdef STACK_DEBUG
        printf("The top can't popped because the stack is Empty!\n");
        #endif
    }
    else{
        Local_ReturnStatus=Return_NULL_Error;
        *value=-1;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_ReturnStatus;
}
/**
  *@brief Get Top of the stack
  *@param my_stack Pointer to the stack
  *@param pointer to the value
  *@retval Status of the getting top value process
  */
Return_Status_e Stack_Top(Stack* my_stack,uint32* value){
    Return_Status_e Local_ReturnStatus=Return_NOK;
    if(my_stack!=NULL && value!=NULL && Stack_isEmpty(my_stack)!=STACK_NOT_EMPTY){
        value=my_stack->data[my_stack->stack_top];
        Local_ReturnStatus=Return_OK;
        #ifdef STACK_DEBUG
        printf("The top is returned Successfully!\n");
        #endif // STACK_DEBUG
    }else if(Stack_isEmpty(my_stack)!=STACK_EMPTY){
        Local_ReturnStatus=Return_NOK;
        #ifdef STACK_DEBUG
        printf("The top can't returned because the stack is Empty!\n");
        #endif
    }
    else{
        Local_ReturnStatus=Return_NULL_Error;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_ReturnStatus;
}
/**
  *@brief Get Size of the stack
  *@param my_stack Pointer to the stack
  *@param pointer to size of the stack
  *@retval Status of the getting size process
  */
Return_Status_e Stack_Size(Stack* my_stack,uint32* stackSize){
    Return_Status_e Local_ReturnStatus=Return_NOK;
    if(my_stack!=NULL && stackSize!=NULL){
        *stackSize=my_stack->stack_size;
        Local_ReturnStatus=Return_OK;
        #ifdef STACK_DEBUG
        printf("The stack size is returned successfully!\n");
        #endif
    }else{
        Local_ReturnStatus=Return_NULL_Error;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_ReturnStatus;
}
/**
  *@brief check empty of the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the checking Empty process
  */
static Stack_Status_e Stack_isEmpty(Stack* my_stack){
    Stack_Status_e Local_StackStatus=STACK_EMPTY;
    if(my_stack!=NULL){
        if(my_stack->stack_size>0)
            Local_StackStatus=STACK_NOT_EMPTY;
        else
            Local_StackStatus=STACK_EMPTY;
        #ifdef STACK_DEBUG
        printf("Empty check is done successfully!\n");
        #endif // STACK_DEBUG
    }else{
        Local_StackStatus=STACK_POINTER_NULL;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_StackStatus;
}
/**
  *@brief Check Full of the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the checking Full process
  */
static Stack_Status_e Stack_isFull(Stack* my_stack){
    Stack_Status_e Local_StackStatus=STACK_FULL;
    if(my_stack!=NULL){
        if(my_stack->stack_size==STACK_MAX_SIZE)
            Local_StackStatus=STACK_FULL;
        else
            Local_StackStatus=STACK_NOT_FULL;
        #ifdef STACK_DEBUG
        printf("Full check is done successfully!\n");
        #endif // STACK_DEBUG
    }else{
        Local_StackStatus=STACK_POINTER_NULL;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_StackStatus;
}
/**
  *@brief Displaying elements of the stack
  *@param my_stack Pointer to the stack
  *@retval Status of the Displaying Elements process
  */
Return_Status_e Stack_Diplay_Elements(Stack* my_stack){
    Return_Status_e Local_ReturnStatus=Return_NOK;
    if(my_stack!=NULL){
        printf("Stack elements: ");
        for(int i=my_stack->stack_top;i>=0;i--){
            printf("%d ",my_stack->data[i]);
        }
        printf("\n");
        Local_ReturnStatus=Return_OK;
        #ifdef STACK_DEBUG
        printf("Display elements is Done successfully!\n");
        #endif // STACK_DEBUG
    }else{
        Local_ReturnStatus=Return_NULL_Error;
        #ifdef STACK_DEBUG
        printf("NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_ReturnStatus;
}
