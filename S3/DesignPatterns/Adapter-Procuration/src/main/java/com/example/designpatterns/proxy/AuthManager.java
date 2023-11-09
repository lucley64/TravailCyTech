package com.example.designpatterns.proxy;


public class AuthManager implements Provider {
    Provider serviceProvider;
    String uName;
    String pwd;


    public AuthManager(Provider serviceProvider) {
        this.serviceProvider = serviceProvider;
        uName = "";
        pwd = "";
    }

    public AuthManager(Provider serviceProvider, String uName, String pwd) {
        this.serviceProvider = serviceProvider;
        this.uName = uName;
        this.pwd = pwd;
    }

    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public void setUName(String uName) {
        this.uName = uName;
    }

    @Override
    public void service1() {
        serviceProvider.service1();
    }

    @Override
    public void service2() {
        serviceProvider.service2();
    }

    @Override
    public void service3() {
        if (uName.equals("user") && pwd.equals("password")){
            serviceProvider.service3();
        }
        else{
            System.out.println("Invalid username or password");
        }
    }

    @Override
    public void service4() {
        if (uName.equals("user") && pwd.equals("password")){
            serviceProvider.service4();
        }
        else{
            System.out.println("Invalid username or password");
        }
    }
}
