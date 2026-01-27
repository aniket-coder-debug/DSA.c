#include<stdio.h>
#include<malloc.h>

#define MAX 6

struct node
{
    int iData;
    int iPriority;
    struct node *pNext;
};

void EnQueue(struct node ** , int , int);
int DeQueue(struct node **);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node ** , int , int);

int main(void)
{
    struct node *pPQueue = NULL;

    EnQueue(&pPQueue , 10 , 3);
    EnQueue(&pPQueue , 20 , 5);
    EnQueue(&pPQueue , 30 , 1);
    EnQueue(&pPQueue , 40 , 2);
    EnQueue(&pPQueue , 50 , 4);

    Display(pPQueue);                                           // |20|->|50|->|10|->|40|->|30|->

    printf("\n\nDeleted data is %d\n\n", DeQueue(&pPQueue));    // Deleted data is 20

    Display(pPQueue);                                           // |50|->|10|->|40|->|30|->

    if(pPQueue != NULL)
    {
        DeleteAll(&pPQueue);
        pPQueue = NULL;
    }

    Display(pPQueue);                                           // List is emtpy

    return 0;
}

void EnQueue(struct node **ppHead , int iNo , int iPri)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    if(IsQueueFull(*ppHead))
    {
        printf("\nQueue is Full\n");
        return;
    }

    if(NULL == *ppHead || iPri > (*ppHead) -> iPriority)
    {
        InsertFirst(ppHead , iNo , iPri);
        return ;
    }

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return ;
    }

    pNewNode -> iData = iNo;
    pNewNode -> iPriority = iPri;

    pTemp = *ppHead;
    while(pTemp -> pNext != NULL)
    {
        if(iPri > pTemp -> pNext -> iPriority)
        {
            pNewNode -> pNext = pTemp -> pNext;
            pTemp -> pNext = pNewNode;
            return;
        }

        pTemp = pTemp -> pNext;
    }

    pNewNode -> pNext = NULL;
    pTemp -> pNext = pNewNode;
}

void InsertFirst(struct node **ppHead , int iNo , int iPri)
{
    struct node *pNewNode = NULL;           

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> iPriority = iPri;

    if(NULL == *ppHead)                     // list jr empty asel tr 
        pNewNode -> pNext = NULL;           // navin jo node insert hoylay tyachya next madhe NULL takato
    else                                    // nahitr
        pNewNode -> pNext = *ppHead;        // new node chya next madhe adhichya node cha address takto

    *ppHead = pNewNode;
}

int DeQueue(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is Empty\n");
        return -1;
    }

    pTemp = *ppHead;                        // pointing to first node
    *ppHead = pTemp -> pNext;               // second node cha address *ppHead madhe jato

    iDelData = pTemp -> iData;
    pTemp -> pNext = NULL;
    free(pTemp);

    return iDelData;
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

void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\n\nList is emtpy\n");
        return;
    }

    while(pHead != NULL)
    {
        printf("|%d|->",pHead -> iData);
        pHead = pHead -> pNext;
    }
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

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while(NULL != *ppHead)
    {
        pTemp = *ppHead;
        *ppHead = pTemp -> pNext;
        free(pTemp);
    }
}
