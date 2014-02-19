#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <gmpxx.h>

class Utils
{
	// private
	private:
	

	// public
	public:
		static mpz_class genereNombrePremier(gmp_randclass& seeder);
		static mpz_class genereNombrePremier(gmp_randclass& seeder, mpz_class& M);
		static mpz_class pgcd(mpz_class& a, mpz_class& b);
		static mpz_class algorithmeBezout(mpz_class C, mpz_class M);
		static bool estPremierLent(mpz_class& nb);
		static bool sontPremier(mpz_class a, mpz_class b);

};

#endif // UTILS_H