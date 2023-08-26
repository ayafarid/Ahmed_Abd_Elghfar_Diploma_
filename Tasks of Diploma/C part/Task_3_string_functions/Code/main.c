#include <stdio.h>
#include <errno.h>
#include "my_string.h"
int main(){
    /// 1-MEMCHR test
#if 0
    unsigned char array[5]={'1','2','3','4','3'};
    const char ch='3';
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
    unsigned char string1[50];
    const unsigned char* string2="abcd";
    memcpy(string1,string2,4);
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
#if 0
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
    /// 12-STRCPY test
#if 0
    char string1[50];
    const char* string2="abcd";
    strcpy(string1,string2);
    printf("%s\n",string1);
#endif
    /// 13-STRCPY test
#if 0
    char string1[50];
    const char* string2="aya farid abd-alkarim";
    strncpy(string1,string2,strlen(string2));
    printf("%s\n",string1);
#endif
    /// 14-STRCSPN test
#if 0
    int len;
    const char str1[] = "ABCDEF4960910";
    const char str2[] = "013";

    len = strcspn(str1, str2);

    printf("First matched character is at %d\n", len);
#endif
    /// 15-STRERROR test
#if 0
    FILE *fp;
    fp = fopen("file.txt","r");
    if( fp == NULL )
    {
        printf("Error: %s\n", strerror(errno));
    }
#endif
    /// 16-STRLEN test
#if 0
    const char * str="aya farid abd-alkrim";
    printf("Length = %d\n",strlen(str));
#endif
    /// 17-STRPBRK test
#if 0
   const char str1[] = "abcde2fghi3jk4l";
   const char str2[] = "g34";
   char *ret;

   ret = strpbrk(str1, str2);
   if(ret) {
      printf("First matching character: %c\n", *ret);
   } else {
      printf("Character not found");
   }
#endif
    /// 18-STRRCHR test
#if 0
    const char str[] = "https://www.tutorialspoint.com";
    const char ch = '.';
    char * ret=strrchr(str, ch);

    printf("String after |%c| is - |%s|\n", ch, ret);
#endif
    /// 19-STRSPN test
#if 0
    int len;
    const char str1[] = "ABCDEFG019874";
    const char str2[] = "ABCD";

    len = strspn(str1, str2);

    printf("Length of initial segment matching %d\n", len );
#endif
    /// 20-STRSTR test
#if 0
    const char haystack[20] = "TutorialsPoint";
    const char needle[10] = "Point";
    char *ret;

    ret = strstr(haystack, needle);

    printf("The substring is: %s\n", ret);
#endif
    /// 21-STRTOK test
#if 0
    char str[80] = "This is - www.tutorialspoint.com - website";
    const char s[2] = "-";
    char *token;
    char * tocken=my_strtok_2(str, s);
    printf("%s",str);
#endif
    /// 22-STRXFRM test
#if 0
    char dest[20];
    char src[20];
    int len;

    strcpy(src, "Tutorials Point");
    len = strxfrm(dest, src, 20);

    printf("Length of string |%s| is: |%d|", dest, len);
#endif
    return 0;
}
