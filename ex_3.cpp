/* https://www.pbinfo.ro/?pagina=probleme&id=1501 */

#include <iostream>

int pow_d(int number, int power) {
    if(power == 1) return number;
    return pow_d(number * number, power - 1);
}
bool is_norocos(int n, int k){
    int x = n;
    for(int i = 1; i < x; i++){
        int sum = 0, _count = 0;
        for(int j = i; j < x; j++){
            sum += j;
            _count++;
            if(sum == x && _count == k ) return true;
            if(sum > x) break;
        }
    }
    return false;
}
int norocoase(int k, int a){
    int _count = 0;
    for(int i = k; i <= a; i++){
        if(i == 1) _count++;
        if(is_norocos(pow_d(i, 2), i)) { std::cout << i << " "; _count++; }
    }
    return _count;
}
