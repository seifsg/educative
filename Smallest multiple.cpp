


//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?


#include<iostream>

using namespace std;

bool ediv(long long int i, int b, int e ){

bool bla = true;

for(int h = b;h<=e;h++){

    if(i%h != 0){
        bla = false;
        break;
    }

}

return bla;

}

int main(){

long long int i =0;
while(1){
    i++;
    if(ediv(i,1,10)){

        cout<<i<<endl;

        break;

    }
}

return 0;
}
