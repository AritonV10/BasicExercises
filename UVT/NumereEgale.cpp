#include <iostream>

int dig(int n){
    int digits = 0;
    while(n > 0){
        digits++;
        n /= 10;
    }
    return digits;
}

int bigger(int n, int m){return n > m ? n : m;}


int smaller(int n, int m){return n < m ? n : m;}

bool fun(int n, int m){
   bool egale = false;

   int s_cop = smaller(n, m), copie = bigger(n, m);
   int b_digits = dig(bigger(n, m)), s_digits = dig(smaller(n, m));

   int arr[b_digits], s_copie = smaller(n, m);
   for(int i = 0; i < b_digits; i++){
        arr[i] = copie % 10;
        copie /= 10;
   }
   for(int i = 0; i < s_digits; i++){
        for(int j = 0; j < b_digits; j++){
            if(s_cop == 0) break;
            if(arr[j] != s_cop % 10){
                continue;
            }
            if(arr[j] == s_cop % 10) {
                egale = true;
                break;
            }
        }
        if(!egale)
            break;

        s_copie /= 10;
        s_cop = s_copie;
   }
   return egale;
}

int main()
{
    if(fun(63326, 623))
        std::cout<<"Egale";
    else
        std::cout<<"Nu sunt in baza 10";

}
