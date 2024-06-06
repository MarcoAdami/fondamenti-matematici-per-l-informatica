#include <iostream>
#include "func_number_theory.h"
using namespace std;

void sistema_di_congurneze(int resto1, int resto2, int mod1, int mod2)
{
    int res = -1;
    int temp = mcm(mod1, mod2);
    norm(resto1, mod1);
    norm(resto2, mod2);

    // cout<<teorema_cinese_del_resto(resto1, resto2, mod1, mod2)<<endl;

    if (teorema_cinese_del_resto(resto1, resto2, mod1, mod2))
    {
        res = trovare_soluz_sistema(resto1, resto2, mod1, mod2);
    }
    else
    {
        cout << "Non esistono soluzioni di questo sistema" << endl;
        return;
    }

    // scrittura risultato
    cout << "Risultato del sistema: ";
    cout << res << "[" << temp << "]";
}


void rsa_exercise(int pow, int resto, int mod)
{
    int phi, d, res;
    if(applicabilità_rsa(pow, resto, mod, phi)){
        //d = esponente a cui bisogna elevare il resto
        d = modInverse(pow, phi);
        
        res = modular_exponentation(resto, d, mod);
        // cout<<d<<endl;
    }else{
        cout<<"Non è possibile risolvere questo rsa"<<endl;
        return;
    }

    // scrittura risultato
    cout << "Risultato dell' RSA: ";
    cout << res << "[" << mod << "]";
}

void pow_div(int num, int pow, int mod){
    cout<<modular_exponentation(num, pow, mod);
}