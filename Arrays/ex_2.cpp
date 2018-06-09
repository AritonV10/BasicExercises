/* https://www.pbinfo.ro/?pagina=probleme&id=1307 */

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <utility>
#include <ctime>

fstream fout("cop.out");
ifstream fin("cop.in");


void display(std::vector<int>& _vec){
    for(auto it = _vec.begin(); it != _vec.end(); it++)
        std::cout<<*it << " ";
}
bool is_prime(int _num){
    bool _test = true;
    for(int i = 2; i < _num; i++)
        if(_num%i==0) _test=false;
    return _test;
}
bool is_alone(std::vector<int>& _vec, int number){
    int _count = 0;
    for(auto it = _vec.begin(); it != _vec.end(); it++)
        if(*it == number) _count++;
    return _count == 1;
}
bool vector_contains_factor(std::vector<int>& _vec, int number){
    for(auto it = _vec.begin(); it != _vec.end(); it++)
        if(*it == number) return true;
    return false;
}
void vector_prime_factors(std::vector<int>& prime_vector, std::vector<int>& _vec){
    for(auto it = prime_vector.begin(); it != prime_vector.end(); it++)
        if(is_prime(*it) && !vector_contains_factor(_vec, *it) && is_alone(prime_vector, *it)) _vec.push_back(*it);
}
void sort_vector(std::vector<int>& _vec){
    sort(_vec.begin(), _vec.end());
}
void prime_factors_increment(int& a, int& b) { a += 1; b = 2;}
void prime_factors_helper(int number, std::vector<int>& _vec){
    int divisor = 2, divided = 2;
    if(is_prime(number)) { _vec.push_back(number); return; }
    for(;;){
        if(divisor == number) {
            _vec.push_back(number);
            break;
        } else if(divided == number){ prime_factors_increment(divisor, divided); }
        if(divisor*divided != number && divisor*divided > number){ prime_factors_increment(divisor, divided); }
        else if (divisor*divided != number){ divided++; }
        else if(divisor*divided == number){
            _vec.push_back(divisor);
            number = divided;
            divided = 2;
            divisor = 2;
        }
    }
}
void prime_factors_function(std::vector<int>& _vec, std::vector<int>& dummy_vec, int * v, unsigned v_size){
    for(unsigned i = 0; i < v_size; i++){
        prime_factors_helper(v[i], dummy_vec);
        vector_prime_factors(dummy_vec, _vec);
        dummy_vec.clear();
    }
    sort_vector(_vec);
    if(_vec.empty()) std::cout<<"Sirul Y este vid";
    else display(_vec);
}
void display_array(int * v, unsigned v_size){
    for(unsigned i = 0; i < v_size; i++)
        std::cout<<v[i] << " ";
}
void read_array(int * v, unsigned v_size){
    for(unsigned i = 0; i < v_size; i++)
        std::cin>>v[i];
}
int arr[501];
std::vector<int> result, prime_factors;
auto main() -> int {

    std::clock_t start;
    start = std::clock();
    
    unsigned arr_size, number_of_elements;
    std::cin>>arr_size;
    read_array(arr, arr_size);
    prime_factors_function(result, prime_factors, arr, arr_size);

    std::cout << "\n\nTime: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
}
