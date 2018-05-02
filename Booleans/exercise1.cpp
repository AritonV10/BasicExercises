/*
  https://www.pbinfo.ro/?pagina=probleme&id=287
*/



#include <iostream>
bool fun(int m, int n){

 	if(m >= n)
        return true;

    return false;
}

int main()
{
   int n, sir, numere, nr;
   std::cin>>n;
   int v[n];
   for(int i = 1; i <= n; i++){
        std::cin >> sir;
        bool sortat = true;
        nr = -10000000;
        for(int j = 1; j <= sir; j++){
            std::cin >> numere;
            if(sortat){
                if(fun(numere, nr)){
                    sortat = true;
                } else {sortat = false;}
            }
            nr = numere;
        }

        if(sortat)
            v[i] = 1;
        else
            v[i] = 0;
   }

    for(int i = 1; i <= n; i++)
        std::cout << v[i] << " ";

}
