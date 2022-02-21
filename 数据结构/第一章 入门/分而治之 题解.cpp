#include<stdio.h>
#include<stdlib.h>
int max3(int a, int b, int c);
int divideandconquer(int a[] , int left ,int right);
int maxsubseqsum(int a[], int n);
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i); 
	printf("%d",maxsubseqsum(a,n));
	return 0;
}
int max3(int a, int b, int c)
{
	return a>c?a>b?a:b:c>b?c:b; 
}
int divideandconquer(int a[] , int left ,int right)
{
	int maxleft,maxright;//存放左右子问题的解
	int maxleftbordersum=0,maxrightbordersum=0;//存放跨分界线的结果
	int leftbordersum=0,rightbordersum=0;
	int center,i;
	
	if(left==right)
	{
		return a[left]>0?a[left]:0;
	}
	
	center=left+(right-left)/2;
	maxleft = divideandconquer(a,left,center) ;
	maxright = divideandconquer(a,center+1,right);
	for(i=center;i>=left;i--)
	{
		leftbordersum+=a[i];
		if(leftbordersum>maxleftbordersum)
			maxleftbordersum=leftbordersum;
	}
	
	for(i=center+1;i<=right;i++)
	{
		rightbordersum+=a[i];
		if(rightbordersum>maxrightbordersum)
			maxrightbordersum=rightbordersum;
	}
	
	return max3(maxleft,maxright,maxrightbordersum + maxleftbordersum);
}
int maxsubseqsum(int a[], int n)
{
	return divideandconquer(a,0,n-1);
}

