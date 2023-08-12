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
void display_range(int lowerLimit,int upperLimit);
void display_range_odd(int lowerLimit,int upperLimit);
void display_range_even(int lowerLimit,int upperLimit);
int sum_range(int lowerLimit,int upperLimit);
int reverse_number(int num);
void check_palindrome(int num);
int sum_of_digit(int num);
int factorial(int num);
int fibonacci(int num);
int greatestCommonDivisor(int num1,int num2);
int lowestCommonMultiple(int a, int b);
void print_array_elements(int array[],int size);
int sum_of_array_elements(int array[],int size);
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
#endif
    /// TASK NINE
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Armstrong numbers between %d-%d are: ",lowerLimit,upperLimit);
    display_perfect(lowerLimit,upperLimit);
#endif
    /// TASK TEN
#if 0
    int number,power;
    printf("Input base number: ");
    scanf("%d",&number);
    printf("Input power: ");
    scanf("%d",&power);
    printf("%d ^ %d = %d",number,power,power_using_recursion(number,power));
#endif
    /// TASK 11
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Natural numbers between %d to %d: ",lowerLimit,upperLimit);
    display_range(lowerLimit,upperLimit);
#endif
    /// TASK 12
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Even numbers between %d to %d: ",lowerLimit,upperLimit);
    display_range_even(lowerLimit,upperLimit);
    printf("\n");
    printf("Odd numbers between %d to %d: ",lowerLimit,upperLimit);
    display_range_odd(lowerLimit,upperLimit);
#endif
    /// TASK 13
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Even numbers between %d to %d: ",lowerLimit,upperLimit);
    display_range_even(lowerLimit,upperLimit);
    printf("\n");
    printf("Odd numbers between %d to %d: ",lowerLimit,upperLimit);
    display_range_odd(lowerLimit,upperLimit);
#endif
    /// TASK 14
#if 0
    int lowerLimit,upperLimit;
    printf("Input lower limit: ");
    scanf("%d",&lowerLimit);
    printf("Input upper limit: ");
    scanf("%d",&upperLimit);
    printf("Sum of natural numbers from %d to %d = %d",lowerLimit,upperLimit,sum_range(lowerLimit,upperLimit));

#endif
    /// TASK 15
#if 0
    int num;
    printf("Input number: ");
    scanf("%d",&num);
    printf("Reverse: %d",reverse_number(num));
#endif
    /// TASK 16
#if 0
    int num;
    printf("Input number: ");
    scanf("%d",&num);
    check_palindrome(num);
#endif
    /// TASK 17
#if 0
    int num;
    printf("Input number: ");
    scanf("%d",&num);
    printf("Sum of digits: %d",sum_of_digit(num));
#endif
    /// TASK 18
#if 0
    int num;
    printf("Input number: ");
    scanf("%d",&num);
    printf("Factorial of %d = %d",num,factorial(num));
#endif
    /// TASK 19
#if 0
    int num;
    printf("Input number: ");
    scanf("%d",&num);
    printf("Fibonacci of %d = %d",num,fibonacci(num));
#endif=
    /// TASK 20
#if 0
    int num1,num2;
    printf("Input first number: ");
    scanf("%d",&num1);
    printf("Input second number: ");
    scanf("%d",&num2);
    printf("HCF of %d and %d = %d",num1,num2,greatestCommonDivisor(num1,num2));
#endif
    /// TASK 21
#if 0
    int num1,num2;
    printf("Input first number: ");
    scanf("%d",&num1);
    printf("Input second number: ");
    scanf("%d",&num2);
    int LCM;
    if(num1>num2)
        LCM=lowestCommonMultiple(num2,num1);
    else
        LCM=lowestCommonMultiple(num1,num2);
    printf("LCM of %d and %d = %d",num1,num2,LCM);
#endif
    /// TASK 22
#if 0
    int size;
    printf("Input size: ");
    scanf("%d",&size);
    int array[size];
    printf("Input elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    printf("Array elements: ");
    print_array_elements(array,size);
#endif
    /// TASK 23
#if 0
    int size;
    printf("Input size: ");
    scanf("%d",&size);
    int array[size];
    printf("Input elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    printf("Sum of array: %d",sum_of_array_elements(array,size));
#endif
    /// TASK 24
#if 0
    int size;
    printf("Input size: ");
    scanf("%d",&size);
    int array[size];
    printf("Input elements: ");
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    int min=array[0],max=array[0];
    max_and_min(array,size,&max,&min);
    printf("Maximum element = %d\nMinimum element = %d",max,min);
#endif
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
long long fact(int num){
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
void display_range(int lowerLimit,int upperLimit){
    if(lowerLimit>upperLimit)
        return;
    else{
        printf("%d ,",lowerLimit);
        lowerLimit++;
        display_range(lowerLimit,upperLimit);
    }
}
void display_range_odd(int lowerLimit,int upperLimit){
    if(lowerLimit>upperLimit)
        return;
    else{
        if(lowerLimit%2!=0){
             printf("%d ,",lowerLimit);
        }
        lowerLimit++;
        display_range_odd(lowerLimit,upperLimit);
    }
}
void display_range_even(int lowerLimit,int upperLimit){
    if(lowerLimit>upperLimit)
        return;
    else{
        if(lowerLimit%2==0){
            printf("%d ,",lowerLimit);
        }
        lowerLimit++;
        display_range_even(lowerLimit,upperLimit);
    }
}
int sum_range(int lowerLimit,int upperLimit){
    if(lowerLimit>upperLimit)
        return 0;
    else{
        return lowerLimit+sum_range(lowerLimit+1,upperLimit);
    }
}
int reverse_number(int num){
    int num_digit=(int) log10(num);
    int product=pow(10,num_digit);
    int reversed_num=0;
    while(product){
        reversed_num+=product*(num%10);
        num/=10;
        product/=10;
    }
    return reversed_num;
}
void check_palindrome(int num){
    if(reverse_number(num)==num)
        printf("%d is palindrome",num);
    else
        printf("%d is not palindrome",num);
}
int sum_of_digit(int num){
    int sum;
    while(num){
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int factorial(int num){
    if(num==0)
        return 1;
    else
        return num*factorial(num-1);
}
int fibonacci(int num){
    if(num==0)
        return 0;
    else if(num==1)
        return 1;
    else if(num>1){
        return fibonacci(num-1)+fibonacci(num-2);
    }
}
int greatestCommonDivisor(int num1,int num2){
    if(num2==0)
        return num1;
    else{
        return greatestCommonDivisor(num2,num1%num2);
    }

}
int lowestCommonMultiple(int a, int b){
    static int multiple = 0;
    multiple += b;
    if((multiple % a == 0) && (multiple % b == 0))
    {
        return multiple;
    }
    else
    {
        return lowestCommonMultiple(a, b);
    }
}
void print_array_elements(int array[],int size){
    static int i=0;
    if(i==size)
        return;
    else{
        printf("%d ,",array[i]);
        i++;
        print_array_elements(array,size);
    }
}
int sum_of_array_elements(int array[],int size){
    static int i=0,sum=0;
    if(i==size)
        return sum;
    else{
        sum+=array[i];
        i++;
        sum_of_array_elements(array,size);
        return sum;
    }
}
void max_and_min(int array[],int size,int* max,int* min){
    static int i=0;
    if(i==size)
        return;
    else{
        if(*max<array[i])
            *max=array[i];
        if(*min>array[i])
            *min=array[i];
        i++;
        max_and_min(array,size,max,min);
        return;
    }
}
