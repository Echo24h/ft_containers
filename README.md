Le projet consiste à réécrire les conteneurs standards de la bibliothèque C++98 tels que `std::map`, `std::vector` et `std::stack`, ainsi que leurs itérateurs, en implémentant les mêmes fonctionnalités que les versions officielles. Cela implique également la création d'un arbre binaire de recherche, similaire à celui utilisé dans std::map.

Une fois le projet compilé avec make, vous pouvez lancer des tests de comparaison entre les conteneurs officiels et ceux que vous avez créés en utilisant les commandes suivantes :

* `./check map` pour comparer std::map et ft::map
* `./check vec` pour comparer std::vector et ft::vector
* `./check stack` pour comparer std::stack et ft::stack

Le projet comprend également un test de vitesse pour évaluer les performances des conteneurs en comparaison avec les versions officielles. Vous pouvez lancer ce test en utilisant la commande `./check speed`.

Pour vous aider dans votre implémentation, des ressources telles que https://en.cppreference.com/, https://cplusplus.com/ et https://en.wikipedia.org/wiki/Binary_search_tree sont mises à votre disposition. Vous pouvez également trouver des exemples de code pour les arbres de recherche binaire sur https://www.geeksforgeeks.org/binary-search-tree-data-structure/.

En résumé, ce projet école permet de renforcer les compétences en programmation C++, en approfondissant la compréhension des conteneurs standards de la bibliothèque. Le projet inclut des tests de comparaison et de vitesse pour évaluer l'efficacité de vos implémentations, ainsi que des ressources pour vous aider dans votre implémentation.


