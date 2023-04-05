package com.example.algo;
/*
 * Auteur : Remi Vernay <rvy@eisti.eu>
 * Date   : 24/03/2014
 */

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

import net.bubuntu.graph.Convertor;
import net.bubuntu.graph.EGraphIncorrectVertex;
import net.bubuntu.graph.EdgeDirectedValuated;
import net.bubuntu.graph.GraphSimple;
import net.bubuntu.graph.GraphSimpleValuated;
import net.bubuntu.graph.GraphVIZSimpleDirectedValuated;
import net.bubuntu.graph.VertexDirected;

public class App {

    private static void creerAretes(final GraphSimpleValuated<Character, Integer> graph, final int nbSommets,
            final int nbAretes) {
        graph.getEdges().clear();
        while (graph.getEdges().size() < nbAretes) {
            final Character head = (char) ('A' + (int) (Math.random() * nbSommets));
            final Character tail = (char) ('A' + (int) (Math.random() * nbSommets));
            graph.getEdges().add(head, tail, (int) (Math.random() * 30) + 1);
        }
    }

    private static void creerGrapheAleatoire(final GraphSimpleValuated<Character, Integer> graph, final int nbSommets,
            final int nbAretes) {
        creerSommets(graph, nbSommets);
        creerAretes(graph, nbSommets, nbAretes);
    }

    private static void creerSommets(final GraphSimple<Character> graph, final int nbSommets) {
        graph.getVertices().clear();
        for (int i = 0; i < nbSommets; ++i) {
            graph.getVertices().add((char) ('A' + i));
        }
    }

    private static void marquesSuivants(VertexDirected<Character> sommet,
            GraphVIZSimpleDirectedValuated<Character, Integer> original,
            final Map<VertexDirected<Character>, VertexDirected<Character>> peres,
            final Map<VertexDirected<Character>, Integer> poids) {
        var suivants = sommet.getNextVertices();
        for (var next : suivants) {
            try {
                var a = original.getEdges().get(sommet, next).getValue() + poids.get(sommet);
                if (poids.get(next).intValue() > a) {
                    poids.replace(next, a);
                    peres.put(next, sommet);
                }
            } catch (Exception e) {
                // unhandeled
            }
        }
    }

    private static void construireGraphe(final Map<VertexDirected<Character>, VertexDirected<Character>> peres,
            final GraphVIZSimpleDirectedValuated<Character, Integer> original,
            final GraphVIZSimpleDirectedValuated<Character, Integer> resultat) throws EGraphIncorrectVertex {
        for (var kv : peres.entrySet()) {
            try {
                if (!resultat.getVertices().contains(kv.getValue())) {
                    resultat.getVertices().add(kv.getValue());
                }
                resultat.getVertices().add(kv.getKey());
                resultat.getEdges().add(kv.getValue(), kv.getKey(),
                        original.getEdges().get(kv.getValue(), kv.getKey()).getValue());
            } catch (Exception e) {
                // unhandled exception
            }
        }
    }

    private static void dijkstra(final GraphVIZSimpleDirectedValuated<Character, Integer> original,
            final Character depart, final GraphVIZSimpleDirectedValuated<Character, Integer> resultat)
            throws EGraphIncorrectVertex {
        final Set<VertexDirected<Character>> marques = new HashSet<VertexDirected<Character>>();
        final Map<VertexDirected<Character>, VertexDirected<Character>> peres = new HashMap<VertexDirected<Character>, VertexDirected<Character>>();
        final Map<VertexDirected<Character>, Integer> poids = new HashMap<VertexDirected<Character>, Integer>();

        initialisation(poids, original, depart);

        do {
            final VertexDirected<Character> sommet = plusPetitSommetNonMarque(marques, poids);
            marquesSuivants(sommet, original, peres, poids);
            marques.add(sommet);
        } while (marques.size() < original.getVertices().size());

        construireGraphe(peres, original, resultat);
    }

