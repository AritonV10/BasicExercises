/**

  Exercise: calculate the sum of n!

**/
int FactorialFun(int n){
    if(!n) return 1;
    return n * FactorialFun(n - 1);
}
int main(){
    const int sum = FactorialFun(4);
    std::cout << sum;
}
