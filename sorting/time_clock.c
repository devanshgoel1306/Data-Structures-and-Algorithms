/*Program using clock_t variable and clock() function*/
#include<time.h>
#include<stdio.h>

//defining the function factorial
int fact(int number){

if( number==1 || number==0)//base case
{
    return 1;
}
else return number*fact(number-1);
}
int main(){
    //creating variable of type clock_t
    clock_t start, end;
    //calling the function clock with return type clock_t
    //no argument required for clock function
    //clock function returns the total processor clock
    start= clock();

    //creating a variable to store the number
    int number=0;
    printf("Factorial\n");
    //input the count of no's you want to calculate factorial of
    int count=0;
    printf("Enter the count of no.: ");
    scanf("%d",&count);
    int i=0;
    for(; i<count; i++){
        printf("Enter a number: ");
        scanf("%d",&number);

        //calling the factorial function
        int ans= fact(number);

        //print the returned value
        printf("Factorial of %d is %d.\n",number, ans);
    }

    //again calling the clock function
    //it will store the total no. of processor clock at this point
    end= clock();

    //to get the actual time in sec
    //we need to divide the no. of clocks  by macro CLOCKS_PER_SEC
    printf("Total time taken by program is %f s",(double)(end-start)/CLOCKS_PER_SEC);

return 0;
}

/*Sample Output
Factorial
Enter the count of no.: 12
Enter a number: 2
Factorial of 2 is 2.
Enter a number: 3
Factorial of 3 is 6.
Enter a number: 4
Factorial of 4 is 24.
Enter a number: 5
Factorial of 5 is 120.
Enter a number: 6
Factorial of 6 is 720.
Enter a number: 7
Factorial of 7 is 5040.
Enter a number: 8
Factorial of 8 is 40320.
Enter a number: 9
Factorial of 9 is 362880.
Enter a number: 10
Factorial of 10 is 3628800.
Enter a number: 11
Factorial of 11 is 39916800.
Enter a number: 12
Factorial of 12 is 479001600.
Enter a number: 13
Factorial of 13 is 1932053504.
Total time taken by program is 57.916000 s
Process returned 0 (0x0)   execution time : 59.188 s
*/


