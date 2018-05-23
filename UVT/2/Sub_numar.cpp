/* BAC 2018 - sub3, ex4 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

size_t digits(int n, int _cif){
    if(n==0) return _cif;
    return digits(n/10, _cif+1);
}
int ten(int x, unsigned int z){
    if(z==2) return x;
    return ten(x*10, z-1);
}
int digits(int n){ return ten(1,digits(n,0)); }
int fragmentedDigits(int n, int div, int _div){
    return n/(div/_div)%100;
}
bool containsDigits(int n, int x, int div){
    int _x = fragmentedDigits(x, ten(1, digits(x, 0)), div);
    if(n==_x) { return true; }
    if(div==ten(1, digits(x, 0))) { return false; }
    return containsDigits(n, x, div*10);
}
void hasTheSameDigits(int arr[], const unsigned int arrLength){
    int firstNumberDivide = 1, digitsToCheck;
    bool sameDigits = false;
    for(unsigned int i = 0;;){
       if(i==arrLength) break;
       int _digitsToCheck = fragmentedDigits(arr[i], ten(1, digits(arr[i],0)), firstNumberDivide);
       if(firstNumberDivide != ten(1, digits(arr[i],0)))
            if(containsDigits(_digitsToCheck, arr[i], firstNumberDivide*10)){ i++; continue; }

       bool areSame = false;
       for(unsigned int j = 0; j < arrLength; j++){
            if(j==i) continue;
            int divisionHelper = 1;
            for(int k = 0; k < digits(arr[j], 0)-1; k++){
                int _digitsToCheckSecond = fragmentedDigits(arr[j], ten(1, digits(arr[j],0)), divisionHelper);
                if(_digitsToCheck==_digitsToCheckSecond) { areSame=true; break; }
                divisionHelper*=10;
            }
            if(areSame) break;
            else divisionHelper=1;
       }
       if(!areSame) std::cout<<_digitsToCheck << " ";
       if(firstNumberDivide==ten(1, digits(arr[i],0))){ i++; firstNumberDivide=1; continue; }
       firstNumberDivide *= 10;
    }
}
int main(){
    int arr[] = {391, 7772, 4358, 23972};
    hasTheSameDigits(arr, 4);
}



