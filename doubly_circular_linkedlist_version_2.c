#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **ppHead , struct node **ppTail , int iNo);
void InsertLast(struct node **ppHead , struct node **ppTail , int iNo);
void InsertAtPosition(struct node **ppHead , struct node **ppTail , int iNo , int iPos);
int DeleteFirst(struct node **ppHead , struct node **ppTail);
int DeleteLast(struct node **ppHead , struct node **ppTail);
int DeleteAtPosition(struct node **ppHead , struct node **ppTail , int iPos);
int CountNodes(struct node *pHead , struct node *pTail);
int SearchFirstOccurrence(struct node *pHead , struct node *pTail , int iKey);
int SearchLastOccurrence(struct node *pHead , struct node *pTail , int iKey);
int SearchAllOccurrences(struct node *pHead , struct node *pTail , int iKey);
void Display(struct node *pHead , struct node *pTail);
void ConcatLists(struct node **ppHead1 , struct node **ppTail1 , struct node **ppHead2 , struct node **ppTail2);
void ConcatAtPosition(struct node **ppHead1 , struct node **ppTail1 , struct node **ppHead2 , struct node **ppTail2 , int iPos);
void PhysicalReverse(struct node **ppHead , struct node **ppTail);
void ReverseDisplay(struct node *pHead , struct node *pTail);
void DeleteAll(struct node **ppHead , struct node **ppTail);