    private static void initialisation(final Map<VertexDirected<Character>, Integer> poids,
            final GraphVIZSimpleDirectedValuated<Character, Integer> graph, final Character depart)
            throws EGraphIncorrectVertex {
        for (final VertexDirected<Character> sommet : graph.getVertices()) {
            if (sommet.getValue().equals(depart)) {
                poids.put(sommet, 0);
            } else {
                poids.put(sommet, Integer.MAX_VALUE);
            }
        }
    }

    public static void main(final String[] args) throws IOException, EGraphIncorrectVertex {
        final GraphVIZSimpleDirectedValuated<Character, Integer> original = new GraphVIZSimpleDirectedValuated<Character, Integer>(
                0, Convertor.CHARACTER, Convertor.INTEGER);
        final GraphVIZSimpleDirectedValuated<Character, Integer> resultat = new GraphVIZSimpleDirectedValuated<Character, Integer>(
                0, Convertor.CHARACTER, Convertor.INTEGER);

        final int NB_SOMMETS = 5;
        final int NB_ARETES = 12;
        final Character DEPART = 'A';
        final String DOSSIER = ""; // par defaut, dans le dossier du projet Eclipse

        creerGrapheAleatoire(original, NB_SOMMETS, NB_ARETES);
        original.getVIZ().save(DOSSIER + "original.dot");

        if (verifDijkstra(original, DEPART)) {
            dijkstra(original, DEPART, resultat);
            resultat.getVIZ().save(DOSSIER + "resultat.dot");
        }

    }

    private static VertexDirected<Character> plusPetitSommetNonMarque(final Set<VertexDirected<Character>> marques,
            final Map<VertexDirected<Character>, Integer> poids) {
        VertexDirected<Character> min = null;
        for (var kv : poids.entrySet()) {
            if (!marques.contains(kv.getKey()) && (min == null || poids.get(min).compareTo(kv.getValue()) > 0)) {
                min = kv.getKey();
            }
        }
        return min;
    }

    private static boolean verifDijkstra(final GraphVIZSimpleDirectedValuated<Character, Integer> graph,
            final Character depart) throws EGraphIncorrectVertex {
        boolean result = true;

        result = result && verifDijkstraDepartExistant(graph, depart);
        result = result && verifDijkstraValuationsPositives(graph);
        result = result && verifDijkstraSommetsAtteignables(graph, depart);

        return result;
    }

    private static boolean verifDijkstraDepartExistant(final GraphVIZSimpleDirectedValuated<Character, Integer> graph,
            final Character depart) {
        return graph.getVertices().contains(depart);
    }

    private static boolean verifDijkstraSommetsAtteignables(
            final GraphVIZSimpleDirectedValuated<Character, Integer> graph, final Character depart)
            throws EGraphIncorrectVertex {
        final VertexDirected<Character> sommetDepart = graph.getVertices().get(depart);

        final Stack<VertexDirected<Character>> pile = new Stack<VertexDirected<Character>>();
        final Set<VertexDirected<Character>> marques = new HashSet<VertexDirected<Character>>();

        pile.add(sommetDepart);

        while (!(pile.isEmpty())) {
            final VertexDirected<Character> sommetPile = pile.pop(); // recupere le sommet et depile
            if (!(marques.contains(sommetPile))) {
                marques.add(sommetPile);

                for (final VertexDirected<Character> suivant : sommetPile.getNextVertices()) {
                    pile.add(suivant);
                }
            }
        }

        return (marques.size() == graph.getVertices().size());
    }

    private static boolean verifDijkstraValuationsPositives(
            final GraphVIZSimpleDirectedValuated<Character, Integer> graph) {
        boolean result = true;
        for (final EdgeDirectedValuated<Character, Integer> e : graph.getEdges()) {
            result = result && (e.getValue() >= 0);
        }
        return result;
    }

}
