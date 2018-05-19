/* https://www.pbinfo.ro/?pagina=probleme&id=1148 */

#include <iostream>
int func(int arr[], int _start, int _sfarsit){
    // 1, 2, 4, 3, 4, 5 6, 7, 8, 9, 10-> n/2-1 -> 1, 2, 3, 4, 5 (0, 1, 2, 3, 4)
    if(_start+1==_sfarsit) return arr[_start] + arr[_sfarsit];
    else if(_start == _sfarsit) return arr[_start];
    if(_start==0) return func(arr, _start, _sfarsit/2) + func(arr, _start+((_sfarsit/2)+1), _sfarsit); 
    else return func(arr, _start, _sfarsit-2) + func(arr, _start+(_sfarsit%2==0 ? 1 : 2), _sfarsit); 
}
bool combine(int first_half, int second_half){
    if((first_half + second_half) % 2 != 0) return true;
    return false;
}
bool has_odd(int n, int arr[]){
    return combine(func(arr, 0, (n/2)-1), func(arr, (n/2), n-1));
}
int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        std::cin>>arr[i];
    if(has_odd(n, arr)) std::cout<<"DA";
    else std::cout<<"NU";

}