int main(void)
{
    int iNumber;
    int iCount;
    int iTemp;

    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    while(1)
    {
        printf("\n\n1.InsertFirst\n2.InsertLast\n3.InsertAtPosition\n4.DeleteFirst\n5.DeleteLast\n6.DeleteAtPosition\n7.CountNodes\n8.SearchFirstOccurrence\n9.SearchLastOccurrence\n10.SearchAllOccurrences\n11.PhysicalReverse\n12.ReverseDisplay\n13.ConcatLists\n14.ConcatAtPosition\n15.Exit\n");
        printf("\nEnter your choice:\t");
        scanf("%d",&iNumber);

        if(iNumber <= 0 || iNumber > 15)
        {
            printf("\nInvalid choice\n");
            continue;
        }

        if(iNumber == 15)
            break;

        switch(iNumber)
        {
            case 1:
                printf("\nEnter Data:\t");
                scanf("%d",&iNumber);
                InsertFirst(&pFirst1 , &pLast1 , iNumber);
                Display(pFirst1,pLast1);
                continue;;

            case 2:
                printf("\nEnter Data:\t");
                scanf("%d",&iNumber);
                InsertLast(&pFirst1 , &pLast1 , iNumber);
                Display(pFirst1,pLast1);
                break;

            case 3:
                printf("\nEnter your Position\t");
                scanf("%d",&iNumber);

                iCount = CountNodes(pFirst1,pLast1);
                
                if(iNumber <= 0 || iNumber > iCount + 1)
                {
                    printf("\nPosition is Invalid\n");
                    Display(pFirst1,pLast1);
                    break;
                }

                printf("\nEnter Data:\t");
                scanf("%d",&iCount);
                InsertAtPosition(&pFirst1,&pLast1,iCount,iNumber);
                Display(pFirst1,pLast1);
                break;

            case 4:
                iNumber = DeleteFirst(&pFirst1,&pLast1);
                if(iNumber != -1)
                    printf("\nDeleted Data is %d\n",iNumber);
                Display(pFirst1,pLast1);
                break;

            case 5:
                iNumber = DeleteLast(&pFirst1,&pLast1);
                if(iNumber != -1)
                    printf("\nDeleted Data is %d\n",iNumber);
                Display(pFirst1,pLast1);
                break;

            case 6:
                if(NULL == pFirst1)
                {
                    printf("List is empty\n");
                    break;
                }

                printf("\nEnter your Position:\t");
                scanf("%d",&iNumber);

                iCount = CountNodes(pFirst1,pLast1);
                if(iNumber <= 0 || iNumber > iCount + 1)
                {
                    printf("\nPosition is Invalid\n");
                    break;
                }

                iCount = DeleteAtPosition(&pFirst1,&pLast1,iNumber);
                if(iCount != -1)
                    printf("\nDeleted Data is %d\n",iCount);
                Display(pFirst1,pLast1);
                break;

            case 7:
                iCount = CountNodes(pFirst1,pLast1);
                printf("\nTotal node count is %d\n ",iCount);
                break;

            case 8:
                if(NULL == pFirst1)
                {
                    printf("List is empty\n");
                    break;
                }
                
                printf("\nEnter Data:\t");
                scanf("%d",&iNumber);

                iCount = SearchFirstOccurrence(pFirst1,pLast1,iNumber);
                if(iCount != 0)
                    printf("\nFirst Occurrence of %d is at %d position\n",iNumber,iCount);
                else
                    printf("\nData not found\n");
                Display(pFirst1,pLast1);
                break;

            case 9:
                if(NULL == pFirst1)
                {
                    printf("List is empty\n");
                    break;
                }

                printf("\nEnter Data:\t");
                scanf("%d",&iNumber);

                iCount = SearchLastOccurrence(pFirst1,pLast1,iNumber);
                if(iCount != 0)
                    printf("\nLast Occurrence of %d is at %d position\n",iNumber,iCount);
                else
                    printf("\nData not found\n");
                Display(pFirst1,pLast1);
                break;

            case 10:
                if(NULL == pFirst1)
                {
                    printf("List is empty\n");
                    break;
                }

                printf("\nEnter Data:\t");
                scanf("%d",&iNumber);

                iCount = SearchAllOccurrences(pFirst1,pLast1,iNumber);
                if(iCount != -1)
                    printf("\n%d Found %d times\n",iNumber,iCount);
                Display(pFirst1,pLast1);
                break;

            case 11:
                PhysicalReverse(&pFirst1,&pLast1);
                Display(pFirst1,pLast1);
                break;

            case 12:
                ReverseDisplay(pFirst1,pLast1);
                break;

            case 13:
                while(1)
                {
                    printf("\n\n1.InsertFirst\n2.InsertLast\n3.InsertAtPosition\n4.Back\n");
                    printf("\nEnter your choice:\t");
                    scanf("%d",&iNumber);

                    if(iNumber == 4)
                    {
                        ConcatLists(&pFirst1,&pLast1,&pFirst2,&pLast2);
                        Display(pFirst1,pLast1);
                        Display(pFirst2,pLast2);
                        break;
                    }

                    switch(iNumber)
                    {
                        case 1:
                            printf("\nEnter Data:\t");
                            scanf("%d",&iCount);

                            InsertFirst(&pFirst2,&pLast2,iCount);
                            Display(pFirst2,pLast2);
                            break;

                        case 2:
                            printf("\nEnter Data:\t");
                            scanf("%d",&iCount);

                            InsertLast(&pFirst2,&pLast2,iCount);
                            Display(pFirst2,pLast2);
                            break;

                        case 3:
                            printf("\nEnter your position:\t");
                            scanf("%d",&iNumber);

                            iCount = CountNodes(pFirst2,pLast2);
                            if(iNumber <= 0 || iNumber > iCount + 1)
                            {
                                printf("Position is Invalid\n");
                                break;
                            }

                            printf("\nEnter Data:\t");
                            scanf("%d",&iCount);

                            InsertAtPosition(&pFirst2,&pLast2,iCount,iNumber);
                            Display(pFirst2,pLast2);
                            break;

                        default:
                            printf("\nInvalid Choice\n");
                            continue;
                    }
                }
                break;

            case 14:
                printf("\n\nEnter your position:\t");
                scanf("%d",&iTemp);

                iNumber = CountNodes(pFirst1,pLast1);
                if(iTemp <= 0 || iTemp > iNumber + 1)
                {
                    printf("\nInvalid Position\n");
                    break;
                }

                while(1)
                {
                    printf("\n\n1.InsertFirst\n2.InsertLast\n3.InsertAtPosition\n4.Back\n");
                    printf("\nEnter your choice:\t");
                    scanf("%d",&iNumber);

                    if(iNumber == 4)
                    {
                        ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2,iTemp);
                        Display(pFirst1,pLast1);
                        Display(pFirst2,pLast2);
                        break;
                    }

                    switch(iNumber)
                    {
                        case 1:
                            printf("\nEnter Data:\t");
                            scanf("%d",&iCount);

                            InsertFirst(&pFirst2,&pLast2,iCount);
                            Display(pFirst2,pLast2);
                            break;

                        case 2:
                            printf("\nEnter Data:\t");
                            scanf("%d",&iCount);

                            InsertLast(&pFirst2,&pLast2,iCount);
                            Display(pFirst2,pLast2);
                            break;

                        case 3:
                            printf("\nEnter your Position:\t");
                            scanf("%d",&iNumber);

                            iCount = CountNodes(pFirst2,pLast2);
                            if(iNumber <= 0 || iNumber > iCount + 1)
                            {
                                printf("\nInvalid Position\n");
                                break;
                            }

                            printf("\nEnter Data:\t");
                            scanf("%d",&iCount);

                            InsertAtPosition(&pFirst2,&pLast2,iCount,iNumber);
                            Display(pFirst2,pLast2);
                            break;

                        default:
                            printf("\nInvalid Choice\n");
                            continue;
                    }
                }
        }
    }

    if(pFirst1 != NULL)
    {
        DeleteAll(&pFirst1,&pLast1);
        pFirst1 = NULL;
        pLast1 = NULL;
    }
    if(pFirst2 != NULL)
    {
        DeleteAll(&pFirst2,&pLast2);
        pFirst2 = NULL;
        pLast2 = NULL;
    }
    
    Display(pFirst1,pLast1);
    Display(pFirst2,pLast2);

    return 0;
}


