/* https://www.pbinfo.ro/?pagina=probleme&id=418 */

#include <iostream>
#include <fstream>

std::ifstream fin("test.in");
std::ofstream fout("test.out");

bool isPrime(int n, int m){
    if(m==1) return true;
    else if(n%m==0) return false;
    return isPrime(n, m-1);
}
bool isPrime(int n){
    if(n==1) return false;
    return isPrime(n, n-1);
}

void removePrimeLine(int arr[][1000], int line, int length){
    for(int i = 1; i <= length; i++)
        arr[line][i] = 0;
}
void func(int arr[][1000], int length){
    for(int i = 1; i <= length; i++){
        if(isPrime(i)){ removePrimeLine(arr, i, length); continue; }
        for(int j = 1; j <= length; j++)
                if(isPrime(j))
                    arr[i][j] = 0;

    }
}
int connections(int arr[][1000], int length){
    int _count = 0;
    for(int i = 1; i <= length; i++)
        for(int j = 1; j <= length; j++)
            if(arr[i][j] != 0) _count++;
    return _count/2;
}
int arr[1000][1000],n, m, varfuri;
int main(){
    fin>>varfuri;
    while(fin>>n>>m){
        if(arr[n][m] != 1){
            arr[n][m] = 1;
            arr[m][n] = 1;
        }
    }
    func(arr, varfuri);
    fout<< connections(arr, varfuri);
}
