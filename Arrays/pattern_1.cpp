/* https://www.pbinfo.ro/?pagina=probleme&id=1952 */

#include <iostream>


void display(int result_array[600][600], unsigned & result_array_size)
{
    for(unsigned i = 0; i < result_array_size; ++i)
    {
        for(unsigned j = 0; j < result_array_size; ++j)
            std::cout<<result_array[i][j] << " ";
        std::cout<<'\n';
    }
}

int int_pow(int number, int number_helper, int power)
{
    if(power == 1) return number;
    return int_pow(number*number_helper, number_helper, power - 1);
}
int int_pow(int n, int power)
{
    return int_pow(n, n, power);
}

void copy_pattern_helper(int result_array[600][600], int f_line, int t_line, int f_col, int t_col)
{
    int pos_i = 0, pos_k = 0;
    for(int i = f_line; i <= t_line; ++i)
    {
        for(int k = f_col; k <= t_col; ++k)
        {
            result_array[i][k] = result_array[pos_i][pos_k++];
        }
        ++pos_i;
        pos_k = 0;
    }
}

void copy_pattern(int result_array[600][600], int result_array_size)
{
    int middle = result_array_size/2;
    copy_pattern_helper(result_array, 0, middle, middle + 1, result_array_size);
    copy_pattern_helper(result_array, middle+1, result_array_size, 0, middle);
    copy_pattern_helper(result_array, middle+1, result_array_size, middle + 1, result_array_size);
}
void generate_pattern(int result_array[600][600], unsigned number, int middle)
{

   if(number == 2)
   {
        for(unsigned i = 0; i < 3; ++i)
        {
            for(unsigned j = 0; j < 3; ++j)
            {
                if(j%2!=0 || i%2!=0) continue;
                result_array[i][j] = number - 1;
            }
        }

        result_array[1][1] = number;
        return;
   }

   generate_pattern(result_array, number - 1, middle/2);
   result_array[middle][middle] = number - 1;
   copy_pattern(result_array, int_pow(2, number)-1);
}

void pattern(int result_array[600][600], unsigned & number, unsigned middle)
{
    generate_pattern(result_array, number, middle/2);
    result_array[middle][middle] = number;
}

auto main() -> int
{
    unsigned n;
    std::cin>>n;
    unsigned v_size = int_pow(2, n)-1;
    unsigned middle = (v_size-1)/2;
    int result_array[600][600];
    for(unsigned i = 0; i < v_size; ++i)
    {
        for(unsigned j = 0; j < v_size; ++j)
           result_array[i][j] = 0;
    }
    pattern(result_array, n, middle);
    display(result_array, v_size);

}
