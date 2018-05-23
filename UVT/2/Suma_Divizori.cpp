/* 24 x=4, y=8, z=12 -> z>y>x -> z+y+x == n */

#include <iostream>
#include <vector>

int divisors[250];
std::vector<int> right_divisors;
std::vector<int>::iterator it = right_divisors.begin();
void func(int n, int& x, int& y, int& z){
    int idx = -1;
    for(int i = 2; i < n; i++)
        if(n%i==0) divisors[++idx] = i;

    if(idx==-1||idx==0) { x=0; y=0; z=0; return; }
    for(int i = idx;; i--){
        if(i==1) { x = 0; y = 0; z = 0; break; }
        right_divisors.push_back(divisors[i]);
        int sum = divisors[i];
        for(int j = i-1; j >= 0; j--){
            if(sum+divisors[j]<=n) { right_divisors.push_back(divisors[j]); sum+=divisors[j]; }
            if(sum==n) break;
        }
        if(sum==n) break;
        else { sum=0; right_divisors.empty(); }
    }
    if(right_divisors.empty()){ x=0; y=0; z=0; }
    else { z=right_divisors.at(0); y=right_divisors.at(1); x=right_divisors.at(2); }

}
int main(){
    int x, y, z;
    func(30, x, y, z);
    std::cout<<x << " " << y << " " << z;
}
