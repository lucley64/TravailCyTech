package com.example.jee.data;

import jakarta.persistence.Embeddable;
import jakarta.persistence.ManyToOne;

import java.io.Serializable;

@Embeddable
public class NotePK implements Serializable {
    @ManyToOne(targetEntity = Movie.class)
    private Movie movie;

    @ManyToOne(targetEntity = Critique.class)
    private Critique critique;
}
