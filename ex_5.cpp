/* https://www.pbinfo.ro/?pagina=probleme&id=2144 */
#include <iostream>

bool vizitat[50001];
int diofantic(const unsigned int vec_length, const int arr[], const int a, const int b, const int c){
    int _pairs = 0;
    long sum_a, sum_b;
    for(unsigned int i = 1; i <= vec_length; i++){
        sum_a = a*(arr[i]*arr[i]);
        if(sum_a > c) break;
        //else if(vizitat[i]) continue;
        for(unsigned int j = 1; j <= vec_length; j++){
            sum_b = b*(arr[j]*arr[j]);
            //if(vizitat[j]) continue;
            if(sum_a + sum_b == c && arr[i] != arr[j]) { std::cout<<"(" << arr[i] << ", " << arr[j] << ") \n"; vizitat[j] = true; _pairs += 2; break;}
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
