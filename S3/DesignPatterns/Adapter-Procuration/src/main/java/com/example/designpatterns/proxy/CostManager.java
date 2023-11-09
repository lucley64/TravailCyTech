package com.example.designpatterns.proxy;

import org.jetbrains.annotations.Contract;

public class CostManager implements Provider{
    Provider serviceProvider;
    double service1Cost;
    double service2Cost;
    double service3Cost;
    double service4Cost;
    int service1Usages;
    int service2Usages;
    int service3Usages;
    int service4Usages;

    @Contract(pure = true)
    public CostManager(Provider serviceProvider, double service1Cost, double service2Cost, double service3Cost, double service4Cost){
        this.serviceProvider = serviceProvider;
        this.service1Cost = service1Cost;
        this.service2Cost = service2Cost;
        this.service3Cost = service3Cost;
        this.service4Cost = service4Cost;
        service1Usages = 0;
        service2Usages = 0;
        service3Usages = 0;
        service4Usages = 0;
    }

    @Override
    public void service1() {
        service1Usages++;
        serviceProvider.service1();
    }

    @Override
    public void service2() {
        service2Usages++;
        serviceProvider.service2();
    }

    @Override
    public void service3() {
        service3Usages++;
        serviceProvider.service3();
    }

    @Override
    public void service4() {
        service4Usages++;
        serviceProvider.service4();
    }


    public double getTotalCosts(){
        return service1Cost * service1Usages + service2Cost * service2Usages + service3Usages * service3Cost + service4Cost * service4Usages;
    }
}
