/* https://www.pbinfo.ro/?pagina=probleme&id=417 */

#include <iostream>
#include <fstream>

std::ifstream fin("graf.in");
std::ofstream fout("graf.out");

int amount(int arr[][1000], int length, int _highestGrade){
     int _count = 0;
     for(int i = 0; i < length; i++){
        int _x = 0;
        for(int j = 0; j < length; j++){
            if(arr[i][j] != 0) _x++;
        }
        if(_x == _highestGrade) _count++;
    }

    return _count;
}
bool grade(int arr[][1000], int pos, int length, int _highestGrade){
    int _num = 0;
    for(int i = 0; i < length; i++)
        if(arr[pos][i] != 0) _num++;
    return _num == _highestGrade;
}

int highestGrade(int arr[][1000], int length){
    int _count = -1;
    for(int i = 0; i < length; i++){
        int _x = 0;
        for(int j = 0; j < length; j++){
            if(arr[i][j] != 0) _x++;
        }
        if(_x > _count) _count = _x;
    }
    return _count;
}
int arr[1000][1000], _grad[101], n, m, varfuri, high;
int main(){
   fin >> varfuri;
   while(fin >> n >> m){
        if(arr[n-1][m-1] != 1){
            arr[n-1][m-1] = 1;
            arr[m-1][n-1] = 1;
        }
   }
   high = highestGrade(arr, varfuri);
   int amountHigh = amount(arr, varfuri, high);
   fout << amountHigh << " ";
   for(int i = 0; i < varfuri; i++)
        if(grade(arr, i, varfuri, high)) fout << i+1 << " ";

}
