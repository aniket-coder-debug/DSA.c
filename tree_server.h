#define MAX 25

struct BST
{
    struct BST *pLChild;
    int iData;
    struct BST *pRChild;
};

void Preorder(struct BST *);
void Inorder(struct BST *);
void Postorder(struct BST *);
void Levelorder(struct BST *);

void DeleteAll(struct BST **);
int CountBSTsVersion1(struct BST *);
int CountBSTsVersion2(struct BST *);
int CountLeafBSTs(struct BST *);
int CountNonLeafBSTs(struct BST *);
int LargestElement(struct BST *);
int SmallestElement(struct BST *);
int Height(struct BST *);

struct BST* SearchBSTRecursive(struct BST *, int);
struct BST* SearchBSTNonRecursive(struct BST *, int);

void InsertBST(struct BST **, int);
void DeleteBST(struct BST **, int);

struct node
{
    struct BST *iData;
    struct node *pNext;
};

void EnQueue(struct node ** , struct BST*);
struct BST* DeQueue(struct node **);
int IsQueueFull(struct node *);
int IsQueueEmpty(struct node *);
int CountNodes(struct node *);
