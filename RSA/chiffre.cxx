#include <iostream>
#include <gmpxx.h>
#include <cstdlib> 

using namespace std;

int main( int argc, char * argv [] )
{
	string message;
	getline(cin, message);

	if (argc != 4)
	{
		cout << "Nombre d'arguments incorrect ( [n] [b] [t] ) " << endl;;
		exit(1);
	}

	mpz_class n = atoi(argv[1]);
	mpz_class b = atoi(argv[2]);
	mpz_class t = atoi(argv[3]);

	cout << "** CHIFFRE sur " << t  << " bits ***" << endl;

	cout << "Clé publique utilisée  : (" << n << "," << b << ") "  << endl;
	cout << "Message : " << message << endl;
}
