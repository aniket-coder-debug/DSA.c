#include<stdio.h>
#include<malloc.h>
#include "tree_server.h"

void EnQueue(struct node **ppHead , struct BST *pRoot)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    if(IsQueueFull(*ppHead))
    {
        printf("\nQueue is Full\n");
        return ;
    }

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = pRoot ;
    pNewNode -> pNext = NULL;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;
    while(pTemp -> pNext != NULL)
        pTemp = pTemp -> pNext;

    pTemp -> pNext = pNewNode;
}

struct BST* DeQueue(struct node **ppHead)
{
    struct BST *DelData = NULL ;
    struct node *pTemp = NULL;

    if(IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is Empty\n");
        return NULL;
    }

    pTemp = *ppHead;
    *ppHead = pTemp -> pNext;

    DelData = pTemp -> iData;
    pTemp -> pNext = NULL;
    free(pTemp);

    return DelData ;
}

int IsQueueFull(struct node *pHead)
{
    if(CountNodes(pHead) == MAX)
        return 1;
    return 0;
}

int IsQueueEmpty(struct node *pHead)
{
    if(NULL == pHead)
        return 1;
    return 0;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
}
