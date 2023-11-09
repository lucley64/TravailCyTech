package com.example.jee.controllers;

import com.example.jee.data.Artist;
import com.example.jee.repositories.ArtistRepo;
import com.example.jee.repositories.MovieRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.util.Date;

@Controller
public class FormHandleController {

    @Autowired
    MovieRepo movieRepo;

    @Autowired
    ArtistRepo artistRepo;

    @GetMapping("/")
    String index(Model model) {
        return "index";
    }

    @PostMapping("/")
    String postForm(Model model) {
        return "index";
    }

    @GetMapping("/Add-Movie")
    String addMovie(Model model) {

        var artists = artistRepo.findAll();

        model.addAttribute("artists", artists);

        return "MovieForm";
    }

    @GetMapping("/Add-Artist")
    String addArtist(Model model){

        var movies = movieRepo.findAll();

        model.addAttribute("movies", movies);

        return "ArtistForm";
    }

    @PostMapping("/Add-Artist")
    String postArtist(String name, String surname, String birthdate) throws ParseException {

        Artist artist = new Artist();

        artist.setName(name);
        artist.setSurname(surname);
        artist.setBirthDate(new SimpleDateFormat("yyyy-MM-dd").parse(birthdate));

        artistRepo.save(artist);

        return "redirect:/";
    }

}
