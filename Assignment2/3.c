#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Enter a Number: "); 
    int num;
    scanf("%d", &num);  
    int cout=0;
    while(num>10){
        int sum=0;
        while(num>0){
            sum += num%10;
            num=num/10;
        }
    num=sum;    


    }
    printf("Single digit sum: %d\n", num);
}
