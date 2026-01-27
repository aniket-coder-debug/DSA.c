#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node ** , int);
void InsertLast(struct node ** , int);
void InsertAtPosition(struct node ** , int , int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node ** , int);
int CountNodes(struct node *);
int SearchFirstOccurrence(struct node * , int);
int SearchLastOccurrence(struct node * , int);
int SearchAllOccurrences(struct node * , int);
void Display(struct node *);
void ConcatLists(struct node ** , struct node **);
void ConcatAtPosition(struct node ** , struct node ** , int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iNumber;

    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst);                                    // List is empty

    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);

    Display(pFirst);                                    // <-|10|-><-|20|-><-|30|->

    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 50);
    InsertLast(&pFirst , 60);

    Display(pFirst);                                    // <-|10|-><-|20|-><-|30|-><-|40|-><-|50|-><-|60|->

    InsertAtPosition(&pFirst , 20 , 4);

    Display(pFirst);                                    // <-|10|-><-|20|-><-|30|-><-|20|-><-|40|-><-|50|-><-|60|->

    iNumber = DeleteFirst(&pFirst);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);    // Deleted data is 10

    Display(pFirst);                                    // <-|20|-><-|30|-><-|20|-><-|40|-><-|50|-><-|60|->

    iNumber = DeleteLast(&pFirst);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);    // Deleted data is 60

    Display(pFirst);                                    // <-|20|-><-|30|-><-|20|-><-|40|-><-|50|->

    iNumber = DeleteAtPosition(&pFirst , 2);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);    // Deleted data is 30

    Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|->

    iNumber = SearchFirstOccurrence(pFirst , 20);
    if(iNumber != 0)
        printf("\n\nFirst Occurrence of %d is at %d position\n",20 ,iNumber);   // First Occurrence of 20 is at 1 position

    iNumber = SearchLastOccurrence(pFirst , 20);
    if(iNumber != 0)
        printf("\n\nLast Occurrence of %d is at %d position\n",20 ,iNumber);    // Last Occurrence of 20 is at 2 position

    iNumber = SearchFirstOccurrence(pFirst , 20);
    if(iNumber != 0)
        printf("\n\n%d Found %d times\n",20 ,iNumber);                          // 20 Found 1 times

    Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|->
    iNumber = CountNodes(pFirst);
    printf("\n\nTotal node count is %d\n",iNumber);     // Total node count is 4

    PhysicalReverse(&pFirst);
    Display(pFirst);                                    // <-|50|-><-|40|-><-|20|-><-|20|->
    PhysicalReverse(&pFirst);
    Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|->
    ReverseDisplay(pFirst);                             // <-|50|-><-|40|-><-|20|-><-|20|->
    //Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|->

    InsertLast(&pSecond , 100);
    InsertLast(&pSecond , 200);
    InsertLast(&pSecond , 300);
    Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|->
    Display(pSecond);                                   // <-|100|-><-|200|-><-|300|->
    ConcatLists(&pFirst , &pSecond);
    Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|-><-|100|-><-|200|-><-|300|->
    Display(pSecond);                                   // List is empty

    InsertLast(&pSecond , 400);
    InsertLast(&pSecond , 500);
    InsertLast(&pSecond , 600);
    Display(pFirst);                                    // <-|20|-><-|20|-><-|40|-><-|50|-><-|100|-><-|200|-><-|300|->
    Display(pSecond);                                   // <-|400|-><-|500|-><-|600|->
    ConcatAtPosition(&pFirst , &pSecond , 3);
    Display(pFirst);                                    // <-|20|-><-|20|-><-|400|-><-|500|-><-|600|-><-|40|-><-|50|-><-|100|-><-|200|-><-|300|->
    Display(pSecond);                                   // List is empty

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    if(pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }
    Display(pFirst);                                    // List is empty
    Display(pSecond);                                   // List is empty

    return 0;
}

void InsertFirst(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;               // ha kadhipn NULL ch asnar

    if(NULL == *ppHead)                     // node nasel tr
    {
        pNewNode -> pNext = NULL;           // new node chya next madhe NULL janar
        *ppHead = pNewNode;                 // pFirst madhe new node cha address janar
        return;
    }
    else
    {
        pNewNode -> pNext = *ppHead;        // new node chya next madhe adhichya pahilya node cha address janar
        (*ppHead) -> pPrev = pNewNode;      // junya 1st node chya prev madhe new node cha address janar
        *ppHead = pNewNode;                 // pFirst madhe new node cha address janar
    }
}

