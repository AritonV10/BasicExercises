/**
    https://www.pbinfo.ro/?pagina=probleme&id=347
**/
int exercise3(){

    int n, m, sum = 1000000, sum2 = -1000000;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> m;

        if(m < sum){
            sum = m;
        }

        if(m > sum2){
            sum2 = m;
        }
    }
    cout << sum << " " << sum2;

}