/**
    https://www.pbinfo.ro/?pagina=probleme&id=119
**/

int exercise8(){

    int n;
    cin >> n;
    int v[n];
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j++){
            if(v[j] > v[j+1]){
                int temp;
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
        }
    }
}