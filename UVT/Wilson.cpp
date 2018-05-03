#include <iostream>

int func(int p){
    if(p == 0) return 1;
    return p * func(p-1);
}

// is prime if (n-1)! + 1 is divizible by n
bool wilson(int n){
    if((func(n-1)+1)%n==0)
        return true;
    else
        return false;
}
int main(){

   if(wilson(11))
    std::cout<<"PRIME";
   else
    std::cout<<"NOT_PRIME";

}
