#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#define LINKEDLIST_DEBUG
#undef LINKEDLIST_DEBUG
typedef struct node_t{
    uint32 nodeData;
    struct node_t* nodeLink;
}Node;

typedef enum{
    LINKEDLIST_OK=0,
    LINKEDLIST_NOK,
    LINKEDLIST_NULL_POINTER,
    LINKEDLIST_EMPTY,
    LINKEDLIST_FULL,
    LINKEDLIST_OUT_OF_RANGE
}LinkedList_State;
/**
  *@brief Insert at begin
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
LinkedList_State Insert_Node_AtTheBegin(Node** ptrList);
/**
  *@brief Insert at end
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
LinkedList_State Insert_Node_AtTheEnd(Node** ptrList);
/**
  *@brief Insert after certain position
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
LinkedList_State Insert_Node_AtTheAfter(Node** ptrList);
/**
  *@brief delete at begin
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
LinkedList_State Delete_Node_AtTheBegin(Node** ptrList);
/**
  *@brief delete at end
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
LinkedList_State Delete_Node_AttheEnd(Node** ptrList);
/**
  *@brief delete after certain position
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
LinkedList_State Delete_Node_After(Node** ptrList);
/**
  *@brief display all elements of linked list
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
void displayLinkedListElements(Node** ptrList);
/**
  *@brief return number of elements in LINKEDLIST
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
uint32 GetNumberOfElementOfLL(Node** ptrList);
/**
  *@brief return the data of a certain node at a certain position
  *@param pointer to a pointer to node (ptrList)
  *@retval state of LINKEDLIST
  */
uint32 Return_Node_AtPosition(Node** ptrList);
#endif // _LINKEDLIST_H_
