/**

  Exercise: ask the user for a number, then output a triangle
  Example:
  4 3 2 1
  3 2 1
  2 1
  1
  
**/

#include <iostream>
using namespace std;

int main{
    
    int number;
    cin >> number;
    int copie = number;

    while (number >= 1){
        
        
        // prints the number
        while(number >= 1){
          
            cout << number << " ";
            number--;

            // once the number is 0, it adds a new line
            if(number == 0){
                cout << " \n";
            }
        }
        // it decrements the number and then assigns it back to the number variable
        // for example, if the number is 4, then it becomes 3 and the variable number becomes 3
        copie--;
        number = copie;
    }


}
