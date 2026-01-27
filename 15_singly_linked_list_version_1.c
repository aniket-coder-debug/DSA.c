#include <stdio.h>
#include <malloc.h>

struct node
{
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

    Display(pFirst);                                    // |10|->|20|->|30|->

    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 50);
    InsertLast(&pFirst , 60);

    Display(pFirst);                                    // |10|->|20|->|30|->|40|->|50|->|60|->

    InsertAtPosition(&pFirst , 20 , 4);

    Display(pFirst);                                    // |10|->|20|->|30|->|20|->|40|->|50|->|60|->

    iNumber = DeleteFirst(&pFirst);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);    // Deleted data is 10

    Display(pFirst);                                    // |20|->|30|->|20|->|40|->|50|->|60|->

    iNumber = DeleteLast(&pFirst);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);    // Deleted data is 60

    Display(pFirst);                                    // |20|->|30|->|20|->|40|->|50|->

    iNumber = DeleteAtPosition(&pFirst , 2);
    if(iNumber != -1)
        printf("\n\nDeleted data is %d\n", iNumber);    // Deleted data is 30

    Display(pFirst);                                    // |20|->|20|->|40|->|50|->

    iNumber = SearchFirstOccurrence(pFirst , 20);
    if(iNumber != 0)
        printf("\n\nFirst Occurrence of %d is at %d position\n",20 ,iNumber);     // First Occurrence of 20 is at 1 position

    iNumber = SearchLastOccurrence(pFirst , 20);
    if(iNumber != 0)
        printf("\n\nLast Occurrence of %d is at %d position\n",20 ,iNumber);      // Last Occurrence of 20 is at 2 position

    iNumber = SearchFirstOccurrence(pFirst , 20);
    if(iNumber != 0)
        printf("\n\n%d Found %d times\n",20 ,iNumber);                            // 20 Found 1 times

    Display(pFirst);                                    // |20|->|20|->|40|->|50|->
    iNumber = CountNodes(pFirst);
    printf("\n\nTotal node count is %d\n",iNumber);     // Total node count is 4

    PhysicalReverse(&pFirst);
    Display(pFirst);                                    // |50|->|40|->|20|->|20|->
    PhysicalReverse(&pFirst);
    Display(pFirst);                                    // |20|->|20|->|40|->|50|->
    ReverseDisplay(pFirst);                             // |50|->|40|->|20|->|20|->
    Display(pFirst);                                    // |20|->|20|->|40|->|50|->

    InsertLast(&pSecond , 100);
    InsertLast(&pSecond , 200);
    InsertLast(&pSecond , 300);
    Display(pFirst);                                    // |20|->|20|->|40|->|50|->
    Display(pSecond);                                   // |100|->|200|->|300|->
    ConcatLists(&pFirst , &pSecond);
    Display(pFirst);                                    // |20|->|20|->|40|->|50|->|100|->|200|->|300|->
    Display(pSecond);                                   // List is empty

    InsertLast(&pSecond , 400);
    InsertLast(&pSecond , 500);
    InsertLast(&pSecond , 600);
    Display(pFirst);                                    // |20|->|20|->|40|->|50|->|100|->|200|->|300|->
    Display(pSecond);                                   // |400|->|500|->|600|->
    ConcatAtPosition(&pFirst , &pSecond , 3);
    Display(pFirst);                                    // |20|->|20|->|400|->|500|->|600|->|40|->|50|->|100|->|200|->|300|->
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

    if(NULL == *ppHead)                 // list jr Empty asel tr
        pNewNode -> pNext = NULL;       // new node chya next madhe NULL jato
    else                                // nahitr
        pNewNode -> pNext = *ppHead;    // new node chya next madhe junya pahilyacha address jato ani ha pahila hoto

    *ppHead = pNewNode;                 // pFirst madhe new node cha address jato
}

