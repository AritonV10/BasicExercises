/* https://www.pbinfo.ro/?pagina=probleme&id=422 */

#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("graf_partial_2.in");
std::ofstream fout("graf_partial_2.out");

int gradesHelper(int arr[][1000], int length){
    int _b = -1;
    for(int i = 1; i <= length; i++){
        int s = 0;
        for(int j = 1; j <= length; j++)
            if(arr[i][j] != 0) s++;              
        if(s > _b) _b = s;
    }
    return _b;
}
int grades(int arr[][1000], int& length){ return gradesHelper(arr, length); }
void removeConnection(int arr[][1000], int& line, int& _b){ arr[line][_b] = 0; arr[_b][line] = 0; }
void checkConnection(int arr[][1000], std::vector<int>& _vec, int& length, int line, int& _b, int& _count){
    for(int i = 1; i <= length; i++){
        for(std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++){
            if(arr[line][*it] != 0){
                removeConnection(arr, line, *it);
                _count++;
            }
        }
    }
}
int lineGrade(int arr[][1000], int& length, int line){
    int _count = 0;
    for(int i = 1; i <= length; i++)
        if(arr[line][i] != 0) _count++;
    return _count;
}
void func(int arr[][1000], int& length, std::vector<int>& _vec, int& _b){
    for(int i = 1; i <= length; i++){
        if(lineGrade(arr, length, i) == _b)
            _vec.push_back(i);
    }
}
void _func(int arr[][1000], int& length, std::vector<int>& _vec, int& _b, int& pairs){
    int _count = 0;
    for(int i = 1; i <= length; i++){
        checkConnection(arr, _vec, length, i, _b, _count);
    }
    pairs = _count;
}
void result(int arr[][1000], int& length, std::vector<int>& _vec, int& pairs){
    int _g = grades(arr, length);
    func(arr, length, _vec, _g);
    _func(arr, length, _vec, _g, pairs);
}
void display(int arr[][1000], int length){
    for(int i = 1; i <= length; i++){
        for(int j = 1; j <= length; j++)
            fout<<arr[i][j] << " ";
        fout<<"\n";
    }
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
int arr[1000][1000], n, m, varfuri, pairs;
std::vector<int> _vec;
int main(){
    read(arr, n, m, varfuri);
    result(arr, varfuri, _vec, pairs);
    fout<< pairs << " \n";
    display(arr, varfuri);
}
