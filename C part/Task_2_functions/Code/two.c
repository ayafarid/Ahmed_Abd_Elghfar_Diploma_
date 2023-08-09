#include <stdio.h>
#include <stdlib.h>

int cube_of_a_number(int number);
int main()
{
    int number,cubeNumber;
    printf("Input any number: ");
    scanf("%d",&number);
    cubeNumber=cube_of_a_number(number);
    printf("Cube of %d = %d",number,cubeNumber);
    return 0;
}
int cube_of_a_number(int number){
    return number*number*number;
}
