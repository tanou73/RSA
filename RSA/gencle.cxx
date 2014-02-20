#include <iostream>
#include <gmpxx.h>
#include "utils.h"

using namespace std;
//http://fr.openclassrooms.com/informatique/cours/la-cryptographie-asymetrique-rsa/creation-de-la-cle-privee
int main( int argc, char ** argv )
{
  cout << "** GENERE CLE **" << endl;

  // pick 2 nombre premier P et Q
  // random seeder intialization
  gmp_randclass rr(gmp_randinit_mt);
  rr.seed(time(NULL));
  mpz_class P = Utils::genereNombrePremier(rr);
  mpz_class Q = Utils::genereNombrePremier(rr);
  cout << "P --> " << P << endl << "Q -->" << Q << endl;

  // N = P * Q
  mpz_class N = P * Q;
  cout << "N --> " << N << endl;

  // M = (P-1)*(Q-1)
  mpz_class M = (P-1)*(Q-1);
  cout << "M --> " << M << endl;

  // C -> Premier avec M
  mpz_class C = Utils::genereNombrePremier(rr, M);
  cout << "C --> " << C << endl;

  // cle public K = (N,C)  
  cout << "************************************************************" << endl;
  cout << "Votre clé publique (N,C) est : (" << N << "," << C << ")." << endl;
  cout << "************************************************************" << endl;

  //  U tel que C*U + M*V = 1
  //  U est l'inverse C (bézout)
  mpz_class U = Utils::algorithmeBezout(C%M, M);
  cout << "Votre clé privée (N,U) est : (" << N << "," << U << ")." << endl;
  cout << "************************************************************" << endl;
}
