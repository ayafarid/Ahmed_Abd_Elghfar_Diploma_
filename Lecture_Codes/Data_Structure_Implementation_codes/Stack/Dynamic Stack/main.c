#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#include "stack.h"
uint32 stack_1Size=5;
Stack* my_dstack;
uint32 var1=0x11;
float32 var2=2.24;
uint16 var3='A';
uint32 stack_count=0;
int main()
{
    Stack_Status_e local_statusofStack=STACK_NOK;
    my_dstack=creatStack(stack_1Size,&local_statusofStack);
    local_statusofStack=PushStack(my_dstack,&var1);
    local_statusofStack=PushStack(my_dstack,&var1);
    local_statusofStack=PushStack(my_dstack,&var1);
    local_statusofStack=PushStack(my_dstack,&var2);
    local_statusofStack=PushStack(my_dstack,&var3);
    local_statusofStack=PushStack(my_dstack,&var2);
    local_statusofStack=PushStack(my_dstack,&var3);
    local_statusofStack=StackCount(my_dstack,&stack_count);
    printf("Stack count: %d\n",stack_count);
    void *Stack1_return;
    Stack1_return=StackTop(my_dstack,&local_statusofStack);
    if(Stack1_return!=NULL)printf("Stack Top: %c\n",*((uint16 *)Stack1_return));

    Stack1_return=PopStack(my_dstack,&local_statusofStack);
    if(Stack1_return!=NULL)printf("Popped value: %c\n",*((uint16 *)Stack1_return));//1

    Stack1_return=StackTop(my_dstack,&local_statusofStack);
    if(Stack1_return!=NULL)printf("Stack Top: %0.2f\n",*((float32 *)Stack1_return));

    Stack1_return=PopStack(my_dstack,&local_statusofStack);//2
    if(Stack1_return!=NULL)printf("Popped value: %0.2f\n",*((float32 *)Stack1_return));

    Stack1_return=PopStack(my_dstack,&local_statusofStack);//3
    if(Stack1_return!=NULL)printf("Popped value: 0x%X\n",*((uint32 *)Stack1_return));

    Stack1_return=PopStack(my_dstack,&local_statusofStack);//4
    if(Stack1_return!=NULL)printf("Popped value: 0x%X\n",*((uint32 *)Stack1_return));

    Stack1_return=PopStack(my_dstack,&local_statusofStack);//5
    if(Stack1_return!=NULL)printf("Popped value: 0x%X\n",*((uint32 *)Stack1_return));
    local_statusofStack=StackCount(my_dstack,&stack_count);
    printf("Stack count: %d\n",stack_count);
    Stack1_return=PopStack(my_dstack,&local_statusofStack);
    if(Stack1_return!=NULL)printf("Popped value: 0x%X\n",*((uint32 *)Stack1_return));
    Stack1_return=PopStack(my_dstack,&local_statusofStack);
    if(Stack1_return!=NULL)printf("Popped value: 0x%X\n",*((uint32 *)Stack1_return));

    Stack1_return=StackTop(my_dstack,&local_statusofStack);
    if(Stack1_return!=NULL)printf("Stack Top: %0.2f\n",*((float32 *)Stack1_return));

    local_statusofStack=PushStack(my_dstack,&var1);
    local_statusofStack=PushStack(my_dstack,&var2);
    local_statusofStack=PushStack(my_dstack,&var3);
    local_statusofStack=StackCount(my_dstack,&stack_count);
    printf("Stack count: %d\n",stack_count);
    DestroyStack(my_dstack,&local_statusofStack);
    return 0;
}
