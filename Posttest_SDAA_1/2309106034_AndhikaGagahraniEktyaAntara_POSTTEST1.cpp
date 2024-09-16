#include <iostream>
using namespace std;

// variable koefisien digunakan untuk menyimpan nilai disetiap iterasi.
void segitigapascal(int tingkat,int iterasi1,int koefisien, int iterasi2 ){
    if (iterasi1 < tingkat && iterasi2 <= iterasi1 ){
        cout<<koefisien<<" ";
        koefisien =koefisien * (iterasi1-iterasi2)/(iterasi2+1); 
        segitigapascal(tingkat, iterasi1, koefisien, iterasi2+1);
    }
    if (iterasi1 < tingkat && iterasi2 > iterasi1 ){
        cout<<"\n"; 
        segitigapascal(tingkat, iterasi1+1, 1, 0);
    }
}

int main(){
    int tingkat = 3;
    segitigapascal(tingkat,0,1,0);
}