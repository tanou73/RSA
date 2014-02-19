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

mpz_class Utils::algorithmeBezout(mpz_class C, mpz_class M) {
	mpz_class r = C;
	mpz_class r1 = M;
	mpz_class u = 1;
	mpz_class v = 0;
	mpz_class u1 = 0;
	mpz_class v1 = 1;
	// variable auxiliaires
	mpz_class rs, us, vs, q;
 
	while (r1 != 0){
		q = r / r1; // on prend que la partie entiere
		rs = r;
		us = u;
		vs = v;
		r = r1;
		u = u1;
		v = v1;
		r1 = rs - q *r1;
		u1 = us - q*u;
		v1 = vs - q*v1;
	}

	return u;
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
