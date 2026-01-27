#include<stdio.h>

#define MAX 5

void Push(int * , int * , int);
int Pop(int * , int *);
int IsFull(int);
int IsEmpty(int);
void Display(const int * , int );

int main(void)
{
    int iPoppedData;
    int Stack[MAX];
    int iTop = -1;

    Push(Stack , &iTop, 10);
    Push(Stack , &iTop, 20);
    Push(Stack , &iTop, 30);

    Display(Stack , iTop);                                  // 10 20 30

    iPoppedData = Pop(Stack , &iTop);
    if(iPoppedData != 0)
        printf("\nDeleted data is %d\n\n", iPoppedData);    // Deleted data is 30

    Display(Stack , iTop);                                  // 10 20

    return 0;
}

void Push(int *pStack , int *piTop , int iNo)
{
    if(IsFull(*piTop))
    {
        printf("\nStack Overflow\n");
        return;
    }

    pStack[++(*piTop)] = iNo;           // adhi pudh sarak mag data bhar
}

int Pop(int *pStack , int *piTop)
{
    if(IsEmpty(*piTop))
    {
        printf("\nStack is empty\n");
        return 0;
    }

    return pStack[(*piTop)--];          // adhi value return kr ani mg mag ja
}

int IsFull(int iTop)
{
    if(iTop == MAX - 1)
        return 1;
    return 0;
}

int IsEmpty(int iTop)
{
    if(iTop == -1)
        return 1;
    return 0;
}

void Display(const int *pStack , int iTop)
{
    int iCounter;

    for(iCounter = 0; iCounter <= iTop ; iCounter++)
        printf("%d\n",pStack[iCounter]);
}
