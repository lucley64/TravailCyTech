package org.example.graphics3d;

import org.example.canvas.Canvas;

import javax.swing.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class KeyboardMovement extends KeyAdapter {
    private Canvas canvas;
    private Scene scene;
    private final float speed = 5;

    public KeyboardMovement(Canvas canvas, Scene scene) {
        this.canvas = canvas;
        this.scene = scene;
        canvas.addKeyListener(this);
        canvas.getInputMap().put(KeyStroke.getKeyStroke("A"), "a");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("Z"), "z");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("E"), "e");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("Q"), "q");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("S"), "s");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("D"), "d");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("R"), "r");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("F"), "f");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("W"), "w");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("X"), "x");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("1"), "1");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("2"), "2");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("3"), "3");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("UP"), "up");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("DOWN"), "down");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("RIGHT"), "right");
        canvas.getInputMap().put(KeyStroke.getKeyStroke("LEFT"), "left");
    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_A -> rotateZNeg();
            case KeyEvent.VK_E -> rotateZPos();
            case KeyEvent.VK_Z -> moveYPos();
            case KeyEvent.VK_Q -> moveXNeg();
            case KeyEvent.VK_S -> moveYNeg();
            case KeyEvent.VK_D -> moveXPos();
            case KeyEvent.VK_R -> moveZPos();
            case KeyEvent.VK_F -> moveZNeg();
            case KeyEvent.VK_W -> zoomIn();
            case KeyEvent.VK_X -> zoomOut();
            case KeyEvent.VK_NUMPAD1 -> resetRotationEuler();
            case KeyEvent.VK_NUMPAD2 -> resetRotationAngleAxis();
            case KeyEvent.VK_NUMPAD3 -> zoomOut();
            case KeyEvent.VK_UP -> rotateXPos();
            case KeyEvent.VK_DOWN -> rotateXNeg();
            case KeyEvent.VK_RIGHT -> rotateYNeg();
            case KeyEvent.VK_LEFT -> rotateYPos();
            case KeyEvent.VK_SUBTRACT -> toggleProjection();
            case KeyEvent.VK_ADD -> toggleWireFrame();
            case KeyEvent.VK_MULTIPLY -> toggleBackfaceCulling();
            case KeyEvent.VK_I -> moveUp();
            case KeyEvent.VK_J -> moveLeft();
            case KeyEvent.VK_K -> moveDown();
            case KeyEvent.VK_L -> moveRight();
            case KeyEvent.VK_U -> lookLeft();
            case KeyEvent.VK_O -> lookRight();
            case KeyEvent.VK_P -> lookUp();
            case KeyEvent.VK_M -> lookDown();
        }
        scene.printRotation();
        scene.rerender(canvas);
        super.keyPressed(e);
    }

    private void toggleBackfaceCulling() {
        scene.setUseBackfaceCulling(!scene.isUseBackfaceCulling());
    }

    private void rotateXNeg() {
        scene.rotateX(-speed);
    }

    private void rotateYNeg() {
        scene.rotateY(-speed);
    }

    private void rotateZNeg() {
        scene.rotateZ(-speed);
    }

    private void rotateXPos() {
        scene.rotateX(speed);
    }

    private void rotateYPos() {
        scene.rotateY(speed);
    }

    private void rotateZPos() {
        scene.rotateZ(speed);
    }

    private void moveXPos() {
        scene.translate(speed, 0, 0);
    }

    private void moveYPos() {
        scene.translate(0, speed, 0);
    }

    private void moveZPos() {
        scene.translate(0, 0, speed);
    }

    private void moveXNeg() {
        scene.translate(-speed, 0, 0);
    }

    private void moveYNeg() {
        scene.translate(0, -speed, 0);
    }

    private void moveZNeg() {
        scene.translate(0, 0, -speed);
    }

    private void zoomIn() {
        scene.scale(1.1f);
    }

    private void zoomOut() {
        scene.scale(0.9f);
    }

    private void resetRotationEuler() {
        scene.resetRotationEulerAngles(canvas);
    }

    private void resetRotationAngleAxis(){
        scene.resetRotationExponentialMap(canvas);
    }

    private void toggleProjection() {
        scene.setUsesPerspective(!scene.isUsesPerspective());
    }

    private void toggleWireFrame(){
        scene.setWireFrame(!scene.isWireFrame());
    }

    private void moveUp() {
        scene.getCamera().translate(0, 0, -speed);
    }

    private void moveLeft() {
        scene.getCamera().translate(speed, 0, 0);
    }

    private void moveRight() {
        scene.getCamera().translate(-speed, 0, 0);
    }

    private void moveDown() {
        scene.getCamera().translate(0, 0, speed);
    }

    private void lookLeft() {
        scene.getCamera().rotateY((float) (-Math.PI/180));
    }

    private void lookRight() {
        scene.getCamera().rotateY((float) (Math.PI/180));
    }

    private void lookUp() {
        scene.getCamera().rotateX((float) (-Math.PI/180));
    }

    private void lookDown() {
        scene.getCamera().rotateX((float) (Math.PI/180));
    }
}
