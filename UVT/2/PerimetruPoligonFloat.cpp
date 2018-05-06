struct Pereche{
    float x;
    float y;
    //Radical _e;
    Pereche(){}
    Pereche(float _x, float _y) : x(_x), y(_y) {}
    ~Pereche() {}
    float getX() { return this->x; }
    float getY() { return this->y; }
};

float power(int x, int y);
float distanta(float xa, float ya, float xb, float yb);
void func(Pereche perechi[], int numar_perechi);

std::vector<float> distante;
float sum = 0;
int main(){
    int arr_size;
    std::cin >> arr_size;
    Pereche perechii[arr_size];
    for(int i = 0; i < arr_size; i++){
        float x, y;
        std::cin >> x >> y;
        Pereche per(x, y);
        perechii[i] = per;
    }
    func(perechii, arr_size);
    for(std::vector<float>::iterator it = distante.begin(); it != distante.end(); it++)
        sum += *it;

    std::cout << sum;

}
void func(Pereche perechi[], int numar_perechi){
   for(int i = 0; i < numar_perechi - 1; i++){
        float _sum = distanta(perechi[i].getX(), perechi[i+1].getX(), perechi[i].getY(), perechi[i+1].getY());
        distante.push_back(_sum);
   }
}
float power(float x, int y){
    float num = x;
    for(int i = 1; i < y; i++)
        num *= num;
    return num;
}
float distanta(float xa, float ya, float xb, float yb){
    return sqrt(power((xa-xb), 2) + power((ya-yb), 2));
}
