#include <iostream>
#include "Personne.hpp"

//////////////////////////////////////////////////////////////////////////
// Programme : main.cpp                                                 //
// Acces     : Public                                                   //
// But       : Utilisation de la classe Etudiant                        //
//                                                                      //
// Arguments                                                            //
// - IN      : neant                                                    //
// - IN/OUT  : neant                                                    //
// - OUT     : neant                                                    //
// Retour    : EXIT_SUCCESS Execution OK                                //
//             EXIT_FAILURE Execution KO                                //
//                                                                      //
// Historique                       Date        Version  par            //
// Ajout main.cpp                   20/02/2024  1.0.00   Alain BERTAILS //
//////////////////////////////////////////////////////////////////////////

int main()
{ Etudiant Alain("BERTAILS","Alain");
  
  Alain.SetId("0001");
  Alain.Afficher();
  
  Alain.SetId("0002");
  Alain.SetNom("TERRIEUR");
  Alain.Afficher();

  return EXIT_SUCCESS;
}
