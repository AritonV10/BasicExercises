/**
    https://www.pbinfo.ro/?pagina=probleme&id=346
**/

int exercise7(){

    int n, m, ap = 1, sum = -2147483648;
    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> m;
        if(m == sum){
            ap++;
        }
        if(m > sum){
            sum = m;
            ap = 1;
        }
    }
    cout << sum << " " << ap;
}