/* https://www.pbinfo.ro/?pagina=probleme&id=1150 */

#include <iostream>
int _conquer_(int arr[], int _start, int _sfarsit){
    if(_start==_sfarsit){
        if(arr[_start]%2 == 0) return 1;
        else return 0;
    }
    return _conquer_(arr, _start, (_start+_sfarsit)/2) + _conquer_(arr, ((_start+_sfarsit)/2)+1, _sfarsit);
}
int _numere_pare_(int arr[], int n){
    return (_conquer_(arr, 0, (n/2)) + _conquer_(arr, (n/2)+1, n-1)) == n;
}
int main(){
    unsigned int n = 2u; std::cin>>n;
    int arr[n];
    for(unsigned int i = 0; i < n; i++)
        std::cin>>arr[i];
    if(_numere_pare_(arr, n)) std::cout<<"DA";
    else std::cout<<"NU";
}
