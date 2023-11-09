package com.example.tp.vote;

import java.util.Set;

public class MajoriteAbsolue extends ResultatScrutin{
    public MajoriteAbsolue(int nbVotant, Set<Vote> votesSoumis) {
        super(nbVotant, votesSoumis);
    }

    public Vote getVaiqueur() {
        if (estClos){
            int taille = nbVotant - votes.get(Vote.NUL) - votes.get(Vote.BLANC);
            for (var kv : votes.entrySet()) {
                if (kv.getValue() > taille / 2 && !kv.getKey().equals(Vote.NUL) && !kv.getKey().equals(Vote.BLANC)) {
                    return kv.getKey();
                }
            }
            return null;
        }
        else{
            throw new ScrutinNonClosException();
        }
    }
}
