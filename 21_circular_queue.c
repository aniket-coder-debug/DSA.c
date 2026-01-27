#include<stdio.h>

#define MAX 5

void EnQueue(int * , int* , int * , int);
int DeQueue(int * , int * , int *);
int IsQueueFull(int , int);
int IsQueueEmpty(int);
void Display(const int * , int , int);

int main(void)
{
    int Queue[MAX];
    int iDelData;
    int iRear = -1;
    int iFront = 0;

    EnQueue(Queue , &iRear , &iFront , 10);
    EnQueue(Queue , &iRear , &iFront , 20);
    EnQueue(Queue , &iRear , &iFront , 30);
    EnQueue(Queue , &iRear , &iFront , 40);

    Display(Queue , iRear , iFront);                    // 10 20 30 40

    iDelData = DeQueue(Queue , &iRear , &iFront);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 10

    EnQueue(Queue , &iRear , &iFront , 50);

    Display(Queue , iRear , iFront);                    // 20 30 40 50

    return 0;
}

void EnQueue(int *pQueue , int *piRear , int *piFront , int iNo)
{
    if(IsQueueFull(*piRear , *piFront))
    {
        printf("\nQueue is Full\n");
        return;
    }

    if(*piRear == MAX - 1)          // no need to check (iFront) != 0
        *piRear = 0;
    else
        ++(*piRear);

    pQueue[*piRear] = iNo;
}

int DeQueue(int *pQueue , int *piRear , int *piFront)
{
    int iDelData ;

    if(IsQueueEmpty(*piRear))
    {
        printf("\nQueue is Empty\n");
        return -1;
    }

    iDelData = pQueue[*piFront];

    if(*piRear == *piFront)
    {
        *piRear = -1;
        *piFront = 0;
    }
    else
        ++(*piFront);

    return iDelData;
}

int IsQueueFull(int iRear , int iFront)
{
    if((iFront == 0 && iRear == MAX - 1) || (iRear == iFront - 1 && iRear != -1))
        return 1;
    return 0;
}

int IsQueueEmpty(int iRear)
{
    if(iRear == -1)
        return 1;
    return 0;
}

void Display(const int *pQueue , int iRear , int iFront)
{
    int iCounter = iFront;

    if(iRear == -1)
    {
        printf("\nQueue is Empty\n");
        return ;
    }

    if(iRear < iFront)              // circular
    {
        for( ; iCounter <= MAX - 1 ; iCounter++)
            printf("%d\n",pQueue[iCounter]);

        iCounter = 0;
    }

    for( ; iCounter <= iRear ; iCounter++)
        printf("%d\n", pQueue[iCounter]);
}
