/* https://www.hackerrank.com/challenges/picking-numbers/problem */

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

#define NEW_NUMBER 1

std::ifstream in("hack.txt");
std::ofstream out("hack_out.txt");

void display(std::vector<int> _vec) {
    for(const auto & value : _vec)
        std::cout<<value<< " ";
    std::cout<<'\n';
}
int highest_element(std::map<int,int> & _map, const int & current_number) {
    int highest = 0, number;
    for(auto it = _map.begin(); it != _map.end(); ++it) {
        if(it->first == current_number) continue;
        else if(it->second > highest) {
            highest = it->second;
            number = it->first;
        }
    }
    return number;
}

int add_same_elements(std::vector<int> & _dummy, const int & number) {
    std::map<int,int> _map;
    for(unsigned i = 0; i < _dummy.size(); ++i) {
        auto val = _map.find(_dummy[i]);
        if(val == _map.end()) {
            _map.emplace(std::make_pair(_dummy[i], NEW_NUMBER));
        } else {
            val->second++;
        }
    }
    return highest_element(_map, number);
}
int _func(std::vector<int> & _vec) {
    std::vector<int> _dummy;
    int elements = 0, highest_pairs = 0;
    for(unsigned i = 0; i < _vec.size(); ++i) {
        if(_vec[i] == 0) continue;
        for(unsigned j = i; j < _vec.size(); ++j) {
            if(_vec[j] == 0) continue;
            else if(std::abs(_vec[i] - _vec[j]) == 1 || std::abs(_vec[i] - _vec[j]) == 0) {
                _dummy.push_back(_vec[j]);
            }
        }
        const auto num = add_same_elements(_dummy, _vec[i]);
        int current_number = _vec[i];
        if(_dummy.size() >= 3) {
            for(unsigned k = i; k < _vec.size(); ++k) {
                if(_vec[k] == num || _vec[k] == current_number) {
                    _vec[k] = 0;
                }
            }
            for(const auto & val : _dummy) {
                if(val == num || val == current_number)
                    ++elements;
            }
        }
        if(elements > highest_pairs) {
            highest_pairs = elements;
        }
         elements = 0;
        _dummy.clear();
    }

    return highest_pairs;
}
int main() {
    std::vector<int> _vec;
    int num;
    while(in >> num){
        _vec.push_back(num);
    }
    std::cout<<_func(_vec);
}
