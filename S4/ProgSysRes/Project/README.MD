# Projet Programmation Système et Réseau

## Compilation

___Cmake 3.28 et ninja sont nécessaires pour compiler___

```Bash
cmake --build cmake-build-debug --target Project -j 6
```

## Partie A

```bash
./cmake-build-debug/Project part_a
```


## Partie B

### Premier client / serveur

```bash
./cmake-build-debug/Project part_b <client_1|server_1>
```

Ce premier programme est plutôt simple. En passant par deux pipes, un client → serveur et un serveur → client, un message est envoyé du client ver le serveur puis il est inversé et est renvoyé du serveur vers le client.

### Deuxième client / serveur

```bash
./cmake-build-debug/Project part_b <client_2|server_2>
```

Ce deuxième programme est aussi simple. Avec le même protocole que précédemment, le message est envoyé traité et retourné.




