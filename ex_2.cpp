/* https://www.pbinfo.ro/?pagina=probleme&id=43 */

#include <iostream>

int power(int k, int p){
    if(k == 0) return p;
    return power(k-1, p*10);
}

int dig(int k){
    int _count = 0;
    while(k > 0){
        _count++;
        k /= 10;
    }
    return _count;
}

double nreal(int n, int k){
    int s_dig = dig(k), s_z = power(s_dig, 1), x = (n * s_z) + k, x_cif = dig(x);
    return (double) x / s_z;
}

int main(){}
