#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__

class Fraction
{
  private:
    int numerateur;
    int denominateur;

  protected:

  public:
    // Constructeur
    Fraction ();            // par defaut
    Fraction (int n);       // par parametre
    Fraction (int n,int d); // par parametres
    // Destructeur
    ~Fraction();
};

#endif