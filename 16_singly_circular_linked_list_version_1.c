#include <stdio.h>
#include <malloc.h>

struct node
{
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

    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    Display(pFirst1 , pLast1);                                      // List is empty

    InsertFirst(&pFirst1 , &pLast1 , 30);
    InsertFirst(&pFirst1 , &pLast1 , 20);
    InsertFirst(&pFirst1 , &pLast1 , 10);

    Display(pFirst1 , pLast1);                                      // |10|->|20|->|30|->

    InsertLast(&pFirst1 , &pLast1 , 40);
    InsertLast(&pFirst1 , &pLast1 , 50);
    InsertLast(&pFirst1 , &pLast1 , 60);

    Display(pFirst1 , pLast1);                                      // |10|->|20|->|30|->|40|->|50|->|60|->

    InsertAtPosition(&pFirst1 , &pLast1 , 20 , 4);

    Display(pFirst1 , pLast1);                                      // |10|->|20|->|30|->|20|->|40|->|50|->|60|->

    iNumber = DeleteFirst(&pFirst1 , &pLast1);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);                // Deleted data is 10

    Display(pFirst1 , pLast1);                                      // |20|->|30|->|20|->|40|->|50|->|60|->

    iNumber = DeleteLast(&pFirst1 , &pLast1);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);                // Deleted data is 60

    Display(pFirst1 , pLast1);                                      // |20|->|30|->|20|->|40|->|50|->

    iNumber = DeleteAtPosition(&pFirst1 , &pLast1 , 2);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);                // Deleted data is 30

    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->

    iNumber = SearchFirstOccurrence(pFirst1 , pLast1 , 20);
    if(iNumber != 0)
        printf("\n\nFirst Occurrence of %d is at %d position\n",20 ,iNumber);     // First Occurrence of 20 is at 1 position

    iNumber = SearchLastOccurrence(pFirst1 , pLast1 , 20);
    if(iNumber != 0)
        printf("\n\nLast Occurrence of %d is at %d position\n",20 ,iNumber);      // Last Occurrence of 20 is at 2 position

    iNumber = SearchFirstOccurrence(pFirst1 , pLast1 , 20);
    if(iNumber != 0)
        printf("\n\n%d Found %d times\n",20 ,iNumber);              // 20 Found 1 times

    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->
    iNumber = CountNodes(pFirst1 , pLast1);
    printf("\n\nTotal node count is %d\n",iNumber);                 // Total node count is 4

    PhysicalReverse(&pFirst1 , &pLast1);
    Display(pFirst1 , pLast1);                                      // |50|->|40|->|20|->|20|->
    PhysicalReverse(&pFirst1 , &pLast1);
    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->
    ReverseDisplay(pFirst1 , pLast1);                               // |50|->|40|->|20|->|20|->
    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->

    InsertLast(&pFirst2 , &pLast2 , 100);
    InsertLast(&pFirst2 , &pLast2 , 200);
    InsertLast(&pFirst2 , &pLast2 , 300);
    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->
    Display(pFirst2 , pLast2);                                      // |100|->|200|->|300|->
    ConcatLists(&pFirst1 , &pLast1 , &pFirst2 , &pLast2);
    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->|100|->|200|->|300|->
    Display(pFirst2 , pLast2);                                      // List is empty

    InsertLast(&pFirst2 , &pLast2 , 400);
    InsertLast(&pFirst2 , &pLast2 , 500);
    InsertLast(&pFirst2 , &pLast2 , 600);
    Display(pFirst1 , pLast1);                                      // |20|->|20|->|40|->|50|->|100|->|200|->|300|->
    Display(pFirst2 , pLast2);                                      // |400|->|500|->|600|->
    ConcatAtPosition(&pFirst1 , &pLast1 , &pFirst2 , &pLast2 , 3);
    Display(pFirst1 , pLast1);                                      // |20|->|20|->|400|->|500|->|600|->|40|->|50|->|100|->|200|->|300|->
    Display(pFirst2 , pLast2);                                      // List is empty

    if(pFirst1 != NULL)
    {
        DeleteAll(&pFirst1 , &pLast1);
        pFirst1 = NULL;
    }

    if(pFirst2 != NULL)
    {
        DeleteAll(&pFirst2 , &pLast2);
        pFirst2 = NULL;
    }
    Display(pFirst1 , pLast1);                                      // List is empty
    Display(pFirst2 , pLast2);                                      // List is empty

    return 0;
}

