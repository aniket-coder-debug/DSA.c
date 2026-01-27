#include<stdio.h>
#include<malloc.h>

#define MAX 5

struct node
{
    int iData;
    struct node *pNext;
};

void EnQueue(struct node ** , int);
int DeQueue(struct node **);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iDelData;
    struct node *pQueue = NULL;

    EnQueue(&pQueue , 10);
    EnQueue(&pQueue , 20);
    EnQueue(&pQueue , 30);

    Display(pQueue);                                    // |10|->|20|->|30|->

    iDelData = DeQueue(&pQueue);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 10

    Display(pQueue);                                    // |20|->|30|->

    if(pQueue != NULL)
    {
        DeleteAll(&pQueue);
        pQueue = NULL;
    }

    Display(pQueue);                                    // List is emtpy

    return 0;
}

void EnQueue(struct node **ppHead , int iNo)
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

    pNewNode -> iData = iNo;
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

int DeQueue(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(IsQueueEmpty(*ppHead))
    {
        printf("\nQueue is Empty\n");
        return -1;
    }

    pTemp = *ppHead;
    *ppHead = pTemp -> pNext;

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
        printf("\nList is emtpy\n");
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

