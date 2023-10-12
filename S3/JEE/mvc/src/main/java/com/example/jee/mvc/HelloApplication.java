package com.example.jee.mvc;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

@WebServlet(name = "hello", urlPatterns = "/")
public class HelloApplication extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String viewPath = "/showUserForm.jsp";
        req.getRequestDispatcher(viewPath).forward(req, resp);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        PrintWriter out = resp.getWriter();

        var name = req.getParameter("name");
        var surname = req.getParameter("surname");
        Date birthDate = null;
        try {
            birthDate = new SimpleDateFormat("yyyy-MM-dd").parse(req.getParameter("birth"));
        } catch (ParseException ignored) {
            // ignored
        }
        var birthPlace = req.getParameter("birthplace");
        var gender = req.getParameter("gender");
        var address = req.getParameter("address");
        var postCode = req.getParameter("postcode");
        var city = req.getParameter("city");
        var transportation = Transportation.valueOf(req.getParameter("transport").toUpperCase());

        if (name == null || surname == null || birthDate == null || birthPlace == null || gender == null || address == null || postCode == null || city == null || transportation == null){
            doGet(req, resp);
        }
        else {

            User user = new User(surname, name, address, postCode, city, birthDate, gender, birthPlace, transportation);
            String viewPath = "/showUserForm.jsp";
            req.getRequestDispatcher(viewPath).forward(req, resp);


        }
    }
}