package com.example.designpatterns;

import com.example.designpatterns.adapter.Adapter;
import com.example.designpatterns.adapter.Utils;
import com.example.designpatterns.proxy.AuthManager;
import com.example.designpatterns.proxy.CostManager;
import com.example.designpatterns.proxy.ServiceProvider;

import java.util.List;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        List<Object> list = List.of(.2, "Hello", 55, true, ',', -6, "World", '!');
        StringTokenizer st = new StringTokenizer("this is a test");

        Utils.printChars(list.iterator());
        Utils.printChars(new Adapter<>(st));;


        ServiceProvider serviceProvider = new ServiceProvider();
        AuthManager authManager = new AuthManager(serviceProvider);
        CostManager costManager = new CostManager(authManager, 2.5, 3.3, 5, 10);


        costManager.service1();
        costManager.service2();
        costManager.service1();
        costManager.service3();
        authManager.setUName("user");
        authManager.setPwd("password");
        costManager.service4();
        costManager.service2();
        costManager.service4();
        costManager.service1();


        System.out.println(costManager.getTotalCosts());




    }
}