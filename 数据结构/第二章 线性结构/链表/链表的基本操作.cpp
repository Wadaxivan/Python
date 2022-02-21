#include<iostream>
#include<memory>
using namespace std;
#define ElementType int
typedef struct LNode* List;
struct LNode
{
	ElementType Data;
	List Next;
};
struct LNode L;
List PrtL;
int ListLenth(List PrtL);
List ListDelete(int K,List PrtL);
List ListFindByNode(int K,List PrtL);
List ListFindByValue(ElementType X,List PrtL);
List ListInsert(ElementType X,int K,List PrtL);
int main()
{
	return 0;	
}
int ListLenth(List PrtL)
{
	List p=PrtL;
	int Lenth=0;
	while(p)
	{
		p=p->Next;
		Lenth++;
	}
	return Lenth;
}
List ListFindByNode(int K,List PrtL)
{
	List p=PrtL;
	int i=1;
	while(p!=NULL&&i<K)
	{
		p=p->Next;
		i++;
	}
	if(i==K)
		return p;
	else 
		return NULL;
}
List ListFindByValue(ElementType X,List PrtL)
{
	List p=PrtL;
	while(p!=NULL&&p->Data!=X)
	{
		p=p->Next;
	}
	return p;
}
List ListInsert(ElementType X,int K,List PrtL)
{
	List p,pr;
	if(K==1)
	{
		pr=(List)malloc(sizeof(struct LNode));
		pr->Data=X;
		pr->Next=PrtL;
		return pr;
	}
	p=ListFindByNode(K-1,PrtL);
	if(p==NULL)
	{
		cout<<"Error!"<<endl;
		return NULL;
	}
	else
	{
		pr=(List)malloc(sizeof(struct LNode));
		pr->Next=p->Next;
		p->Next=pr;
		pr->Data=X;
		return PrtL;
	}
}
List ListDelete(int K,List PrtL)
{
	List p,pr;
	if(K==1)
	{
		pr=PrtL;
		if(PrtL!=NULL)
		{
			PrtL=PrtL->Next;
		}
		else
		{
			return NULL;
		}
		free(pr);
		return PrtL;
	}
	p=ListFindByNode(K-1,PrtL);
	if(p==NULL)
	{
		cout<<"Error!"<<endl;
		return NULL;
	}
	else if(p->Next==NULL)
	{
		cout<<"Error!"<<endl;
		return NULL;		
	}
	else
	{
		pr=p->Next;
		p->Next=pr->Next;
		free(pr);
		return PrtL;
	}
}
