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
		static mpz_class getNombrePremier();
		static bool estPremierLent(mpz_class nb);
};

#endif // UTILS_H