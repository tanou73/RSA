#include <iostream>
#include <gmpxx.h>
#include <cstdlib>
#include <sstream>
#include "utils.h"
#include "sha1.h"

using namespace std;
// On signe avec notre clé privée, comme ça le destinataire déchiffrera avec notre clé publique
int main( int argc, char * argv [] )
{
    // fichier
    string home = getenv("HOME");
    const char * filenameArg =  (argc == 2 ) ? argv[1] : (home + "/.my_rsa").c_str();
    string fileName(filenameArg);

    int bits;
    mpz_class n, p, q, a, b;

    Utils::litFichierPrive(fileName.c_str(), bits, n, p, q, a, b);

    Utils::chiffre(n, a, bits);
}
