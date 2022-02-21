#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

#define ZERO 1e-10
#define MAXOP 100
#define MAXMATRIXSIZE 100
#define MAXSTACKSIZE 100

struct Offsets
{
    short int Vert;
    short int Horiz;
};
struct MazePosition
{
    short int Row;
    short int Col;
    short int Dir;
};
typedef struct MazePosition ElementType;

typedef int Position;
struct SNode
{
    ElementType P[MAXSTACKSIZE];
    Position Top;
    int MaxSize;
};
typedef struct SNode* PtrToSNode;
typedef PtrToSNode Stack;
const ElementType ERROR={-1,-1,-1};
int Mark[MAXMATRIXSIZE][MAXMATRIXSIZE];
int Maze[MAXMATRIXSIZE][MAXMATRIXSIZE];

Stack CreateStack(int Max)
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
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
        S->P[++(S->Top)]=X;
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
        return (S->P[(S->Top)--]);
    }
}

void Path(int Maze[][ MAXMATRIXSIZE],int EXITROW,int EXITCOL)
{
    struct Offsets Move[8]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    Stack S;
    ElementType P;
    short int Row,Col,NextRow,NextCol,Dir;
    bool Found=false;
    S=CreateStack(MAXSTACKSIZE);
    Mark[EXITROW][EXITCOL]=1;
    P.Row=EXITROW;
    P.Col=EXITCOL;
    P.Dir=0;
    Push(S,P);

    while(!IsEmpty(S)&&!Found)
    {
        P=Pop(S);
        Row=P.Row;
        Col=P.Col;
        Dir=P.Dir;
        while(Dir<8&&!Found)
        {
            NextRow=Row+Move[Dir].Vert;
            NextCol=Col+Move[Dir].Horiz;
            if(NextCol==1&&NextRow==1)
            {
                Found=true;
            }
            else
            {
                if(!Maze[NextRow][NextCol]&&!Mark[NextRow][NextCol])
                {
                    Mark[NextRow][NextCol]=1;
                    P.Row=Row;
                    P.Col=Col;
                    P.Dir=Dir+1;
                    Push(S,P);
                    Row=NextRow;
                    Col=NextCol;
                    Dir=0;
                }
                else
                {
                    Dir++;
                }
            }
        }
    }
    if(Found)
    {
        printf("查找路径如下\n");
        printf("行 列\n");
        printf("%2d %2d\n",1,1);
        printf("%2d %2d\n",Row,Col);
        while(!IsEmpty(S))
        {
            P=Pop(S);
            printf("%2d %2d\n",P.Row,P.Col);
        }
    }
    else
    {
        printf("该迷宫无解!\n");
    }
}
int main()
{
    int Row,Col,ExitRow,ExitCol;
    printf("Please input the Col and Row of martix.\n");
    printf("Row:");
    scanf("%d",&Row);
    printf("Col:");
    scanf("%d",&Col);
    printf("Please input the out.\n");
    printf("Row:");
    scanf("%d",&ExitRow);
    printf("Col:");
    scanf("%d",&ExitCol);
    for(int i=0;i<=Row+1;i++)
    {
        if(i==0||i==Row+1)
        {
            for(int j=0;j<=Col+1;j++)
            {
                Maze[i][j]=1;
            }
        }
        else
        {
            for(int j=1;j<=Col;j++)
            {
                int Temp;
                scanf("%1d",&Temp);
                Maze[i][j]=Temp;
            }
               Maze[i][0]=Maze[i][Col+1]=1;
        }
    }
    Path(Maze,ExitRow,ExitCol);
    return 0;
}
