#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SIZE_OF_STRING    84


typedef struct{
    int id;
    float degree;
    char name[50];
}Student_t;
Student_t myStudent;
FILE * my_file;
char read_data_student[TOTAL_SIZE_OF_STRING];
void getStudentData(Student_t*);
void fetchStudentData(Student_t*,char data_std[]);
int main()
{
#if 1
    int checkClose=0;
    int studentCount=0;

    my_file=fopen("text.txt","r");
    if(my_file==NULL){
        printf("Erorr!!!\n");
    }else{
        printf("File is opened Successfully.\n");
        for(int i=0;i<6;i++){
            fgets(read_data_student,TOTAL_SIZE_OF_STRING,my_file);
            fetchStudentData(&myStudent,read_data_student);
            printStudentInfo(&myStudent);
        }
    }
#endif // 0
#if 0
    /** test FOPEN function **/
    int num;
    char name_Std[50];
    FILE* my_file=fopen("text.txt","w");
    if(my_file==NULL){
        printf("Error while creating file!!!\n");
    }else{
        printf("File opened successfully\n");
        printf("Please Enter number of student: ");
        scanf("%d",&num);
        for(int i=0;i<num;i++){
            getStudentData(&myStudent);
            int ret=fprintf(my_file,"Id [%i] - Name [%s] - Degree [%0.2f]\n",myStudent.id,myStudent.name,myStudent.degree);
            printf("%d",ret);
        }
    }
    int test=fclose(my_file); /// return 0 if function is done and EOF if error happend
    if(test==0){
        printf("file closed successfully\n");
    }else{
        printf("Error while closing file!!!\n");
    }
#endif // 0
    return 0;
}
void getStudentData(Student_t* myStudent){
    printf("Enter Student ID: ");
    scanf("%i",&(*myStudent).id);
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(myStudent->name);
    printf("Enter Student Degree: ");
    scanf("%f",&(*myStudent).degree);
    int size=strlen(myStudent->name);
    for(int i=size;i<50;i++)
        myStudent->name[i]=' ';
}
void fetchStudentData(Student_t * ptrStd,char read_std[]){
    char student_id_str[3]={0};
    char student_name_str[50]={0};
    char student_degree_str[5]={0};
    strncpy(student_id_str,read_data_student+4,2);
    strncpy(student_name_str,read_data_student+16,50);
    strncpy(student_degree_str,read_data_student+78,4);
    strcpy(ptrStd->name,student_name_str);
    ptrStd->degree=atof(student_degree_str);
    ptrStd->id=atoi(student_id_str);
}
void printStudentInfo(Student_t* ptrStd){
    printf("_____________________________________________\n");
    printf("Id: %d\nName: %s\nDegree: %0.2f\n",ptrStd->id,ptrStd->name,ptrStd->degree);
    printf("_____________________________________________\n");
}