void InsertFirst(struct node **ppHead , struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;

    if(NULL == *ppHead)                 // list jr Empty asel tr
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail) -> pNext = *ppHead;

        return;
    }
    
    pNewNode -> pNext = *ppHead;
    *ppHead = pNewNode;
    (*ppTail) -> pNext = *ppHead;
}

void InsertLast(struct node **ppHead , struct node **ppTail , int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;

    if(NULL == *ppHead)                 // list jr empty asel tr
    {
        *ppHead = pNewNode;             // new node cha address pFirst madhe janar
        *ppTail = pNewNode;             // plast madhe pn takla
        (*ppTail) -> pNext = *ppHead;   // circular effect

        return;
    }

    (*ppTail) -> pNext = pNewNode;      // last node chya next madhe new node takla
    *ppTail = pNewNode;                 // pTail pointing to last node
    (*ppTail) -> pNext = *ppHead;       // circular effect
}

int DeleteFirst(struct node **ppHead , struct node **ppTail)
{
    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData = (*ppHead) -> iData;

    if(*ppHead == *ppTail)                  // only one node
    {
        free(*ppHead);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        *ppHead = (*ppHead) -> pNext;       // tu adhi pudh bg
        free((*ppTail) -> pNext);
        (*ppTail) -> pNext = *ppHead;       // circular effect
    }

    return iDelData;
}

int DeleteLast(struct node **ppHead , struct node **ppTail)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    iDelData = (*ppTail) -> iData;

    if(*ppHead == *ppTail)                          // one node asel tr
    {
        free(*ppHead);
        *ppHead = NULL;
        *ppTail = NULL;
    }
    else
    {
        pTemp = *ppHead;
        while(pTemp -> pNext != *ppTail)            // second last node la thamb
            pTemp = pTemp -> pNext;

        free(*ppTail);
        *ppTail = pTemp;                            // last node cha address takla pTail madhe
        (*ppTail) -> pNext = *ppHead;               // circular effect
    }

    return iDelData;
}

void InsertAtPosition(struct node **ppHead , struct node **ppTail , int iNo , int iPos)
{
    int iCount;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead , *ppTail);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nPosition is Invalid\n");
        return;
    }

    if(1 == iPos)            
    {
        InsertFirst(ppHead , ppTail , iNo);
        return;
    }

/*    if(iPos == iCount + 1)       
    {
        InsertLast(ppHead , ppTail , iNo);
        return ;
    }
*/

// khali yety mhanje 2 node chi teri list ahe

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\nMemory allocation FAILED\n");
        return ;
    }

    pNewNode -> iData = iNo;

    pTemp = *ppHead;
    iCount = 1;
    while(iCount < iPos - 1)                // ji position deli tyachya adhichya node la jaun thambaych
    {
        iCount ++;
        pTemp = pTemp -> pNext;
    }

    pNewNode -> pNext = pTemp -> pNext;     // new node chya next madhe ptemp chya next cha address
    pTemp -> pNext = pNewNode;              // pTemp chya next madhe new node cha address
}

int DeleteAtPosition(struct node **ppHead  , struct node **ppTail , int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead , *ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nPosition is Invalid\n");
        return -1;
    }

    if(1 == iPos)                       // 1st node delete karaychya asel tr
        return DeleteFirst(ppHead , ppTail);

//    if(iPos == iCount)
//        return DeleteLast(ppHead , ppTail);

    pTemp1 = *ppHead;                   // pointing to first node
    iCount = 1;
    while(iCount < iPos - 1)            // position chya adhichya node la jaun thambto
    {
        iCount++;
        pTemp1 = pTemp1 -> pNext;
    }

    pTemp2 = pTemp1 -> pNext;           // pointing to deleting node

    pTemp1 -> pNext = pTemp2 -> pNext;  // jo node delete hoylay tyachya adhichya node chya next madhe tyachya pudhchyacha address taktoy
    iCount = pTemp2 -> iData;

    free(pTemp2);

    return iCount;
}

