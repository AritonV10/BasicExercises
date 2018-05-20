/* https://www.pbinfo.ro/?pagina=probleme&id=1018 */

#include <iostream>
int _conquer_(int arr[], int _start, int _sfarsit){
    if(_start==_sfarsit){
        if(arr[_start]%2 != 0) return 1;
        else return 0;
    }
    return _conquer_(arr, _start, (_start+_sfarsit)/2) + _conquer_(arr, ((_start+_sfarsit)/2)+1, _sfarsit);
}
int _divide_and_conquer(int arr[], int n){ return _conquer_(arr, 0, (n/2)) + _conquer_(arr, (n/2)+1, n-1); }
int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    std::cout<<_divide_and_conquer(arr, n);
}
