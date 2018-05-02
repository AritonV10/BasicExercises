#include <iostream>
#include <climits>

int cif(int n){
    int _count = 0;
    while(n > 0){
        ++_count;
        n /= 10;
    }
    return _count;
}
int cif_at(int a, int b){
    int _count = 0;
    int num;
    while(a > 0){
        if(_count == b)
            return num;
        num = a % 10;
        a /= 10;
        _count++;
    }
}
int mirror_num(int num){
    int _mirror = 0;
    while(num > 0){
        int last = num % 10;
        _mirror = _mirror*10+last;
        num /= 10;
    }
    return _mirror;
}

int swap_num(int number, int a, int b){

    int closer_to_end = cif_at(number, b), closer_to_start = cif_at(number, a);
    int _mirror = 0, _count = 1;
    while(number > 0){     
        int last = number % 10;
        if(_count == b) 
            _mirror = _mirror*10+closer_to_start;
        else if(_count == a) 
            _mirror = _mirror*10+closer_to_end;
        else 
            _mirror = _mirror*10+last;
     
        _count++;
        number /= 10;
    }
    return _mirror;
}

int fun(unsigned int number, unsigned int a, unsigned int b){
    int reversed_num = swap_num(number, a, b);
    return mirror_num(reversed_num);
}

int main()
{
   std::cout<<fun(45612, 4, 2);
}





