#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"
#include "doubleLinkedList.h"
Double_Linked_Node * myHead=NULL;
int main()
{
    InsertDoubleLinkedList_AtBegin(&myHead);
    InsertDoubleLinkedList_AtEnd(&myHead);
    printf("Size = %d\n",GetSize(myHead));
    InsertDoubleLinkedList_AfterCertainPosition(&myHead);
    InsertDoubleLinkedList_BeforeCertainPosition(&myHead);
    DisplayDoubleLinkedListData(myHead);
    DisplayDoubleLinkedListDataReverse(myHead);
    DeleteNodeAtBegining(&myHead);
    DisplayDoubleLinkedListData(myHead);
    DeleteNodeAtEnd(&myHead);
    DisplayDoubleLinkedListData(myHead);
    DeleteNodeAfterCertainPosition(&myHead);
    DisplayDoubleLinkedListData(myHead);

    return 0;
}
