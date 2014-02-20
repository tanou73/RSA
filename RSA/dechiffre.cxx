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

		mpz_class bits;
		mpz_class n;
		mpz_class p;
		mpz_class q;
		mpz_class a;
		mpz_class b;

		Utils::litFichierPrive(fileName,bits,n,p,q,a,b);

		cout << bits << endl;


/*
	ifstream file(fileName, ios::in);

	if (file)
	{
		clog <<  fileName << " chargé " << endl;
		string data[6];
		int wordsRead = 0;
		int i = 0;
		string word;
		while (file >> data[i++]);
		mpz_class bits(data[0]);
		mpz_class n(data[1]);
		mpz_class p(data[2]);
		mpz_class q(data[3]);
		mpz_class a(data[4]);
		mpz_class b(data[5]);
		file.close();
	}
	else
	{
		cerr << "Impossible d'ouvrir " << fileName << endl;
		exit(1);
	}

	*/

	return 0;
}
