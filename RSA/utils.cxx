#include <iostream>
#include <gmpxx.h>
#include "utils.h"

using namespace std;
/*
void Contexte::i2c( uint64_t idx, string & c )
{

}*/

mpz_class Utils::getNombrePremier(gmp_randclass& seeder)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(8);
	} while (!estPremierLent(n));

	return n;
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