/* https://www.pbinfo.ro/?pagina=probleme&id=1845 */
#include<iostream>
template<typename T, size_t N >
void num(T (&arr)[N], T a, /* private */ T _idx = 0){
    if(a == 0) return;
    if(_idx == a-1) return num(arr, a-1, _idx = 0);
    if(arr[_idx] > arr[_idx+1]){
        T temp = arr[_idx+1];
        arr[_idx+1] = arr[_idx];
        arr[_idx] = temp;
    }
    return num(arr, a, _idx+=1);
}

int main(){
    int arr[] = {63,273,9,83,93,123};
    num(arr, 6);
    for(int i = 0; i < 6; i++)
        std::cout<<arr[i] << " ";
}
