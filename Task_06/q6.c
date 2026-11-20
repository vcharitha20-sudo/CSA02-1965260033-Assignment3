#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 500
#define LEN 30
static char names[MAX][LEN];
int compare_ci(const char *a,const char *b){while(*a&&*b){int x=tolower((unsigned char)*a),y=tolower((unsigned char)*b);if(x!=y)return x-y;a++;b++;}return tolower((unsigned char)*a)-tolower((unsigned char)*b);}
void trim(char s[]){size_t n=strlen(s);if(n&&s[n-1]=='\n')s[n-1]=0;}
int search(char a[][LEN],int n,const char *key,int *comparisons){int lo=0,hi=n-1;*comparisons=0;while(lo<=hi){int mid=lo+(hi-lo)/2,c=strcmp(a[mid],key);(*comparisons)++;if(c==0)return mid;if(c<0)lo=mid+1;else hi=mid-1;}return -1;}
int main(void){int n,i,j,cmp=0,copies=0,steps,pos;char tmp[LEN],key[LEN],line[64];printf("How many residents (1-500)? ");if(!fgets(line,sizeof(line),stdin)||sscanf(line,"%d",&n)!=1||n<1||n>MAX){puts("Invalid count");return 1;}for(i=0;i<n;i++){printf("Name %d (max 29 chars): ",i+1);if(!fgets(line,sizeof(line),stdin))return 1;trim(line);if(strlen(line)>=LEN){puts("Name too long (max 29 characters)");return 1;}strcpy(names[i],line);}for(i=1;i<n;i++){strcpy(tmp,names[i]);copies++;j=i-1;while(j>=0){cmp++;if(strcmp(names[j],tmp)<=0)break;strcpy(names[j+1],names[j]);copies++;j--;}strcpy(names[j+1],tmp);copies++;}printf("\nSorted directory:\n");for(i=0;i<n;i++)printf("%s\n",names[i]);printf("strcmp calls: %d, string copies: %d\n",cmp,copies);puts("Duplicates:");j=0;for(i=1;i<n;i++)if(strcmp(names[i],names[i-1])==0){printf("%s\n",names[i]);j++;}if(!j)puts("None");printf("Search exact name: ");if(!fgets(key,sizeof(key),stdin))return 1;trim(key);pos=search(names,n,key,&steps);printf("Search index: %d, comparisons: %d\n",pos,steps);printf("Case-insensitive example Apple vs apple: %d\n",compare_ci("Apple","apple"));return 0;}
