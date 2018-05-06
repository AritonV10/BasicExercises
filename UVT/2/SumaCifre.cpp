#include <iostream>

int cif_sum(int cif){
    int sum = 0;
    while(cif > 0){
        sum += cif % 10;
        cif /= 10;
    }
    return sum;
}
int cif(int& cif){
    int num = 1;
    for(int i = 0; i < cif - 1; i++)
        num *= 10;
    return cif = num;
}
int func(int& digits, const int& sum_of_digits){
    int _num;
    cif(digits); // 3 -> 100;
    for(int i = digits;;++i){
        if(cif_sum(i) == sum_of_digits){
            _num = i;
            break;
        }
    }
    return _num;
}

int main(){
    int x = 3;
    std::cout<<func(x, 25);
}
