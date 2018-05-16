/* https://www.pbinfo.ro/?pagina=probleme&id=1847 */
#include <iostream>

bool is_prime(int n){
    bool _is_prime = true;
    for(int i = 2; i < n; i++)
        if(n%i==0) _is_prime=false;
    return _is_prime;
}
int func(const int arr[], int arr_length, int& x, /*private*/ int k){
    if(arr_length == 0) return k;
    return func(arr, arr_length - 1, x, k+(is_prime(arr[arr_length]) ? arr[arr_length] : 0));
}
int func(const int arr[], int arr_length, int& x){
    return x = func(arr, arr_length - 1, x, 0);
}
int main(){
    int x, arr[] = {12, 7, 6, 3, 8, 5};
    func(arr, 6, x);
    std::cout<<x;
}
