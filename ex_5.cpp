/* https://www.pbinfo.ro/?pagina=probleme&id=2144 */
#include <iostream>

bool vizitat[50001];
int diofantic(int vec_length, int arr[], int a, int b, int c){
    int _pairs = 0;
    long long sum_a, sum_b;
    bool _same = (a == b ? true : false);
    for(int i = 1; i <= vec_length; i++){
        sum_a = a*(arr[i]*arr[i]);
        if(sum_a > c) break;
        else if(_same){ if(vizitat[i]) continue; }
        for(int j = 1; j <= vec_length; j++){
            sum_b = b*(arr[j]*arr[j]);
            if(_same){ if(vizitat[j]) continue; }
            if(sum_a + sum_b == c && arr[i] != arr[j]) { if(_same) {vizitat[j] = true; } _pairs++; break;}
            else if(sum_a + sum_b > c) { break; }
        }     
    }
    return _pairs;
}
int main(){

    int a, b, c, l;
    std::cin>>a>>b>>c>>l;
    int arr[l];
    for(int i = 1; i <= l; i++)
        std::cin>>arr[i];
    std::cout<<diofantic(l, arr, a, b, c);

}
