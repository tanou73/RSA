#include <gmpxx.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
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
	ifstream fichier(argv[4], ios::in);

	string signature = "";
	string line = "";

	if (fichier.is_open())
  	{
    	while ( getline (fichier,line) )
    	{
      		signature += line + '\n';
    	}
    	signature = signature.substr(0,signature.size()-1);
    	fichier.close();
  	}

	string uncrypted(Utils::dechiffre(n, b, bits,false));

  	cout << "signature espérée : " << endl << signature << endl;
  	cout << "signature obtenue : " << endl <<  uncrypted << endl;
}
