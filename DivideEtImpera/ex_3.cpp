/* https://www.pbinfo.ro/?pagina=probleme&id=1017 */

#include <iostream>
int second_half(int arr[], int _start, int _sfarsit){
    if(_start > _sfarsit) return 0;
    if(_start==_sfarsit){
        if(arr[_start]%2==0) return arr[_start];
        else return 0;
    }
    return second_half(arr, _start, (_start+_sfarsit)/2) + second_half(arr, ((_start+_sfarsit)/2)+1 /*_start+((_sfarsit/_start)+(_sfarsit%2==0 ? 0 : 1))*/, _sfarsit);
}
int first_half(int arr[], int _start, int _sfarsit){
    if(_start > _sfarsit) return 0;
    if(_start==_sfarsit){
        if(arr[_start]%2==0) return arr[_start];
        else return 0;
    }
    return first_half(arr, _start, _sfarsit/2) + second_half(arr, (_sfarsit/2)+1, _sfarsit);
}
int combine(int first_half, int second_half) { return first_half + second_half; }
int has_odd(int n, int arr[]){
    return combine(first_half(arr, 0, (n/2)-1), second_half(arr, n/2, n-1));
}
int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    std::cout<<has_odd(n, arr);

}


