#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <gmpxx.h>
#include <fstream>
#include <cstdlib>
#include <string>

class Utils
{
	// private
	private:
	

	// public
	public:
		static mpz_class genereNombrePremier(gmp_randclass& seeder, int t_block);
		static mpz_class genereNombrePremierAvecM(gmp_randclass& seeder, mpz_class& M, int t_block);
		static mpz_class genereNombrePremierRapide(gmp_randclass& seeder, int t_block);
		static mpz_class pgcd(mpz_class& a, mpz_class& b);
		static mpz_class algorithmeBezout(mpz_class C, mpz_class M);
		static void litFichierPrive(const char * fileName , int &bits , mpz_class &n , mpz_class &p , mpz_class &q , mpz_class &a, mpz_class &b );
		static void litFichierPublic(const char * fileName , int &bits , mpz_class &n, mpz_class &b );
		static mpz_class inverseModulaire(mpz_class C, mpz_class M);
		static bool estPremierLent(mpz_class& nb);
		static bool estPremierRapide(gmp_randclass& seeder, const mpz_class& p, int t_block, int iteration);
		static bool sontPremier(mpz_class& a, mpz_class& b);
		static bool chiffre(mpz_class n, mpz_class b, int bits);
		static std::string encryptSha1(std::string c);
		static std::string dechiffre(mpz_class n, mpz_class b, int bits, bool displayOnCout = true);
};

#endif // UTILS_H