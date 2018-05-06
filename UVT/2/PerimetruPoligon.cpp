// (fara float) perimetru P1(2,5)P2(1,4)P3(1,2)P4(2,1)P5(5,1)P6(8,1)P7(9,3)P8(8,5)P9(5,5)
// afiseaza "RADICAL" daca numarul nu ii patrat perfect -> nr1, nr2, nr3(RADICAL)
enum Radical {
    RADICAL,
    NON_RADICAL
};
struct Distanta{
    int distanta;
    Radical r;
    Distanta() {}
    Distanta(int _distanta) : distanta(_distanta){}
    ~Distanta(){}
    int getDistanta() { return this->distanta; }
    Radical getRadical() { return this->r; }
};
struct Pereche{
    int x;
    int y;
    //Radical _e;
    Pereche(){}
    Pereche(int _x, int _y) : x(_x), y(_y) {}
    ~Pereche() {}
    int getX() { return this->x; }
    int getY() { return this->y; }
};

int power(int x, int y);
int radical(int sum);
int distanta(int xa, int ya, int xb, int yb);
int distanta_fara_radical(int xa, int ya, int xb, int yb);
int func(Pereche perechi[], int numar_perechi);

std::vector<Distanta> distante;
int sum = 0;
int main(){
    int arr_size;
    std::cin >> arr_size;
    Pereche perechii[arr_size];
    for(int i = 0; i < arr_size; i++){
        int x, y;
        std::cin >> x >> y;
        Pereche per(x, y);
        perechii[i] = per;
    }
    func(perechii, arr_size);
    int i = 0;
    for(std::vector<Distanta>::iterator it = distante.begin(); it != distante.end(); ++it){
        if(distante.at(i).r==NON_RADICAL) sum += it->distanta;
        ++i;
    }
    int j = 0;
    std::cout<<"Perimetru poligon: " << sum << " ";
    for(std::vector<Distanta>::iterator it = distante.begin(); it != distante.end(); ++it){
        if(distante.at(j).r==RADICAL) std::cout<<it->distanta<<"(RADICAL) ";
        ++j;
    }
}
int func(Pereche perechi[], int numar_perechi){
   for(int i = 0; i < numar_perechi - 1; i++){
        int _sum = distanta(perechi[i].getX(), perechi[i+1].getX(), perechi[i].getY(), perechi[i+1].getY());
        int _sum_fara = distanta_fara_radical(perechi[i].getX(), perechi[i+1].getX(), perechi[i].getY(), perechi[i+1].getY());
        Distanta _dis(_sum);
        if(_sum_fara == _sum) {
             distante.push_back(_dis);
             distante.at(i).r = Radical::RADICAL;
        } else {
             distante.push_back(_dis);
             distante.at(i).r = Radical::NON_RADICAL;
        }
   }
}
int power(int x, int y){
    int num = x;
    for(int i = 1; i < y; i++)
        num *= num;
    return num;
}
int distanta_fara_radical(int xa, int ya, int xb, int yb){
    return power((xa-xb), 2) + power((ya-yb), 2);
}
int distanta(int xa, int ya, int xb, int yb){
    return radical(power((xa-xb), 2) + power((ya-yb), 2));
}
int radical(int sum){
    for(int i = 2; i <= sum; i++)
        if(i * i == sum) return i;
    return sum;
}
