#include <iostream>
using namespace std ;
int main (){
    int a= 2 ;
    int b =3 ;
    // Swapiing using XOR 
    a=a^b;
    b=a^b;
    a=a^b;
    return 0;
}