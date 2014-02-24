#include <iostream>
#include <gmpxx.h>
#include <cstdlib>
#include "utils.h"

using namespace std;

int main( int argc, char ** argv )
{
	cout << "# Verification de signature " << endl;

	if (argc != 5)
	{
		cerr << "Nombre d'arguments incorrect ( [n] [b] [t] [fichier-signature] ) " << endl;
		exit(1);
	}

	//get args
	mpz_class n(argv[1]);
	mpz_class b(argv[2]);
	int bits = atoi(argv[3]);
	ofstream fichier(argv[4], ios::in);

	Utils::dechiffre(n, b, bits);

	
	//TODO comparer
}
