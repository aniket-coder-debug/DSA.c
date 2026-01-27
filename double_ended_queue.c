#include<stdio.h>

#define MAX 5

int g_iRear = -1;
int g_iFront = 0;

void EnQueueAtRear(int *, int);
int DeQueueFromFront(int *);
void EnQueueAtFront(int * , int);
int DeQueueFromRear(int *);
int IsQueueFull(void);
int IsQueueEmpty(void);
void Display(const int *);

int main(void)
{
    int Queue[MAX] = {0};
    int iDelData;

    EnQueueAtRear(Queue , 10);
    EnQueueAtRear(Queue , 20);

    Display(Queue);                                     // 10 20 0 0 0  

    iDelData = DeQueueFromFront(Queue);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 10

    iDelData = DeQueueFromFront(Queue);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 20

    Display(Queue);                                     // Queue is Empty

    printf("\n\n");

    EnQueueAtFront(Queue , 60);         
    EnQueueAtFront(Queue , 70);

    Display(Queue);                                     // 10 20 0 70 60

    iDelData = DeQueueFromRear(Queue);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 60

    iDelData = DeQueueFromRear(Queue);
    if(iDelData != -1)
        printf("\nDeleted data is %d\n", iDelData);     // Deleted data is 70

    Display(Queue);                                     // Queue is Empty

    return 0;
}

void EnQueueAtRear(int *pQueue , int iNo)
{
    if(IsQueueFull())
    {
        printf("\nQueue is Full\n");
        return;
    }

    if(g_iRear == MAX - 1)          
        g_iRear = 0;
    else
        ++(g_iRear);

    pQueue[g_iRear] = iNo;
}

int DeQueueFromFront(int *pQueue )
{
    int iDelData ;

    if(IsQueueEmpty())
    {
        printf("\nQueue is Empty\n");
        return -1;
    }

    iDelData = pQueue[g_iFront];

    if(g_iRear == g_iFront)
    {
        g_iRear = -1;
        g_iFront = 0;
    }
    else
        ++(g_iFront);

    return iDelData;
}

void EnQueueAtFront(int *pQueue , int iNo)
{
    if(IsQueueFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if(g_iFront == 0)
    {
        g_iFront = MAX - 1;
        g_iRear = MAX - 1;
    }
    else
        --(g_iFront);

    pQueue[g_iFront] = iNo;

}

int DeQueueFromRear(int *pQueue)
{
    int iDelData;

    if(IsQueueEmpty())
    {
        printf("\nQueue is Empty\n");
        return -1;
    }

    iDelData = pQueue[g_iRear];

    if(g_iRear == g_iFront)
    {
        g_iRear = MAX - 1;
        g_iFront = MAX;
    }
    else
        --(g_iRear);

    return iDelData;
}

int IsQueueFull(void)
{
    if((g_iFront == 0 && g_iRear == MAX - 1) || (g_iRear == g_iFront - 1 && g_iRear != -1))
        return 1;
    return 0;
}

int IsQueueEmpty(void)
{
    if(g_iRear == -1)
        return 1;
    return 0;
}

void Display(const int *pQueue)
{
    int iCounter;

    if(g_iRear == -1)
    {
        printf("\nQueue is Empty\n");
        return ;
    }

    for(iCounter = 0; iCounter <= MAX - 1; iCounter++)
        printf("%d ", pQueue[iCounter]);

    printf("\n");
}
