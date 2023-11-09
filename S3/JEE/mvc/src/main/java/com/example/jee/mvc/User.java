package com.example.jee.mvc;

import org.jetbrains.annotations.Contract;

import java.util.Date;

public class User {
    private String firstName;
    private String lastName;
    private String street;
    private String postCode;
    private String city;
    private Date birthDate;
    private String gender;
    private String birthplace;
    private Transportation transportation;

    public User() {
        this("John", "Doe", "phony street", "0000", "phony", new Date(0), "none", "nowhere", Transportation.BUS);
    }

    @Contract(pure = true)
    public User(String firstName, String lastName, String street, String postCode, String city, Date birthDate, String gender, String birthplace, Transportation transportation) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.street = street;
        this.postCode = postCode;
        this.city = city;
        this.birthDate = birthDate;
        this.gender = gender;
        this.birthplace = birthplace;
        this.transportation = transportation;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getPostCode() {
        return postCode;
    }

    public void setPostCode(String postCode) {
        this.postCode = postCode;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public Date getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(Date birthDate) {
        this.birthDate = birthDate;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getBirthplace() {
        return birthplace;
    }

    public void setBirthplace(String birthplace) {
        this.birthplace = birthplace;
    }

    public Transportation getTransportation() {
        return transportation;
    }

    public void setTransportation(Transportation transportation) {
        this.transportation = transportation;
    }
}
