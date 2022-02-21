#include<iostream>
using namespace std;
#define ELementType int
const int MaxSize=100;
const ELementType ERROR=-1;
struct SNode
{
	ELementType Data[MaxSize];
	int top1;
	int top2;
};
typedef SNode* PrtToSNode;
typedef PrtToSNode Stack;
bool Push(Stack S,ELementType X,int Tag);
ELementType Pop(Stack S,ELementType X,int Tag);
int main()
{
	;
}
bool Push(Stack S,ELementType X,int Tag)
{
	if((S->top2-S->top1==1))
	{
		cout<<"The Stack is full!";
		return false;
	}
	else
	{
		if(Tag==1)
		{
			S->Data[++(S->top1)]=X;
		}	
		else
		{
			S->Data[--(S->top2)]=X;
		}
		return true;
	}
}
ELementType Pop(Stack S,int Tag)
{
	if(Tag==1)
	{
		if(S->top1==-1)
		{
			cout<<"The Stack is empty!";
			return ERROR;
		}
		else
		{
			return S->Data[(S->top1)--];
		}
	}
	else
	{
		if(S->top2==MaxSize)
		{
			cout<<"The Stack is empty";
			return ERROR;
		}
		else
		{
			return S->Data[(S->top2)++];
		}
	}
}

