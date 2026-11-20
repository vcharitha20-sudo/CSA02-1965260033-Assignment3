#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 256
int own_len(const char s[]){int n=0;while(s[n])n++;return n;}
int own_words(const char s[]){int i,inside=0,n=0;for(i=0;s[i];i++){if(isspace((unsigned char)s[i]))inside=0;else if(!inside){n++;inside=1;}}return n;}
void own_upper(char s[]){int i;for(i=0;s[i];i++)s[i]=(char)toupper((unsigned char)s[i]);}
void own_reverse(char s[]){int i=0,j=own_len(s)-1;char t;while(i<j){t=s[i];s[i]=s[j];s[j]=t;i++;j--;}}
int own_pal(const char s[]){int i=0,j=own_len(s)-1;while(i<j){while(i<j&&!isalpha((unsigned char)s[i]))i++;while(i<j&&!isalpha((unsigned char)s[j]))j--;if(tolower((unsigned char)s[i])!=tolower((unsigned char)s[j]))return 0;i++;j--;}return 1;}
int main(void){char input[SIZE],copy[SIZE];printf("Enter feedback (can be empty): ");if(!fgets(input,sizeof(input),stdin))return 1;input[strcspn(input,"\n")]=0;printf("Own length: %d, library strlen: %lu\n",own_len(input),(unsigned long)strlen(input));printf("Words: %d\n",own_words(input));snprintf(copy,sizeof(copy),"%s",input);own_upper(copy);printf("Uppercase: %s\n",copy);snprintf(copy,sizeof(copy),"%s",input);own_reverse(copy);printf("Reverse: %s\n",copy);printf("Palindrome: %s\n",own_pal(input)?"yes":"no");printf("Library strcmp of copy and original: %d\n",strcmp(copy,input));printf("Extra-space test words: %d\n",own_words(" Hi   there\tfriend! "));printf("Palindrome test: %d\n",own_pal("Madam, I'm Adam"));return 0;}
