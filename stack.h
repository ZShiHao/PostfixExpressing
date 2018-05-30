
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef  char ElementType;

struct Node0;
typedef struct Node0 *PtrToNode0;
typedef PtrToNode0 Stack0;

/*
 * CreateStack-Create a linked stack,and return the head pointer S.
 */
Stack CreateStack();
/*
 * IsEmpty-Judge if a stack S is empty,if it is return 1,else return 0.
 */
int IsEmpty(Stack S);
/*
 * MakeEmpty-Clear stack S.
 */
void MakeEmpty(Stack S);
/*
 * Push-Push an element into the stack S.
 */
void Push(Stack S,ElementType e);
/*
 * GetTop-Return the top element in the stack S.
 */
ElementType GetTop(Stack S);
/*
 * Pop-Delete the top element.
 */
void Pop(Stack S);


/*
 * CreateStack-Create a linked stack,and return the head pointer S.
 */
Stack0 CreateStack0();
/*
 * IsEmpty-Judge if a stack S is empty,if it is return 1,else return 0.
 */
int IsEmpty0(Stack0 S);
/*
 * MakeEmpty-Clear stack S.
 */
void MakeEmpty0(Stack0 S);
/*
 * Push-Push an element into the stack S.
 */
void Push0(Stack0 S,int e);
/*
 * GetTop-Return the top element in the stack S.
 */
int GetTop0(Stack0 S);
/*
 * Pop-Delete the top element.
 */
void Pop0(Stack0 S);