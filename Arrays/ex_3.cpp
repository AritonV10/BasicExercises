/* https://www.pbinfo.ro/?pagina=probleme&id=1664 */

#include <iostream>
#include <fstream>

std::ifstream fin("palindrom_ciclic.in");
std::ofstream fout("palindrom_ciclic.out");

bool back_to_start(int * v, int * _v, unsigned v_size){
    for(unsigned i = 0; i < v_size; i++)
        if(v[i] != _v[i]) return false;
    return true;
}
void swap_helper(int * v, unsigned int a, unsigned int b){
    unsigned t = v[b];
    v[b] = v[a];
    v[a] = t;
}
void swap_elements(int * v, unsigned v_size){
    for(unsigned i = 2; i < (v_size); i++)
        swap_helper(v, i, i-1);
    swap_helper(v, 0, v_size-1);
}
bool is_palindrom_ciclic(int * v, unsigned v_size){
    unsigned i, j;
    for(i = 0, j = v_size-1 ; i < (v_size/2); i++, j--)
        if(v[i] != v[j]) return false;
    return true;
}
void func(int * v, int * _v, unsigned v_size){
    int _count = 0;
    bool is_over = false;
    while(!is_palindrom_ciclic(v, v_size)){
        swap_elements(v, v_size);
        if(back_to_start(v, _v, v_size)){
             is_over = true;
             break;
        }
        _count++;
    }
    if(is_over) fout << "NU";
    else fout<<"DA " << _count;
}
void read_elements(int * v, int * _v, unsigned v_size){
    int element;
    for(unsigned i = 0; i < v_size; i++){
        fin>>element;
        v[i] = element;
        _v[i] = v[i];
    }
}
int arr[1001], cop[1001];
auto main() -> int {
    unsigned v_size;
    fin>>v_size;
    read_elements(arr, cop, v_size);
    func(arr, cop, v_size);

}
