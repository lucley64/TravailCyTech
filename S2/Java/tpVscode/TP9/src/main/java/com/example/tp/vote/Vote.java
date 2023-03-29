package com.example.tp.vote;

public class Vote {
    private String nom;

    public Vote(String nom) {
        this.nom = nom;
    }

    public Vote(Vote that){
        this.nom = that.nom;
    }

    public String getNom() {
        return nom;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((nom == null) ? 0 : nom.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Vote other = (Vote) obj;
        if (nom == null) {
            if (other.nom != null)
                return false;
        } else if (!nom.equals(other.nom))
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Vote pour " + nom;
    }


    public static final Vote OUI = new Vote("Oui");
    public static final Vote NON = new Vote("Non");
    public static final Vote BLANC = new Vote("Blanc");
    public static final Vote NUL = new Vote("Nul");
}
