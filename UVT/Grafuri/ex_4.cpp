/*https://www.pbinfo.ro/?pagina=probleme&id=421*/

#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("graf_partial_1.in");
std::ofstream fout("graf_partial_1.out");

struct g{
    int small, big;
    g(int s, int b) : small(s), big(b) {}
    int getSmall() { return this->small; }
    int getBig() { return this->big; }
};
int gradesHelper(int arr[][1000], int length, bool _t){
    int _s = 101, _b = -1;
    for(int i = 1; i <= length; i++){
        int s = 0;
        for(int j = 1; j <= length; j++){
            if(arr[i][j] != 0){
                s++;
            }
        }
        if(!_t && s < _s) _s = s;
        else if(_t && s > _b) _b = s;
    }
    return _t ? _b : _s;
}
g grades(int arr[][1000], int length){
    return g( gradesHelper(arr, length, false), gradesHelper(arr, length, true) );
}
void removeConnection(int arr[][1000], int length, int line, std::vector<int>& _vec){
    for(int i = 1; i <= length; i++)
        for(std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
        if(i == *it)  { arr[line][i] = 0; arr[i][line] = 0; }
}
int lineGrade(int arr[][1000], int length, int line){
    int _count = 0;
    for(int i = 1; i <= length; i++)
        if(arr[line][i] != 0) _count++;

    return _count;
}
void func(int arr[][1000], int length, std::vector<int>& _vec, int _b){
    for(int i = 1; i <= length; i++){
        if(lineGrade(arr, length, i) == _b)
            _vec.push_back(i);
    }
}
void _func(int arr[][1000], int length, std::vector<int>& _vec, int _s, int& pairs){
    int _count = 0;
    for(int i = 1; i <= length; i++){
        if(lineGrade(arr, length, i) == _s){
            removeConnection(arr, length, i, _vec);
            _count++;
        }
    }
    pairs = _count;
}

void result(int arr[][1000], int length, std::vector<int>& _vec, int& pairs){
    g _g = grades(arr, length);
    func(arr, length, _vec, _g.getBig());
    _func(arr, length, _vec, _g.getSmall(), pairs);
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
