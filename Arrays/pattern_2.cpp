#include <iostream>


int arr[1025][1025];

void ternary_helper();

void display(int arr[1025][1025], unsigned & arr_size)
{
    for(unsigned i = 0; i < arr_size; ++i)
    {
        for(unsigned k = 0; k < arr_size; ++k)
        {
            std::cout<<arr[i][k] << " ";
        }
        std::cout<<'\n';
    }
}

void init_array(int arr[1025][1025], unsigned & arr_size, bool & is_init)
{
    for(unsigned i = 0; i < arr_size/2; ++i)
    {
        for(unsigned k = 0; k < arr_size/2; ++k)
        {
            arr[i][k] = 1;
        }
    }
    is_init = true;
}

void result_helper(int arr[1025][1025], unsigned arr_size, unsigned unchanged_arr_size, unsigned f_line = 0, unsigned t_line = 0, unsigned f_col = 0, unsigned t_col = 0)
{
    static bool is_init = false;
    if(!is_init)
        init_array(arr, arr_size, is_init);
    if(arr_size != unchanged_arr_size)
    {
        for(unsigned i = f_line; i < t_line-1; ++i)
        {
            for(unsigned j = f_col; j < t_col-1; ++j)
            {
                arr[i][j] = 1;
                if((i == f_line && j + 1 == t_col-1)) arr[i][j+1] = 1;
                else if(i + 1 == t_line - 1 && j == f_col) arr[i+1][j] = 1;
                else if(i + 1 == t_line - 1 && j+1 == t_col-1) arr[i+1][j+1] = 1;

            }
        }

        return;
    }
    unsigned half_middle = (arr_size/2);
    result_helper(arr, arr_size/2, unchanged_arr_size, 0, half_middle-1, half_middle, arr_size-1);
    result_helper(arr, arr_size/2, unchanged_arr_size, half_middle, arr_size-1, 0, half_middle-1);
    result_helper(arr, arr_size/2, unchanged_arr_size, half_middle, arr_size-1, half_middle, arr_size-1);
}

void result(int arr[1025][1025], unsigned arr_size)
{
    result_helper(arr, arr_size, arr_size);
}
auto main() -> int
{
    unsigned power;
    std::cin>>power;
    unsigned array_size = 1 << power;
    result(arr, array_size);
    display(arr, array_size);

}
