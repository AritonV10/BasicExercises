/**
    https://www.pbinfo.ro/?pagina=probleme&id=274
**/

int exercise9(){

    int n;
    cin >> n;
    int v[n];
    for(int i = 1; i<=n; i++){
        cin >> v[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n-i; j++){
            if(v[j] > v[j+1]){
                int temp;
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
            }
        }
    }

    for(int i = 3; i >= 1; i--){
    	cout << v[i] << " ";
    }

}