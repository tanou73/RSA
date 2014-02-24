#include <iostream>
#include <gmpxx.h>
#include <fstream>
#include <cstdlib>
#include "utils.h"
#include "sha1.h"
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

mpz_class Utils::genereNombrePremier(gmp_randclass& seeder, int t_block)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(t_block);
	} while (!estPremierLent(n));

	return n;
}

mpz_class Utils::genereNombrePremierAvecM(gmp_randclass& seeder, mpz_class& M, int t_block)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(t_block);
	} while ( (n > M*0.1) && !sontPremier(n, M) );

	return n;
}

mpz_class Utils::genereNombrePremierRapide(gmp_randclass& seeder, int t_block)
{
	mpz_class n;
	int interations = 50;
	do 
	{
		n = seeder.get_z_bits(t_block);
	}while (!estPremierRapide(seeder,n,t_block,interations));

	return n;
}

bool Utils::sontPremier(mpz_class& m, mpz_class& n)
{

	mpz_class a(m);
	mpz_class b(n);
	//pgcd en peu de lignes
	while (true)
  	{
    	if ((a %= b) == 0) return b == 1 ;
    	if ((b %= a) == 0) return a == 1 ;
  	}
}

mpz_class Utils::pgcd(mpz_class& m, mpz_class& n)
{
	while ( n != 0 ) {
    	mpz_class r = m % n;
		m = n;
		n = r;
	}

	return m;
}

mpz_class Utils::inverseModulaire(mpz_class C, mpz_class M) {
	mpz_class u;
	do
	{
		u = algorithmeBezout(C, M);
	} while ( u <= 0 );

	return u;
}

void Utils::litFichierPrive(const char * fileName , int &bits , mpz_class &n , mpz_class &p , mpz_class &q , mpz_class &a, mpz_class &b )
{

	ifstream file(fileName, ios::in);

	if (file)
	{
		string data[6];
		int i = 0;

		while (file >> data[i++]);
		bits = atoi(data[0].c_str());
		n = data[1];
		p = data[2];
		q = data[3];
		a = data[4];
		b = data[5];
		file.close();
	}
	else
	{
		cerr << "Impossible d'ouvrir " << fileName << endl;
		exit(1);
	}
}


mpz_class Utils::algorithmeBezout(mpz_class u, mpz_class v) {
	mpz_class inv, u1, u3, v1, v3, t1, t3, q;
    mpz_class iter;

    /* Step X1. Initialise */
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;

    /* Remember odd/even iterations */
    iter = 1;

    /* Step X2. Loop while v3 != 0 */
    while (v3 != 0)
    {
        /* Step X3. Divide and "Subtract" */
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        /* Swap */
        u1 = v1; 
        v1 = t1; 
        u3 = v3; 
        v3 = t3;

        iter = -iter;
    }

    /* Make sure u3 = gcd(u,v) == 1 */
    if (u3 != 1)
        return 0;   /* Error: No inverse exists */

    /* Ensure a positive result */
    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;

    return inv;
}

bool Utils::estPremierLent(mpz_class& n){
	mpz_class m = sqrt( n );

	if ( (n % 2) == 0 ) 
		return n == 2;
	
	for ( mpz_class i = 3; i <= m; i = i + 2 )
		if ( (n % i) == 0 ) 
			return false;
	
	return true;
}

bool Utils::estPremierRapide(gmp_randclass& seeder, const mpz_class& p, int t_block, int iteration)
{
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0)
    {
        return false;
    }
    mpz_class s(p-1);
    while(s%2==0)
    {
        s/=2;
    }
    for(int i=0;i<iteration;i++)
    {
    	mpz_class a = seeder.get_z_bits(t_block);
    	a = a % (p-1) + 1;
    	mpz_class temp(s);
    	mpz_class mod; 
        //long long a=rand()%(p-1)+1,temp=s;
        //long long mod=modulo(a,temp,p);
   		mpz_powm(mod.get_mpz_t(),a.get_mpz_t(),temp.get_mpz_t(),p.get_mpz_t());

        while(temp!=p-1 && mod!=1 && mod!=p-1)
        {
            //mod=mulmod(mod,mod,p);
        	mpz_class two(2);
   			mpz_powm(mod.get_mpz_t(),mod.get_mpz_t(),two.get_mpz_t(),p.get_mpz_t());
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0)
        {
            return false;
        }
    }
    return true;
}

string Utils::dechiffre(mpz_class n, mpz_class b, int bits , bool displayOnCout)
{
	int bytes = bits / 8 ;
	string msg = "";
	char result[bytes];

	string resultStr = "";
	while ( getline(cin,msg))
	{
		if (msg[0] != '#')
		{
			mpz_class current(msg);
			mpz_class res;
			mpz_powm(res.get_mpz_t(),current.get_mpz_t(),b.get_mpz_t(),n.get_mpz_t());
			mpz_export (result, NULL, 0, sizeof result, 0, 0,res.get_mpz_t());

			for (int i = bytes-1; i >= 0 ; --i)
			{
				resultStr += result[i];
				if ( displayOnCout )
				{
					cout << result[i];
				}
			}
		}
	}
	return resultStr;
	
}



bool Utils::chiffre(mpz_class n, mpz_class b, int bits)
{
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

	return true;
}

string Utils::encryptSha1(string c)
{
	SHA1 sha;
    unsigned msgDigest[5];
    string d;

    sha.Reset();
    sha << c.c_str();

    if (!sha.Result(msgDigest))
    {
        cerr << "ERROR-- could not compute message digest" << endl;
    }
    else
    {
        for(int i = 0; i < 5 ; i++)
        {
            stringstream buffer;
            buffer << hex << msgDigest[i];
            d = d + buffer.str();
        }
    }

    return d;
}
