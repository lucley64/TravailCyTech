package com.example.tp.repertoire;

public interface Repertoire {
    public void ajouterContact(Contact c);
    public void suprimerContact(Contact c);

    public void ajouterNum(Contact c, NumeroTelephone num);
    public void modifierNum(Contact c, NumeroTelephone num);
    public void suprimerNum(Contact c, NumeroTelephone num);

    public Contact rechercherContactParNom(String nom);
    public Contact rechercherContactParPrenom(String prenom);

    public Contact rechercherContactParNumero(NumeroTelephone num);

    public void afficherListeContacts();


}