void InsertLast(struct node **ppHead , int iNo)
{
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = NULL;           // kadhipn NULL asnar

    if(NULL == *ppHead)                 // list nasel tr
    {
        pNewNode -> pPrev = NULL;
        *ppHead = pNewNode;             // pFirst madhe new node cha address
        return;
    }

    pTemp = *ppHead ;                   // pointing to first node
    while(pTemp -> pNext != NULL)       // tuzya next madhe jo paryant NULL yet nay
        pTemp = pTemp -> pNext;

    pTemp -> pNext = pNewNode;          // last node chya next madhe new node cha address
    pNewNode -> pPrev = pTemp;          // new node chya prev madhe last node cha address
}

void InsertAtPosition(struct node **ppHead , int iNo , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nPosition is Invalid\n");
        return;
    }

    if(1 == iPos)   
    {
        InsertFirst(ppHead , iNo);
        return;
    }

    if(iPos == iCount + 1)
    {
        InsertLast(ppHead , iNo);
        return;
    }

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("Memory allocation Failed\n");
        return;
    }

    pNewNode -> iData = iNo;

    pTemp = *ppHead;
    iCount = 1;
    while(iCount < iPos - 1)                // position ji ahe tyachya adhichya node la thamb
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    pNewNode -> pNext = pTemp -> pNext;     // new node chya next madhe pTemp chya next cha address
    pTemp -> pNext -> pPrev = pNewNode;     // pTemp chya next chya prev madhe new node cha address
    pTemp -> pNext = pNewNode;              // pTemp chya next madhe new node cha address
    pNewNode -> pPrev = pTemp;              // new node pTemp la bagto
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;

    if(NULL == *ppHead)                     // list jr empty asel tr ja maghari
        return -1;

    iDelData = (*ppHead) -> iData;

    if(NULL == (*ppHead) -> pNext)          // 1 node chi list asel tr
    {
        free(*ppHead);
        *ppHead = NULL;
        return iDelData;
    }
    else
    {
        *ppHead = (*ppHead) -> pNext;       // pFirst adhi pudhchya node la set kela
        (*ppHead) -> pPrev -> pNext = NULL; // mg 1st node chya next madhe NULL takla

        free((*ppHead) -> pPrev);           // mg 1st node free la pathavla
        (*ppHead) -> pPrev = NULL;          // ata 2nd node 1st zala manun tyachya prev madhe NULL takla
    }   

    return iDelData;
}

int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    pTemp = *ppHead;

    if(NULL == pTemp -> pNext)              // 1 node asel tr
    {
        *ppHead = NULL;
    }
    else
    {
        while(pTemp -> pNext != NULL)       // tuzya next madhe jo paryant NULL yet ny
            pTemp = pTemp -> pNext;

        pTemp -> pPrev -> pNext = NULL;     // 2nd last node chya next madhe NULL takla
    }

    iDelData = pTemp -> iData;
    pTemp -> pPrev = NULL;                  // last node cha prev NULL kela
    free(pTemp);

    return iDelData;
}

int DeleteAtPosition(struct node **ppHead , int iPos)
{
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nPosition is Invalid\n");
        return -1;
    }

    if(1 == iPos)
        return DeleteFirst(ppHead);

    if(iPos == iCount)
        return DeleteLast(ppHead);

    pTemp = *ppHead;
    iCount = 1;
    while(iCount < iPos)                        // pointing to deleting node
    {
        iCount++;
        pTemp = pTemp -> pNext;
    }

    iCount = pTemp -> iData;
    pTemp -> pPrev -> pNext = pTemp -> pNext;   // deleted node chya adhichya node madhe tyachya pudhchyacha address takla
    pTemp -> pNext -> pPrev = pTemp -> pPrev;   // ani tyachya pudhchya node chya prev madhe deleted node chya adhichyacha address takla

    free(pTemp);

    return iCount;
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

int SearchFirstOccurrence(struct node *pHead , int iKey)
{
    int iPos = 0;

    while(pHead != NULL)
    {
        iPos ++;

        if(pHead -> iData == iKey)
            return iPos;

        pHead = pHead -> pNext;
    }

    return 0;           // list jr empty asel tr ani data matching nasel tr 0 return karnar
}

