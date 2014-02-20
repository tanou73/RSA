#include <iostream>
#include <gmpxx.h>
#include "utils.h"

using namespace std;

mpz_class Utils::genereNombrePremier(gmp_randclass& seeder, int t_block)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(t_block);
	} while (!estPremierLent(n));

	return n;
}

mpz_class Utils::genereNombrePremier(gmp_randclass& seeder, mpz_class& M, int t_block)
{
	mpz_class n;

	do {
		n = seeder.get_z_bits(t_block);
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

mpz_class Utils::inverseModulaire(mpz_class C, mpz_class M) {
	mpz_class u;
	do
	{
		u = algorithmeBezout(C, M);
	} while ( u <= 0 );

	return u;
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

/*
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
*/
bool Utils::estPremierLent(mpz_class& n){
	mpz_class m = sqrt( n );

	if ( (n % 2) == 0 ) 
		return n == 2;
	
	for ( mpz_class i = 3; i <= m; i = i + 2 )
		if ( (n % i) == 0 ) 
			return false;
	
	return true;
}
