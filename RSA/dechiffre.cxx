#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <gmpxx.h>
#include "utils.h"

using namespace std;

int main( int argc, char ** argv )
{

	//string msg = getline();
	clog << "** DECHIFFRE **" << endl;

  	const char * fileName =  (argc == 2 ) ? argv[1] : "~/.my_rsa";

	int bits; 
	mpz_class n,p,q,a,b;
	Utils::litFichierPrive(fileName,bits,n,p,q,a,b);



	return 0;
}
