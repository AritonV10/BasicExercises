/* https://www.pbinfo.ro/?pagina=probleme&id=1847 */
#include <iostream>

bool is_prime(int n){
    int _p = 1;
    for(int i = 2; i < n; i++)
        if(n%i==0) _p=-1;
    return _p == 1;
}
int func(const int arr[], int arr_length, int& x, /*private*/ int k){
    if(arr_length == 1) return k;
    return func(arr, arr_length - 1, x, k+= (is_prime(arr[arr_length])));
}
int func(const int arr[], int arr_length, int& x){
    return x = func(arr, arr_length - 1, x, 0);
}
int main(){
    int x, arr[] = {1, 5, 5, 6, 6, 3, 5, 5};
    func(arr, 8, x);
    std::cout<<x;
}
