/*https://www.pbinfo.ro/?pagina=probleme&id=1015*/
#include <iostream>
int combine(int first_half_sum, int second_half_sum) { return first_half_sum + second_half_sum; }
int second_half(int arr[], int st, int d){ // 5, 6, 7, 8 -> 8/(5-1) -> 6 -> [5, 6]
    if(st+1 == d) return arr[st] + arr[d];
    else if(st == d) { return arr[st]; }
    return second_half(arr, st, d-(d/((d/2)))) + second_half(arr, st+(d/st), d); // 5, 6, 7 -> 5+(7/4) -> 5+1 -> 6 -> [6, 7]
}
int first_half(int arr[], int st, int d){
    if(st+1 == d) return arr[st] + arr[d];
    else if(st == d) return arr[st];
    return first_half(arr, st, (d/2)) + first_half(arr, st+(d/2), d);
}
int divide(int n, int arr[]){
   return combine(first_half(arr, 1, (n/2)), second_half(arr, (n/2)+1, n));
}

int main(){
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 1; i<=n; i++)
        std::cin>>arr[i];
    std::cout<<divide(n, arr);
}
