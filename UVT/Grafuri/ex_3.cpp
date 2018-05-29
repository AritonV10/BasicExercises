/* https://www.pbinfo.ro/?pagina=probleme&id=419 */

#include <iostream>
#include <fstream>

std::ifstream fin("subgraf1.in");
std::ofstream fout("subgraf1.out");

int gradeCol(int arr[][1000], int& length, int& line){
    int _countCol = 0;
    for(int i = 1; i <= length; i++)
        if(arr[line][i] != 0) _countCol++;
    return _countCol;
}
int gradeLine(int arr[][1000], int& length, int& line){
    int _countLine = 0;
    for(int i = 1; i <= length; i++)
        if(arr[i][line] != 0) _countLine++;
    return _countLine;
}
int grade(int arr[][1000], int length, int line){
    return (gradeCol(arr, length, line) + gradeLine(arr, length, line))/2;
}
int smallestGrade(int arr[][1000], int length){
    int _sGrade = 101, _g;
    for(int i = 1; i <= length; i++){
      _g = grade(arr, length, i);
      if( _g < _sGrade ) _sGrade = _g;
    }
    return _sGrade;
}
void removeLine(int arr[][1000], int length, int line){
    for(int i = 1; i <= length; i++){
        arr[line][i] = 0;
    }
    for(int i = 1; i <= length; i++){
        if(i==line) continue;
        for(int j = 1; j <= length; j++)
        if(j==line) arr[i][j] = 0;
    }
}
int connections(int arr[][1000], int length){
    int _count = 0;
    for(int i = 1; i <= length; i++)
        for(int j = 1; j <= length; j++)
            if(arr[i][j] != 0) _count++;
    return _count/2;
}
void func(int arr[][1000], int length, int _smallestGrade){
    for(int i = 1; i <= length; i++)
        if(grade(arr, length, i) == _smallestGrade)
            removeLine(arr, length, i);

}
void read(int arr[][1000], int& n, int& m, int& v){
    fin>>v;
    while(fin>>n>>m){
        if(arr[n][m] != 1){
            arr[n][m] = 1;
            arr[m][n] = 1;
        }
    }
}
int arr[1000][1000], n, m, varfuri;
int main(){
    read(arr, n, m, varfuri);
    int _s = smallestGrade(arr, varfuri);
    func(arr, varfuri, _s);
    fout << connections(arr, varfuri);
}
