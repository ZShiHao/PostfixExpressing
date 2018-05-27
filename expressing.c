
#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef  char ElementType;

struct Node{
	ElementType elem;
	struct Node *Next;
}Stack_Node;

typedef struct expressing
{
	int b;
	char c;
	int num;
}Sign_Num;

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
int GetPriority(char op1,char op2);
void Infix_Postfix(Sign_Num* Infix,Sign_Num* Postfix,int Max);

int main(){
	int Max;
	printf("Please input the max number of the infix expressing:\n");\
	scanf("%d",&Max);
	Sign_Num Infix[Max];
	int i,k;
	printf("If the input is a number please input (1,0,x).\n");
	printf("If the input is a sign please input (0,x,0):\n");
	for(i=0;i<Max;i++){
		scanf("%d,%c,%d",&Infix[i].b,&Infix[i].c,&Infix[i].num);
		if(Infix[i].c=='(') k+=2;
	}
	Sign_Num Postfix[Max-k];
	Infix_Postfix(Infix,Postfix,Max);
	printf("The infix expressing is : ");
	for(i=0;i<Max;i++){
		if(Infix[i].b==1){
			printf("%d",Infix[i].num );
		}
		else{
			printf("%c",Infix[i].c );
		}
	}
	printf("\n");
	printf("The postfix expressing is : ");
	for(i=0;i<Max-k;i++){
		if(Postfix[i].b==1){
			printf("%d",Postfix[i].num );
		}else{
			printf("%c",Postfix[i].c );
		}
	}
	printf("\n");
	return 0;

}

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

int GetPriority(char op1,char op2){
	if((op1=='+'||op1=='-')&&(op2=='+'||op2=='-')) return 0;
	else if((op1=='*'||op1=='/')&&(op2=='*'||op2=='/')) return 0;
	else if((op1=='+'||op1=='-')&&(op2=='*'||op2=='/')) return -1;
	else if((op1=='*'||op1=='/')&&(op2=='+'||op2=='-')) return 1;
	else return 2;
}

void Infix_Postfix(Sign_Num* Infix,Sign_Num* Postfix,int Max){
	Stack S;
	S=CreateStack();
	int i,k,j=0;
	for(i=0;i<Max;i++){
		if(Infix[i].c>=40&&Infix[i].c<=47){
			if(IsEmpty(S)) Push(S,Infix[i].c);
			else if(Infix[i].c=='('){
				Push(S,Infix[i].c);
				do{
					i++;
					if(Infix[i].c==')'){
						do{
							Postfix[j].b=0;
							Postfix[j].c=GetTop(S);
							printf("%c\n",GetTop(S));
							j++;
							Pop(S);
							if(GetTop(S)=='('){
								Pop(S);
								break;
							}
						}while(1);
						break;
					}else{
						if(Infix[i].c>=40&&Infix[i].c<=47){
							switch(GetPriority(Infix[i].c,GetTop(S))){
								case 0:
									Postfix[j].b=0;
									Postfix[j].c=GetTop(S);
									j++;
									Pop(S);
									Push(S,Infix[i].c);
								case -1:
									while(GetTop(S)!='('){
										Postfix[j].b=0;
										Postfix[j].c=GetTop(S);
										j++;
										Pop(S);
									}
									Push(S,Infix[i].c);
								case 1:Push(S,Infix[i].c);
								default:Push(S,Infix[i].c);
							}
						}else{
								Postfix[j]=Infix[i];
								j++;
						}

					}
				}while(1);
			}else{
				switch(GetPriority(Infix[i].c,GetTop(S))){
					case 0:
						Postfix[j].b=0;
						Postfix[j].c=GetTop(S);
						j++;
						Pop(S);
						Push(S,Infix[i].c);
					case -1:
						while(!IsEmpty(S)){
							Postfix[j].b=0;
							Postfix[j].c=GetTop(S);
							j++;
							Pop(S);
						}
					case 1:Push(S,Infix[i].c);
				}
			}
	
		}
		else{
			Postfix[j]=Infix[i];
			j++;
		}
	}
	while(!IsEmpty(S)){
		Postfix[j].b=0;
		Postfix[j].c=GetTop(S);
		j++;
		Pop(S);
	}
}