int SearchLastOccurrence(struct node *pHead , int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    while(pHead != NULL)
    {
        iPos++ ;

        if(pHead -> iData == iKey)
            iLastPos = iPos;

        pHead = pHead -> pNext;

    }

    return iLastPos;    // list jr empty asel tr ani data matching nasel tr 0 return karnar 
}

int SearchAllOccurrences(struct node *pHead , int iKey)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        if(pHead -> iData == iKey)      // jr donhi deta same astil trch iCount ++ honar
            iCount++ ;

        pHead = pHead -> pNext;
    }

    return iCount;
}

void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\n\nList is empty\n");
        return;
    }

    printf("\nList is :\t");

    while(pHead != NULL)
    {
        printf("<-|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }
}

void ConcatLists(struct node **ppHead1 , struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(NULL == *ppHead2)                // scenerio 1 & 2
        return;

    if(NULL == *ppHead1)                // scenerio 3
    {
        *ppHead1 = *ppHead2;            // 2nd list 1st zali
        *ppHead2 = NULL;                // pSecond madhe NULL takla
        return;
    }

    // donhi list present ahet ata
    // scenerio 4

    pTemp = *ppHead1;
    while(pTemp -> pNext != NULL)       // last node la janar
        pTemp = pTemp -> pNext;

    pTemp -> pNext = *ppHead2;          // concat
    (*ppHead2) -> pPrev = pTemp;        // 2nd list chya 1st node chya prev madhe pTemp takla
    *ppHead2 = NULL;                    // pSecond NULL kela
}

void ConcatAtPosition(struct node **ppHead1 , struct node **ppHead2 , int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead1);

    if(iPos <= 0 || iPos > iCount + 1)
    {
        printf("\nPosition is Invalid\n");
        return ;
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
        ConcatLists(ppHead2 , ppHead1);     // 1st concat 2nd
        *ppHead1 = *ppHead2;                // 2nd list 1st zali
        *ppHead2 = NULL;                    // pSecond NULL kela
        return;
    }

    // both list are present

    if(iPos == iCount + 1)                  // position jr last asel tr
    {
        ConcatLists(ppHead1 , ppHead2);
        return;
    }

    pTemp1 = *ppHead1;
    iCount = 1;
    while(iCount < iPos - 1)                // position chya adhichya node la thamb
    {
        iCount++;
        pTemp1 = pTemp1 -> pNext;
    }

    pTemp2 = *ppHead2;
    while(pTemp2 -> pNext != NULL)          // 2nd list chya last node paryant ja
        pTemp2 = pTemp2 -> pNext;

    pTemp2 -> pNext = pTemp1 -> pNext;      // 2nd list chya last node chya next madhe pTemp1 jith thamblay tyachya pudhchyacha address takto
    pTemp2 -> pNext -> pPrev = pTemp2;      // ani pTemp1 chya pudhchyacha prev madhe 2nd list chya last node cha address takto
    pTemp1 -> pNext = *ppHead2;             // pTemp1 chya next madhe 2nd list chya 1st node cha address takto
    (*ppHead2) -> pPrev = pTemp1;           // 2nd list chya 1st node chya prev madhe pTemp1 cha address takto

    *ppHead2 = NULL;                        // pSecond NULL kela
}

void PhysicalReverse(struct node **ppHead)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent -> pNext;              // pNext 2nd node la set kela
        pCurrent -> pNext = pCurrent -> pPrev;  // pCurrent chya next madhe magchyacha address takat gelo
        pCurrent -> pPrev = pNext;              // pCurrent chya prev madhe pNext takat gelo
        *ppHead = pCurrent;                     // pFirst madhe pCurrent takat gelo
        pCurrent = pNext;                       // ani ith pCurrent madhe NULL ala tari kahi adchan ny 
    }
}

void ReverseDisplay(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\nList is empty\n");
        return;
    }

    while(pHead -> pNext != NULL)
        pHead = pHead -> pNext;

    printf("\nList is :\t");

    while(pHead != NULL)
    {
        printf("<-|%d|->", pHead -> iData);
        pHead = pHead -> pPrev;
    }
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;

    while(*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp -> pNext;
        free(pTemp);
    }
}

