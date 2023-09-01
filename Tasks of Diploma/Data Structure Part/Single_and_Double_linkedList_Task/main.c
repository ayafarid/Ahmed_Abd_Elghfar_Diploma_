#include <stdio.h>
#include <stdlib.h>

#include "Platform_Types.h"
#include "linkedList.h"
#include "doubleLinkedList.h"
Node* head=NULL;
Double_Linked_Node* headDouble=NULL;
/// Single

/// 1-Reverse the list
static void reverse(Node** head_ref);
/// 2-Swap 2 nodes in the list
static void swap2Nodes(Node** head,int positionNode1,int positionNode2);
/// 3-Sort the nodes in the list
/// ?

/// Double

/// 1-Reverse the list
void reverseDouble(Double_Linked_Node ** head);
/// 2-Swap 2 nodes in the list
void swapNodeValues(Double_Linked_Node* head_ref, int node1, int node2);
/// 3-Sort the nodes in the list
/// ?
int main()
{
    #if 0
    Insert_Node_AtTheBegin(&head);
    Insert_Node_AtTheEnd(&head);
    Insert_Node_AtTheAfter(&head);
    Insert_Node_AtTheBegin(&head);
    displayLinkedListElements(&head);
    reverse(&head);
    displayLinkedListElements(&head);
    swap2Nodes(&head,2,1);
    displayLinkedListElements(&head);
    #endif // 0
    #if 1
    InsertDoubleLinkedList_AtBegin(&headDouble);
    InsertDoubleLinkedList_AtEnd(&headDouble);
    InsertDoubleLinkedList_AtEnd(&headDouble);
    InsertDoubleLinkedList_AtEnd(&headDouble);
    InsertDoubleLinkedList_AtEnd(&headDouble);
    DisplayDoubleLinkedListData(headDouble);
    reverseDouble(&headDouble);
    DisplayDoubleLinkedListData(headDouble);
    swapNodeValues(headDouble,3,2);
    DisplayDoubleLinkedListData(headDouble);
    #endif // 1
    return 0;
}
static void reverse(Node** head_ref)
{
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->nodeLink;

        // Reverse current node's pointer
        current->nodeLink = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
static void swap2Nodes(Node** head,int positionNode1,int positionNode2){
    Node* temp=*head;
    Node* nodeOne=NULL;
    Node* nodeTwo=NULL;
    uint32 tempData;
    Node* tempLink;
    uint32 size=GetNumberOfElementOfLL(head);
    for(int i=0;i<size;i++){
        if(i==positionNode1){
            nodeOne=temp;
        }
        if(positionNode2==i){
            nodeTwo=temp;
        }
        temp=temp->nodeLink;
    }
    tempData=nodeOne->nodeData;
    tempLink=nodeOne->nodeLink;
    nodeOne->nodeData=nodeTwo->nodeData;
    //nodeOne->nodeLink=nodeTwo->nodeLink;
    nodeTwo->nodeData=tempData;
    //nodeTwo->nodeLink=tempLink;
}
void reverseDouble(Double_Linked_Node ** head)
{
    Double_Linked_Node* temp = NULL;
    Double_Linked_Node* current = *head;

    /* swap next and prev for all nodes of
      doubly linked list */
    while (current != NULL) {
        temp = current->prevLink;
        current->prevLink = current->nextLink;
        current->nextLink = temp;
        current = current->prevLink;
    }

    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if (temp != NULL)
        *head = temp->prevLink;
}
void swapNodeValues(Double_Linked_Node* head_ref, int node1, int node2)
{

    Double_Linked_Node* temp = head_ref;
    int N = 0;
    while (temp != NULL){
        N++;
        temp = temp->nextLink;
    }

    if(node1 < 1 || node1 > N || node2 < 1 || node2 > N)
        return;

    Double_Linked_Node* pos1 = head_ref;
    Double_Linked_Node* pos2 = head_ref;
    for(int i = 1; i < node1; i++){
        pos1 = pos1->nextLink;
    }
    for(int i = 1; i < node2; i++){
        pos2 = pos2->nextLink;
    }

    int val = pos1->nodeData;
    pos1->nodeData = pos2->nodeData;
    pos2->nodeData = val;
}
