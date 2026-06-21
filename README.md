# ⚙️ Arduino Fault Tolerance & Hardware Watchdog

**Concept :** Émulation matérielle (TRL 4) de systèmes critiques.
**Objectif :** Tester la résilience physique d'un microcontrôleur face à un emballement logiciel.

**Tests de laboratoire (Wokwi) :**
Ce dépôt contient les tests d'interruption matérielle. Le Watchdog surveille la latence de calcul. Si la latence dépasse 5 ms, le microcontrôleur verrouille l'exécution du programme dans une boucle de sécurité infinie (`while(true)`). 
*Observabilité :* Pour prouver que le système n'est pas simplement planté ou à court d'énergie, une routine de "Heartbeat" (battement de cœur visuel via LED rouge et ping série) est maintenue pendant le verrouillage.
