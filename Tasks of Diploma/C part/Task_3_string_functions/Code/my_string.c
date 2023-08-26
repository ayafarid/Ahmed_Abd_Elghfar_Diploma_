#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "my_string.h"

void *memchr(const void *str, int c, size_t n){
    unsigned char * temStr=str;
    int tempN=n;
    int flag=0;
    while(n--){
        if(*temStr==c){
            return temStr;
        }else{
            temStr++;
        }
    }
    return NULL;
}
int memcmp(const void *str1, const void *str2, size_t n){
    unsigned char *tempStr1=str1;
    unsigned char *tempStr2=str2;
    if(tempStr1!=NULL&&tempStr2!=NULL){
        if(tempStr1==tempStr2)
            return 0;
        else{
            while(n--){
                if(*tempStr1==*tempStr2){
                    continue;
                }
                else if(*tempStr1>*tempStr2){
                    return 1;
                }
                else if(*tempStr1<*tempStr2){
                    return -1;
                }
                tempStr1++;
                tempStr2++;
            }
            return 0;
        }
    }else{
        printf("NULL pointer is used!\n");
        return -100;
    }
}
void *memcpy(void *dest, const void *src, size_t n){
    unsigned char * tempDest=dest;
    unsigned char * tempSrc=src;
    if(tempDest!=NULL&&tempSrc!=NULL){
        while(n--){
            *tempDest=*tempSrc;
            tempDest++;
            tempSrc++;
        }
    }
    return dest;
}
void *memmove(void *str1, const void *str2, size_t n){
    unsigned char* tempStr1=str1;
    unsigned char* tempStr2=str2;
    unsigned char* tempSection=(unsigned char*)malloc(sizeof(char)*n);
    if(tempStr1!=NULL&&tempStr2!=str2&&tempSection!=NULL){
        for(int i=0;i<n;i++){
            *(tempSection+i)=*(tempStr2+i);
        }
        for(int i=0;i<n;i++){
            *(tempStr1+i)=*(tempSection+i);
        }
        free(tempSection);
    }
    else{
        return NULL;
    }
    return str1;
}
void *memset(void *str, int c, size_t n){
    unsigned char* tempStr=str;
    if(tempStr!=NULL){
        while(n--){
            *tempStr++=(char)c;
        }
    }else{
        return NULL;
    }
    return str;
}
char *strcat(char *dest, const char *src){
    char * tempDes=dest;
    if(dest!=NULL&&src!=NULL){
        while(*tempDes!='\0'){
            tempDes++;
        }
        while(*src!='\0'){
            *tempDes++=*src++;
        }
        *tempDes='\0';
    }else{
        return NULL;
    }
    return dest;
}
char *strncat(char *dest, const char *src, size_t n){
    char * tempDes=dest;
    if(dest!=NULL&&src!=NULL){
        while(*tempDes!='\0'){
            tempDes++;
        }
        while(n--&&*src!='\0'){
            *tempDes++=*src++;
        }
        *tempDes='\0';
    }else{
        return NULL;
    }
    return dest;
}
char *strchr(const char *str, int c) {
    while(*str!=(char)c&&*str!=NULL) {
        str++;
    }
    if(*str == (char)c)
        return (char *)str;
    else
        return NULL;
}
int strcmp(const char *str1, const char *str2){
    if(str1==str2)
        return 0;
    while(str1!=NULL&&str2!=NULL){
        if(*str1==*str2)
            continue;
        else if(*str1<*str2){
            return -1;
        }else if(*str1>*str2){
            return 1;
        }
        str1++;
        str2++;
    }
}
int strncmp(const char *str1, const char *str2, size_t n){
    if(str1==str2)
        return 0;
    while(n--&&*str1!=NULL&&*str2!=NULL){
        if(*str1==*str2)
            continue;
        else if(*str1<*str2){
            return -1;
        }else if(*str1>*str2){
            return 1;
        }
    }
}
int strcoll(const char *str1, const char *str2){
    if(str1==str2)
        return 0;
    while(str1!=NULL&&str2!=NULL){
        if(*str1==*str2)
            continue;
        else if(*str1<*str2){
            return -1;
        }else if(*str1>*str2){
            return 1;
        }
        str1++;
        str2++;
    }
}
char *strcpy(char *dest, const char *src){
    char * tempDest=dest;
    char * tempSrc=src;
    if(tempDest!=NULL&&tempSrc!=NULL){
        while(*tempSrc!=NULL){
            *tempDest=*tempSrc;
            tempDest++;
            tempSrc++;
        }
    }else {
        return NULL;
    }
    return dest;
}
char *strncpy(char *dest, const char *src, size_t n){
    char * tempDest=dest;
    char * tempSrc=src;
    if(tempDest!=NULL&&tempSrc!=NULL){
        while(n--){
            *tempDest=*tempSrc;
            tempDest++;
            tempSrc++;
        }
    }
    return dest;
}
size_t strcspn(const char *str1, const char *str2){
    char* tempStr1=str1;
    char* tempStr2=str2;
    int count=0,str1Len=strlen(str1),str2Len=strlen(str2);
    for(int i=0;i<str1Len;i++){
        char ch1=tempStr1[i],flag=0;
        for(int j=0;j<str2Len;j++){
            if(ch1==tempStr2[j]){
                flag=1;
                break;
            }
        }
        if(flag==0)
            count++;
    }
    return count;
}
/// Another solution
#if 0
unsigned int my_strcspn(const char *s1, const char *s2)
{
    unsigned int len =0;
    //return 0 if any one is NULL
    if((s1 == NULL) || (s2 == NULL))
        return len;
    //till not get null character
    while(*s1)
    {
        //return s1 char position if found in s2
        if(strchr(s2,*s1))
        {
            return len;
        }
        else
        {
            //increment s1
            s1++;
            //increment len variable
            len++;
        }
    }
    return len;
}
#endif
char *my_strerror(int num)
{
	return  strerror(num);;
}
size_t strlen(const char *str){
    char * tempStr=str;
    int length=0;
    if(tempStr!=NULL){
        while(*tempStr!=NULL){
            length++;
            tempStr++;
        }
    }
    return length;
}
char *strpbrk(const char *str1, const char *str2){
    char * temStr1=str1;
    char * temStr2=str2;
    int lenStr1=strlen(str1);
    int lenStr2=strlen(str2);
    if(temStr1!=NULL && temStr2!=NULL){
        for(int i=0;i<lenStr1;i++){
            char ch1=temStr1[i];
            for(int j=0;j<lenStr2;j++){
                if(ch1==temStr2[j])
                    return (temStr1+i);
            }
        }
        return NULL;
    }else{
        return NULL;
    }
}
char *strrchr(const char *str, int c){
    char * temStr=str;
    int len=strlen(str);
    char * lastOccur=NULL;
    if(temStr!=NULL){
        for(int i=0;i<len;i++){
            if(temStr[i]==(char)c){
                lastOccur=(temStr+i);
            }
        }
        return lastOccur;
    }else{
        return NULL;
    }
}
size_t strspn(const char *str1, const char *str2){
    char* tempStr1=str1;
    char* tempStr2=str2;
    int count=0,str1Len=strlen(str1),str2Len=strlen(str2);
    for(int i=0;i<str1Len;i++){
        char ch1=tempStr1[i],flag=0;
        for(int j=0;j<str2Len;j++){
            if(ch1==tempStr2[j]){
                flag=1;
                break;
            }
        }
        if(flag==1)
            count++;
    }
    return count;
}
char *strstr(const char *haystack, const char *needle){
    char * temHaystack=haystack;
    char * temNeedle=needle;
    int lenHaystack=strlen(haystack);
    int lenNeedle=strlen(needle);
    int check=0;
    if(temHaystack!=NULL && temNeedle!=NULL){
        for(int i=0;i<lenHaystack;i++){
            if(temHaystack[i]==temNeedle[0]){
                int temI=i+1;
                for(int j=1;j<lenNeedle;j++){
                    if(temHaystack[temI]==temNeedle[j]){
                        temI++;
                    }else{
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    return (temHaystack+i);
                }else{
                    check=0;
                }
            }
        }
        return NULL;
    }else{
        return NULL;
    }
}
unsigned int is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}
char *my_strtok_1(char *srcString, char *delim)
{
    static char *backup_string; // start of the next search
    if(!srcString)
    {
        srcString = backup_string;
    }
    if(!srcString)
    {
        // user is bad user
        return NULL;
    }
    // handle beginning of the string containing delims
    while(1)
    {
        if(is_delim(*srcString, delim))
        {
            srcString++;
            continue;
        }
        if(*srcString == '\0')
        {
            // we've reached the end of the string
            return NULL;
        }
        break;
    }
    char *ret = srcString;
    while(1)
    {
        if(*srcString == '\0')
        {
            /*end of the input string and
            next exec will return NULL*/
            backup_string = srcString;
            return ret;
        }
        if(is_delim(*srcString, delim))
        {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
}
char *my_strtok_2(char *str, const char *delim)
{
    int counter =0;
    int strlength = strlen(str);
    for(counter =0;counter<strlength;counter++)
    {
        if(str[counter] == *delim)
        {
            str[counter]='\n';
        }
    }
    return str;
}
size_t strxfrm(char *dest, const char *src, size_t n){
    char* temDest=dest;
    char* temSrc=src;
    int lenSrc=strlen(src);
    int count=n<lenSrc?n:lenSrc;
    if(temDest!=NULL && temSrc!=NULL){
        for(int i=0;i<count;i++){
            temDest[i]=temSrc[i];
        }
    }
    return count;
}






