/* https://www.pbinfo.ro/?pagina=probleme&id=913 */

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <iterator>

bool is_prime_bool(int& number)
{
    for(int i = 2; i < number; i++)
        if(number % i == 0) return false;
    return true;
}

int is_prime(int& from)
{
    for(int i = from + 1;;i++)
    {
        for(int k = 2; k < i; k++)
        {
           if(i % k == 0) break;
           if(k == i-1 && i % k != 0) return i;
        }
    }
    return -1;
}
void next_prime(int& number)
{
    number = is_prime(number);
}

void display(int * arr, unsigned& v_size)
{
    for(unsigned i = 0; i < v_size; i++)
        std::cout<< arr[i] << " ";
}
void read()
{
    unsigned v_size;
    std::cin>>v_size;
    int arr[v_size];
    for(unsigned i = 0; i < v_size; i++)
    {
        int _num;
        std::cin>>_num;
        if(is_prime_bool(_num)) arr[i] = _num;
        else { next_prime(_num); arr[i] = _num; }
    }
    display(arr, v_size);
}

int main()
{
    read();
    return 0;
}
