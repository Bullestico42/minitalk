de messagerie en utilisant les signaux UNIX. Deux signaux spécifiques sont utilisés dans ce projet :  

- `SIGUSR1`  
- `SIGUSR2`  

Ces signaux permettent de reconstruire une chaîne de caractères (`string`) lors de la réception des données.  

## 🔧 Utilisation  

### 1️⃣ Lancer le serveur  
Exécute la commande suivante pour démarrer le serveur :  

```bash
./server
```

Le serveur affichera son **PID** (identifiant du processus). Note-le, car il sera nécessaire pour envoyer un message.  

### 2️⃣ Envoyer un message avec le client  
Exécute la commande suivante en remplaçant `[PID]` par le numéro de processus du serveur et `"Ton message"` par le texte à envoyer :  

```bash
./client [PID] "Ton message"
```

### 3️⃣ Réception du message  
Une fois cette commande exécutée, le serveur affichera le message reçu en reconstruisant chaque caractère à l'aide des signaux `SIGUSR1` et `SIGUSR2`.  

## 🎯 Objectif pédagogique  
Minitalk est un excellent exercice pour comprendre :  
✅ La manipulation des bits en C.  
✅ L'envoi et la réception de signaux UNIX.  
✅ La communication interprocessus (IPC).  
