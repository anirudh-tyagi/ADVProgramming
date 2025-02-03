#include <stdio.h>
#include <stdlib.h>

void perfect(int a){
    int b=a;
    int sum=0;
    while (a!=0)
    {sum += a%10;
    a=a/10;
    }
    if (sum==b)
    {printf("It's a perfect number."); 
    }
    else
    {printf("It's not a perfect number."); }
    
       
}

int main() {
    printf("Enter a Number: "); 
    int num;
    scanf("%d", &num);  
    perfect(num); 
    return 0;
}
