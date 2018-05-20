
#include <iostream>
/* https://www.pbinfo.ro/?pagina=probleme&id=1149 */

#include <iostream>
bool prime(int _numar, /* private */ int _private_number){
    if(_private_number == 1) return true;
    if(_numar%_private_number==0) return false;
    return prime(_numar, _private_number-1);
}
bool prime(int _numar){
    if(_numar % 2 == 0) return false;
    return prime(_numar, _numar-1);
}
int _conquer_(int arr[], int _start, int _sfarsit){
    if(_start+1==_sfarsit){
        if( arr[_start] + arr[_sfarsit] % 2 != 0){
            if( prime(arr[_start]) || prime(arr[_sfarsit]) ) return 1;
            else return 0;
        } else { return 0; }
    }
    if(_start==_sfarsit){
        if( prime(arr[_start]) ) return 1;
        else return 0;
    }
    return _conquer_(arr, _start, (_start+_sfarsit)/2) + _conquer_(arr, ((_start+_sfarsit)/2)+1, _sfarsit);
}
int _primes(int arr[], int n){
    if( (_conquer_(arr, 0, (n/2))) != 0) return 1;
    if( (_conquer_(arr, (n/2)+1, n-1)) != 0) return 1;
    return 0;
}
int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    if(_primes(arr, n)!=0) std::cout<<"DA";
    else std::cout<<"NU";

}


