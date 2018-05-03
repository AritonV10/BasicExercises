#include<iostream>
#include<stdarg.h>

bool isPrime(const int& size_of_varargs, ...){
    va_list args;
    va_start(args, size_of_varargs);
    unsigned short _s = 0;
    for(unsigned int j = 0; j < size_of_varargs; j++){
        int num = va_arg(args, int);
        for(unsigned int i = 2; i < num; i++)
            if(num%i==0) _s++;

        if(_s != 0) break;
    }

    va_end(args);
    return _s == 0;
}

void prime_range(const int& size_of_var, const int& num){
   for(int i = 2; i < num; i++)
        if(isPrime(size_of_var, i-1, i+1))
            std::cout<< i << " \n";
}
int main(){
    int size_ = 2, num = 43;
    prime_range(size_, num);
}
