package com.example.jee.data;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;
import java.util.Set;

@Entity
@Getter
@Setter
public class Artist {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private int id;

    @Column
    private String name;

    @Column
    private String surname;

    @Column
    private Date birthDate;

    @ManyToMany(targetEntity = Movie.class, mappedBy = "artists")
    private Set<Movie> movies;

    @ManyToMany(targetEntity = Movie.class, mappedBy = "directors")
    private Set<Movie> directed;
}
