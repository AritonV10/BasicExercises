#include <iostream>

bool hasNext(int * v, unsigned _pos, unsigned numberUpTo){
    if((unsigned) v[_pos] < numberUpTo){ v[_pos]++; return true; }
    else return false;
}
bool isValid(int * v, unsigned _pos){
    for(unsigned i = 0; i < _pos; i++)
        if(v[i] == v[_pos])
            return false;
    return true;
}
void display_array(int * v, unsigned& v_size){
    for(unsigned i = 0; i < v_size; i++)
        std::cout<<v[i] << " ";
    std::cout<<"\n";
}
void back_tracking(int * v, unsigned _pos, unsigned& numberUpTo){
    if(_pos == numberUpTo){
        display_array(v, _pos);
    } else {

        v[_pos] = 0; // 0 = 1 -> 1 = 2 -> 2 = 3
        display_array(v, x);
        while(hasNext(v, _pos, numberUpTo)){
            if(isValid(v, _pos)){
                back_tracking(v, _pos+1, numberUpTo); /// 0 -> 1 -> 2 -> 3
            }
        }
    }
}
int arr[100];
auto main() -> int{
   unsigned upTo = 3;
   back_tracking(arr, 0, upTo);
}
