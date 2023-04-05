package com.example.algo;
/*
 * Auteur : Remi Vernay <rvy@eisti.eu>
 * Date   : 24/03/2014
 */

import java.io.IOException;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.concurrent.LinkedBlockingDeque;

import net.bubuntu.graph.Convertor;
import net.bubuntu.graph.EGraphIncorrectVertex;
import net.bubuntu.graph.EdgeDirectedValuated;
import net.bubuntu.graph.GraphSimple;
import net.bubuntu.graph.GraphSimpleValuated;
import net.bubuntu.graph.GraphVIZSimpleDirectedValuated;
import net.bubuntu.graph.VertexDirected;

public class App {

    private static void creerAretes(final GraphSimpleValuated<Integer, Integer> graph, final int nbSommets,
            final int nbAretes) {
        graph.getEdges().clear();
        var r = new Random(System.currentTimeMillis());
        while (graph.getEdges().size() < nbAretes) {
            final Integer head = (r.nextInt(nbSommets));
            final Integer tail = (r.nextInt(nbSommets));
            graph.getEdges().add(head, tail, (r.nextInt(30)) + 1);
        }
    }

    private static void creerGrapheAleatoire(final GraphSimpleValuated<Integer, Integer> graph, final int nbSommets,
            final int nbAretes) {
        creerSommets(graph, nbSommets);
        creerAretes(graph, nbSommets, nbAretes);
    }

    private static void creerSommets(final GraphSimple<Integer> graph, final int nbSommets) {
        graph.getVertices().clear();
        for (int i = 0; i < nbSommets; ++i) {
            graph.getVertices().add(i);
        }
    }

    private static void marquesSuivants(VertexDirected<Integer> sommet,
            GraphVIZSimpleDirectedValuated<Integer, Integer> original,
            final Map<VertexDirected<Integer>, VertexDirected<Integer>> peres,
            final Map<VertexDirected<Integer>, Integer> poids) {
        if (sommet != null) {
            var suivants = sommet.getNextVertices();
            for (var next : suivants) {
                try {
                    var a = original.getEdges().get(sommet, next).getValue() + poids.get(sommet);
                    if (poids.get(next).intValue() > a) {
                        poids.replace(next, a);
                        peres.put(next, sommet);
                    }
                } catch (Exception e) {
                    // unhandeled exception
                }
            }
        }
    }

    private static void construireGraphe(final Map<VertexDirected<Integer>, VertexDirected<Integer>> peres,
            final GraphVIZSimpleDirectedValuated<Integer, Integer> original,
            final GraphVIZSimpleDirectedValuated<Integer, Integer> resultat) {
        for (var kv : peres.entrySet()) {
            try {
                resultat.getVertices().add(kv.getValue());
                resultat.getVertices().add(kv.getKey());
                resultat.getEdges().add(kv.getValue(), kv.getKey(),
                        original.getEdges().get(kv.getValue(), kv.getKey()).getValue());
            } catch (Exception e) {
                // unhandled exception
            }
        }
    }

    private static void dijkstra(final GraphVIZSimpleDirectedValuated<Integer, Integer> original,
            final Integer depart, final GraphVIZSimpleDirectedValuated<Integer, Integer> resultat) {
        final Set<VertexDirected<Integer>> marques = new HashSet<>();
        final Map<VertexDirected<Integer>, VertexDirected<Integer>> peres = new HashMap<>();
        final Map<VertexDirected<Integer>, Integer> poids = new HashMap<>();

        initialisation(poids, original, depart);

        do {
            final VertexDirected<Integer> sommet = plusPetitSommetNonMarque(marques, poids);
            marquesSuivants(sommet, original, peres, poids);
            marques.add(sommet);
        } while (marques.size() < original.getVertices().size());

        construireGraphe(peres, original, resultat);
    }

    private static void initialisation(final Map<VertexDirected<Integer>, Integer> poids,
            final GraphVIZSimpleDirectedValuated<Integer, Integer> graph, final Integer depart) {
        for (final VertexDirected<Integer> sommet : graph.getVertices()) {
            if (sommet.getValue().equals(depart)) {
                poids.put(sommet, 0);
            } else {
                poids.put(sommet, Integer.MAX_VALUE);
            }
        }
    }

    public static void main(final String[] args) throws IOException, EGraphIncorrectVertex {
        final GraphVIZSimpleDirectedValuated<Integer, Integer> original = new GraphVIZSimpleDirectedValuated<>(
                0, Convertor.INTEGER, Convertor.INTEGER);
        final GraphVIZSimpleDirectedValuated<Integer, Integer> resultat = new GraphVIZSimpleDirectedValuated<>(
                0, Convertor.INTEGER, Convertor.INTEGER);

        final int NB_SOMMETS = 100;
        final int NB_ARETES = 2000;
        final Integer DEPART = 0;
        final String DOSSIER = ""; // par defaut, dans le dossier du projet Eclipse

        creerGrapheAleatoire(original, NB_SOMMETS, NB_ARETES);
        original.getVIZ().save(DOSSIER + "original.dot");

        if (verifDijkstra(original, DEPART)) {
            dijkstra(original, DEPART, resultat);
            resultat.getVIZ().save(DOSSIER + "resultat.dot");
        }

    }

    private static VertexDirected<Integer> plusPetitSommetNonMarque(final Set<VertexDirected<Integer>> marques,
            final Map<VertexDirected<Integer>, Integer> poids) {
        VertexDirected<Integer> min = null;
        for (var kv : poids.entrySet()) {
            if (!marques.contains(kv.getKey()) && (min == null || poids.get(min).compareTo(kv.getValue()) > 0)) {
                min = kv.getKey();
            }
        }
        return min;
    }

    private static boolean verifDijkstra(final GraphVIZSimpleDirectedValuated<Integer, Integer> graph,
            final Integer depart) throws EGraphIncorrectVertex {
        boolean result;

        result = verifDijkstraDepartExistant(graph, depart);
        result = result && verifDijkstraValuationsPositives(graph);
        result = result && verifDijkstraSommetsAtteignables(graph, depart);

        return result;
    }

    private static boolean verifDijkstraDepartExistant(final GraphVIZSimpleDirectedValuated<Integer, Integer> graph,
            final Integer depart) {
        return graph.getVertices().contains(depart);
    }

    private static boolean verifDijkstraSommetsAtteignables(
            final GraphVIZSimpleDirectedValuated<Integer, Integer> graph, final Integer depart)
            throws EGraphIncorrectVertex {
        final VertexDirected<Integer> sommetDepart = graph.getVertices().get(depart);

        final Deque<VertexDirected<Integer>> pile = new LinkedBlockingDeque<>();
        final Set<VertexDirected<Integer>> marques = new HashSet<>();

        pile.add(sommetDepart);

        while (!(pile.isEmpty())) {
            final VertexDirected<Integer> sommetPile = pile.pop(); // recupere le sommet et depile
            if (!(marques.contains(sommetPile))) {
                marques.add(sommetPile);

                for (final VertexDirected<Integer> suivant : sommetPile.getNextVertices()) {
                    pile.add(suivant);
                }
            }
        }

        return (marques.size() == graph.getVertices().size());
    }

    private static boolean verifDijkstraValuationsPositives(
            final GraphVIZSimpleDirectedValuated<Integer, Integer> graph) {
        boolean result = true;
        for (final EdgeDirectedValuated<Integer, Integer> e : graph.getEdges()) {
            result = result && (e.getValue() >= 0);
        }
        return result;
    }

}
