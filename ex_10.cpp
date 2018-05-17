/* https://www.pbinfo.ro/?pagina=probleme&id=1846 */

#include <iostream>
template<typename T, size_t N >
void num(T (&arr)[N], T a, T st, T nd, /* private */ T _idx = 0){
    if(nd == st) return;
    if(arr[st] > arr[st+1]){
        T temp = arr[st+1];
        arr[st+1] = arr[st];
        arr[st] = temp;
    }
    if(st == nd - 1) return num(arr, a, st-_idx, nd-1, 0);
    return num(arr, a, st+1, nd, _idx+1);
}
int main(){
    int arr[] = {63,273,9,83,93,123};
    num(arr, 6, 1, 3);
    for(int i = 0; i < 6; i++)
        std::cout<<arr[i] << " ";
}
