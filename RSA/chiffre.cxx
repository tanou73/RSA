#include <iostream>
#include <gmpxx.h>
#include <cstdlib>
#include "utils.h"

using namespace std;

int main( int argc, char * argv [] )
{
	//get args
	mpz_class n, b;
	int bits;

	if (argc == 4)
	{
		n = argv[1];
		b = argv[2];
		bits = atoi(argv[3]);
	} 
	else if (argc == 2)
	{
		Utils::litFichierPublic(argv[1], bits, n, b);
	}
	else 
	{
		cerr << "Nombre d'arguments incorrect ( [n] [b] [t] ) " << endl;
		exit(1);
	}

	Utils::chiffre(n, b, bits);
}
