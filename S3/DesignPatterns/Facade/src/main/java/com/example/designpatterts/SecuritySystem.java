package com.example.designpatterts;

import java.util.List;

import security.Alarm;
import security.Camera;
import security.Light;
import security.Sensor;

public class SecuritySystem {
    private List<Sensor> sensorList;

    private List<Alarm> alarmList;

    private List<Camera> cameraList;

    private List<Light> lightsList;

    public SecuritySystem(){
        Sensor sensor1 = new Sensor();
        Sensor sensor2 = new Sensor();
        Sensor sensor3 = new Sensor();
        Sensor sensor4 = new Sensor();
        Sensor sensor5 = new Sensor();

        sensorList = List.of(sensor1, sensor2, sensor3, sensor4, sensor5);

        alarmList = List.of(new Alarm());

        cameraList = List.of(new Camera(), new Camera());

        lightsList = List.of(new Light(), new Light(), new Light());
        
    }

    public void turnOn(){
        for (var alarm : alarmList) {
            alarm.activate();
        }
        for (var light : lightsList) {
            light.turnOn();
        }
        for (var camera : cameraList) {
            camera.turnOn();
        }
        for (var sensor : sensorList) {
            sensor.activate();
        }
    }

    public void turnOff(){
        for (var alarm : alarmList) {
            alarm.deactivate();
        }
        for (var light : lightsList) {
            light.turnOff();
        }
        for (var camera : cameraList) {
            camera.turnOff();
        }
        for (var sensor : sensorList) {
            sensor.deactivate();
        }
    }
}

