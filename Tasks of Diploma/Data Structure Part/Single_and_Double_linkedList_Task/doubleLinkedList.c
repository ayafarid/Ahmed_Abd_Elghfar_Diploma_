#include <stdio.h>
#include "Platform_Types.h"
#include "doubleLinkedList.h"
Double_LinkedList_Status_e InsertDoubleLinkedList_AtBegin(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_Status=DOUBLELINKEDLIST_NOK;
    Double_Linked_Node* temp=*head;
    Double_Linked_Node* myNode=NULL;
    uint32 dataNode=0;
    myNode=(Double_Linked_Node*)malloc(sizeof(Double_Linked_Node));
    if(myNode==NULL){
        Local_Status=DOUBLELINKEDLIST_NOK;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Error while creating new node using malloc function and returned NULL!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }else{
        printf("Enter data: ");
        scanf("%d",&dataNode);
        myNode->nodeData=dataNode;
        if(temp==NULL){
            myNode->nextLink=NULL;
            myNode->prevLink=NULL;
            *head=myNode;
        }else{
            myNode->nextLink=temp;
            myNode->prevLink=NULL;
            temp->prevLink=myNode;
            *head=myNode;
        }
        Local_Status=DOUBLELINKEDLIST_OK;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Insertion at the begin is done successfully!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }
    return Local_Status;
}
Double_LinkedList_Status_e InsertDoubleLinkedList_AtEnd(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_Status=DOUBLELINKEDLIST_NOK;
    Double_Linked_Node* temp=*head;
    Double_Linked_Node* lastNode=*head;
    uint32 dataNode=0;
    Double_Linked_Node* myNode=NULL;
    myNode=(Double_Linked_Node*)malloc(sizeof(Double_Linked_Node));
    if(myNode==NULL){
        Local_Status=DOUBLELINKEDLIST_NOK;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Error while creating new node using malloc function and returned NULL!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }else{
        printf("Enter data: ");
        scanf("%d",&dataNode);
        myNode->nodeData=dataNode;
        if(temp==NULL){
            myNode->nextLink=NULL;
            myNode->prevLink=NULL;
            *head=myNode;
        }else{
            while(lastNode->nextLink!=NULL){
                lastNode=lastNode->nextLink;
            }
            myNode->nextLink=NULL;
            myNode->prevLink=lastNode;
            lastNode->nextLink=myNode;
        }
        Local_Status=DOUBLELINKEDLIST_OK;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Insertion at the begin is done successfully!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }
    return Local_Status;
}
Double_LinkedList_Status_e InsertDoubleLinkedList_AfterCertainPosition(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_Status=DOUBLELINKEDLIST_NOK;
    Double_Linked_Node* mynode=*head;
    Double_Linked_Node* nodeCounterLast=*head;
    Double_Linked_Node* nodeCounterLastNext=*head;
    uint32 position=0;
    uint32 count=position;
    uint32 nodeData=0;
    uint32 size=GetSize(*head);
    printf("Enter Position you want add node after it : ");
    scanf("%d",&position);
    if(position<size){
        mynode=(Double_Linked_Node*)malloc(sizeof(Double_Linked_Node));
        if(mynode==NULL){
            Local_Status=DOUBLELINKEDLIST_NOK;
            #ifdef DOUBLELINKEDLIST_DEBUG
            printf("Can't allocate new node!\n");
            #endif // DOUBLELINKEDLIST_DEBUG
        }else{
            printf("Enter data: ");
            scanf("%d",&nodeData);
            mynode->nodeData=nodeData;
            while(position--){
                nodeCounterLast=nodeCounterLast->nextLink;
            }
            nodeCounterLastNext=nodeCounterLast->nextLink;
            if(nodeCounterLastNext==NULL){
                mynode->nextLink=NULL;
                mynode->prevLink=nodeCounterLast;
                nodeCounterLast->nextLink=mynode;
            }else{
                nodeCounterLast->nextLink=mynode;
                nodeCounterLastNext->prevLink=mynode;
                mynode->nextLink=nodeCounterLastNext;
                mynode->prevLink=nodeCounterLast;
            }
            Local_Status=DOUBLELINKEDLIST_OK;
            #ifdef DOUBLELINKEDLIST_DEBUG
            printf("Added new node after position %d is done Successfully!\n",count);
            #endif // DOUBLELINKEDLIST_DEBUG
        }
    }else{
        Local_Status=DOUBLELINKEDLIST_OUT_OF_RANGE;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Out of range Error!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }

    return Local_Status;
}
Double_LinkedList_Status_e InsertDoubleLinkedList_BeforeCertainPosition(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_Status=DOUBLELINKEDLIST_NOK;
    Double_Linked_Node* mynode=*head;
    Double_Linked_Node* nodeCounterLast=*head;
    Double_Linked_Node* nodeCounterLastPrev=*head;
    uint32 position=0;
    uint32 count=0;
    uint32 nodeData=0;
    uint32 size=GetSize(*head);
    printf("Enter Position you want add new node before it : ");
    scanf("%d",&position);
    if(position<size){
        mynode=(Double_Linked_Node*)malloc(sizeof(Double_Linked_Node));
        if(mynode==NULL){
            Local_Status=DOUBLELINKEDLIST_NOK;
            #ifdef DOUBLELINKEDLIST_DEBUG
            printf("Can't allocate new node!\n");
            #endif // DOUBLELINKEDLIST_DEBUG
        }else{
            printf("Enter data: ");
            scanf("%d",&nodeData);
            mynode->nodeData=nodeData;
            while(position--){
                nodeCounterLast=nodeCounterLast->nextLink;
            }
            nodeCounterLastPrev=nodeCounterLast->prevLink;
            if(nodeCounterLastPrev==NULL){
                mynode->nextLink=nodeCounterLast;
                mynode->prevLink=NULL;
                nodeCounterLast->prevLink=mynode;
                *head=mynode;
            }else{
                nodeCounterLast->prevLink=mynode;
                nodeCounterLastPrev->nextLink=mynode;
                mynode->nextLink=nodeCounterLast;
                mynode->prevLink=nodeCounterLastPrev;
            }
            Local_Status=DOUBLELINKEDLIST_OK;
            #ifdef DOUBLELINKEDLIST_DEBUG
            printf("Added new node before position %d is done Successfully!\n",count);
            #endif // DOUBLELINKEDLIST_DEBUG
        }
    }else{
        Local_Status=DOUBLELINKEDLIST_OUT_OF_RANGE;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Out of range Error!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }

    return Local_Status;
}
Double_LinkedList_Status_e DeleteNodeAtBegining(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_State=DOUBLELINKEDLIST_NOK;
    #if 0
    Double_Linked_Node* temp=*head;
    *head=(*head->nextLink);
    *head->prevLink=NULL;
    free(temp);
    Local_State=DOUBLELINKEDLIST_OK;
    #ifdef DOUBLELINKEDLIST_DEBUG
    printf("Delete from begin is done successfully!\n");
    #endif // DOUBLELINKEDLIST_DEBUG
    #endif // 0
    #if 1
    *head=(*head)->nextLink;
    free((*head)->prevLink);
    (*head)->prevLink=NULL;
    Local_State=DOUBLELINKEDLIST_OK;
    Local_State=DOUBLELINKEDLIST_OK;
    #ifdef DOUBLELINKEDLIST_DEBUG
    printf("Delete from begin is done successfully!\n");
    #endif // DOUBLELINKEDLIST_DEBUG
    #endif // 1
    return Local_State;
}
Double_LinkedList_Status_e DeleteNodeAtEnd(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_State=DOUBLELINKEDLIST_NOK;
    Double_Linked_Node* lastOne=*head;
    Double_Linked_Node* lastTwo=*head;
    while(lastOne->nextLink!=NULL){
        lastOne=lastOne->nextLink;
    }
    lastTwo=lastOne->prevLink;
    lastTwo->nextLink=NULL;
    free(lastOne);
    lastOne=NULL;
    Local_State=DOUBLELINKEDLIST_OK;
    #ifdef DOUBLELINKEDLIST_DEBUG
    printf("Deleting from end is done successfully!\n");
    #endif // DOUBLELINKEDLIST_DEBUG
    return Local_State;
}
Double_LinkedList_Status_e DeleteNodeAfterCertainPosition(Double_Linked_Node** head){
    Double_LinkedList_Status_e Local_State=DOUBLELINKEDLIST_NOK;
    uint32 position=0;
    uint32 size=GetSize(*head);
    Double_Linked_Node* temp1=*head;
    Double_Linked_Node* temp2=*head;
    printf("Enter position of the node you want to delete : ");
    scanf("%d",&position);
    if(position==0){
        printf("Please use DeleteNodeAtBegining!\n");
    }else{
    if(position<size){
        while(position--){
            temp1=temp1->nextLink;
        }
        temp2=temp1->prevLink;
        temp2->nextLink=temp1->nextLink;
        if(temp2->nextLink!=NULL)
            (temp2->nextLink)->prevLink=temp2;
        free(temp1);
        temp1=NULL;
        Local_State=DOUBLELINKEDLIST_OK;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Delete at certain position is done successfully!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }else{
        Local_State=DOUBLELINKEDLIST_OUT_OF_RANGE;
        #ifdef DOUBLELINKEDLIST_DEBUG
        printf("Out of range Error!\n");
        #endif // DOUBLELINKEDLIST_DEBUG
    }
    }
    return Local_State;
}
uint32 GetSize(Double_Linked_Node* head){
    uint32 size=0;
    while(head!=NULL){
        head=head->nextLink;
        size++;
    }
    return size;
}
Double_LinkedList_Status_e DisplayDoubleLinkedListData(Double_Linked_Node* head){
    printf("Display all list elements : ");
    while(head!=NULL){
        printf("%d -> ",head->nodeData);
        head=head->nextLink;
    }
    printf("NULL\n");
}
Double_LinkedList_Status_e DisplayDoubleLinkedListDataReverse(Double_Linked_Node* head){
    Double_Linked_Node* temp=head;
    while(temp->nextLink!=NULL){
        temp=temp->nextLink;
    }
    printf("Display all list elements in reverse order: ");
    while(temp!=NULL){
        printf("%d -> ",temp->nodeData);
        temp=temp->prevLink;
    }
    printf(" NULL\n");
}
