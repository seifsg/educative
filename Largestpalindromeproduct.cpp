

//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

//Find the largest palindrome made from the product of two 3-digit numbers.


#include<iostream>
#include <sstream>
#include<string.h>
using namespace std;

bool palpro(string ch){
    if (ch.length()<2){
        return true;
    }else if (ch[0] == ch[ch.length()-1]){
        return palpro(ch.substr(1,ch.length()-2));
    }else{
        return false;
    }

}

bool pal(int i,int j){

stringstream s;
s<<i*j;
string ch = s.str();

if(palpro(ch)){
    return true;
}else{

    return false;

}

}


int main(){

int m = 0;
for(int i = 100;i<1000;i++){

    for(int j = 100;j<=i;j++){
        bool p = pal(i,j);
        if(p){if(m<(i*j)){m = i*j;}
        }
    }
}

cout<<m<<endl;

return 0;
}
