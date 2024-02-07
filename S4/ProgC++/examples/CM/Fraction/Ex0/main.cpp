using namespace std;

#include <iostream>
#include "Fraction.hpp"

//////////////////////////////////////////////////////////////////////////
// Programme : main.cpp                                                 //
// Acces     : Public                                                   //
// But       : Utilisation de la classe Vector                          //
//                                                                      //
// Arguments                                                            //
// - IN      : neant                                                    //
// - IN/OUT  : neant                                                    //
// - OUT     : neant                                                    //
// Retour    : EXIT_SUCCESS Execution OK                                //
//             EXIT_FAILURE Execution KO                                //
//                                                                      //
// Historique                       Date        Version  par            //
// Ajout main.cpp                   25/12/2023  1.0.00   Alain BERTAILS //
//////////////////////////////////////////////////////////////////////////

int main()
{
  Fraction f1;      // par defaut
  Fraction f2(10);  // par parametre
  Fraction f3(3,7); // par parametres

  return EXIT_SUCCESS;
}
