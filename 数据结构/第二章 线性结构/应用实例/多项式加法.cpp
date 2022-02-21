#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ElementType int
const ElementType ERROR=-1;
struct PolyNode
{
    int coef; //系数
    int expon; //指数
    struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;
int Compare(int e1,int e2)
{
    if(e1>e2)
        return 1;
    else if(e1<e2)
        return -1;
    else
        return 0;
}

void Attach(int coef,int expon,Polynomial* PtrRear)
{
    /*想要在函数内部修改指针的指向，需要传进来指针的地址*/
    Polynomial P;

    /*申请新节点，并赋予初值*/
    P=(Polynomial)malloc(sizeof(struct PolyNode));
    P->coef=coef;
    P->expon=expon;
    P->link=NULL;

    /*将表达式尾项接入P后面*/
    (*PtrRear)->link=P;
    *PtrRear=P;
}

Polynomial PolyAdd(Polynomial P1,Polynomial P2)
{
    Polynomial front,rear,temp;
    int sum;
    rear=(Polynomial)malloc(sizeof(struct PolyNode));
    front=rear;
    while(P1&&P2)
    {
        switch(Compare(P1->expon,P2->expon))
        {
            case 1:
                Attach(P1->coef,P1->expon,&rear);
                P1=P1->link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&rear);
                P2=P2->link;
                break;
            case 0:
                sum=P1->coef+P2->coef;
                if(sum) /*判断相加是不是0，是0则无这一项*/
                {
                    Attach(sum,P1->expon,&rear);
                }
                P1=P1->link;
                P2=P2->link;
                break;
        }
        for(;P1;P1=P1->link)
        {
            Attach(P1->coef,P1->expon,&rear);
        }
        for(;P2;P2=P2->link)
        {
            Attach(P2->coef,P2->expon,&rear);
        }
        rear->link=NULL;
        temp=front;
        front=front->link;
        free(temp);
        return front;
    }


}