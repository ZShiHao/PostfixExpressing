#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct Node{
	ElementType elem;
	struct Node *Next;
}Stack_Node;

Stack CreateStack(){
	Stack S;
	S=(Stack)malloc(sizeof(Stack_Node));
	if(S==NULL) printf("ERROR: Out of space!!!\n");
	S->Next=NULL;
	MakeEmpty(S);
	return S;
}

int IsEmpty(Stack S){
	return S->Next==NULL;
}

void Push(Stack S,ElementType e){
	PtrToNode temp;
	temp=(Stack)malloc(sizeof(Stack_Node));
	if(temp==NULL) printf("ERROR: Out of space!!!\n");
	else{
		temp->elem=e;
		temp->Next=S->Next;
		S->Next=temp;
	}
}

ElementType GetTop(Stack S){
	if(IsEmpty(S)){
		printf("ERROR: Empty Stack.\n");
		return 0;
	}
	else{
		return S->Next->elem;
	}
}

void Pop(Stack S){
	PtrToNode temp;
	if(IsEmpty(S)) printf("ERROR: Empty Stack.\n");
	else{
		temp=S->Next->Next;
		free(S->Next);
		S->Next=temp;
	}
}

void MakeEmpty(Stack S){
	if(S==NULL) printf("Please create stack first.\n");
	else{
		while(!IsEmpty(S)){
			Pop(S);
		}
	}
}

