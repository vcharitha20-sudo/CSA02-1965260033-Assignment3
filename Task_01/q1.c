#include <stdio.h>
#define MAX 100000
static int a[MAX];
int linear(const int x[],int n,int key,int *steps){int i;*steps=0;for(i=0;i<n;i++){(*steps)++;if(x[i]==key)return i;}return -1;}
int binary(const int x[],int n,int key,int *steps){int lo=0,hi=n-1;*steps=0;while(lo<=hi){int mid=lo+(hi-lo)/2;(*steps)++;if(x[mid]==key)return mid;if(x[mid]<key)lo=mid+1;else hi=mid-1;}return -1;}
int main(void){int sizes[]={10,1000,10000,100000},t,j,n,key,steps,pos;for(t=0;t<4;t++){n=sizes[t];for(j=0;j<n;j++)a[j]=1021+j*3;printf("\nCatalogue size %d\n",n);for(j=0;j<4;j++){key=(j==0?a[0]:j==1?a[n/2]:j==2?a[n-1]:a[n-1]+1);pos=linear(a,n,key,&steps);printf("Linear key %d: index %d, comparisons %d\n",key,pos,steps);pos=binary(a,n,key,&steps);printf("Binary key %d: index %d, comparisons %d\n",key,pos,steps);}}return 0;}
