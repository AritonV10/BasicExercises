#include <iostream>


int power(int numar, int power){
    int num = 1;
    for(int i = 1; i <= power; i++){
      num *= numar;
    }
    return num;
}
int fun(int numar, int baza){
    int sum = 0;
    for(int i = 0; i < baza; i++){
        sum += (numar%10)*power(baza, i);
        numar /= 10;
    }
    return sum;
}
int main()
{
    std::cout<<fun(2210, 5);
}





