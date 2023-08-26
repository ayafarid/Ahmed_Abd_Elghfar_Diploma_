#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "Platform_Types.h"
Stack my_stack;
int main()
{
    Stack_Status_e ret;
    uint32 value=0,my_stack_size=0;
    ret=Stack_Init(&my_stack);
    if(ret==Return_OK){
        Stack_Push(&my_stack,1);
        Stack_Push(&my_stack,2);
        Stack_Push(&my_stack,3);
        Stack_Push(&my_stack,4);
        Stack_Push(&my_stack,5);
        Stack_Push(&my_stack,6);
        ret=Stack_Pop(&my_stack,&value);
        if(ret==Return_OK)
            printf("Value Poped: %d\n",value);
        ret=Stack_Pop(&my_stack,&value);
        if(ret==Return_OK)
            printf("Value Poped: %d\n",value);
        Stack_Diplay_Elements(&my_stack);
        ret=Stack_Size(&my_stack,&my_stack_size);
        if(ret==Return_OK)printf("My stack size: %d",my_stack_size);
    }else if(ret==Return_NULL_Error){
    }else{
    }
    return 0;
}
