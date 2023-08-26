#include <stdio.h>
#include <stdlib.h>
/**
*PTR is a function take no element and return pointer
*to an array of 4 elements of type pointer to function
*take nothing and return int
**/
int returnedFunction1(void);
int returnedFunction2(void);
int returnedFunction3(void);
int returnedFunction4(void);

typedef int (*ptrReturnedFunction4)(void);
typedef ptrReturnedFunction4 (*Local)[4];
Local myFunction(void);
ptrReturnedFunction4 AptrToReturnedFunction[4]={
    returnedFunction1,
    returnedFunction2,
    returnedFunction3,
    returnedFunction4
};
int main(){
    int (*(*local)[4])(void)=myFunction();
    printf("%d\n",(*local)[0]());
    printf("%d\n",(*local)[1]());
    printf("%d\n",(*local)[2]());
    printf("%d\n",(*local)[3]());
    printf("--------------------------------\n");
    printf("%d\n",(*AptrToReturnedFunction[0])());
    printf("%d\n",(*AptrToReturnedFunction[1])());
    printf("%d\n",(*AptrToReturnedFunction[2])());
    printf("%d\n",(*AptrToReturnedFunction[3])());
    return 0;
}
int returnedFunction1(void){
    return 1;
}
int returnedFunction2(void){
    return 2;
}
int returnedFunction3(void){
    return 3;
}
int returnedFunction4(void){
    return 4;
}
Local myFunction(void){
    Local Local1=&AptrToReturnedFunction;
    return Local1;
}
