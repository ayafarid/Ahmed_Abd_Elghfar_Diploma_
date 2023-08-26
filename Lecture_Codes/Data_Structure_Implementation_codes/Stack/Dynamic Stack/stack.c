#include "stdio.h"
#include "Platform_Types.h"
#include "stack.h"
/**
  *@brief Create Stack object
  *@param max Size of stack
  *@param return Status of create stack Function
  *@retval pointer to the stack created
  */
Stack * creatStack(uint32 maxSize,Stack_Status_e * retStatus){
    Stack *my_dStack;
    if(retStatus==NULL){
        my_dStack=NULL;
        #ifdef STACK_DEBUG
        printf("Error NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }else{
        my_dStack=(Stack * )malloc(sizeof(Stack));
        if(my_dStack==NULL){
            *retStatus=Return_NULL_Error;
            #ifdef STACK_DEBUG
            printf("Malloc Function failed to allocate the Stack!\n");
            #endif // STACK_DEBUG
        }else{
            my_dStack->MaxSizeOfStack=maxSize;
            my_dStack->ActualSize=0;
            my_dStack->StackTop=-1;
            my_dStack->StackDArray=(void **)calloc(my_dStack->MaxSizeOfStack,sizeof(void*));
            if(my_dStack->StackDArray==NULL){
                #ifdef STACK_DEBUG
                printf("Calloc Function failed to allocate the Stack!\n");
                #endif // STACK_DEBUG
                free(my_dStack);
                my_dStack=NULL;
                *retStatus=STACK_NOK;
            }else{
                #ifdef STACK_DEBUG
                printf("Create Stack of size %d is done successfully!!\n",maxSize);
                #endif // STACK_DEBUG
                *retStatus=STACK_OK;
            }
        }
    }
    return my_dStack;
}

/**
  *@brief Destroy Stack object
  *@param pointer to Stack obj(stack_Obj)
  *@param pointer to retStatus(retStatus)
  *@retval NULL pointer if function is done successfully
  */
Stack* DestroyStack(Stack* stack_Obj,Stack_Status_e* retStatus){
    if(stack_Obj!=NULL&&retStatus!=NULL){
        free(stack_Obj->StackDArray);
        free(stack_Obj);
        *retStatus=STACK_OK;
        #ifdef STACK_DEBUG
        printf("Freeing is done Successfully!\n");
        #endif
    }else if(retStatus!=NULL){
        *retStatus=STACK_NULL_POINTER;
        #ifdef STACK_DEBUG
        printf("Null pointer of stack obj is passed!\n");
        #endif
    }else{
    }
    return NULL;
}
/**
  *@brief push element to stack
  *@param pointer to stack object (stack_obj)
  *@param pointer to the item will be added (itemPtr)
  *@retval return status of push element function
  */
Stack_Status_e PushStack(Stack* stack_obj,void* itemPtr){
    Stack_Status_e Local_StackStatus=STACK_NOK;
    if(stack_obj!=NULL && itemPtr!=NULL){
        uint16 checkFull=Stack_isFull(stack_obj);
        if(checkFull==STACK_FULL){
                Local_StackStatus=STACK_FULL;
            #ifdef STACK_DEBUG
            printf("Can't add new element to stack because stack is full!\n");
            #endif // STACK_DEBUG
        }else{
            stack_obj->StackDArray[++(stack_obj->StackTop)]=itemPtr;
            stack_obj->ActualSize++;
            Local_StackStatus=STACK_OK;
            #ifdef STACK_DEBUG
            printf("Addition done!\n");
            #endif // STACK_DEBUG
        }
    }else{

    }
    return Local_StackStatus;
}
void * PopStack(Stack* stack_obj,Stack_Status_e* retStatus){
    void* dataPtrOut=NULL;
    if(stack_obj==NULL || retStatus==NULL){
        dataPtrOut=NULL;
    }else{
        if(Stack_isEmpty(stack_obj)!=STACK_EMPTY){
            dataPtrOut=stack_obj->StackDArray[(stack_obj->StackTop)--];
            (stack_obj->ActualSize)--;
            *retStatus=STACK_OK;
        }else{
            *retStatus=STACK_EMPTY;
            dataPtrOut=NULL;
            #ifdef STACK_DEBUG
            printf("can't pop from stack because stack is empty!\n");
            #endif // STACK_DEBUG
        }
    }
    return dataPtrOut;
}
void * StackTop(Stack* stack_obj,Stack_Status_e* retStatus){
    void* dataPtrOut=NULL;
    if(stack_obj==NULL || retStatus==NULL){
        dataPtrOut=NULL;
    }else{
        int checkEmpty=Stack_isEmpty(stack_obj)==STACK_EMPTY;
        if(checkEmpty!=1){
            dataPtrOut=stack_obj->StackDArray[stack_obj->StackTop];
            *retStatus=STACK_OK;
        }else if(checkEmpty){
            *retStatus=STACK_EMPTY;
            dataPtrOut=NULL;
            #ifdef STACK_DEBUG
            printf("can't return top from stack because stack is empty!\n");
            #endif // STACK_DEBUG
        }
    }
    return dataPtrOut;
}
Stack_Status_e StackCount(Stack* stack_obj,uint32* stackCount){
    Stack_Status_e Local_stack_Status=STACK_NOK;
    if(stack_obj!=NULL&&stackCount!=NULL){
        *stackCount=stack_obj->ActualSize;
        Local_stack_Status=STACK_OK;
    }else{
        Local_stack_Status=STACK_NULL_POINTER;
    }
    return Local_stack_Status;
}
/**
  *@brief check Empty stack function
  *@param pointer to a stack object (stack_obj)
  *@retval return status of stack Empty check function
  */
static Stack_Status_e Stack_isEmpty(Stack* stack_obj){
    Stack_Status_e Local_stack_Status=STACK_NOK;
    if(stack_obj!=NULL){
        if(stack_obj->ActualSize==0){
            Local_stack_Status=STACK_EMPTY;
        }else{
            Local_stack_Status=STACK_NOT_EMPTY;
        }
        #ifdef STACK_DEBUG
        printf("Check Empty stack is done successfully!\n");
        #endif // STACK_DEBUG
    }else{
        Local_stack_Status=STACK_NULL_POINTER;
        #ifdef STACK_DEBUG
        printf("Error NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_stack_Status;
}
/**
  *@brief check Full stack function
  *@param pointer to a stack object (stack_obj)
  *@retval return status of stack Full check function
  */
static Stack_Status_e Stack_isFull(Stack* stack_obj){
    Stack_Status_e Local_stack_Status=STACK_NOK;
    if(stack_obj!=NULL){
        if(stack_obj->ActualSize==stack_obj->MaxSizeOfStack){
            Local_stack_Status=STACK_FULL;
        }else{
            Local_stack_Status=STACK_NOT_FULL;
        }
        #ifdef STACK_DEBUG
        printf("Check Full stack is done successfully!\n");
        #endif // STACK_DEBUG
    }else{
        Local_stack_Status=STACK_NULL_POINTER;
        #ifdef STACK_DEBUG
        printf("Error NULL pointer is passed!\n");
        #endif // STACK_DEBUG
    }
    return Local_stack_Status;
}
