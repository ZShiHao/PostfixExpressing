#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Node0{
	int elem;
	struct Node0 *Next;
}Stack_Node0;

Stack0 CreateStack0(){
	Stack0 S;
	S=(Stack0)malloc(sizeof(Stack_Node0));
	if(S==NULL) printf("ERROR: Out of space!!!\n");
	S->Next=NULL;
	MakeEmpty0(S);
	return S;
}

int IsEmpty0(Stack0 S){
	return S->Next==NULL;
}

void Push0(Stack0 S,int e){
	PtrToNode0 temp;
	temp=(Stack0)malloc(sizeof(Stack_Node0));
	if(temp==NULL) printf("ERROR: Out of space!!!\n");
	else{
		temp->elem=e;
		temp->Next=S->Next;
		S->Next=temp;
	}
}

int GetTop0(Stack0 S){
	if(IsEmpty0(S)){
		printf("ERROR: Empty Stack.\n");
		return 0;
	}
	else{
		return S->Next->elem;
	}
}

void Pop0(Stack0 S){
	PtrToNode0 temp;
	if(IsEmpty0(S)) printf("ERROR: Empty Stack.\n");
	else{
		temp=S->Next->Next;
		free(S->Next);
		S->Next=temp;
	}
}

void MakeEmpty0(Stack0 S){
	if(S==NULL) printf("Please create stack first.\n");
	else{
		while(!IsEmpty0(S)){
			Pop0(S);
		}
	}
}