void InsertLast(struct node **ppHead , int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

    pNewNode = (struct node *) malloc (sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("\nMemory allocation FAILED\n");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = NULL;           // ha kadhipn NULL ch asnar

    if(NULL == *ppHead)                 // list jr empty asel tr
    {
        *ppHead = pNewNode;             // new node cha address pFirst madhe janar
        return;
    }

    pTemp = *ppHead;                    // pointing to First node
    while(pTemp -> pNext != NULL)       // pTemp tuzya next madhe jo paryant NULL yet ny to paryant
        pTemp = pTemp -> pNext;

    pTemp -> pNext = pNewNode;          // last node chya next madhe new node cha address janar
}

int DeleteFirst(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    pTemp = *ppHead;                    // pointing to first node
    *ppHead = pTemp -> pNext;           // second node cha address pFirst madhe

    iDelData = pTemp -> iData;
    pTemp -> pNext = NULL;              // 1st node chya next madhe NULL
    free(pTemp);

    return iDelData;
}

int DeleteLast(struct node **ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1;

    pTemp = *ppHead;

    if(NULL == pTemp -> pNext)                          // one node asel tr
    {
        iDelData = pTemp -> iData;
        free(pTemp);
        *ppHead = NULL;
    }
    else
    {
        while(pTemp -> pNext -> pNext != NULL)          // pTemp 2nd last node la thambto
            pTemp = pTemp -> pNext;

        iDelData = pTemp -> pNext -> iData;
        free(pTemp -> pNext);                           // 2nd last node la thambun ch tyala free karto
        pTemp -> pNext = NULL;
    }

    return iDelData;
}

void Display(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\n\nList is empty\n");
        return ;
    }

    printf("\n\nList is :\t");

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

int SearchFirstOccurrence(struct node *pHead , int iKey)
{
    int iPos = 0;

    while(pHead != NULL)
    {
        iPos++;

        if(pHead -> iData == iKey)
            return iPos;

        pHead = pHead -> pNext;
    }

    return 0;           //  If List is empty or Data Not Found
}

int SearchLastOccurrence(struct node *pHead , int iKey)
{
    int iPos = 0;
    int iLastPos = 0;

    while(pHead != NULL)
    {
        iPos ++;

        if(pHead -> iData == iKey)
            iLastPos = iPos;

        pHead = pHead -> pNext;
    }

    return iLastPos;        // data jr ny sapdla ani list jr empty asel tr 0 return karto
}

int SearchAllOccurrences(struct node *pHead , int iKey)
{
    int iPos = 0;

    while(pHead != NULL)
    {
        if(pHead -> iData == iKey)
            iPos ++;

        pHead = pHead -> pNext;
    }

    return iPos;            // data jr ny sapdla ani list jr empty asel tr 0 return karto
}

void InsertAtPosition(struct node **ppHead , int iNo , int iPos)
{
    int iCount;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;

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

/*    if(iPos == iCount + 1)       
    {
        InsertLast(ppHead , iNo);
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

int DeleteAtPosition(struct node **ppHead , int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nPosition is Invalid\n");
        return -1;
    }

    if(1 == iPos)                       // 1st node delete karaychya asel tr
        return DeleteFirst(ppHead);

//    if(iPos == iCount)
//        return DeleteLast(ppHead);

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

void ConcatLists(struct node **ppHead1 , struct node **ppHead2)
{
    struct node *pTemp = NULL;

    if(NULL == *ppHead2)            // scenerio 1 & 2
        return;

    // khali alay mhanje second list ahe

    if(NULL == *ppHead1)            // scenerio 3
    {
        *ppHead1 = *ppHead2;        // dusrila pahil banvl
        *ppHead2 = NULL;            // 2nd list empty
        return;
    }

    // khali alay mhanje donhi lists ahet
    // scenerio 4

    pTemp = *ppHead1;               // pointing to first node
    while(pTemp -> pNext != NULL)   // jo paryant tuzya next madhe NULL yet ny
        pTemp = pTemp -> pNext;

    pTemp -> pNext = *ppHead2;      // 1st list chya last node chya next madhe 2nd list chya 1st node cha address
    *ppHead2 = NULL;                // 2nd list empty
}

void ReverseDisplay(struct node *pHead)
{
    if(NULL == pHead)
    {
        printf("\nList is empty\n");
        return;
    }

    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
}

void PhysicalReverse(struct node **ppHead)
{
    struct node *pNext = NULL;
    struct node *pCurrent = *ppHead;
    struct node *pPrev = NULL;

    while(pCurrent != NULL)             // pCurrent madhe jo paryant NULL jat nay
    {
        pNext = pCurrent -> pNext;      // pCurrent chya pudhchya node la pNext set kela
        pCurrent -> pNext = pPrev;      // pCurrent chya next madhe tyachya magchyacha address takla
        pPrev = pCurrent;               // pPrev pCurrent chya jagi anla
        pCurrent = pNext;               // pCurreant pNext chya jagi nela
    }

    *ppHead = pPrev;   // last la jevha pCurrent madhe NULL jaun loop chya baher yenar tevha prev ha last node la asnar manun tyacha address pFirst madhe
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

void ConcatAtPosition(struct node **ppHead1 , struct node **ppHead2 , int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;


    iCount = CountNodes(*ppHead1);

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
        ConcatLists(ppHead2 , ppHead1);     // dusri list philya list la jodun ali
        *ppHead1 = *ppHead2;                // 2nd become 1st
        *ppHead2 = NULL;                    // 2nd become empty
        return;
    }

// surely both list are present

//    if(iPos == iCount + 1)
//    {
//        ConcatLists(ppHead1 , ppHead2);
//        return;
//    }

    pTemp1 = *ppHead1;
    iCount = 1;
    while(iCount < iPos - 1)
    {
        iCount ++;
        pTemp1 = pTemp1 -> pNext;
    }

    pTemp2 = *ppHead2;
    while(pTemp2 -> pNext != NULL)
        pTemp2 = pTemp2 -> pNext;

    pTemp2 -> pNext = pTemp1 -> pNext;
    pTemp1 -> pNext = *ppHead2;

    *ppHead2 = NULL;
}
