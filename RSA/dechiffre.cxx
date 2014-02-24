#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <gmpxx.h>
#include "utils.h"

using namespace std;

int main( int argc, char ** argv )
{
	// fichier
	string home = getenv("HOME");
	const char * filenameArg =  (argc == 2 ) ? argv[1] : (home + "/.my_rsa").c_str();
	string fileName(filenameArg);

	int bits; 
	mpz_class n,p,q,a,b;
	Utils::litFichierPrive(fileName.c_str(), bits, n, p, q, a, b);
	Utils::dechiffre(n,a,bits);


	return 0;
}
