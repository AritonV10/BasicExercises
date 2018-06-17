/* https://www.pbinfo.ro/?pagina=probleme&id=2343 */
/* not done */

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <iterator>
#include <limits>

std::ifstream in("bec.in");
std::ofstream out("bec.out");

typedef std::map<std::pair<int,int>,int>::iterator map_iterator;

enum Directions
{

    DIAGONAL_DOWN_RIGHT,
    DIAGONAL_UP_RIGHT,
    DIAGONAL_DOWN_LEFT,
    DIAGONAL_UP_LEFT,
};

bool is_line_blocked(int arr[][300], int line, int row, int bulb_line, int bulb_row)
{
    if(bulb_row > row)
    {
        if(line == bulb_line && row+1 == bulb_row)
            return true;
        else
            return false;
    }
    else
    {
        if(line == bulb_line && row-1 == bulb_row)
            return true;
        else
            return false;
    }
    return true;
}

bool is_row_blocked(int arr[][300], int line, int row, int bulb_line, int bulb_row)
{
    if(bulb_line > line)
    {
        if(arr[line+1][row] == arr[bulb_line][bulb_row])
            return true;
        else
            return false;
    }
    else
    {
        if(arr[line-1][row] == arr[bulb_line][bulb_row])
            return true;
        else
            return false;
    }
    return true;
}

bool is_diagonal_blocked(int arr[][300], int current_line, int current_row, int arr_line, int arr_row, int bulb_line, int bulb_row, Directions direction)
{

    int direction_line, direction_row;
    if(direction == DIAGONAL_DOWN_RIGHT)
    {
        direction_line = 1;
        direction_row = 1;
    }
    else if(direction == DIAGONAL_UP_RIGHT)
    {
        direction_line = -1;
        direction_row = 1;
    }
    else if(direction == DIAGONAL_DOWN_LEFT)
    {
        direction_line = 1;
        direction_row = -1;
    }
    else if(direction == DIAGONAL_UP_LEFT)
    {
        direction_line = -1;
        direction_row = -1;
    }

    int i = current_line, j = current_row;
    bool same_diagonal = false;
    for(;;)
    {
        if(current_row > bulb_row)
        {
            if(j == 0)
                return true;
        }
        else if(current_row < bulb_row)
        {
            if(j == arr_row - 1)
                return true;
        }
        if(arr[i+direction_line][j+direction_row] != arr[bulb_line][bulb_row])
        {
            i += direction_line;
            j += direction_row;
        }
        else
        {
            same_diagonal = true;
            break;
        }
    }
    if(same_diagonal)
    {
        if(arr[current_line+direction_line][current_row+direction_row] == arr[bulb_line][bulb_row])
            return true;
        else
            return false;
    }

    return false;

}
int prima_cerinta(int v[][300], int lines, int rows, std::vector<int>& _vector, std::vector<std::pair<int,int>>& _vector_doi, std::map<std::pair<int,int>,int>& light_bulbs_map)
{
    int luminated_trees_one = -1, luminated_trees_two = -1, bulb_energy_efficiency = std::numeric_limits<int>::max();
    for(map_iterator it = light_bulbs_map.begin(); it != light_bulbs_map.end(); it++)
    {
        std::pair<int,int> const& key = it->first;
        int bulb_energy = it->second;
        for(int i = 0; i < lines; i++)
        {
            for(int j = 0; j < rows; j++)
            {
                if(v[i][j] < 0)
                    continue;
                if(i < key.first && j < key.second )
                {
                    if( is_diagonal_blocked(v, i, j, lines, rows, key.first, key.second, DIAGONAL_DOWN_RIGHT))
                        _vector.push_back(v[i][j]);
                }
                else if(i != key.first && j == key.second)
                {
                    if( is_row_blocked(v, i, j, key.first, key.second ))
                        _vector.push_back(v[i][j]);
                }
                else if( i == key.first )
                {
                    if( is_line_blocked(v, i, j, key.first, key.second) )
                        _vector.push_back(v[i][j]);
                }
                else if ( i < key.first && j > key.second )
                {
                    if( is_diagonal_blocked( v, i, j, lines, rows, key.first, key.second, DIAGONAL_DOWN_LEFT) )
                        _vector.push_back(v[i][j]);
                }
                else if(i > key.first && j < key.second )
                {
                    if( is_diagonal_blocked( v, i, j, lines, rows, key.first, key.second, DIAGONAL_UP_RIGHT) )
                        _vector.push_back(v[i][j]);
                }
                else if(i > key.first && j > key.second )
                {
                    if( is_diagonal_blocked( v, i, j, lines, rows, key.first, key.second, DIAGONAL_UP_LEFT) )
                        _vector.push_back(v[i][j]);
                }
            }
        }
        if(static_cast<int>(_vector.size()) >= luminated_trees_two && bulb_energy < bulb_energy_efficiency)
        {
            _vector_doi.clear();
            luminated_trees_two = _vector.size();
            bulb_energy_efficiency = bulb_energy;
            _vector_doi.push_back(std::make_pair(key.first+1, key.second+1));
        }
        if(static_cast<int>(_vector.size()) > luminated_trees_one)
            luminated_trees_one = _vector.size();

        _vector.clear();
    }

    return luminated_trees_one;
}

void init_with_zeros(int v[][300], int lines, int rows)
{
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < rows; j++)
            v[i][j] = 0;
    }
}
void add_light_bulbs(int arr[][300], std::map<std::pair<int,int>,int>& light_bulbs_map)
{
    int bulb = -1;
    for(map_iterator it = light_bulbs_map.begin(); it != light_bulbs_map.end(); it++)
    {

        std::pair<int,int> const& key = it->first;
        arr[key.first][key.second] = bulb--;
    }
}
void init_with_nums(int v[][300], int lines, int rows)
{
    int _count = 1;
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < rows; j++)
            if(v[i][j] >= 0)
                v[i][j] = _count++;
    }
}
int arr[300][300];
auto main() -> int
{
    std::vector<int> cerinta_unu_rezultat;
    std::vector< std::pair<int,int> > cerinta_doi;
    int cerinta, lines, rows, light_bulbs, light_bulb_line, light_bulb_row, light_bulb_energy;
    in>>cerinta>>lines>>rows>>light_bulbs;
    
    std::map<std::pair<int,int>,int> light_bulbs_map;

    for(int i = 0; i < light_bulbs; i++)
    {
        in>>light_bulb_line>>light_bulb_row>>light_bulb_energy;
        light_bulbs_map.emplace(std::make_pair(light_bulb_line-1, light_bulb_row-1), light_bulb_energy);
    }

    init_with_zeros(arr, lines, rows);
    add_light_bulbs(arr, light_bulbs_map);
    init_with_nums(arr, lines, rows);

    int prima_cer_rezultat = prima_cerinta(arr, lines, rows, cerinta_unu_rezultat, cerinta_doi, light_bulbs_map);

    if(cerinta == 1)
        out<<prima_cer_rezultat;
    else
        out<<cerinta_doi.front().first << " " << cerinta_doi.front().second;

    return 0;
}
