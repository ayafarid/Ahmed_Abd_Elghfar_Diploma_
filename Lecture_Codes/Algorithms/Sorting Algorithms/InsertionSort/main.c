#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#define MAX_SIZE 10
uint32 myArrayData[MAX_SIZE]={10,22,4,0,99,123,23,14,88,90};
void printDataArray(uint32 array[],uint32 size);
void insertionSort(uint32 array[],uint32 size);
int main()
{
    printf("Insertion sort Test.\n");
    printf("Array before sort: ");
    printDataArray(myArrayData,MAX_SIZE);
    insertionSort(myArrayData,MAX_SIZE);
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
void insertionSort(uint32 array[],uint32 size){
    uint32 sortedIndex=0;
    uint32 unsortedInex=0;
    sint32 comparedValueIndex=0;
    uint32 key=0;
    for(unsortedInex=1;unsortedInex<size;unsortedInex++){
        comparedValueIndex=unsortedInex-1;
        key=array[unsortedInex];
        while((comparedValueIndex>=0) && (array[comparedValueIndex]>key)){
            array[comparedValueIndex+1]=array[comparedValueIndex];
            comparedValueIndex--;
        }
        array[comparedValueIndex+1]=key;
    }
}
