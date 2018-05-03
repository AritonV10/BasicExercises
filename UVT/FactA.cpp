#include <iostream>
#include <memory>

int fac(int n){
    if(n == 0)
        return 1;
    return n * fac(n-1);
}
int dig(int& n){
    std::unique_ptr<int> unique_cop(&n);
    int _sum = 0;
    while(*unique_cop > 0){
        _sum += fac(*unique_cop%10);
        *unique_cop/=10;
    }
    return _sum;
}
int sum_of_fac_dig(int& n){
    return dig(n);
}
int main(){
   int x = 8984;
   std::cout<<sum_of_fac_dig(x);
}
