Projet de bibliothèque C++ multiplateforme compatible Arduino : Pour plus d'informations, consultez http://www.visualmicro.com

Ce projet fonctionne exactement de la même manière qu'une bibliothèque Arduino devrait fonctionner. 
Le code doit être dans le dossier \src, le code dans les sous-dossiers profonds sous le dossier \src est également pris en charge.

Le dossier \src, s'il existe, sera ajouté en tant que compilateur -I include path, 
sinon le dossier de la bibliothèque sera un compilateur -I include path.

Les très anciennes bibliothèques Arduino ont du code dans le dossier de la bibliothèque et du code 
privé dans le sous-dossier \utility. Ils doivent être convertis dans ce nouveau format en utilisant \src et library.properties

Ajoutez ce projet à toute solution contenant un projet Arduino et #include <headers.h> 
dans le code comme vous le feriez pour n'importe quel en-tête de bibliothèque Arduino normal.

Pour activer intellisense et prendre en charge la découverte de build en direct en dehors 
des emplacements de bibliothèque Arduino "standard", assurez-vous que la bibliothèque est ajoutée 
en tant que référence de projet partagée au projet Arduino principal. Pour cela, faites un clic droit 
sur le nœud "Références" du projet maître puis cliquez sur "Ajouter une référence". 
Une fenêtre s'ouvrira et la bibliothèque apparaîtra dans l'onglet "Projets partagés". 
Cochez la case à côté du nom de la bibliothèque pour ajouter la référence. 
Si cette bibliothèque est déplacée, la référence à celle-ci doit être supprimée/rajoutée de 
tous les projets Arduino qui l'utilisent.

VS2017 a un bogue, solution de contournement : après avoir déplacé le code source existant 
dans une "bibliothèque ou un projet partagé", fermez et rouvrez la solution.

Visual Studio affichera intellisense pour les bibliothèques en fonction de la plate-forme/carte 
qui a été spécifiée pour le "projet de démarrage" actuellement actif de la solution actuelle.

L'ajout d'une référence de projet de bibliothèque partagée pour une architecture incorrecte 
(sélection de carte incorrecte) entraînera des erreurs Intellisense et/ou de compilation.

IMPORTANT : Les règles de la bibliothèque arduino.cc doivent être suivies lors 
de l'ajout de code ou de la restructuration de bibliothèques.


blog : http://www.visualmicro.com/post/2017/01/16/Arduino-Cross-Platform-Library-Development.aspx