package org.example.canvas;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class Canvas extends JPanel {
    private transient List<Drawable> drawables = new ArrayList<>();

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        for (Drawable drawable : drawables) {
            drawable.draw(g);
        }
    }

    public void addDrawable(Drawable drawable) {drawables.add(drawable);repaint();revalidate();}
    public List<Drawable> getDrawables() {return drawables;}
    public void removeDrawable(Drawable drawable) {drawables.remove(drawable);repaint();}
    public void clearDrawables() {drawables.clear();repaint();}


}
