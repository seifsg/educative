/*
10001st prime
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(n){
    bool b = true;int i;int len = n/2;
    for(i = 2;i<len;i++){
        if(n % i == 0){
            b = false;break;
        }
    }
    return b;
}

int main()
{
    int count = 6;unsigned n = 14;
    while(1){
        if(is_prime(n)){
            count++;
        }
        if(count == 10001)
            break;
        n++;
    }
    printf("%u\n",n);
    return 0;
}
