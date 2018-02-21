/**
    https://www.pbinfo.ro/?pagina=probleme&id=55
**/

int exercise5(){
    int number = 1000000;
    int n, sum = number;
    for(int i = 1; n != 0;){

        cin >> n;
        if(n == 0 && sum == number){
            cout << "NU EXISTA";
            break;
        }
        if(n == 0){
            cout << sum;
            break;
        } else if(n < sum && n > 0){
            sum = n;
        }
    }

}