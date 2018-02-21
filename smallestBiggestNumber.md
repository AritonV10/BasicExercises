/**
	
	Exercise: print the smallest number and the biggest
	
**/

#include <iostream>
using namespace std;

int main{
    int numbers;
    int n_max, n_min, n;
    n_max = -99;
    n_min = 99;

    cin >> numbers;

    for(int i = 1; i <= number; i++){

        cin >> n;

        if(n < n_min){
            n_min = n;
        }

        if(n > n_max){
            n_max = n;
        }

        cout << n_min << " " << n_max << " \n";

    }



}
