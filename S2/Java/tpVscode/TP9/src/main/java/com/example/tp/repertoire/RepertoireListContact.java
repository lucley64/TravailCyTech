package com.example.tp.repertoire;

import java.util.ArrayList;
import java.util.List;

public class RepertoireListContact implements Repertoire{
    private List<ContactNum> contacts;

    public RepertoireListContact() {
        contacts = new ArrayList<>();
    }

    public RepertoireListContact(RepertoireListContact that) {
        this.contacts = new ArrayList<>(that.getContacts());
    }

    public RepertoireListContact(List<ContactNum> contacts) {
        this.contacts = contacts;
    }

    public List<ContactNum> getContacts() {
        return contacts;
    }

    public void setContacts(List<ContactNum> contacts) {
        this.contacts = contacts;
    }

    @Override
    public void ajouterContact(Contact c) {
        contacts.add(new ContactNum(c));
    }

    @Override
    public void suprimerContact(Contact c) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'suprimerContact'");
    }

    @Override
    public void ajouterNum(Contact c, NumeroTelephone num) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'ajouterNum'");
    }

    @Override
    public void modifierNum(Contact c, NumeroTelephone num) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'modifierNum'");
    }

    @Override
    public void suprimerNum(Contact c, NumeroTelephone num) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'suprimerNum'");
    }

    @Override
    public Contact rechercherContactParNom(String nom) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'rechercherContactParNom'");
    }

    @Override
    public Contact rechercherContactParPrenom(String prenom) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'rechercherContactParPrenom'");
    }

    @Override
    public Contact rechercherContactParNumero(NumeroTelephone num) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'rechercherContactParNumero'");
    }

    @Override
    public void afficherListeContacts() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'afficherListeContacts'");
    }

    

    
}
