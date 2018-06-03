#include <iostream>
#include <fstream>

//ifstream fin("test.in");
//ofstream fout("test.out");

void swap_elements(int * v, int a_pos, int b_pos){
    int temp = v[a_pos];
    v[a_pos]=v[b_pos];
    v[b_pos]=temp;
}
bool hasMore(int number){ return number==0; }
int findSmallest(int * v, unsigned v_size){
    int _pos = v_size;
    while(v[_pos] < v[_pos-1] && _pos > 1) _pos--;
    return _pos - 1;
}
void sort_array(int * v, unsigned v_size, int _pos){
    for(int i = v_size; i > _pos; i--){
        for(int j = _pos; j < i; j++){
            if(v[j] > v[j+1])
                swap_elements(v, j, j+1);
        }
    }
}
void display_array(int * v, unsigned v_size){
    for(int i = 1; i <= v_size; i++)
        std::cout<<v[i] << " ";
    std::cout<<"\n";
}
void func(int*v, unsigned v_size){
    int _pos;
    do{
         _pos = findSmallest(v, v_size);
        if(_pos){
            int b_num = v[_pos+1], b_cop = b_num, b_pos=_pos+1;
            for(int i = _pos + 1; i <= v_size; i++)
                if(b_num > v[i] && v[i] > v[_pos]) { b_num = v[i]; b_pos = i; }
            if(b_cop == b_num) swap_elements(v, _pos, _pos+1);
            else swap_elements(v, _pos, b_pos);
            sort_array(v, v_size, _pos+1);
            display_array(v, v_size);
        }
    }while(_pos);
}
auto main() -> int{
   int arr[100];
   unsigned numberUpTo;
   std::cin>>numberUpTo;
   for(unsigned i=1;i<=numberUpTo;i++) arr[i]=i;
   func(arr, numberUpTo);
}
