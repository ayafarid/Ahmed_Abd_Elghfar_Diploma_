#include <stdio.h>
#include <stdlib.h>
#include "Platfrom_Types.h"
#include "linkedList.h"
Node* myLinkedListHead1=NULL;
uint32 operation=0;
uint8 endloop=0;
int main()
{
    while(!endloop){
        printf("=========================================\n");
        printf("-> 1- Insert node at beginning.\n");
        printf("-> 2- Insert node at end.\n");
        printf("-> 3- Insert node after certain position.\n");
        printf("-> 4- Delete node at beginning.\n");
        printf("-> 5- Delete Node at end.\n");
        printf("-> 6- Delete Node after certain position.\n");
        printf("-> 7- Display All Nodes.\n");
        printf("-> 8- Get Length.\n");
        printf("-> 9- Return Data at a certain position.\n");
        printf("-> 10- Quit from Application.\n");
        printf("=========================================\n");
        printf("Enter number of operation you want to perform (1:10) : ");
        scanf("%d",&operation);
        switch(operation){
        case 1:
            Insert_Node_AtTheBegin(&myLinkedListHead1);
            break;
        case 2:
            Insert_Node_AtTheEnd(&myLinkedListHead1);
            break;
        case 3:
            Insert_Node_AtTheAfter(&myLinkedListHead1);
            break;
        case 4:
            Delete_Node_AtTheBegin(&myLinkedListHead1);
            break;
        case 5:
            Delete_Node_AttheEnd(&myLinkedListHead1);
            break;
        case 6:
            Delete_Node_After(&myLinkedListHead1);
            break;
        case 7:
            displayLinkedListElements(&myLinkedListHead1);
            break;
        case 8:
            printf("Length of LinkedList= %d\n",GetNumberOfElementOfLL(&myLinkedListHead1));
            break;
        case 9:
            printf("The at this position = %d\n",Return_Node_AtPosition(&myLinkedListHead1));
            break;
        case 10:
            endloop=1;
            break;
        }
    }
    return 0;
}
