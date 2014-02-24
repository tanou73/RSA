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

	//get args
	mpz_class n, b;
	int bits;
	string filename;

	if (argc == 5)
	{
		n = argv[1];
		b = argv[2];
		bits = atoi(argv[3]);
		filename = argv[4];
	} 
	else if (argc == 3)
	{
		Utils::litFichierPublic(argv[1], bits, n, b);
		filename = argv[2];
	}
	else 
	{
		cerr << "Nombre d'arguments incorrect ( [n] [b] [t] [fichier-signature] ) " << endl;
		exit(1);
	}

	ifstream fichier(filename.c_str(), ios::in);

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
