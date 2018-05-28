/* Interclasarea a doua tablouri intr-unul (numerele nu sunt ordonate) crescator */

#include <iostream>
#include <vector>

#define LIM_VALUE 2000000000
std::vector<int> _vector;
struct _pair{
    int smallest, pos;
    _pair(int s, int p) : smallest(s), pos(p) {}
    int getS() { return this->smallest; }
    int getP() { return this->pos; }
};
void _swapElements(int arr[], int a, int b){
    int* temp = &arr[a];
    arr[a] = arr[b-1];
    arr[b-1] = *temp;
}
void _swap(int arr[], int a, int b, int& length){
    if(a==length-1 && length != 1){ length--; return; }
    else if(a==length-1){ length--; return; }
    _swapElements(arr, a, b);
    length--;
}
_pair smallestNumberFinder(int arr[], int& length){
    int max_value = LIM_VALUE, pos;
    if(length == 1) return _pair(arr[0], 0);
    else
        for(int i = 0; i < length; i++){
            if(arr[i] < max_value) { max_value = arr[i]; pos = i; break; }
        }
    return _pair(max_value, pos);
}
int smallestNumber(int arr[], int _arr[], int& a, int& b){
    _pair _f = _pair(LIM_VALUE, -1), _s = _pair(LIM_VALUE, -1);
    if(a != 0) _f = smallestNumberFinder(arr, a);
    if(b != 0) _s = smallestNumberFinder(_arr, b);
    if(_f.getS() < _s.getS()){ _swap(arr, _f.getP(), a, a); return _f.getS(); }
    else { _swap(_arr, _s.getP(), b, b); return _s.getS(); }
    return 0;
}
void func(int arr[], int _arr[], int& a, int& b, int len_cop){
    for(int i = 0; i < len_cop; i++){
        _vector.push_back(smallestNumber(arr, _arr, a, b));
    }
}
void displayResult(){
    for(std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout<<*it << " ";
}
void input(int arr[], int length){
    for(int i = 0; i < length; i++)
        std::cin>>arr[i];
}
int arr[100000], _arr[100000];
int main(){
    int x, y;
    std::cin>>x;
    input(arr, x);
    std::cin>>y;
    input(_arr, y);
    func(arr, _arr, x, y, x+y);
    displayResult();
}
