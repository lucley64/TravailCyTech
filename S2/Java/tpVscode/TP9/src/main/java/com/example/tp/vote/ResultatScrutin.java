package com.example.tp.vote;

import java.lang.System.Logger;
import java.lang.System.Logger.Level;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.StringJoiner;

public abstract class ResultatScrutin {

    protected Map<Vote, Integer> votes;
    protected int nbVotant;
    protected boolean estClos;
    protected int votesRestants;

    protected ResultatScrutin(int nbVotant, Set<Vote> votesSoumis) {
        votes = new HashMap<>();
        votesSoumis.forEach(value -> votes.put(value, 0));
        votes.putIfAbsent(Vote.NUL, 0);
        votes.putIfAbsent(Vote.BLANC, 0);
        this.nbVotant = nbVotant;
        estClos = false;
        votesRestants = nbVotant;
    }

    public Set<Vote> getVotesPossibles() {
        return votes.keySet();
    }

    public void ajouterVote(Vote v) {
        if (!estClos || votesRestants == 0) {
            if (!votes.keySet().contains(v))
                v = Vote.NUL;
            votes.replace(v, votes.get(v) + 1);
            votesRestants--;
        } else {
            throw new ScrutinClosException();
        }
    }

    public void afficherResultats(Logger logger) {
        if (estClos) {
            var sj = new StringJoiner("\n");
            votes.forEach((k, v) -> sj.add(k.toString() + " a obtenu " + v));
            logger.log(Level.INFO, sj.toString());
        } else {
            throw new ScrutinNonClosException();
        }
    }

    public void cloturer(Logger logger) {
        while (votesRestants != 0) {
            ajouterVote(Vote.BLANC);
        }
        estClos = true;
        afficherResultats(logger);
    }

    public abstract Vote getVaiqueur();

    public class ScrutinClosException extends RuntimeException {
        public ScrutinClosException() {
            super("Erreur le scrutin est clos");
        }
    }

    public class ScrutinNonClosException extends RuntimeException {
        public ScrutinNonClosException() {
            super("Erreur le scrutin n'est pas clos");
        }
    }


    public static void main(String[] args) {
        var logger = System.getLogger("null");

        var referendum = new MajoriteAbsolue(200, Set.of(Vote.OUI, Vote.NON));

        var rand = new Random(System.nanoTime());

        for (var i = 0; i < 175; i++){
            var vote = (rand.nextBoolean())? Vote.OUI : Vote.NON;
            referendum.ajouterVote(vote);
        }

        referendum.cloturer(logger);
        logger.log(Level.INFO, "Le vaiqueur est " + referendum.getVaiqueur().toString());
    }
}
