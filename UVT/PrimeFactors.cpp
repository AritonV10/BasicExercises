#include <iostream>

int last_dig(int n);
bool isDivisible(int num);
void easy_fun(int n);
std::vector<int> v;

int main(){
    easy_fun(55);
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout<<*it << " ";
    }

}
void easy_fun(int n){
    int _cop = n;
    while(true){
        int div = last_dig(_cop);
        if(!isDivisible(_cop)){
            v.push_back(_cop);
            break;
        }else{
             v.push_back(div);
            _cop /= div;
        }
    }
}

bool isDivisible(int num){
    for(int i = 2; i < num; i++)
        if(num % i == 0) return true;
    
    return false;
}
int last_dig(int n){
    for(int i = 2;;i++)
        if(n % i == 0) return i;
        else if(i > n) break;
}