void InsertFirst(struct node **ppHead , struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;

    if(*ppHead == NULL)                     // list jr empty asel tr
    {
        *ppHead = pNewNode;                 // dogh pn ekach node la bagnar
        *ppTail = pNewNode;
        (*ppHead) -> pPrev = *ppTail;
        (*ppTail) -> pNext = *ppHead;

        return ;
    }

    pNewNode -> pNext = *ppHead;            // junya 1st node cha address new node chya next madhe
    (*ppHead) -> pPrev = pNewNode;          // junya 1st node chya prev madhe pNewnode cha address
    *ppHead = pNewNode;                     // new node cha address pFirst madhe
    (*ppTail) -> pNext = *ppHead;           // circular effect
    (*ppHead) -> pPrev = *ppTail;           // circular effect
}

void InsertLast(struct node **ppHead , struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;

    if(NULL == *ppHead)                     // list nasel tr
    {
        *ppHead = pNewNode;                 // dogh pn ekalach bagnar
        *ppTail = pNewNode;
        (*ppHead) -> pPrev = *ppTail;       // circular effect
        (*ppTail) -> pNext = *ppHead;

        return ;
    }

    (*ppTail) -> pNext = pNewNode;          // last node chya next madhe new node cha address
    pNewNode -> pPrev = *ppTail;            // ha adhichya node la magh bagto
    *ppTail = pNewNode;                     // ppTail pointing to last node
    (*ppTail) -> pNext = *ppHead;           // circular effect
    (*ppHead) -> pPrev = *ppTail;           // circular effect
}

void InsertAtPosition(struct node **ppHead , struct node **ppTail , int iNo , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead , *ppTail);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("Position is Invalid\n");
        return;
    }

    if(1 == iPos)                           // 1st pos asel tr
    {
        InsertFirst(ppHead , ppTail , iNo);
        return;
    }

    if(iPos == iCount + 1)                  // last pos asel tr
    {
        InsertLast(ppHead , ppTail , iNo);
        return;
    }

    pNewNode = (struct node*) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;

    pTemp = *ppHead;
    iCount = 1;
    while(iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    pTemp -> pNext -> pPrev = pNewNode;
    pNewNode -> pNext = pTemp -> pNext;
    pNewNode -> pPrev = pTemp;
    pTemp -> pNext = pNewNode;

}

int DeleteFirst(struct node **ppHead , struct node **ppTail)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData = (*ppHead) -> iData;

    if(*ppHead == *ppTail)          // ekch node asel tr
    {
        free(*ppHead);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead) -> pNext;       // 2nd node la ja
        free((*ppTail) -> pNext);           
        (*ppHead) -> pPrev = *ppTail;       // circular effect
        (*ppTail) -> pNext = *ppHead;       // circular effect
    }

    return iDelData;
}

int DeleteLast(struct node **ppHead , struct node **ppTail)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData = (*ppTail) -> iData;

    if(*ppHead == *ppTail)
    {
        free(*ppHead);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        *ppTail = (*ppTail) -> pPrev;
        free((*ppTail) -> pNext);
        (*ppTail) -> pNext = *ppHead;       // circular effect
        (*ppHead) -> pPrev = *ppTail;       // circular effect
    }

    return iDelData;
}

int DeleteAtPosition(struct node **ppHead , struct node **ppTail , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead , *ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("Position is Invalid\n");
        return -1;
    }

    if(1 == iPos)
        return DeleteFirst(ppHead , ppTail);

    if(iPos == iCount)
        return DeleteLast(ppHead , ppTail);

    pTemp = *ppHead;
    iCount = 1;
    while(iCount < iPos)
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    iCount = pTemp -> iData;
    pTemp -> pNext -> pPrev = pTemp -> pPrev;           
    pTemp -> pPrev -> pNext = pTemp -> pNext;

    free(pTemp);

    return iCount;
}

