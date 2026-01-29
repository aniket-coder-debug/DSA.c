#include <malloc.h>
#include <stdio.h>
#include "tree_server.h"

int main(void)
{
    struct BST *pRoot = NULL;
    struct BST *pTemp = NULL;

    InsertBST(&pRoot, 100);
    InsertBST(&pRoot, 150);
    InsertBST(&pRoot, 90);
    InsertBST(&pRoot, 120);
    InsertBST(&pRoot, 80);
    InsertBST(&pRoot, 50);
    InsertBST(&pRoot, 140);
    InsertBST(&pRoot, 160);

    Preorder(pRoot);                                                            // 100 90 80 50 150 120 140 160
    printf("\n\n");
    Inorder(pRoot);                                                             // 50 80 90 100 120 140 150 160
    printf("\n\n");
    Postorder(pRoot);                                                           // 50 80 90 140 120 160 150 100
    printf("\n\n");
    Levelorder(pRoot);                                                          // 100 90 150 80 120 160 50 140
    printf("\n\n");

    printf("\nBST count is %d\n", CountBSTsVersion1(pRoot));                  // 8
    printf("\nBST count is %d\n", CountBSTsVersion2(pRoot));                  // 8
    printf("\nLeaf BST count is %d\n", CountLeafBSTs(pRoot));                 // 3
    printf("\nNonLeaf BST count is %d\n", CountNonLeafBSTs(pRoot));           // 5
    printf("\nHeight of tree is %d\n", Height(pRoot));                          // 4
    printf("\nSmallest element is %d\n", SmallestElement(pRoot));               // 50
    printf("\nLargest element is %d\n", LargestElement(pRoot));                 // 160

    pTemp = SearchBSTRecursive(pRoot, 120);
    if(pTemp != NULL)
        printf("\n%d data found\n", pTemp->iData);                              // 120

    pTemp = SearchBSTNonRecursive(pRoot, 120);
    if(pTemp != NULL)
        printf("\n%d data found\n\n", pTemp->iData);                            // 120

    DeleteBST(&pRoot, 50);                                                      // no childs
    Levelorder(pRoot);                                                          // 100 90 150 80 120 160 140
    printf("\n\n");

    DeleteBST(&pRoot, 90);                                                      // single child
    Levelorder(pRoot);                                                          // 100 80 150 120 160 140
    printf("\n\n");

    DeleteBST(&pRoot, 100);                                                     // both childs
    Levelorder(pRoot);                                                          // 120 80 150 140 160
    printf("\n\n");

    if(pRoot != NULL)
    {
        DeleteAll(&pRoot);
        pRoot = NULL;
    }

    return 0;
}

void Preorder(struct BST *pRoot)
{
    if(NULL == pRoot)
        return ;

    printf("%d ", pRoot -> iData);
    Preorder(pRoot -> pLChild);
    Preorder(pRoot -> pRChild);
}

void Inorder(struct BST *pRoot)
{
    if(NULL == pRoot)
        return ;

    Inorder(pRoot -> pLChild);
    printf("%d ", pRoot -> iData);
    Inorder(pRoot -> pRChild);
}

void Postorder(struct BST *pRoot)
{
    if(NULL == pRoot)
        return ;

    Postorder(pRoot -> pLChild);
    Postorder(pRoot -> pRChild);
    printf("%d ", pRoot -> iData);

}

void Levelorder(struct BST *pRoot)
{
    struct node *pQueue = NULL;
    struct BST *pPtr = NULL;

    if(NULL == pRoot)
        return;

    EnQueue(&pQueue , pRoot);

    while(! IsQueueEmpty(pQueue))
    {   
        pPtr = DeQueue(&pQueue);

        printf("%d ",pPtr -> iData);

        if(pPtr -> pLChild != NULL)
            EnQueue(&pQueue , pPtr -> pLChild);

        if(pPtr -> pRChild != NULL)
            EnQueue(&pQueue , pPtr -> pRChild);
    }
}

void DeleteAll(struct BST **ppRoot)
{
    if(NULL == *ppRoot)
        return;

    DeleteAll(&(*ppRoot) -> pLChild);
    DeleteAll(&(*ppRoot) -> pRChild);
    free(*ppRoot);
    *ppRoot = NULL;
}

int CountBSTsVersion1(struct BST *pRoot)
{
    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    iCount ++;

    CountBSTsVersion1(pRoot -> pLChild);
    CountBSTsVersion1(pRoot -> pRChild);

    return iCount;

}

int CountBSTsVersion2(struct BST *pRoot)
{
    if(NULL == pRoot)
        return 0;

    return CountBSTsVersion2(pRoot -> pLChild) + CountBSTsVersion2(pRoot -> pRChild) + 1 ;
}

