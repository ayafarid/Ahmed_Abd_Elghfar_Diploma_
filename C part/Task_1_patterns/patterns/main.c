#include <stdio.h>
#include <stdlib.h>

int main()
{
    /// #1 - Rectangle Pattern Programs in C, C++, Java
    /// pattern number one
    /*
    int row=3,col=5;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// pattern number two
    /*
    int row=3,col=5;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(i==0||i==row-1){
                printf("* ");
            }else if(j==0){
                printf("* ");
            }else if(j==col-1){
                printf(" *");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    */
    /// #2 - Pyramid Pattern Programs in C, C++, and Java using stars
    /// pattern number three
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// pattern number four
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int j=0;j<col-i;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// pattern number five
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int j=0;j<col-i;j++){
            if(i==0||j==0){
                printf("* ");
            }else if(i+j==row-1){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    */
    /// pattern number six
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int k=0;k<row-i-1;k++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// pattern number seven
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int k=0;k<i;k++){
            printf(" ");
        }
        for(int j=0;j<row-i;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// pattern number seven
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int k=0;k<row-i-1;k++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            if(i==row-1){
                printf("* ");
            }else if(j==0||j==i){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    */
    /// #3 - Pyramid Pattern Programs in C, C++, and Java using numbers
    /// pattern number eight
    /*
    int row=5,col=5;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    */
    /// pattern number nine
    /*
    int row=5,col=5;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=row-i+1;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    */
    /// pattern number ten
    /*
    int row=5,col=5;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            if(i==row){
                printf("%d ",j);
            }else if(j==1||j==i){
                printf("%d ",j);
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    */
    /// pattern number 11
    /*
    int row=5,col=9;
    for(int i=1;i<=row;i++){
        for(int k=1;k<=row-i;k++){
            printf("  ");
        }
        for(int j=1;j<=i;j++){
            printf("%d ",i+j-1);
        }
        for(int j=i-1;j>=1;j--){
            printf("%d ",i+j-1);
        }
        printf("\n");
    }
    */
    /// pattern number 12
    /*
    int row=5;
    for(int i=1;i<=row;i++){
        for(int k=1;k<=row-i;k++){
            printf("  ");
        }
        for(int j=1;j<=i;j++){
            if(i==row)
                printf("%d  ",j);
            else if(j==1)
                printf("%d  ",j);
            else if(j==i)
                printf(" %d",j);
            else
                printf("   ");
        }
        printf("\n");
    }
    */
    /// pattern number 13
    /*
    int row=5;
    for(int i=1;i<=row;i++){
        for(int j=i;j<=row;j++){
            if(i==1)
                printf("%d ",j);
            else if(j==i||j==row)
                printf("%d ",j);
            else
                printf("  ");
        }
        printf("\n");
    }
    */
    /// #4 - Palindrome Pyramid Pattern Programs in C, C++, and Java using numbers & Alphabets
    /// pattern number 14
    /*
    int row=5;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(int j=i-1;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    */
    /// pattern number 15
    /*
    int row=5;
    for(int i=1;i<=row;i++){
        for(int k=1;k<=row-i;k++)
        printf("  ");
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        for(int j=i-1;j>=1;j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    */
    /// pattern number 16
    /*
    int row =5;
    char ch='A';
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            printf("%c ",ch+j);
        }
        for(int k=i-1;k>=0;k--){
            printf("%c ",ch+k);
        }
        printf("\n");
    }
    */
    /// pattern number 17
    /*
    int row=5,s=8;
    for(int i=1;i<=row;i++){
        for(int k=1;k<=s;k++)
        {
            printf("*");
        }
        for(int j=1;j<=i;j++){
            printf("%d",i);
            if(j!=i)
                printf("*");
        }
        for(int k=1;k<=s;k++)
        {
            printf("*");
        }
        printf("\n");
        s--;
    }
    */
    /// #5 - Diamond Pattern Programs in C, C++, and Java using stars
    /// pattern number 18
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int k=0;k<row-i-1;k++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=0;i<row;i++){
        for(int k=0;k<i;k++){
            printf(" ");
        }
        for(int j=0;j<row-i;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// pattern number 19
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int k=0;k<row-i-1;k++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            if(j==0||j==i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for(int i=0;i<row;i++){
        for(int k=0;k<i;k++){
            printf(" ");
        }
        for(int j=0;j<row-i;j++){
            if(j==0||j==row-i-1)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    */
    /// pattern number 20
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=0;i<row-1;i++){
        for(int j=0;j<row-i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    */
    /// #6 - Diamond Pattern Programs in C, C++, and Java using numbers and stars
    /// pattern number 21
    /*
    int row=4;
    int count=row-1;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            printf("%d",count);
        }
        printf("\n");
        count++;
    }
    count-=2;
    for(int i=row-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            printf("%d",count);
        }
        printf("\n");
        count--;
    }
    */
    /// pattern number 22
    /*
    int row=4;
    for(int i=1;i<=row;i++){
        for(int j=0;j<i;j++){
            printf("%d",i);
            if(j!=i-1)
                printf("*");
        }
        printf("\n");
    }
    for(int i=row;i>=1;i--){
        for(int j=0;j<i;j++){
            printf("%d",i);
            if(j!=i-1)
                printf("*");
        }
        printf("\n");
    }
    */
    /// pattern number 23
    /*
    int row=4,count=1;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            printf("%d",count);
            count++;
            if(j!=i)
                printf("*");
        }
        printf("\n");
    }
    int k=row;
    count=7;
    for(int i=row;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("%d",count);
            count++;
            if(j!=i)
                printf("*");
        }
        printf("\n");
        count--;
        k--;
        count-=2*k;
    }
    */
    /// pattern number 24
    /*
    int row=4;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            if(j==0)
                printf("* ");
            else
                printf("%d ",j);
        }
        for(int j=i-1;j>=0;j--){
            if(j==0)
                printf("* ");
            else
                printf("%d ",j);
        }
        printf("\n");
    }
    for(int i=row-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(j==0)
                printf("* ");
            else
                printf("%d ",j);
        }
        for(int j=i-1;j>=0;j--){
            if(j==0)
                printf("* ");
            else
                printf("%d ",j);
        }
        printf("\n");
    }
    */
    /// #7 - Floyd's Triangle Pattern Program in C, C++, Java, Python
    /// pattern number 25
    /*
    int row=7,count=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<=i;j++){
            printf("%d ",count);
            count++;
        }
        printf("\n");
    }
    */
    /// #8 - Pascal's Triangle Pattern Program in C, C++, Java, Python
    /// pattern number 26
    /*
    int n=7;
    int arr[n][n];
    for (int line = 0; line < n; line++){
        for (int i = 0; i <= line; i++){
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
    */
    /// #9 - Hollow Diamond Inscribed in a Rectangle
    /// pattern number 27
    /*
    int row=6,col=6;
    for(int i=0;i<row;i++){
        for(int j=0;j<col-i;j++){
            printf("* ");
        }
        for(int j=0;j<i;j++){
            printf("  ");
        }
         for(int j=0;j<i;j++){
            printf("  ");
        }
        for(int j=0;j<col-i;j++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=row-1;i>=0;i--){
        for(int j=0;j<col-i;j++){
            printf("* ");
        }
        for(int j=0;j<i;j++){
            printf("  ");
        }
         for(int j=0;j<i;j++){
            printf("  ");
        }
        for(int j=0;j<col-i;j++){
            printf("* ");
        }
        printf("\n");
    }
    */
    /// another solution
    /*
    int i, j, n;
    scanf("%d", &n);
    // upper half of the pattern
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i + j <= n - 1)  // upper left triangle
                printf("*");
            else
                printf(" ");
            if((i + n) <= j)  // upper right triangle
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    // bottom half of the pattern
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j)  //bottom left triangle
                printf("*");
            else
                printf(" ");
            if(i >= (2 * n - 1) - j)  // bottom right triangle
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    */
    /// #10 - Butterfly Pattern Printing
    /// patter number 28
    /*
    int i, j, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j)  //bottom left triangle
                printf("*");
            else
                printf(" ");
            if(i >= (2 * n - 1) - j)  // bottom right triangle
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i + j <= n - 1)  // upper left triangle
                printf("*");
            else
                printf(" ");
            if((i + n) <= j)  // upper right triangle
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    */
    /// #11 - Diagonal & Sides of a Rectangle
    /// pattern number 29
    /*
    int row=10;
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            if(i==0||i==row-1||j==0||j==row-1||i==j||i+j==row-1){
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    */
    /// #12 - Diagonal & Sides of a Rhombus/Diamond
    /// pattern number 30
    /*
    int i, j, n;
    scanf("%d", &n);  // ‘n’ must be odd
    int num1 = n / 2 * 3;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == n / 2 || j == n / 2 || i + j == n / 2 || i - j == n / 2 || j - i == n / 2 || i + j == num1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    */
    /// #13 - Left and Right Arrows
    /// pattern number 31
    /*
    int row=4,count=row-1,space=10;
    for(int i=0;i<row;i++){
        for(int k=0;k<count;k++){
            printf(" ");
        }
        printf("*");
        for(int l=0;l<space;l++){
            printf(" ");
        }
        printf("*\n");
        space-=2;
        count++;
    }
    for(int i=0;i<8;i++)
        printf("*");
    for(int l=0;l<space;l++)
        printf(" ");
    for(int i=0;i<8;i++)
        printf("*");
    printf("\n");
    count=row+2;
    for(int i=0;i<row;i++){
        for(int k=0;k<count;k++){
            printf(" ");
        }
        printf("*");
        space+=2;
        for(int l=0;l<space;l++){
            printf(" ");
        }
        printf("*\n");
        count--;
    }
    */
    /// Another solution
    /*
    int i, j, n;
    scanf("%d", &n);
    int num1 = n / 2 * 3;
    printf("Right Arrow\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == n / 2 || j - i == n / 2 || i + j == num1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Left Arrow\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == n / 2 || i - j == n / 2 || i + j == n / 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    */
    /// #14 - Rhombus Pattern Program in C, C++, Java
    /// pattern number 32
    /*
    int row=4;
    int count=row-1;
    for(int i=0;i<row;i++){
        for(int k=0;k<count;k++){
            printf(" ");
        }
        for(int j=0;j<row;j++){
            printf("*");
        }
        printf("\n");
        count--;
    }
    */
    /// pattern number 33
    /*
    int row=4;
    int count=row-1;
    for(int i=0;i<row;i++){
        for(int k=0;k<count;k++){
            printf(" ");
        }
        for(int j=0;j<row;j++){
            if(i==0||i==row-1||j==0||j==row-1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
        count--;
    }
    */
    return 0;
}
