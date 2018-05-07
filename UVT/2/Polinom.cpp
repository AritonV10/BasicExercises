#include <iostream>

Date de test: z=2+3i, P(z)=2z3-3z2+z-6.

int la_putere(int a, int x, int m){
    if(m==0) return 1;
    return (a+x)*la_putere(a, x, m - 1);
}
int func(int coeficienti[], int marime_vector, int polinom_grad){
    int sum = 0, grad = polinom_grad;
    for(int i = 0; i < marime_vector; i++){
        if(i != marime_vector - 1)
            sum += coeficienti[i]*(la_putere(2, 3, grad));
        else if((i+1) == marime_vector)
            sum += (2+3)+(coeficienti[i]);

         std::cout<<sum << " SUMA \n";
        --grad;
        //std::cout<<sum << " SUMA";
    }
    return sum;
}
int main(){
    int arr_length;
    std::cin>>arr_length;
    int arr[arr_length];
    for(int i = 0; i < arr_length; i++)
        std::cin>>arr[i];
    std::cout<<func(arr, arr_length, arr_length);
}
