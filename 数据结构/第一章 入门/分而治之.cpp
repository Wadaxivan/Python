#include<iostream>
using namespace std;
#define Max(x,y,z) x>y?(x>z?x:z):(y>z?y:z)
int MaxSubseqSum3(int A[],int N);
int DivideAndConquer(int A[],int left,int right);
int main()
{
	int N;
	cout<<"Please input the total number:";
	cin>>N;
	cout<<"PLease input the number:";
	int *A=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
	{
		scanf("%d",A+i);
	}
	int result=0;
	result=MaxSubseqSum3(A,N);
	cout<<result;
	return 0;
}
int DivideAndConquer(int A[],int left,int right)
{
	if(left==right)
	{
		return A[left]>0?A[left]:0;
	}
	int MaxLeft,MaxRight;
	int LeftBoundary=0,RightBoundary=0;
	int MaxLeftBoundary=0,MaxRightBoundary=0;
	int Center=left+(right-left)/2;
	MaxLeft=DivideAndConquer(A,left,Center);
	MaxRight=DivideAndConquer(A,Center+1,right);
	for(int i=Center;i>=left;i--)
	{
		LeftBoundary+=A[i];
		if(LeftBoundary>MaxLeftBoundary)
		{
			MaxLeftBoundary=LeftBoundary;
		}
	}
	for(int j=Center+1;j<=right;j++)
	{
		RightBoundary+=A[j];
		if(RightBoundary>MaxRightBoundary)
		{
			MaxRightBoundary=RightBoundary;
		}
	}
	return Max(MaxLeft,MaxRight,(MaxLeftBoundary+MaxRightBoundary));
}
int MaxSubseqSum3(int A[],int N)
{
	return DivideAndConquer(A,0,N-1);
}
