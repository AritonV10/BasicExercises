#include <iostream>
#include <limits>
#include <vector>
#include <utility>

std::vector<std::pair<int,int>> _small, _big;
void display(std::vector<std::pair<int,int>>& _vec){
    for(auto it = _vec.begin(); it != _vec.end(); it++)
        std::cout<< (*it).first << " ";
}
void contains(int v[][100], int& v_line, int& v_column, std::pair<int,int>& _p, std::vector<std::pair<int,int>>& _vec){
    for(int i = 0; i < v_column; i++){
        if(i == _p.second) continue;
        else if(_p.first == v[v_line][i]){ _vec.push_back(std::make_pair(_p.first, i)); }
    }
}
void has_more(std::vector<std::pair<int,int>>& _vec, int v[][100], int& v_line, int& v_column){
    size_t vector_size = _vec.size();
    for(size_t it = 0; it < vector_size; it++){
        contains(v, v_line, v_column, _vec.at(it), _vec);
    }
}
void array_num(int v[][100], int& v_line, int& v_column){
    int _s = std::numeric_limits<int>::max(), _b = std::numeric_limits<int>::min(), b_p, s_p;
    for(int i = 0; i < v_column; i++){
        if(v[v_line][i] > _b) { _b = v[v_line][i]; b_p = i; }
        if(v[v_line][i] < _s) { _s = v[v_line][i]; s_p = i; }
    }
    _small.push_back(std::make_pair(_s, s_p));
    _big.push_back(std::make_pair(_b, b_p));
    has_more(_small, v, v_line, v_column);
    has_more(_big, v, v_line, v_column);
}
bool column(int v[][100], int& v_size, std::pair<int,int> _p, bool _s){
    for(int i = 0; i < v_size; i++){
        if(i == _p.second) continue;
        if(_s){ if(_p.first < v[i][_p.second]) return false; }
        else { if(_p.first > v[i][_p.second]) return false; }
    }
    return true;
}
void clear_vectors(){
    _small.clear();
    _big.clear();
}
int func(int v[][100], int& v_line, int& v_column){
    int _count = 0;
    for(int i = 0; i < v_line; i++){
        array_num(v, i, v_column);
        for(auto it = _small.begin(); it != _small.end(); it++)
                if( column(v, v_line, *it, true))
                        _count++;
        for(auto _it = _big.begin(); _it != _big.end(); _it++)
                if( column(v, v_line, *_it, false) )
                        _count++;
        clear_vectors();
    }
    return _count;
}
int arr[100][100];
auto main() -> int {
    int a, b;
    std::cin>>a>>b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++)
            std::cin>>arr[i][j];
    }
    func(arr, a, b);
    return 0;
}
