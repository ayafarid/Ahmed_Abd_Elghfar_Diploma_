#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_
#include "Platform_Types.h"
#define DOUBLELINKEDLIST_DEBUG

typedef struct node{
    uint32 nodeData;
    struct node* prevLink;
    struct node* nextLink;
}Double_Linked_Node;

typedef enum{
    DOUBLELINKEDLIST_OK=0,
    DOUBLELINKEDLIST_NOK,
    DOUBLELINKEDLIST_FULL,
    DOUBLELINKEDLIST_NULL_POINTER,
    DOUBLELINKEDLIST_OUT_OF_RANGE,
    DOUBLELINKEDLIST_EMPTY
}Double_LinkedList_Status_e;

/**
  *@brief insert node at the begin of double linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e InsertDoubleLinkedList_AtBegin(Double_Linked_Node** head);
/**
  *@brief insert node at the end of double linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e InsertDoubleLinkedList_AtEnd(Double_Linked_Node** head);
/**
  *@brief insert node after a certain position of the double linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e InsertDoubleLinkedList_AfterCertainPosition(Double_Linked_Node** head);
/**
  *@brief insert node before a certain position of the double linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e InsertDoubleLinkedList_BeforeCertainPosition(Double_Linked_Node** head);
/**
  *@brief delete node at the begin of the double linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e DeleteNodeAtBegining(Double_Linked_Node** head);
/**
  *@brief delete node from the end of double linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e DeleteNodeAtEnd(Double_Linked_Node** head);
/**
  *@brief delete node at the certain element of the linked list
  *@param pointer to pointer the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e DeleteNodeAfterCertainPosition(Double_Linked_Node** head);
/**
  *@brief print all elements of the double linked list
  *@param pointer to the head of double linked list (head)
  *@retval the status of the double linked list
  */
Double_LinkedList_Status_e DisplayDoubleLinkedListData(Double_Linked_Node* head);
/**
  *@brief return size of double linked list
  *@param pointer to the head of double linked list (head)
  *@retval the size of double linked list
  */
uint32 GetSize(Double_Linked_Node* head);
#endif // _DOUBLELINKEDLIST_H_
