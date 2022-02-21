#include<iostream>
using namespace std;
int MaxSubseqSum4(int A[],int N);
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
	result=MaxSubseqSum4(A,N);
	cout<<result;
	return 0;
}
int MaxSubseqSum4(int A[],int N)
{
	int ThisSum=0,MaxSum=0;
	for(int i=0;i<N;i++)
	{
		ThisSum+=A[i];
		if(ThisSum>MaxSum)
		{
			MaxSum=ThisSum;
		}
		else if(ThisSum<0)
		{
			ThisSum=0;
		}
	}
	return MaxSum;
}
