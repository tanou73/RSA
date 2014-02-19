#include <iostream>
#include <gmpxx.h>
#include "utils.h"

using namespace std;

int main( int argc, char ** argv )
{
  cout << "** GENERE CLE **" << endl;

  // pick 2 nombre premier P et Q
  // random seeder intialization
  gmp_randclass rr(gmp_randinit_mt);
  rr.seed(time(NULL));
  mpz_class P = Utils::getNombrePremier(rr);
  mpz_class Q = Utils::getNombrePremier(rr);

  cout << "random number --> " << P << "-" << Q << endl;

  // N = P * Q
  mpz_class N = P * Q;

  // M = (P-1)*(Q-1)
  mpz_class M = (P-1)*(Q-1);

  // C -> Premier avec M
  

  // cle public K = (N,C)
}
