#include <stdio.h>
#include "my_string.h"
int main(){
    /// 1-MEMCHR test
#if 0
    printf("Hello world!\n");
    unsigned char array[5]={'1','2','3','4','3'};
    const char ch='6';
    char *ptr=memchr(array,ch,5);
    if(ptr)
        printf("%c\n",*ptr);
    else
        printf("Not found\n");
#endif
    /// 2-MEMCMP test
#if 0
    unsigned char* string1="abcdef";
    unsigned char* string2=NULL;
    int ret=memcmp(string1,string2,5);
    if(ret==0)
        printf("str1 is equal to str2");
    else if(ret>0)
        printf("str2 is less than str1");
    else if(ret<0){
        if(ret==-1)
        printf("str1 is less than str2");
        else
            printf("Null error\n");
    }
#endif
    /// 3-MEMCPY test
#if 0
    unsigned char* string1;
    const unsigned char* string2="abcd";
    memccpy(string1,string2,4);
    printf("%s\n",string1);
#endif
    /// 4-MEMMOVE test
#if 0
    unsigned char string1[16]="rtyui";
    const unsigned char* string2="ab";
    unsigned char* check=memmove(string1,string2,2);
    if(check)
        printf("%s\n",string1);
    else
        printf("NULL error!!!\n");
#endif
    /// 5-MEMSET test
#if 0
    unsigned char str[15]="abcdefghij";
    unsigned char* check=memset(str,'a',10);
    if(check)
        printf("%s\n",str);
    else
        printf("NULL error!!!\n");
#endif
    /// 6-STRCAT test
#if 0
    unsigned char str1[50]="aya";
    unsigned char str2[50]="farid";
    strcat(str1,str2);
    printf("%s",str1);
#endif
    /// 7-STRNCAT test
#if 0
    unsigned char str1[50]="aya ";
    unsigned char str2[50]="farid abd-alkarim";
    strncat(str1,str2,20);
    printf("%s",str1);
#endif
    /// 8-STRCHR test
#if 0
    char *str="aya farid";
    char * ret=strchr(str,'k');
    if(ret)
        printf("%c",*ret);
    else
        printf("NOT found");
#endif
    /// 9-STRCMP test
#if 0
    char *str1="abcdef";
    char *str2="ABCDEF";
    int chek;
    chek=strcmp(str1,str2);
    if(chek==0){
        printf("str1 is equal to str2\n");
    }else if(chek<0){
        printf("str1 is less than str2\n");
    }else if(chek>0){
        printf("str2 is less than str1\n");
    }
#endif
    /// 10-STRNCMP test
#if 0
    char *str1="abcdef";
    char *str2="abcDEF";
    int chek;
    chek=strncmp(str1,str2,3);
    if(chek==0){
        printf("str1 is equal to str2\n");
    }else if(chek<0){
        printf("str1 is less than str2\n");
    }else if(chek>0){
        printf("str2 is less than str1\n");
    }
#endif
    /// 11-STRCOLL test
#if 1
    char *str1="abcdef";
    char *str2="ABCDEF";
    int chek;
    chek=strcoll(str1,str2);
    if(chek==0){
        printf("str1 is equal to str2\n");
    }else if(chek<0){
        printf("str1 is less than str2\n");
    }else if(chek>0){
        printf("str2 is less than str1\n");
    }
#endif
    return 0;
}
