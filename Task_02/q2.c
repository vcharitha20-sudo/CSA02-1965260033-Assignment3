#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000
static int original[MAX],work[MAX];
void bubble(int a[],int n,long long *cmp,long long *moves){int i,j,tmp,changed;*cmp=*moves=0;for(i=0;i<n-1;i++){changed=0;for(j=0;j<n-1-i;j++){(*cmp)++;if(a[j]>a[j+1]){tmp=a[j];a[j]=a[j+1];a[j+1]=tmp;(*moves)++;changed=1;}}if(!changed)break;}}
void selection(int a[],int n,long long *cmp,long long *moves){int i,j,m,tmp;*cmp=*moves=0;for(i=0;i<n-1;i++){m=i;for(j=i+1;j<n;j++){(*cmp)++;if(a[j]<a[m])m=j;}if(m!=i){tmp=a[i];a[i]=a[m];a[m]=tmp;(*moves)++;}}}
void insertion(int a[],int n,long long *cmp,long long *moves){int i,j,key;*cmp=*moves=0;for(i=1;i<n;i++){key=a[i];j=i-1;while(j>=0){(*cmp)++;if(a[j]<=key)break;a[j+1]=a[j];(*moves)++;j--;}a[j+1]=key;}}
int main(void){int sizes[]={6,100,1000,10000},n,t,order,i,alg,tmp;long long c,m;clock_t begin;double sec;const char *orders[]={"sorted","nearly sorted","reverse","random"};const char *names[]={"bubble","selection","insertion"};srand(42);for(t=0;t<4;t++){n=sizes[t];for(order=0;order<4;order++){for(i=0;i<n;i++)original[i]=i+1000;if(order==1){if(n>2){tmp=original[n-1];original[n-1]=original[n-2];original[n-2]=tmp;}}else if(order==2){for(i=0;i<n;i++)original[i]=n-i+1000;}else if(order==3){for(i=0;i<n;i++)original[i]=rand()%20000;}printf("n=%d, %s\n",n,orders[order]);for(alg=0;alg<3;alg++){memcpy(work,original,(size_t)n*sizeof(int));begin=clock();if(alg==0)bubble(work,n,&c,&m);else if(alg==1)selection(work,n,&c,&m);else insertion(work,n,&c,&m);sec=(double)(clock()-begin)/CLOCKS_PER_SEC;printf("  %-9s comparisons=%lld swaps/shifts=%lld time=%.4fs\n",names[alg],c,m,sec);for(i=1;i<n;i++)if(work[i]<work[i-1]){printf(" SORT ERROR");break;}printf("\n");}}}return 0;}
