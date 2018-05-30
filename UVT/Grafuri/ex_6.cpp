/* https://www.pbinfo.ro/?pagina=probleme&id=431 */

#include <iostream>
#include <fstream>

std::ifstream fin("graf_complet.in");
std::ofstream fout("graf_complet.out");

bool result(int& x, int n){
    if(((n*(n-1))/2)==x/2) return true;
    return false;
}
void _func(){
    int n, m, _count = 0;
    fin>>n;
    for(int i = 0; i < n*n; i++){
        fin>>m;
        if(m==1) _count++;
    }
    if(result(_count, n)) fout<<"DA\n";
    else fout<<"NU\n";
}
void func(){
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
        _func();
}
int main(){
    func();
}
