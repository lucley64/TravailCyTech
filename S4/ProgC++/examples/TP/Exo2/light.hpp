#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

class Light
{
  private:
    bool on        // Indique si la lumière est allumée (true) ou éteinte (false).
  protected
  public:
    Light ();      // Constructeur par défaut qui crée une lumière éteinte
    ~Ligth();      // Destructeur

    void toggle(); // Si la lumière est allumée, elle sera éteinte et vice versa.
    bool IsOn();   // Retourne true si la lumière est allumée, false sinon

    // C’est une fonction AMIE, pas une methode membre
    friend std::ostream operator << (std::ostream&out,const Light &l);
};

#endif
