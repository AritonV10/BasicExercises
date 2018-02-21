/**
    https://www.pbinfo.ro/?pagina=probleme&id=354
**/
int exercise1(){

    int n, m, sum = -1000;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> m;
        if(m > sum){
            sum = m;
        }
    }
    cout << sum;
}