int CountLeafBSTs(struct BST *pRoot)
{
    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    if(pRoot -> pLChild == NULL && pRoot -> pRChild == NULL)
        iCount++;

    CountLeafBSTs(pRoot -> pLChild);
    CountLeafBSTs(pRoot -> pRChild);

    return iCount;
}

int CountNonLeafBSTs(struct BST *pRoot)
{
    static int iCount = 0;

    if(NULL == pRoot)
        return 0;

    if(pRoot -> pLChild != NULL || pRoot -> pRChild != NULL)
        iCount++;

    CountNonLeafBSTs(pRoot -> pLChild);
    CountNonLeafBSTs(pRoot -> pRChild);

    return iCount;
}

int Height(struct BST *pRoot)
{
    int iLeftHeight;
    int iRightHeight;

    if(NULL == pRoot)
        return 0;

    iLeftHeight = Height(pRoot -> pLChild);
    iRightHeight = Height(pRoot -> pRChild);

    if(iLeftHeight > iRightHeight)
        return iLeftHeight + 1;
    else
        return iRightHeight + 1;
}

int SmallestElement(struct BST *pRoot)
{
    if(NULL == pRoot)
        return 0;

    while(pRoot -> pLChild != NULL)
        pRoot = pRoot -> pLChild;

    return pRoot->iData;
}

int LargestElement(struct BST *pRoot)
{
    if(NULL == pRoot)
        return 0;

    while(pRoot -> pRChild != NULL)
        pRoot = pRoot -> pRChild;

    return pRoot->iData;
}

struct BST* SearchBSTRecursive(struct BST *pRoot, int iKey)
{
    if(NULL == pRoot)
        return NULL;

    if(iKey < pRoot -> iData)
        return SearchBSTRecursive(pRoot -> pLChild , iKey);
    else if(iKey > pRoot -> iData)
        return SearchBSTRecursive(pRoot -> pRChild , iKey);
    else                                                        // mhanjech data found zala
        return pRoot;
}

struct BST* SearchBSTNonRecursive(struct BST *pRoot, int iKey)
{
    while(pRoot != NULL)
    {
        if(iKey < pRoot -> iData)
            pRoot = pRoot -> pLChild;
        else if(iKey > pRoot -> iData)
            pRoot = pRoot -> pRChild;
        else 
            return pRoot;
    }

    return NULL;
}

void InsertBST(struct BST **ppRoot, int iNo)
{
    struct BST *pNewBST = NULL;
    struct BST *pPtr = NULL;
    struct BST *pParent = NULL;

    pPtr = *ppRoot;
    while(pPtr != NULL)
    {
        pParent = pPtr;
        if(iNo < pPtr -> iData)
            pPtr = pPtr -> pLChild;
        else if(iNo > pPtr -> iData)
            pPtr = pPtr -> pRChild;
        else
        {
            printf("\nDuplicate data\n");
            return;
        }
    }

    // khali alyas pParent NULL ch ahe

    pNewBST = (struct BST *) malloc (sizeof(struct BST));
    if(NULL == pNewBST)
    {
        printf("Memory allocation FAILED\n");
        return;
    }

    pNewBST -> iData = iNo;
    pNewBST -> pLChild = pNewBST -> pRChild = NULL;

    if(NULL == pParent)
        *ppRoot = pNewBST;
    else if(iNo < pParent -> iData)
        pParent -> pLChild = pNewBST;
    else
        pParent -> pRChild = pNewBST;
}

void DeleteBST(struct BST **ppRoot, int iKey)
{
    struct BST *pPtr = NULL;
    struct BST *pParent = NULL;
    struct BST *pSuccessor = NULL;
    struct BST *pChild = NULL;

    pPtr = *ppRoot;
    while(pPtr != NULL)
    {
        if(iKey == pPtr -> iData)
            break;

        pParent = pPtr;

        if(iKey < pPtr -> iData)
            pPtr = pPtr -> pLChild;
        else
            pPtr = pPtr -> pRChild;
    }

    // pParent is NULL if Data not Found at root

    if(pPtr -> pLChild != NULL && pPtr -> pRChild != NULL)      // both childs
    {
        pSuccessor = pPtr -> pRChild;
        pParent = pPtr;

        while(pSuccessor -> pLChild != NULL)
        {
            pParent = pSuccessor;
            pSuccessor = pSuccessor -> pLChild;
        }

        pPtr -> iData = pSuccessor -> iData;
        pPtr = pSuccessor;
    }

    if(pPtr -> pLChild != NULL)
        pChild = pPtr -> pLChild;
    else
        pChild = pPtr -> pRChild;

    if(NULL == pParent)
        *ppRoot = pChild;
    else if(iKey < pParent -> iData)
        pParent -> pLChild = pChild;
    else
        pParent -> pRChild = pChild;

    free(pPtr);
}
