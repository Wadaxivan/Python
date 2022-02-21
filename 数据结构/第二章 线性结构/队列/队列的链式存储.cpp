#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ElementType int
#define MAXOP 100
const ElementType ERROR=-1;

typedef struct Node* PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* PtrToQNode;
struct QNode
{
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Front=Q->Rear=NULL;
    Q->MaxSize=MaxSize;
    return Q;
}

void AddQ(Queue Q,ElementType X)
{
    Position RearCell=(Position)malloc(sizeof(struct Node));
    RearCell->Next=NULL;
    RearCell->Data=X;
    if(Q->Rear==NULL)
    {
		Q->Front=RearCell;
        Q->Rear=RearCell;
    }
    else
    {
        Q->Rear->Next=RearCell;
        Q->Rear=RearCell;
    }
	printf("%d Add!\n",RearCell->Data);
}

bool IsEmpty(Queue Q)
{
    return(Q->Front==NULL);
}

ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;
    if(IsEmpty(Q))
    {
        printf("Queue is empty!\n");
        return ERROR;
    }
    else
    {
        FrontCell=Q->Front;
        if(Q->Front==Q->Rear) //在前面if条件判断后，此时Q->Front已经不是NULL
        {
            Q->Front=Q->Rear=NULL;
        }
        else
        {
            Q->Front=Q->Front->Next;
        }
        FrontElem=FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }
}

int main()
{
	Queue Q;
	Q=CreateQueue(MAXOP);
	do
	{
		int option;
		for(int i=1;i<=26;i++)
		{
			printf("=");
		}
		printf("\n1.Add 2.Delete 3.Exit\n");
		printf("Please choose the option: ");
		scanf("%d",&option);
		switch(option) 
		{
			case 1:
				ElementType Temp;
				printf("Please input number:");
				scanf("%d",&Temp);
				AddQ(Q,Temp);
				break;
			case 2:
				Temp=DeleteQ(Q);
				if(Temp!=ERROR)
				{
					printf("%d has been deleted!\n",Temp);
				}
				break;
			case 3:
				printf("Exit!");
				goto End;
			default:
				printf("Illegal input!\n");
				break;
		}
	}while(1);
	End:
		return 0;
}
