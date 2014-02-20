#include <iostream>
#include <gmpxx.h>
#include <cstdlib>
#include "utils.h"

using namespace std;

int main( int argc, char * argv [] )
{

	if (argc != 4)
	{
		cerr << "Nombre d'arguments incorrect ( [n] [b] [t] ) " << endl;
		exit(1);
	}

	//get args
	mpz_class n(argv[1]);
	mpz_class b(argv[2]);
	int bits = atoi(argv[3]);

	Utils::chiffre(n, b, bits);
}
