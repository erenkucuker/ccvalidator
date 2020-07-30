#include <stdio.h>

int main(void)
{
    unsigned long long int number;
    
    printf("Number: ");
    scanf("%llu", &number);
    
    unsigned long long int number1 = number;

    
    int countdigit = 0;
    
    while (number1 != 0)
    {  
        number1 /= 10;
        countdigit++;
    }
    
   
    
    int result = 0; 
    int count = 0;
    int k = 0;  
    int b = 0;  
    int c = 0;  
    
    int numberArray[16];         
    
    while (number != 0)
    {
        numberArray[count] = number % 10;
        
        if (count % 2 == 0)
        {
            c = c + numberArray[count];
        }
        
        else
        {
            if (numberArray[count] * 2 >= 10)
            {
                b = b + (numberArray[count] * 2) % 10;
                k++;
            }
            
            else
            {
                b = b + numberArray[count] * 2;
            }
        }
        
        number /= 10;
        count++;
    }    
    
    result = b + c + k;
    
    if (result % 10 == 0)
    {
        if (countdigit == 16 && numberArray[15] == 5 && (numberArray[14] == 1 || numberArray[14] == 2 || numberArray[14] == 3 || numberArray[14] == 4 || numberArray[14] == 5))
        {
            printf("MASTERCARD!\n");
            main();;
        }
        
        if (countdigit == 15 && numberArray[14] == 3 && (numberArray[13] == 4 || numberArray[13] == 7))
        {
            printf("AMEX!\n");
            main();
        }
        
        if ((countdigit == 13 || countdigit == 14 || countdigit == 15 || countdigit == 16) && numberArray[countdigit - 1] == 4)
        {
            printf("VISA!\n");
            main();
        }
        
        else
        {
            printf("INAPPROPRIATE OR INVALID CARD!\n");
            main();
        }
    }
    
    else
    {
        printf("WRONG CARD NUMBER!\n");
        main();
    }
    
}