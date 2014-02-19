#include <iostream>
#include <gmpxx.h>
#include "utils.h"

using namespace std;
/*
void Contexte::i2c( uint64_t idx, string & c )
{

}*/

mpz_class Utils::genereNombrePremier(gmp_randclass& seeder)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(8);
	} while (!estPremierLent(n));

	return n;
}

mpz_class Utils::genereNombrePremier(gmp_randclass& seeder, mpz_class& M)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(8);
	} while ( (n > M*0.1) && !sontPremier(n, M) );

	return n;
}

bool Utils::sontPremier(mpz_class m, mpz_class n)
{
	return ( pgcd(m,n) == 1 || pgcd(m,n) == -1 );
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

bool Utils::estPremierLent(mpz_class& n){
	mpz_class m = sqrt( n );

	if ( (n % 2) == 0 ) 
		return n == 2;
	
	for ( mpz_class i = 3; i <= m; i = i + 2 )
		if ( (n % i) == 0 ) 
			return false;
	
	return true;
}
