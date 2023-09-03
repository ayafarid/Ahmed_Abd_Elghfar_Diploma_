#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
uint32 myArray[]={1,2,3,4,5,6,7,8,9,10};
uint32 BinarySearchLooping(uint32 dataArray[],uint32 startIndex,uint32 endIndex,uint32 value);
uint32 BinarySearchRecursion(uint32 dataArray[],uint32 startIndex,uint32 endIndex,uint32 value);

int main()
{
    uint32 value=0;
    uint32 size=(*(&myArray+1)-myArray);
    printf("Enter the value you search for: ");
    scanf("%d",&value);
    uint32 ret=BinarySearchRecursion(myArray,0,size-1,value);
    if(ret==-1)
        printf("The value %d not fount!\n",value);
    else
        printf("The value %d is fount at index %d.\n",value,ret);
    return 0;
}
uint32 BinarySearchLooping(uint32 dataArray[],uint32 startIndex,uint32 endIndex,uint32 value){
    uint32 middleIndex=0;
    while(startIndex<=endIndex){
        middleIndex=startIndex+((endIndex-startIndex)/2);
        if(value==dataArray[middleIndex]){
            return middleIndex;
        }else if(value>dataArray[middleIndex]){
            startIndex=middleIndex+1;
        }else{
            endIndex=middleIndex-1;
        }
    }
    return -1;
}
uint32 BinarySearchRecursion(uint32 dataArray[],uint32 startIndex,uint32 endIndex,uint32 value){
    uint32 middleIndex=0;
    while(startIndex<=endIndex){
        middleIndex=startIndex+((endIndex-startIndex)/2);
        if(value==dataArray[middleIndex]){
            return middleIndex;
        }else if(value>dataArray[middleIndex]){
            return BinarySearchRecursion(dataArray, middleIndex+1,endIndex,value);
        }else{
            return BinarySearchRecursion(dataArray, startIndex,middleIndex-1,value);
        }
    }
    return -1;
}
