#include <stdio.h>
#include "Platfrom_Types.h"
#include "linkedList.h"

LinkedList_State Insert_Node_AtTheBegin(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    Node* myNode=NULL;
    myNode=(Node*)malloc(sizeof(Node*));
    uint32 var1=0;
    if(myNode==NULL){
        Local_State=LINKEDLIST_NOK;
        #ifdef LINKEDLIST_DEBUG
        printf("Failed to create node using malloc function!\n");
        #endif
    }else{
        printf("Enter the data you want add at the begin of linked list: ");
        scanf("%d",&var1);
        myNode->nodeData=var1;
        myNode->nodeLink=NULL;
        if(*ptrList==NULL){
            *ptrList=myNode;
        }else{
            myNode->nodeLink=*ptrList;
            *ptrList=myNode;
        }
        Local_State=LINKEDLIST_OK;
        #ifdef LINKEDLIST_DEBUG
        printf("Insert Node at the Begin is done successfully!\n");
        #endif // LINKEDLIST_DEBUG
    }
    return Local_State;
}
LinkedList_State Insert_Node_AtTheEnd(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    Node* myNode=NULL;
    Node* LastNode=NULL;
    uint32 nodeData=0;
    myNode=(Node*)malloc(sizeof(Node*));
    if(myNode==NULL){
        Local_State=LINKEDLIST_NOK;
        #ifdef LINKEDLIST_DEBUG
        printf("Failed to create node using malloc function!\n");
        #endif
    }else{
        printf("Enter the data you want add at the End of linked list: ");
        scanf("%d",&nodeData);
        myNode->nodeData=nodeData;
        myNode->nodeLink=NULL;
        if(*ptrList==NULL){
            *ptrList=myNode;

        }else{
            LastNode=*ptrList;
            while(LastNode->nodeLink!=NULL){
                LastNode=LastNode->nodeLink;
            }
            LastNode->nodeLink=myNode;
        }
        Local_State=LINKEDLIST_OK;
        #ifdef LINKEDLIST_DEBUG
        printf("Insert Node at the End is done successfully!\n");
        #endif // LINKEDLIST_DEBUG
    }
    return Local_State;
}
LinkedList_State Insert_Node_AtTheAfter(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    Node* myNode=NULL;
    Node* nodeListCounter=NULL;
    uint32 position=0;
    uint32 counter=0;
    uint32 nodeData=0;
    nodeListCounter=*ptrList;
    counter=GetNumberOfElementOfLL(ptrList);
    printf("Please Enter the position you want to add after it : ");
    scanf("%d",&position);
    if(position>counter){
        Local_State=LINKEDLIST_OUT_OF_RANGE;
        #ifdef LINKEDLIST_DEBUG
        printf("The position passed is larger than linked list number of elements!\n");
        #endif // LINKEDLIST_DEBUG
    }else{
        myNode=(Node*)malloc(sizeof(Node*));
        if(myNode==NULL){
            Local_State=LINKEDLIST_NOK;
            #ifdef LINKEDLIST_DEBUG
            printf("Failed to create node using malloc function!\n");
            #endif
        }else{
            printf("Enter the data you want add at the position %d : ",position+1);
            scanf("%d",&nodeData);
            nodeListCounter=*ptrList;
            counter=0;
            while(counter<position){
                nodeListCounter=nodeListCounter->nodeLink;
                counter++;
            }
            myNode->nodeData=nodeData;
            myNode->nodeLink=nodeListCounter->nodeLink;
            nodeListCounter->nodeLink=myNode;
            Local_State=LINKEDLIST_OK;
            #ifdef LINKEDLIST_DEBUG
            printf("Data Insert after position number %d successfully!\n",position);
            #endif // LINKEDLIST_DEBUG

        }
    }
    return Local_State;
}
uint32 Return_Node_AtPosition(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    uint32 returnedData=0;
    Node* nodeListCounter=NULL;
    uint32 position=0;
    uint32 counter=0;
    uint32 nodeData=0;
    nodeListCounter=*ptrList;
    counter=GetNumberOfElementOfLL(ptrList);
    printf("Please Enter the position you want to return after it : ");
    scanf("%d",&position);
    if(position>counter){
        Local_State=LINKEDLIST_OUT_OF_RANGE;
        #ifdef LINKEDLIST_DEBUG
        printf("The position passed is larger than linked list number of elements!\n");
        #endif // LINKEDLIST_DEBUG
    }else{
        nodeListCounter=*ptrList;
        counter=0;
        while(counter<position){
            nodeListCounter=nodeListCounter->nodeLink;
            counter++;
        }
        returnedData=nodeListCounter->nodeData;
        Local_State=LINKEDLIST_OK;
        #ifdef LINKEDLIST_DEBUG
        printf("The data returned successfully!\n",position);
        #endif // LINKEDLIST_DEBUG

    }
    return returnedData;
}
LinkedList_State Delete_Node_AtTheBegin(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    Node* temp=*ptrList;
    if(*ptrList==NULL){
        Local_State=LINKEDLIST_EMPTY;
        #ifdef LINKEDLIST_DEBUG
        printf("Linked list is empty and you can't delete element from it at begin!\n");
        #endif // LINKEDLIST_DEBUG
    }else{
        *ptrList=temp->nodeLink;
        free(temp);
        Local_State=LINKEDLIST_OK;
        #ifdef LINKEDLIST_DEBUG
        printf("Delete from begin is done!\n");
        #endif
    }
    return Local_State;
}
LinkedList_State Delete_Node_AttheEnd(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    Node* preLast=*ptrList;
    Node* lastNode=*ptrList;
    if(*ptrList==NULL){
        Local_State=LINKEDLIST_EMPTY;
        #ifdef LINKEDLIST_DEBUG
        printf("Linked list is empty and you can't delete element from it at begin!\n");
        #endif // LINKEDLIST_DEBUG
    }else if(lastNode->nodeLink==NULL){
        free(lastNode->nodeLink);
        lastNode=NULL;
    }else{
        while(lastNode->nodeLink!=NULL){
            preLast=lastNode;
            lastNode=lastNode->nodeLink;
        }
        free(lastNode);
        preLast->nodeLink=NULL;
        Local_State=LINKEDLIST_OK;
        #ifdef LINKEDLIST_DEBUG
        printf("Delete from end is done!\n");
        #endif
    }
    return Local_State;
}
LinkedList_State Delete_Node_After(Node** ptrList){
    LinkedList_State Local_State=LINKEDLIST_NOK;
    Node* temp=*ptrList;
    Node* lNodeCount=*ptrList;
    uint32 count=0;
    uint32 position=0;
    uint32 size=GetNumberOfElementOfLL(ptrList);
    printf("Please Enter the position you want to delete after it : ");
    scanf("%d",&position);
    if(position>size){
        Local_State=LINKEDLIST_OUT_OF_RANGE;
        #ifdef LINKEDLIST_DEBUG
        printf("The position passed is larger than linked list number of elements!\n");
        #endif // LINKEDLIST_DEBUG
    }else{
        if(temp==NULL){
            Local_State=LINKEDLIST_EMPTY;
            #ifdef LINKEDLIST_DEBUG
            printf("Linked list is empty and you can't delete element from it at begin!\n");
            #endif // LINKEDLIST_DEBUG
        }
        else{
            if(size<position){
                Local_State=LINKEDLIST_OUT_OF_RANGE;
                #ifdef LINKEDLIST_DEBUG
                printf("the position passed is larger than the size of linked list!\n");
                #endif // LINKEDLIST_DEBUG
            }
            else{
                while(count<position){
                    lNodeCount=lNodeCount->nodeLink;
                    count++;
                }
                temp=lNodeCount->nodeLink;
                lNodeCount->nodeLink=temp->nodeLink;
                free(temp);
                Local_State=LINKEDLIST_OK;
                #ifdef LINKEDLIST_DEBUG
                printf("the deletion done successfully!\n");
                #endif // LINKEDLIST_DEBUG

            }
    }
    }
    return Local_State;
}
void displayLinkedListElements(Node** ptrList){
    Node* myNode=*ptrList;
    while(myNode!=NULL){
        printf("%d -> ",myNode->nodeData);
        myNode=myNode->nodeLink;
    }
    if(myNode==NULL)
        printf("NULL \n");
}
uint32 GetNumberOfElementOfLL(Node** ptrList){
    uint32 size=0;
    Node* tempNode=*ptrList;
    while(tempNode!=NULL){
        size++;
        tempNode=tempNode->nodeLink;
    }
    return size;
}
