#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cube_of_a_number(int number);
void calc_diam_circ_area_of_circle(float radius);
float calc_diameter_of_circle(float radius);
float calc_circunference_of_circle(float radius);
float calc_area_of_circle(float radius);
int max_between_two_numbers(int num1,int num2);
int min_between_two_numbers(int num1,int num2);
int is_odd(int num);
int is_even(int num);
int is_prime(int num);
int is_armstong(int num);
int is_perfect(int num);
void dispaly_primes(int lowRange,int highRange);
void dispaly_strong(int lowRange,int highRange);
void display_armstrong(int lowRange,int highRange);
void display_perfect(int lowRange,int highRange);
long long fact(int num);
int is_strong(int num);
int power_using_recursion(int num,int power);
int main()
{
    /// TASK ONE
#if 0
    int number,cubeNumber;
    printf("Input any number: ");
    scanf("%d",&number);
    cubeNumber=cube_of_a_number(number);
    printf("Cube of %d = %d",number,cubeNumber);
#endif
    /// TASK TWO
#if 0
    float radius,diameter,circumference,area;
    printf("Input radius : ");
    scanf("%f",&radius);
    diameter=calc_diameter_of_circle(radius);
    circumference=calc_circunference_of_circle(radius);
    area=calc_area_of_circle(radius);
    printf("Diameter = %0.2f units\nCircumference = %.2f units\nArea = %.2f sq. units\n",diameter,circumference,area);
#endif
    /// TASK THREE
#if 0
    int number_one , number_two;
    printf("Input two numbers: ");
    scanf("%d %d",&number_one,&number_two);
    int max,min;
    max=max_between_two_numbers(number_one,number_two);
    min=min_between_two_numbers(number_one,number_two);
    printf("Maximum = %d\nMinimum = %d",max,min);
#endif
    /// TASK FOUR
#if 0
    int num;
    printf("Input any number : ");
    scanf("%d",&num);
    if(is_even(num))
        printf("%d is even\n",num);
    else if(is_odd(num))
        printf("%d is odd\n",num);
    else
        printf("%d is not odd or even",num);
#endif
    /// TASK FIVE
#if 0
    int number;
    printf("Input any number : ");
    scanf("%d",&number);
    if(is_prime(number))
        printf("%d is a prime number\n",number);
    else
        printf("%d is not a prime number\n",number);
    if(is_armstong(number))
        printf("%d is an armstrong number\n",number);
    else
        printf("%d is not an armstrong number\n",number);
    if(is_perfect(number))
        printf("%d is a perfect number\n",number);
    else
        printf("%d is not a perfect number\n",number);
#endif
    /// TASK SIX
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Prime numbers between %d-%d are: ",lowerLimit,upperLimit);
    dispaly_primes(lowerLimit,upperLimit);
#endif
    /// TASK SEVEN
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Strong numbers between %d-%d are: ",lowerLimit,upperLimit);
    dispaly_strong(lowerLimit,upperLimit);
#endif // 0
    /// TASK EIGHT
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Armstrong numbers between %d-%d are: ",lowerLimit,upperLimit);
    display_armstrong(lowerLimit,upperLimit);
#endif // 0
    /// TASK NINE
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Armstrong numbers between %d-%d are: ",lowerLimit,upperLimit);
    display_perfect(lowerLimit,upperLimit);
#endif // 0
    /// TASK TEN
#if 0
    int number,power;
    printf("Input base number: ");
    scanf("%d",&number);
    printf("Input power: ");
    scanf("%d",&power);
    printf("%d ^ %d = %d",number,power,power_using_recursion(number,power));
#endif // 0
    return 0;
}
int cube_of_a_number(int number){
    return number*number*number;
}
void calc_diam_circ_area_of_circle(float radius){
    printf("Diameter = %.2f units\nCircumference = %.2f units\nArea = %.2f sq. units\n",radius*2,2*M_PI*radius,M_PI*radius*radius);
}
float calc_diameter_of_circle(float radius){
    return 2*radius;
}
float calc_circunference_of_circle(float radius){
    return 2*M_PI*radius;
}
float calc_area_of_circle(float radius){
    return M_PI*radius*radius;
}
int max_between_two_numbers(int num1,int num2){
    if(num1>num2)
        return num1;
    else
        return num2;
}
int min_between_two_numbers(int num1,int num2){
    if(num1<num2)
        return num1;
    else
        return num2;
}
int is_odd(int num){
    if(num%2!=0)
        return 1;
    else
        return 0;
}
int is_even(int num){
    if(num%2==0)
        return 1;
    else
        return 0;
}
int is_prime(int num){
    if(num<2)
        return 0;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return 0;
    }
    return 1;
}
int is_armstong(int num){
    int temp, lastDigit, sum;

    temp = num;
    sum = 0;

    /* Calculate sum of cube of digits */
    while(temp != 0)
    {
        lastDigit = temp % 10;
        sum += lastDigit * lastDigit * lastDigit;
        temp /= 10;
    }

    /*
     * Check if sum of cube of digits equals
     * to original number.
     */
    if(num == sum)
        return 1;
    else
        return 0;
#if 0
        int lastDigit, sum, originalNum, digits;
    sum = 0;

    originalNum = num;

    /* Find total digits in num */
    digits = (int) log10(num) + 1;

    /*
     * Calculate sum of power of digits
     */
    while(num > 0)
    {
        // Extract the last digit
        lastDigit = num % 10;

        // Compute sum of power of last digit
        sum = sum + round(pow(lastDigit, digits));

        // Remove the last digit
        num = num / 10;
    }

    return (originalNum == sum);
#endif // 0
}
int is_perfect(int num){
    int i, sum, n;
    sum = 0;
    n = num;

    for(i=1; i<n; i++)
    {
        /* If i is a divisor of num */
        if(n%i == 0)
        {
            sum += i;
        }
    }

    return (num == sum);
}
void dispaly_primes(int lowRange,int highRange){
    for(int i=lowRange;i<=highRange;i++){
        if(is_prime(i))
            printf("%d ",i);
    }
}
int is_strong(int num){
    long long sum=0,temp=num;
    while(num){
        sum+=fact(num%10);
        num/=10;
    }
    if(sum==temp)
        return 1;
    else
        return 0;
}
void dispaly_strong(int lowRange,int highRange){
    for(int i=lowRange;i<=highRange;i++){
        if(is_strong(i))
            printf("%d ",i);
    }
}
long long fact(int num)
{
    if(num == 0)
        return 1;
    else
        return (num * fact(num-1));
}
void display_armstrong(int lowRange,int highRange){
    for(int i=lowRange;i<=highRange;i++){
        if(is_armstong(i))
            printf("%d ",i);
    }
}
void display_perfect(int lowRange,int highRange){
    for(int i=lowRange;i<=highRange;i++){
        if(is_perfect(i))
            printf("%d ",i);
    }
}
int power_using_recursion(int num,int power){
    if(power==0)
        return 1;
    else
        return num*power_using_recursion(num,power-1);
}
