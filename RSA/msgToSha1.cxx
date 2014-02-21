#include <iostream>
#include <gmpxx.h>
#include <cstdlib>
#include <sstream>
#include "utils.h"

using namespace std;
// On signe avec notre clé privée, comme ça le destinataire déchiffrera avec notre clé publique
int main( int argc, char * argv [] )
{
	//const char * fileName =  (argc == 2 ) ? argv[1] : "~/.my_rsa";

	string tmp = "";
	string msg = "";

	do 
	{
		msg += tmp + "\n";
	} while (getline(cin, tmp));

	msg += tmp;

	string encrypted = Utils::encryptSha1(msg);

	cout << encrypted << endl;
}
