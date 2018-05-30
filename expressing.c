
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct expressing
{
	int b;
	char c;
	int num;
}Sign_Num;

int GetPriority(char op1,char op2);
void Infix_Postfix(Sign_Num* Infix,Sign_Num* Postfix,int Max);
int CalculatePostfix(Sign_Num* Postfix,int n);

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
	int Result;
	Result=CalculatePostfix(Postfix,Max-k);
	printf("The calculate result is : %d\n",Result );
	return 0;

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
									break;
								case -1:
									while(GetTop(S)!='('){
										Postfix[j].b=0;
										Postfix[j].c=GetTop(S);
										j++;
										Pop(S);
									}
									Push(S,Infix[i].c);
									break;
								case 1:
									Push(S,Infix[i].c);
									break;
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
						break;
					case -1:
						while(!IsEmpty(S)){
							Postfix[j].b=0;
							Postfix[j].c=GetTop(S);
							j++;
							Pop(S);
						}
						Push(S,Infix[i].c);
						break;
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

int CalculatePostfix(Sign_Num* Postfix,int n){
	Stack0 S;
	S=CreateStack0();
	int i,m;
	for(i=0;i<n;i++){
		if(Postfix[i].b==1){
			Push0(S,Postfix[i].num);
		}else{
			switch(Postfix[i].c){
				case '+':
					m=GetTop0(S);
					Pop0(S);
					m=m+GetTop0(S);
					Pop0(S);
					Push0(S,m);
					break;
				case '-':
					m=GetTop0(S);
					Pop0(S);
					m=GetTop0(S)-m;
					Pop0(S);
					Push0(S,m);
					break;
				case '*':
					m=GetTop0(S);
					Pop0(S);
					m=m*GetTop0(S);
					Pop0(S);
					Push0(S,m);
					break;
				case '/':
					m=GetTop0(S);
					Pop0(S);
					m=GetTop0(S)/m;
					Pop0(S);
					Push0(S,m);
					break;
				default: printf("ERROR!!!\n");
			}
		}
	}
	return GetTop0(S);
}

