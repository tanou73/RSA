#include <iostream>
#include <gmpxx.h>
#include "utils.h"

using namespace std;

int main( int argc, char ** argv )
{
  cout << "** GENERE CLE **" << endl;

  // pick 2 nombre premier 
  // P 
  // Q
  mpz_class a = Utils::getNombrePremier();

  // N = P * Q

  // M = (P-1)*(Q-1)

  // C -> Premier avec M

  // cle public K = (N,C)
}
