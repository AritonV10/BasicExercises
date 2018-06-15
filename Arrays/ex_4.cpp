/* https://www.pbinfo.ro/?pagina=probleme&id=915 */

#include <iostream>

void display(int * v, size_t v_size)
{
    for(size_t i = 0; i < v_size; i++)
    {
        if(v[i] == 1) continue;
        else std::cout<<v[i] << " ";
    }

}
unsigned number_digits(int& number)
{
    unsigned _count = 0, _copy = number;
    while(_copy > 0)
    {
        _count++;
        _copy /= 10;
    }
    return _count;
}
void swap_elements(int * v, unsigned& a, size_t& b)
{
    unsigned temp_value = v[a];
    v[a] = v[b];
    v[b] = temp_value;
}
void reverse_array(unsigned v_size, int * v)
{
    unsigned i, j;
    for(i = 0, j = v_size - 1; i < (v_size/2); ++i, --j)
        swap_elements(v, i, j);
}
bool is_palindrom_helper(int * v, size_t v_size)
{
    unsigned i, j;
    size_t _size = (v_size % 2 == 0 ? (v_size/2) - 1 : (v_size)/2);
    for(i = 0, j = v_size - 1; i <= _size; ++i, --j)
        if(v[i] != v[j]) return false;
    return true;
}
bool is_palindrom(int number)
{
    unsigned digits = number_digits(number);
    if(digits == 1) return true;
    int arr[digits];
    for(unsigned i = 0; i < digits; i++)
    {
        arr[i] = number % 10;
        number /= 10;
    }
    if(is_palindrom_helper(arr, digits)) return true;
    else
    {
        reverse_array(digits, arr);
        if(is_palindrom_helper(arr, digits)) return true;
    }
    return false;

}

void read()
{

    size_t v_size;
    std::cin>>v_size;
    int arr[v_size];
    for(size_t i = 0; i < v_size; i++)
        std::cin>>arr[i];
    for(size_t i = 0; i < v_size; i++)
    {
        if(is_palindrom(arr[i]))
            arr[i] = 1;
    }
    display(arr, v_size);
}

auto main() -> int
{

    read();
    return 0;
}
