/* https://www.pbinfo.ro/?pagina=probleme&id=2344 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::ifstream in("dvorak.in");
std::ofstream out("dvorak.out");

typedef std::string::size_type s_size;

bool contains_same_size(std::string& last_password, std::string& contains_this)
{
 	s_size last_password_size = last_password.size();
    for(s_size i = 0; i < last_password_size; ++i)
     	if(last_password[i] != contains_this[i]) return false;   
    
    return true;
}
bool contains(std::string& last_password, std::string& contains_this)
{
    std::string dummy_string = "";
    s_size contains_size = contains_this.size(), last_password_size = last_password.size();
    
    if(contains_size > last_password_size)
        return false;
    else if(contains_size == last_password_size) 
        return contains_same_size(last_password, contains_this);
    
    for(s_size i = 0; i < last_password_size - contains_size + 1; ++i)
    {
        if((last_password_size-i) < contains_size) 
            return false;
        
        bool are_same = true;
        dummy_string += last_password[i];
        
        for(s_size j = i+1;; ++j)
        {
            dummy_string += last_password[j];
            s_size dummy_string_size = dummy_string.size();
            
            if(dummy_string_size == contains_size)
            {
                for(s_size k = 0; k < dummy_string_size; ++k)
                {
                    if(dummy_string[k] != contains_this[k])
                    {
                        dummy_string = "";
                        are_same = false;
                        break;
                    }
                }
            }
            if(!are_same)
                break;
            else if(dummy_string_size == contains_size && are_same)
                break;
        }
        if(are_same)
            return true;
    }

    return false;
}

void transform_string(std::string& arr, std::string& dvorak, const unsigned& from, const unsigned& to)
{
    static const unsigned ALFABHET_SIZE = 26;
    static const char ABC[] =
    {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
        't', 'u', 'v', 'w', 'x', 'y', 'z'
    };

    for(unsigned i = from; i < to; ++i)
    {
        const char current_character = arr[i];
        for(unsigned j = 0; j < ALFABHET_SIZE; ++j)
        {
            if(ABC[j] == current_character)
            {
                arr[i] = dvorak[j];
            }
        }
    }
}

void display_result(std::vector<std::string>& _vector)
{
    for(auto it = _vector.begin(); it != _vector.end();  ++it)
    {
        if(it+1 == _vector.end())
            out<<*it;
        else
            out<<*it<<'\n';
    }

}
auto main() -> int
{
    std::vector<std::string> result;
    unsigned number_of_operations, from, to, code;
    std::string last_password, chunk, encryption;
    in>>number_of_operations>>encryption>>last_password;
    for(unsigned i = 0; i < number_of_operations; ++i)
    {
        in>>code;
        if(code == 1)
        {
            in>>from>>to;
            transform_string(last_password, encryption, from-1, to);
        }
        else if(code == 2)
        {
            in>>chunk;
            if(contains(last_password, chunk))
                result.push_back("Da");
            else
                result.push_back("Nu");
        }
    }
    display_result(result);

    return 0;
}
