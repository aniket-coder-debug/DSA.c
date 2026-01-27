#include<stdio.h>

#define MAX 5

void EnQueue(int * , int * , int);
int DeQueue(int * , int * , int *);
int IsQueueFull(int);
int IsQueueEmpty(int);
void Display(const int * , int , int);

int main(void)
{
    int pQueue[MAX];
    int iDelData;
    int iRear = -1;
    int iFront = 0;

    EnQueue(pQueue , &iRear , 10);
    EnQueue(pQueue , &iRear , 20);
    EnQueue(pQueue , &iRear , 30);

    Display(pQueue , iRear , iFront);                   // 10 20 30

    iDelData = DeQueue(pQueue , &iRear , &iFront);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 10

    EnQueue(pQueue , &iRear , 40);

    iDelData = DeQueue(pQueue , &iRear , &iFront);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 20

    Display(pQueue , iRear , iFront);                   // 30 40

    return 0;
}

void EnQueue(int *pQueue , int *piRear , int iNo)
{
    if(IsQueueFull(*piRear))
    {
        printf("\nQueue is Full\n");
        return;
    }

    pQueue[++(*piRear)] = iNo;          // adhi pudh ja mg data tak
}

int DeQueue(int *pQueue , int *piRear , int *piFront)
{
    int iDelData;

    if(IsQueueEmpty(*piRear))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    iDelData = pQueue[*piFront];            // adhi value kadh

    if(*piRear == *piFront)                 // dogh jr ek jagevr astil tr reset karayche
    {
        *piRear = -1;
        *piFront = 0;
    }
    else
        (*piFront)++ ;                      // mg pudh ja

    return iDelData;
}

int IsQueueFull(int iRear)
{
    if(iRear == MAX - 1)
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
    int iCounter;

    if(iRear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    for(iCounter = iFront ; iCounter <= iRear ; iCounter++)
        printf("%d\n",pQueue[iCounter]);
}
