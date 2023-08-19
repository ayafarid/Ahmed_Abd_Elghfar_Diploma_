#include <stdio.h>
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
