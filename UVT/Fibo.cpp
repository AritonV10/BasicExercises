#include <iostream>

void fib_swap(int& a, int& b, int& c){
    c = a + b; a = b; b = c;
}
bool func(const int* n, const int* _p){
    int a = 0, b = 1, c = 0;
    for(int i = 0; i <= *n; i++){
        fib_swap(a, b, c);
        if(c == *_p)
            return true;
    }
    return false;
}
int main(){
    int x = 30, f = 34;
    int* _p = &x;
    int* p_ = &f;
    if(func(_p, p_))
        std::cout<<"Is part of fibo";
    else
        std::cout<<"Not part of fibo";
}
