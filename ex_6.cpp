/*https://www.pbinfo.ro/?pagina=probleme&id=826*/
#include <iostream>

const int N_LIMIT = 2000000000;
int c = N_LIMIT;
bool has_even = false;
int cif(int n){
    if(n == 0 && N_LIMIT==c) return -1;
    else if(n == 0) return c;
    if(n%10<c && (n%10)%2==0) c = n % 10;
    return cif(n/10);
}
int cif_test(int n){
    if(n==0 && has_even) return N_LIMIT;
    else if(n==0 && !has_even) return -1;
    if((n%10)%2==0) { has_even = true; return n%10 < cif_test(n/10) ? n%10 : cif_test(n/10); }
    else return cif_test(n/10);
}
int main(){
     std::cout<<cif_test(534504);
}
