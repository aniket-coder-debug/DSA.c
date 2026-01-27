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
int IsFull(struct node *);
int IsEmpty(struct node *);
void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iPoppedData;
    struct node *pStack = NULL;

    EnQueue(&pStack , 10);
    EnQueue(&pStack , 20);
    EnQueue(&pStack , 30);

    Display(pStack);                                            // |30|->|20|->|10|->

    iPoppedData = DeQueue(&pStack);
    if(iPoppedData != -1)
        printf("\n\nDeleted data is %d\n\n", iPoppedData);      // Deleted data is 30

    Display(pStack);                                            // |20|->|10|->

    if(pStack != NULL)
    {
        DeleteAll(&pStack);
        pStack = NULL;
    }

    Display(pStack);                                            // List is emtpy

    return 0;
}

void EnQueue(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;

    if(IsFull(*ppHead))
    {
        printf("\nStack Overflow\n");
        return;
    }

    pNewNode = (struct node*) malloc (sizeof(struct node));
    if(pNewNode == NULL)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;

    if(NULL == *ppHead)
        pNewNode -> pNext = NULL;
    else
        pNewNode -> pNext = *ppHead;

    *ppHead = pNewNode;
}

int DeQueue(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(IsEmpty(*ppHead))
    {
        printf("\nStack is empty\n");
        return -1;
    }

    pTemp = *ppHead;
    *ppHead = pTemp -> pNext;

    iDelData = pTemp -> iData;
    pTemp -> pNext = NULL;
    free(pTemp);

    return iDelData;
}

int IsFull(struct node *pHead)
{
    if(CountNodes(pHead) == MAX)
        return 1;
    return 0;
}

int IsEmpty(struct node *pHead)
{
    if(NULL == pHead)
        return 1;
    return 0;
}

void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\n\nStack is emtpy\n");
        return;
    }

    printf("List is:\n");
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