void ConcatLists(struct node **ppHead1 , struct node **ppTail1 , struct node **ppHead2 , struct node **ppTail2)
{
    if(NULL == *ppHead2)            // scenerio 1 & 2
        return;

    // khali alay mhanje second list ahe

    if(NULL == *ppHead1)            // scenerio 3
    {
        *ppHead1 = *ppHead2;        // dusrila pahil banvl
        *ppTail1 = *ppTail2;        // dusrila pahil banvl
        *ppHead2 = NULL;            // 2nd list empty
        *ppTail2 = NULL;            // 2nd list empty

        return;
    }

    // khali alay mhanje donhi lists ahet
    // scenerio 4

    (*ppTail1) -> pNext = *ppHead2;
    *ppTail1 = *ppTail2;
    (*ppTail1) -> pNext = *ppHead1;

    *ppHead2 = NULL;
    *ppTail2 = NULL;
}

void ConcatAtPosition(struct node **ppHead1 , struct node **ppTail1 , struct node **ppHead2 , struct node **ppTail2 , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead1 , *ppTail1);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nPosition is Invalid\n");
        return;
    }

// we dont know 2nd list is present or not
// we dont know 1st list is present or not
// we surely know if 1st list empty then iPos == 1

    if(NULL == *ppHead2)
        return;

// surely 2nd list is present
// we dont know 1st list is present or not
// we surely know if 1st list empty then iPos == 1

    if(1 == iPos)
    {
        ConcatLists(ppHead2 , ppTail2 , ppHead1 , ppTail1);     // dusri list philya list la jodun ali
        *ppHead1 = *ppHead2;                                    // 2nd become 1st
        *ppTail1 = *ppTail2;

        return;
    }

// surely both list are present

//    if(iPos == iCount + 1)
//    {
//        ConcatLists(ppHead1 , ppTail1 , ppHead2 , ppTail2);
//        return;
//    }

    pTemp = *ppHead1;
    iCount = 1;
    while(iCount < iPos - 1)
    {
        iCount ++;
        pTemp = pTemp -> pNext;
    }

    (*ppTail2) -> pNext = pTemp -> pNext;
    pTemp -> pNext = *ppHead2;

    *ppHead2 = *ppTail2 = NULL;
}

void Display(struct node *pHead , struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("\n\nList is empty\n");
        return ;
    }

    printf("\n\nList is :\t");

    do
    {
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;

    }while(pHead != pTail -> pNext);
}

int CountNodes(struct node *pHead , struct node *pTail)
{
    int iCount = 0;

    if(NULL == pHead)
        return -1;

    do
    {
        iCount++;
        pHead = pHead -> pNext;

    }while(pHead != pTail -> pNext);

    return iCount;
}

int SearchFirstOccurrence(struct node *pHead , struct node *pTail , int iKey)
{
    int iPos = 0;

    if(pHead == NULL)
        return 0;

    do
    {
        iPos++;

        if(pHead -> iData == iKey)
            return iPos;

        pHead = pHead -> pNext;
    }while(pHead != pTail -> pNext);

    return 0;           //  If List is empty or Data Not Found
}

int SearchLastOccurrence(struct node *pHead , struct node *pTail , int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    if(pHead == NULL)
        return 0;

    do
    {
        iPos ++;

        if(pHead -> iData == iKey)
            iLastPos = iPos;

        pHead = pHead -> pNext;
    }while(pHead != pTail -> pNext);

    return iLastPos;        // data jr ny sapdla ani list jr empty asel tr 0 return karto
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

void PhysicalReverse(struct node **ppHead , struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    if(NULL == *ppHead)
        return;

    do
    {
        pNext = pCurrent -> pNext;
        pCurrent -> pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;

    } while (pCurrent != *ppHead);

    *ppHead = pPrev;
    *ppTail = pCurrent;
}

void ReverseDisplay(struct node *pHead , struct node *pTail)
{
    if(NULL == pHead)
    {
        printf("\nList is Empty\n");
        return;
    }

    PhysicalReverse(&pHead , &pTail);
    Display(pHead , pTail);
    PhysicalReverse(&pHead , &pTail);
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
