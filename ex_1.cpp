#include <iostream>

int sum_cif(int k){
    int sum = 0;
    while(k > 0){
        sum += k % 10;
        k /= 10;
    }
    return sum;
}
int cif(int k, int a){
    if(k == a) return k;
    if(k < 10 && k != a) return 0;
    return cif(sum_cif(k), a);
}
bool is_equal(int k, int a){
    return cif(k, a) == a;
}
int func(int a, int k){
    int nr_apariti = 0;
    for(int i = a; i <= k; i++)
        if(is_equal(i, a)) nr_apariti++;
    return nr_apariti;
}

int main(){
    std::cout<<func(2, 100);
}




