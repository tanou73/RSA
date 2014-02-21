#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <gmpxx.h>
#include "utils.h"

using namespace std;

int main( int argc, char ** argv )
{
  	string home =  getenv("HOME");
    const char * fileName = "";
    if (argc == 2) {
        fileName = argv[1];
    } else {
        fileName = (home + "/.my_rsa").c_str();
    }

	int bits; 
	mpz_class n,p,q,a,b;
	Utils::litFichierPrive(fileName,bits,n,p,q,a,b);
	Utils::dechiffre(n,a,bits);


	return 0;
}
