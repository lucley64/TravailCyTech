package com.example.commande;

import java.util.ArrayDeque;
import java.util.Deque;

public class Invoker {
    private final Deque<Command> commands;

    public Invoker(){
        commands = new ArrayDeque<>();
    }
    public void add(Command cmd){
        cmd.action();
        commands.add(cmd);
    }

    public Command undo(){
        var cmd = commands.removeLast();
        cmd.undo();
        return cmd;
    }
}
