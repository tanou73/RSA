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

	//bits to bytes
	int bytes = bits / 8 ;

	char buffer[bytes];
	size_t totalBlocsNumber = 0;
	size_t totalBytesRead = 0;
	int charRead;
	
	while (!cin.eof()) 
	{
		cin.read(buffer,bytes);
		charRead = cin.gcount();
	    if (charRead < bytes)
	    {
	    	//si moins de chars ont été lus, on efface la fin du buffer
	    	for (int i = charRead; i < bytes; ++i)
	    	{
	    		buffer[i] = 0;
	    	}
	    }

	    mpz_class z;
	    //transforme les chars en grands entiers
		mpz_import(z.get_mpz_t(), bytes, 1, sizeof(buffer[0]), 0, 0, buffer);

		mpz_class res;
		//puissance, puis modulo
		mpz_powm(res.get_mpz_t(),z.get_mpz_t(),b.get_mpz_t(),n.get_mpz_t());
		cout << res << endl;

		totalBytesRead += charRead;
		++totalBlocsNumber;
	}
	cout << "# "<< totalBytesRead << " bytes read, " <<  totalBlocsNumber << " blocs read." << endl;
}