int CountNodes(struct node *pHead , struct node *pTail)
{
    int iCount = 0;

    if(NULL == pHead)
        return 0;

    do
    {
        iCount ++;
        pHead = pHead -> pNext;

    } while(pHead != pTail -> pNext);
    
    return iCount;
}

int SearchFirstOccurrence(struct node *pHead , struct node *pTail , int iKey)
{
    int iPos = 0;

    if(NULL == pHead)
        return 0;

    do
    {
        iPos ++;

        if(pHead -> iData == iKey)
            return iPos;

        pHead = pHead -> pNext;

    } while (pHead != pTail -> pNext);

    return 0;
    
}

int SearchLastOccurrence(struct node *pHead , struct node *pTail , int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    if(NULL == pHead)
        return 0;

    do
    {
        iPos++;

        if(pHead -> iData == iKey)
            iLastPos = iPos;

        pHead = pHead -> pNext;

    } while (pHead != pTail -> pNext);

    return iLastPos;
}

int SearchAllOccurrences(struct node *pHead , struct node *pTail , int iKey)
{
    int iCount = 0;

    if(NULL == pHead)
        return 0;

    do
    {
        if(pHead -> iData == iKey)
            iCount++;

        pHead = pHead -> pNext;

    } while (pHead != pTail -> pNext);

    return iCount;
}

void Display(struct node *pHead , struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }

    printf("\nList is:\t");
    do
    {
        printf("<-|%d|->", pHead -> iData);
        pHead = pHead -> pNext;

    } while (pHead != pTail -> pNext);
}

void ConcatLists(struct node **ppHead1 , struct node **ppTail1 , struct node **ppHead2 , struct node **ppTail2)
{
    if(NULL == *ppHead2)            // scenerio 1 & 2
        return;

    if(NULL == *ppHead1)            // scenerio 3
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
        return;
    }

    // both lists are present
    // scenerio 4

    (*ppTail1) -> pNext = *ppHead2;
    (*ppHead2) -> pPrev = *ppTail1;
    *ppTail1 = *ppTail2;
    (*ppHead1) -> pPrev = *ppTail1;
    (*ppTail1) -> pNext = *ppHead1;

    *ppHead2 = *ppTail2 = NULL;
}

void ReverseDisplay(struct node *pHead , struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }

    printf("\nList is:\t");

    do
    {
        printf("<-|%d|->", pTail -> iData);
        pTail = pTail -> pPrev;

    }while(pTail != pHead -> pPrev);

}

void DeleteAll(struct node **ppHead , struct node **ppTail)
{
    struct node *pTemp = NULL;

    (*ppTail) -> pNext = NULL;

    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp -> pNext;
        free(pTemp);
    }

    *ppTail = NULL;
}

void ConcatAtPosition(struct node **ppHead1 , struct node **ppTail1 , struct node **ppHead2 , struct node **ppTail2 , int iPos)
{
    struct node *pTemp = NULL;
    int iCount;

    iCount = CountNodes(*ppHead1 , *ppTail1);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nPosition is Invalid\n");
        return;
    }

    if(NULL == *ppHead2)
        return;

    if(1 == iPos)
    {
        ConcatLists(ppHead2 , ppTail2 , ppHead1 , ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
        return;
    }

    if(iPos == iCount + 1)
    {
        ConcatLists(ppHead1 , ppTail1 , ppHead2 , ppTail2);
        return;
    }

    pTemp = *ppHead1;
    iCount = 1;
    while(iCount < iPos - 1)
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    pTemp -> pNext -> pPrev = *ppTail2;
    (*ppTail2) -> pNext = pTemp -> pNext;
    pTemp -> pNext = *ppHead2;
    (*ppHead2) -> pPrev = pTemp;

    *ppHead2 = NULL;
    *ppTail2 = NULL;

}

void PhysicalReverse(struct node **ppHead , struct node **ppTail)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if(NULL == *ppHead)
        return ;

    do
    {
        pNext = pCurrent -> pNext;
        pCurrent -> pNext = pCurrent -> pPrev;
        pCurrent -> pPrev = pNext;
        pCurrent = pNext;
        
    } while (pCurrent != *ppHead);

    *ppTail = pCurrent;
    *ppHead = (*ppTail) -> pNext;
}
