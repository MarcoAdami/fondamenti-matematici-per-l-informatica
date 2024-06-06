#include<iostream>
using namespace std;
int mcd(int x, int y){
    // descrizione: algoritmo di euclide per trovare mcd
    // cond: mcd>=0
    if(y==0){
        
        if(x<0){
            x=x*-1;
        }
        return x;
    }
    return mcd(y, x%y);
}

int mcm(int x, int y){
    // descrizione: euclide
    if(x==0 && y==0){
        return 1;
    }
    return x*y/mcd(x, y);
}

void norm(int &n, int mod)
{
    // funzione che mi riduce al rappresentante canonico della classe n(mod mod)(pià piccolo e positivo)
    n = n % mod;
    if (n < 0)
    {
        n = n + mod;
    }
}

int num_pow_div(int n, int pow, int mod)
{
    // prima rinomalizzazione
    n %= mod;
    int res = 1;
    while (pow != 0)
    {
        if (pow % 2 == 1)
        {
            res = res * n;
            norm(res, mod);
        }

        if (pow >= 2)
        {
            n = n * n;
            norm(n, mod);
        }
        pow = (pow >> 1);
    }
    return res;
}

bool teorema_cinese_del_resto(int resto1, int resto2, int mod1, int mod2)
{
    int temp1 = resto1 - resto2;
    int temp2 = mcd(mod1, mod2);

    // cout<<temp1<<endl;
    // cout<<temp2<<endl;

    return !(temp1 - (temp1 / temp2) * temp2);
}

int trovare_soluz_sistema(int resto1, int resto2, int mod1, int mod2)
{
    int x = resto1;
    while ((x % mod2) != resto2)
    {
        x = x + mod1;
    }
    return x;
}

int trovare_soluz_rsa(int pow, int mod)
{
    int i=0;
    while (((i*pow) % mod) != 1)
    {
        i++;
    }
    return i;
}

int phi_function(int mod)
{
    int result = 0;
    int temp = mod;
    while (temp > 0)
    {
        if (mcd(temp, mod) == 1)
        {
            result++;
        }
        temp--;
    }
    return result;
}

bool applicabilità_rsa(int pow, int resto, int mod, int &phi)
{
    phi = phi_function(mod);
    // se non sono rispettati le condizioni, l'rsa non può essere fatto
    //cout << phi << endl;
    if (mcd(resto, mod) == 1 && mcd(pow, phi) == 1)
    {
        return 1;
    }

    return 0;
}
