package com.example.jee.data;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

@Entity
@Getter
@Setter
public class Note implements Serializable {

    @EmbeddedId
    private NotePK id;



    @Column
    private int noteValue;
}
