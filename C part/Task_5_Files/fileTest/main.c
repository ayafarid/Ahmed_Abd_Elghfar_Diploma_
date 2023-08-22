#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SIZE_OF_STRING             84

#define STUDENT_ID_SIZE                  3
#define STUDENT_NAME_SIZE                50
#define STUDENT_DEGREE_SIZE              4

#define STUDENT_ID_INFO_START_INDEX      4
#define STUDENT_NAME_INFO_START_INDEX    16
#define STUDENT_DEGREE_INFO_START_INDEX  78
typedef struct{
    int id;
    float degree;
    char name[STUDENT_NAME_SIZE];
}Student_t;
Student_t myStudent;
FILE * my_file;
char read_data_student[TOTAL_SIZE_OF_STRING];
void getStudentData(Student_t*);
void fetchStudentData(Student_t*,char data_std[]);
int inline sum(int num1,int num2)__attribute__((always_inline));
int main()
{
    int num1=12,num2=24;
    printf("%d",sum(num1,num2));
#if 0
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
    for(int i=size;i<STUDENT_NAME_SIZE;i++)
        myStudent->name[i]=' ';
}
void fetchStudentData(Student_t * ptrStd,char read_std[]){
    char student_id_str[STUDENT_ID_SIZE]={0};
    char student_name_str[STUDENT_NAME_SIZE]={0};
    char student_degree_str[STUDENT_DEGREE_SIZE]={0};
    strncpy(student_id_str,read_std+STUDENT_ID_INFO_START_INDEX,STUDENT_ID_SIZE);
    strncpy(student_name_str,read_std+STUDENT_NAME_INFO_START_INDEX,STUDENT_NAME_SIZE);
    strncpy(student_degree_str,read_std+STUDENT_DEGREE_INFO_START_INDEX,STUDENT_DEGREE_SIZE);
    strcpy(ptrStd->name,student_name_str);
    ptrStd->degree=atof(student_degree_str);
    ptrStd->id=atoi(student_id_str);
}
void printStudentInfo(Student_t* ptrStd){
    printf("_____________________________________________\n");
    printf("Id: %d\nName: %s\nDegree: %0.2f\n",ptrStd->id,ptrStd->name,ptrStd->degree);
    printf("_____________________________________________\n");
}
int inline sum(int num1,int num2){
    return num1+num2;
}
