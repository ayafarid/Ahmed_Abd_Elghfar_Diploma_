#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
uint32 myArray[]={1,2,3,4,5,6,7,8,9,10};
uint32 linearSearchOneSide(uint32 dataArray[],uint32 size,uint32 value);
uint32 linearSearchDoubleSide(uint32 dataArray[],uint32 size,uint32 value);
int main()
{
    uint32 value=0;
    printf("Array size= %d\n",*(&myArray+1)-myArray);
    printf("Enter the value you search for: ");
    scanf("%d",&value);
    uint32 ret=linearSearchDoubleSide(myArray,*(&myArray+1)-myArray,value);
    if(ret==-1)
        printf("The value %d not fount!\n",value);
    else
        printf("The value %d is fount at index %d.\n",value,ret);
    return 0;
}
uint32 linearSearchOneSide(uint32 dataArray[],uint32 size,uint32 value){
    uint32 indexIter=0;
    for(indexIter=0;indexIter<size;indexIter++){
        if(dataArray[indexIter]==value)
            return indexIter;
    }
    return -1;
}
uint32 linearSearchDoubleSide(uint32 dataArray[],uint32 size,uint32 value){
    uint32 indexIterLeft=0,indexIterRight=size-1;
    for(indexIterLeft=0,indexIterRight=size-1;indexIterLeft<size && indexIterRight>=0;indexIterLeft++,indexIterRight--){
        if(dataArray[indexIterLeft]==value)
            return indexIterLeft;
        else if(dataArray[indexIterRight]==value)
            return indexIterRight;
    }
    return -1;
}
