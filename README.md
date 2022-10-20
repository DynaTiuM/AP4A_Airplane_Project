README!

Ce projet a été compilé grâce à MinGW et les fichiers ont été build grâce à CMAKE en créant un CMakeLists.txt afin de le faire fonctionner sous Visual Studio CODE.

Ce projet possède des thread grâce à la librairie #include <thread>", cette dernière a été intégrée dans le fichier CMakeLists afin de pouvoir normalement fonctionner sous Linux.
La méthode fileWrite de la classe Server permet d'écrire les logs dans des fichiers texte. Ce dernier possède un chemin d'accès (actuellement "C:/Users/rapha/AP4A/src/") qui doit être modifié si vous souhaitez pouvoir avoir accès aux fichiers de logs.

Lors du lancement du programme, il est demandé de choisir le mode d'affichage/écriture des données des sensors. L'utilisateur peut donc choisir d'activer les deux (console & logs), ou un seul etc
!! Il est également possible de pouvoir activer/désactiver les logs/la console ou les 2, ou éventuellement quitter le programme en réenvoyant les mêmes réponses (l, c, y ou q) PENDANT l'utilisation du programme.
Cela est possible grâce à l'utilisation d'un thread indépendant qui pose la question à l'utilisateur (parallel computing) pendant que les données continuent d'être récupérées par les autres threads.
