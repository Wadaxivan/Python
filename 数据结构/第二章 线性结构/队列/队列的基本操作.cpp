#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ElementType int
const ElementType ERROR=-1;

typedef int Position;
typedef struct QNode* PtrToNode;
struct QNode 
{
    ElementType *Data;
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToNode Queue;
int main()
{
    ;
}

Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Data=(ElementType*)malloc(MaxSize*sizeof(ElementType));
    Q->Front=Q->Rear=-1;
    Q->MaxSize=MaxSize;
    return Q;
}

bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%Q->MaxSize==Q->Front);
}

bool AddQ(Queue Q,ElementType X)
{
    if(IsFull(Q))
    {
        printf("Queue is full!");
        return false;
    }
    else
    {
        Q->Rear=(Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear]=X;
        return true;
    }
}

bool IsEmpty(Queue Q)
{
    return(Q->Front==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("Queue is empty!");
        return ERROR;
    }
    else
    {
        Q->Front=(Q->Front+1)%Q->MaxSize;
        return Q->Data[Q->Front];
    }
}


