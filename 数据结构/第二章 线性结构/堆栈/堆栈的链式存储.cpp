#include<iostream>
#include<memory>
using namespace std;
typedef struct SNode* PtrToSNode;
typedef int ElementType;
struct SNode
{
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode StackLink;
StackLink CreateStack();
bool IsEmpty(StackLink S);
void Push(StackLink S,ElementType X);
ElementType Pop(StackLink S);
const ElementType ERROR=-1;
int main()
{
	;
}
StackLink CreateStack()
{
	StackLink S;
	S=(SNode*)malloc(sizeof(SNode));
	S->Next=NULL;
	return S;
}
bool IsEmpty(StackLink S)
{
	return(S->Next==NULL);
}
void Push(StackLink S,ElementType X)
{
	StackLink PtrTemp;
	PtrTemp=(SNode*)malloc(sizeof(SNode));
	PtrTemp->Next=S->Next;
	PtrTemp->Data=X;
	S->Next=PtrTemp;
}
ElementType Pop(StackLink S)
{
	if(IsEmpty(S))
	{
		cout<<"The StackLink is empty!";
		return ERROR;
	}
	else
	{
		StackLink PtrTemp=S->Next;
		ElementType TempData;
		S->Next=PtrTemp->Next;
		TempData=PtrTemp->Data;
		free(PtrTemp);
		return TempData;
	}
}


