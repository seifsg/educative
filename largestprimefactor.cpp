//The prime factors of 13195 are 5, 7, 13 and 29.

//What is the largest prime factor of the number 600851475143 ?


#include<iostream>

using namespace std;

void prim(long long int n){

long long int h ;
int i = 2;
while(n>1){
    if(n % i == 0){
        h = i;
        n = n/i;
    }else{
        i++;
    }
}


cout<<h;

}
    

int main(){

prim(600851475143);

    return 0;
}

