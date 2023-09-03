#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

#define MAX_SIZE 10

uint32 myArrayData[MAX_SIZE]={10,22,4,0,99,123,23,14,88,90};

void printDataArray(uint32 array[],uint32 size);
void selectionSort(uint32 array[],uint32 size);
void swap2Numbers(uint32*,uint32*);
int main()
{
    printf("Selection sort Test.\n");
    printf("Array before sort: ");
    printDataArray(myArrayData,MAX_SIZE);
    selectionSort(myArrayData,MAX_SIZE);
    printf("Array after sort: ");
    printDataArray(myArrayData,MAX_SIZE);
    return 0;
}
void printDataArray(uint32 array[],uint32 size){
    uint32 indextIterator=0;
    for(indextIterator=0;indextIterator<size;indextIterator++){
        printf("%d ",array[indextIterator]);
    }
    printf("\n");
}
/// 10,22,4,0,99,123,23,14,88,90
void selectionSort(uint32 array[],uint32 size){
    uint32 outerIterator=0;
    uint32 inerIterator=0;
    uint32 minmumValueIndex=0;
    for(outerIterator=0;outerIterator<size-1;outerIterator++){
        minmumValueIndex=outerIterator;
        for(inerIterator=outerIterator+1;inerIterator<size;inerIterator++){
            if(array[inerIterator]<array[minmumValueIndex]){
                minmumValueIndex=inerIterator;
            }
        }
        swap2Numbers(&array[minmumValueIndex],&array[outerIterator]);
    }
}
void swap2Numbers(uint32* num1,uint32* num2){
    uint32 temp=*num1;
    *num1=*num2;
    *num2=temp;
}
