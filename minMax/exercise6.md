/**
    https://www.pbinfo.ro/?pagina=probleme&id=171
**/
int exercise6(){

    int n, m, first_sum, second_sum = 0, first_digit = 10000, digit, number = -2000000000;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int copy_of;
        cin >> m;
        copy_of;
        int second_copy = m;

        if(m < 10){
            digit = m;
        } else {
            copy_of = m;
            while(copy_of >= 0){

                copy_of /= 10;

                if(copy_of < 10){
                    digit = copy_of;
                    break;
                }
            }
        }

        if(digit <= first_digit){
            first_digit = digit;
        }

        if(digit == first_digit && second_copy > number){
            number = second_copy;
        }
    }

     cout << number;

}