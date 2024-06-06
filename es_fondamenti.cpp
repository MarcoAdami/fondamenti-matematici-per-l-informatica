#include <iostream>
#include<fstream>
#include"type_of_exercise.h"
using namespace std;

int main()
{
    // scrivere in input_sistema.txt solo i numeri del sistema, tipo:
    // 20 66 8 171 ==> x=20(mod 66) x=8(mod 171)
    // risolve solo una congruenza

    // scrivere in  input_rsa.txt in cui scrivere solo i numeri della congruenza
    // 9 4 205 ==> x^9 = 4(mod 205) ==>
    // risolve solo una congruenza

       

    // sistema lineare
    fstream cin("input_sistema.txt");

    int resto1, resto2, mod1, mod2;
    cin>>resto1>>mod1>>resto2>>mod2;
    sistema_di_congurneze(resto1, resto2, mod1, mod2);

    cin.close();


    cout<<endl;

    //rsa
    // fstream cin2("input_rsa.txt");
    // int pow, resto, mod;
    // cin2>>pow>>resto>>mod;
    // rsa_exercise(pow, resto, mod);
    // cin2.close();

    return 0;
}
