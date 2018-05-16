/* https://www.pbinfo.ro/?pagina=probleme&id=826 */
#include <iostream>

bool is_last = true;
int func(int a, int b, int c = 0, int pow = 1){
    if(a == 0) return c;
    if(a%10 != b){
        if(is_last){ c = a % 10; is_last = false; }
        else c = ((a%10)*pow) + c;
    } else { return func(a/10, b, c, pow); }
    return func(a/10, b, c, pow*10);
}
int main(){
    std::cout<<func(2454, 4);
}
