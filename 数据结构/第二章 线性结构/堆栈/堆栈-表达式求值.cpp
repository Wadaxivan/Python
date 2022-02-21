#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define ZERO 1e-10
#define MAXOP 100
#define INFINITY 1e9
typedef double ElementType;
typedef enum{num,opr,end} Type;
const ElementType ERROR=-1;

typedef int Position;
struct SNode
{
    ElementType *Data;
    Position Top;
    int MaxSize;
    /* data */
};
typedef struct SNode* PtrToSNode;
typedef PtrToSNode Stack;

Stack CreateStack(int Max)
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->Data=(ElementType*)malloc(Max*sizeof(ElementType));
    S->Top=-1;
    S->MaxSize=Max;
    return S;
}

bool IsFull(Stack S)
{
    return(S->Top==S->MaxSize-1);
}

bool Push(Stack S,ElementType X)
{
    if(IsFull(S))
    {
        printf("The stack is full!");
        return false;
    }
    else
    {
        S->Data[++(S->Top)]=X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return(S->Top==-1);
}

ElementType Pop(Stack S)
{
    if(IsEmpty(S))
    {
        printf("The stack is empty!");
        return ERROR;
    }
    else
    {
        return (S->Data[(S->Top)--]);
    }
}

Type GetOp(char *Expr,int *start,char *str)
{
    int i=0;
    while((str[0]=Expr[(*start)++])==' ');
    while(str[i]!=' '&&str[i]!='\0')
    {
        str[++i]=Expr[(*start)++];
    }
    if(str[i]=='\0')
    {
        (*start)--;
    }
    str[i]='\0';
    if(i==0)
    {
        return end;
    }
    else if(isdigit(str[0])||isdigit(str[1]))
    {
        return num;
    }
    else
    {
        return opr;
    }
}

ElementType PostfixExp(char *Expr)
{
    Stack S;
    Type T;
    ElementType Op1,Op2;
    char str[MAXOP];
    int start=0;
    S=CreateStack(MAXOP);
    Op1=Op2=0;
    while((T=GetOp(Expr,&start,str))!=end)
    {
        if(T==num)
        {
            Push(S,atof(str));
        }
        else
        {
            if(!IsEmpty(S))
            {
                Op2=Pop(S);
            }
            else
            {
                Op2=INFINITY;
            }
            if(!IsEmpty(S))
            {
                Op1=Pop(S);
            }
            else
            {
                Op2=INFINITY;
            }
            switch(str[0])
            {
                case '+':
                    Push(S,Op1+Op2);
                    break;
                case '-':
                    Push(S,Op1-Op2);
                    break;
                case '*':
                    Push(S,Op1*Op2);
                    break;
                case '/':
                    if(fabs(Op2)>ZERO)
                        Push(S,Op1/Op2);
                    else
                    {
                        printf("ERROR!The divident is ZERO!");
                        Op2=INFINITY;
                    }
                    break;
                break;
            default:
                printf("ERROR!Unknown operation:%s\n!",str);
                Op2=INFINITY;
                break;
            }
            if(Op2>=INFINITY)
            {
                break;
            }
        }
    }
    if(Op2<INFINITY)
    {
        if(!IsEmpty(S))
        {
            Op2=Pop(S);
        }
        else
        {
            Op2=INFINITY;
        }
    }
    free(S);
    return Op2;
}

int main()
{
    char Expr[MAXOP];
    ElementType f;
    gets_s(Expr);
    f=PostfixExp(Expr);
    if(f<INFINITY)
    {
        printf("%.4f\n",f);
    }
    else
    {
        printf("ERROR!\n");
    }
    return 0;
}
