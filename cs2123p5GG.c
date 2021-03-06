#include "cs2123p5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************** findId ****************************************
 NodeT *findId(NodeT *p, char szId[])
 Purpose: Finds and returns a pointer to the requested location based on element type

 Parameters:
 I/O     NodeT *p                Pointer to node for requested Id.
 I       char szId[]             Element to be compared

 Returns:
 p       Returns a pointer to the node of the requested item

 Notes:
 -Will traverse entire tree if necessary.
 **************************************************************************/
NodeT *findId(NodeT *p, char szId[])
{
    //temp NodeT to not over write pointer
    NodeT *pFound = NULL;

    //base case
    if (p == NULL)
        return NULL;

    //if element is found, return node
    if(strcmp(p->element.szId,szId)== 0)
        return p;

    //recurse through the tree to find the element
    //search for element in the children
    pFound = findId(p->pChild, szId);
    
    if (pFound != NULL)
        return pFound;

    //search through the siblings
    pFound = findId(p->pSibling, szId);
    return pFound;
}

/******************** allocateNodeT ****************************************
 NodeT *allocateNodeT(QuoteSelection quote, Element element)
 Purpose: Allocates memory for a new node in the QuoteSelection tree. Exits
 the program with an error if no memory is available.

 Parameters:
    I/O     Quoteselection quote    Tree to be modified
    I       Element element         Item to be inserted into the tree

 Returns:
    pNew        Returns a pointer to the new node with pSibling and pChild
                pointing to NULL
    ErrExit     No memory available for allocation

 Notes:

 **************************************************************************/
NodeT *allocateNodeT(Element element)
{
    NodeT *pNew;
    pNew = (NodeT *)malloc(sizeof(NodeT));
    if (pNew == NULL)
        ErrExit(ERR_ALGORITHM, "No available memory for binary tree.");
    pNew->element = element;
    pNew->pChild = NULL;
    pNew->pSibling = NULL;
    return pNew;
}

/******************** insertT ****************************************
 NodeT *insertT(NodeT **pp, Element element)
 Purpose: Inserts into the quote tree at the requested location using double
          pointer notation. If location is NULL, allocates memory.

 Parameters:
 I/O     NodeT **pp              Pointer to a pointer of the location to be inserted
 I       Element element         Item to be inserted into the tree

 Returns:
 pp        Returns a pointer to the node's new position

 Notes:
 **************************************************************************/
NodeT *insertT(NodeT **pp, Element element)
{ // if the ID's match, return the node

    if (*pp == NULL){
       *pp = allocateNodeT(element);
        return *pp;
    }else {
          return insertT(&(*pp)->pSibling,element);
          
    }

}
