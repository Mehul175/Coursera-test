Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@Mehul175 
Learn Git and GitHub without any code!
Using the Hello World guide, you’ll start a branch, write comments, and open a pull request.


Mehul175
/
Project-Euler
forked from RisingLight/Project-Euler
0
082
Code
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Project-Euler/C/20.Factorial_Digit_Sum/Mehul175.c
@Mehul175
Mehul175 Update Mehul175.c
Latest commit 3705b17 20 minutes ago
 History
 1 contributor
43 lines (37 sloc)  1.01 KB
  
// Euler 20
#include <stdio.h>
#define MAX_DIGIT 200

int main()
{
    //Find and Store 100! in array because no datatype can store such a huge value.
    int fact[MAX_DIGIT] = {1};
    
    int number_of_digit = 1,i,j,carry = 0,sum=0;
    for(j=2;j<=100;j++)
    {
        for(i=0; i<number_of_digit; i++)
            {
            int x = fact[i]*j; //product
            fact[i] = (x+carry)%10;
            carry = (x+carry)/10;
        
            //we are at end of the number with some carry remaining.
            //number of digit will increase by 1
            if (i == number_of_digit-1 && carry>0)
            number_of_digit++;
            }
    }
    //to display the calculated factorial.
    printf("100!= ");
    for(i=number_of_digit-1; i>=0; i--)
    {
        printf("%d",fact[i]);
    }
    printf("\n");
    
    //To Display the sum og it's digit.
    printf("Sum of digit of 100! = ");
    for(i=number_of_digit-1; i>=0; i--)
    {
        sum=sum+fact[i];
        
    }
    printf("%d",sum);

    return 0;
}
© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
