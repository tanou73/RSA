#include <iostream>
#include <gmpxx.h>
#include <cstdlib>
#include "utils.h"

using namespace std;
// On signe avec notre clé privée, comme ça le destinataire déchiffrera avec notre clé publique
int main( int argc, char * argv [] )
{
    cout << "** SIGNE **" << endl;

    if (argc != 2)
    {
        cerr << "Nombre d'arguments incorrect ( [file] ) " << endl;
        exit(1);
    }

    int bits;
    mpz_class n, p, q, a, b;

    Utils::litFichierPrive(argv[1], bits, n, p, q, a, b);

    cout << bits << n << p << q << a << b << endl;
}
