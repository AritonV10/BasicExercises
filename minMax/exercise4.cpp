/**
    https://www.pbinfo.ro/?pagina=probleme&id=54
**/
int exercise4(){

    int n, sum = -1000000;

    cin >> n;

    if(n == 0){
        cout << "NU EXISTA";
        return 0;
    }

    for(int i = 1; i <= 2;){
        cin >> n;
        if(n == 0){
            cout << sum;
            break;
        }
        if(n > sum){
            sum = n;
        }
    }

}