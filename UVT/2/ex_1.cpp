/* https://www.pbinfo.ro/?pagina=probleme&id=1001 */

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <iterator>
#include <fstream>

std::ifstream in("rotund.in");
std::ofstream out("rotund.out");

typedef std::vector<int> int_vector;
typedef typename std::vector<int>::iterator vector_iterator;

void swap_helper(vector_iterator a, vector_iterator b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swap_elements(int_vector& _vec)
{
    for(vector_iterator it = _vec.begin(); it != _vec.end() - 1; it++)
        swap_helper(it, it+1);
}
void display(int_vector _vec)
{
    for(vector_iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout<< *it << " ";
    std::cout<<std::endl;
}
void reverse_elements(int_vector& _vec)
{
    vector_iterator _begin = _vec.begin(), _end = _vec.end();
    while(_begin != _end)
    {
        --_end;
        if(_end != _begin) swap_helper(_begin++, _end);
        else break;
    }
}
int is_rotund_helper(int_vector& _vec)
{
    int _num = 0;
    for(vector_iterator it = _vec.begin(); it != _vec.end(); it++)
        _num = _num * 10 + *it;
    return _num;
}
bool is_rotund(int_vector& _vec, int _num)
{
    return is_rotund_helper(_vec) == _num;
}
void fragment(int _num, int_vector& _vec)
{
    int _cop = _num;
    while(_cop > 0)
    {
        _vec.push_back(_cop % 10);
        _cop /= 10;
    }
    reverse_elements(_vec);
}

bool rotund(int num, int_vector& _vec)
{
    unsigned _num = 1;
    fragment(num, _vec);
    size_t _vec_size = _vec.size();

    while(_num < _vec_size)
    {
        swap_elements(_vec);
        if(is_rotund(_vec, num))
        {
            _vec.clear();
            return true;
        }
        _num++;
    }
    _vec.clear();
    return false;
}
int main()
{
    int_vector _vec, result_vector;
    unsigned _num;
    in>>_num;

    for(unsigned i = 0; i < _num; i++)
    {
        int x;
        in>>x;
        if(rotund(x, _vec))
            result_vector.push_back(x);
    }

    if(result_vector.size() == 0)
    {
        out << 0;
        return 0;
    }

    out << result_vector.size() <<  "\n";
    for(vector_iterator it = result_vector.begin(); it != result_vector.end(); it++)
       out << *it << " ";
    

    return 0;
}
