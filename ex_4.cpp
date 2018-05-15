/* https://www.pbinfo.ro/?pagina=probleme&id=1745 */

int minDivPrim(int n){
    int _vec[50];
    int _idx = -1;
    for(int i = 2; i < n; i++)
        if(n%i==0) { _idx++; _vec[_idx] = i; } // 3, 5, 15, 25
    int nums = 2;
    if(_idx != -1){
        for(unsigned int i = 2; i <= _idx; i++){
            int _nums = 0;
            for(unsigned int j = 0; j < i; j++){
                if(_vec[i] % _vec[j] == 0) _nums++;
                if(_nums == nums) return _vec[i];
            }
            nums++;
        }
    }
    return n;
}
