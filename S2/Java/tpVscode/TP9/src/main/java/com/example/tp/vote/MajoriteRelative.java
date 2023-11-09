package com.example.tp.vote;

import java.util.Set;

public class MajoriteRelative extends ResultatScrutin {

    public MajoriteRelative(int nbVotant, Set<Vote> votesSoumis) {
        super(nbVotant, votesSoumis);
    }

    @Override
    public Vote getVaiqueur() {
        if (estClos){
            int max = 0;
            Vote ret = null;
    
            for (var kv : votes.entrySet()) {
                if (kv.getValue() > max){
                    max = kv.getValue();
                    ret = kv.getKey();
                }
            }
    
            return ret;
        }
        else{
            throw new ScrutinNonClosException();
        }
    }
    
}
