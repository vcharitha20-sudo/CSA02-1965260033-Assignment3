#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define D 38
#define M 12
#define LARGE 2000
static double rain[D][M];
static int matrix[LARGE][LARGE];
static volatile long long sink;
void totals(const double a[D][M],double out[D]){int i,j;for(i=0;i<D;i++){out[i]=0;for(j=0;j<M;j++)out[i]+=a[i][j];}}
void monthly(const double a[D][M],double out[M]){int i,j;for(j=0;j<M;j++){out[j]=0;for(i=0;i<D;i++)out[j]+=a[i][j];out[j]/=D;}}
void maximum(const double a[D][M],int *di,int *mo){int i,j;*di=*mo=0;for(i=0;i<D;i++)for(j=0;j<M;j++)if(a[i][j]>a[*di][*mo]){*di=i;*mo=j;}}
void deficient(const double total[D]){int i,count=0;double sum=0,average;for(i=0;i<D;i++)sum+=total[i];average=sum/D;printf("State annual average: %.2f mm\n",average);for(i=0;i<D;i++)if(total[i]<0.6*average){printf("Deficient district %d: %.2f mm\n",i+1,total[i]);count++;}if(!count)puts("No deficient districts");}
int main(void){double total[D],avg[M];int i,j,di,mo;clock_t start;double rowtime,coltime;for(i=0;i<D;i++)for(j=0;j<M;j++)rain[i][j]=50+(i*17+j*13)%180;if(D>2)for(j=0;j<M;j++)rain[2][j]=10;totals(rain,total);monthly(rain,avg);maximum(rain,&di,&mo);printf("Annual totals (district 1..38):\n");for(i=0;i<D;i++)printf("%d: %.1f\n",i+1,total[i]);printf("Monthly state averages:\n");for(j=0;j<M;j++)printf("Month %d: %.2f\n",j+1,avg[j]);printf("Wettest: district %d, month %d, %.1f mm\n",di+1,mo+1,rain[di][mo]);deficient(total);for(i=0;i<LARGE;i++)for(j=0;j<LARGE;j++)matrix[i][j]=(i+j)%100;start=clock();for(i=0;i<LARGE;i++)for(j=0;j<LARGE;j++)sink+=matrix[i][j];rowtime=(double)(clock()-start)/CLOCKS_PER_SEC;start=clock();for(j=0;j<LARGE;j++)for(i=0;i<LARGE;i++)sink+=matrix[i][j];coltime=(double)(clock()-start)/CLOCKS_PER_SEC;printf("Traversal 2000x2000 row %.4fs, column %.4fs\n",rowtime,coltime);return 0;}
