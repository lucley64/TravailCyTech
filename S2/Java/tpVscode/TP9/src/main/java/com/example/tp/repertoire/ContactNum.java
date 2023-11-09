package com.example.tp.repertoire;

import java.util.ArrayList;
import java.util.List;

public class ContactNum extends Contact{
    private List<NumeroTelephone> nums;
    public ContactNum(String nom, String prenom) {
        super(nom, prenom);
        nums = new ArrayList<>();
    }
    public ContactNum(String nom, String prenom, List<NumeroTelephone> nums) {
        super(nom, prenom);
        this.nums = nums;
    }
    public ContactNum(Contact contact){
        super(contact.getNom(), contact.getPrenom());
        nums = new ArrayList<>();
    }
    public List<NumeroTelephone> getNums() {
        return nums;
    }
    public void setNums(List<NumeroTelephone> nums) {
        this.nums = nums;
    }

    public void ajouterNum(NumeroTelephone num){
        nums.add(num);
    }

    public void ajouterNum(String nomNum, String num){
        nums.add(new NumeroTelephone(nomNum, num));
    }

    public void modifierNum(NumeroTelephone oldNum, NumeroTelephone newNum){
        nums.remove(oldNum);
        nums.add(newNum);
    }

    public void modifierNum(String nomNum, String newNum){
        nums.removeIf(num -> num.getNom().equals(nomNum));
        nums.add(new NumeroTelephone(nomNum, newNum));
    }

    public void supprimerNum(NumeroTelephone num){
        nums.remove(num);
    }

    public void supprimerNum(String nomNum){
        nums.removeIf(num -> num.getNom().equals(nomNum));
    }
    
}
