#include <iostream>

bool isPrime(const int& n){
    unsigned short _s = 0;
    for(unsigned int i = 2; i < n; i++)
        if(n%i==0) _s++;

    return _s == 0;
}

void prime_range(const int& from, const int& to){
    for(int i = from; i <= to; i++)
        if(isPrime(i)) std::cout<< i << "\n";
}
int main(){
    prime_range(2, 30);
}
