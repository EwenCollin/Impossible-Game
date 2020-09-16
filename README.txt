Jeu-Simple-0.3

Instructions d'utilisation :

Démarrage (console) : 

	La taille est ajustable, cependant certains paramètres comme le déplacement des obstacles ou du joueur ne sont pas exactement sensibles à la taille de la fenêtre mais en unité fixes (problème de cast et non différenciation des calculs de déplacement etc de l'affichage) (temporaire)
	Ainsi il est préférable de mettre la taille de la fenêtre au maximum que peut le permettre l'écran.

Menu principal :

	Les flèches directionnelles sont elles seules utilisées pour gérer le menu principal. (temporaire)
	Flèches haut et bas pour sélectionner les bouttons, flèche de droite pour lancer.

	Jouer :

		Joue tous les niveaux un par un. (bug d'incrémentation qui ne fait que aller jusqu'au niveau 3 je crois)
		Il n'est pas possible de quitter ce mode sans fermer le programme ou gagner tous les niveaux.

	Niveaux :

		Permet d'accéder au dernier niveau édité. (temporaire)
		Il n'est pas possible de quitter ce mode sans fermer le programme ou gagner tous les niveaux.

	Editeur :

		Permet d'utiliser l'éditeur.

Editeur :

	La croix à gauche permet de tout effacer sans demande de confirmation. (pour l'instant)
	Le V à droite permet de valider le niveau, l'enregistre en niveau "level_new.txt" (temporaire)
	Le niveau est directement joué lorsque le niveau est enregisté/validé.
	Pour éditer un nouveau niveau sans écraser l'ancien, il est nécessaire de renommer l'ancien. (temporaire)