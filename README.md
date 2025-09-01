Bonjour!

⸻

Kucing v0.0.3 🐾

Kucing est un langage de programmation interprété léger, inspiré de C, Python et BASIC.

Fonctionnalités (v0.0.3)
	•	Assignation de variables avec opérations mathématiques

let x = 2 + 3;


	•	Impression (affichage à l’écran)

print("Bonjour");
print(x);


	•	Définition et appel de fonction

function greet {
    print("Miaou!");
}

greet();


	•	Expressions conditionnelles (if x > 2 { ... })
	•	Boucles for avec syntaxe personnalisée :
for i from 0 to 5 step 1 { ... }

Exécution du code

Compilation :

gcc src/*.c -Iinclude -o kucing

Exécuter un fichier .kc :

./kucing hello.kc


⸻

🔄 Comparaison de Kucing

Fonction	C	Python	Kucing
Typage statique	Oui	Non	Non
Accolades {}	Oui	Non	Oui
Points-virgules	Oui	Optionnel	Oui
Décl. : int x	Oui	x = 5	let x = 5
Boucles faciles	Non	Oui	Oui
Appel de fonction	foo()	foo()	foo();


⸻

🧬 Héritage C

Kucing est implémenté en C, tout comme l’interpréteur original de Python (CPython).

Plusieurs grands langages — comme Python, Lua, et Kucing — sont écrits en C et interprètent leur propre syntaxe. Cela donne à Kucing :
	•	Une exécution rapide et portable
	•	Un contrôle fin sur la mémoire et le flot d’exécution
	•	Un accès direct au style C pour l’analyse et l’évaluation

⸻

📁 Types de fichiers et image de marque
	•	Extension des fichiers source : .kc (Kucing Code) 🐾
	•	Icône de fichier source : 🐾
	•	Écran d’accueil dans le terminal :

KUCING v0.0.3 🐾



⸻

D’autres fonctionnalités s’en viennent bientôt ! 🐈‍⬛

⸻

📣 Prononciation

Kucing se prononce « koo-ching ».

⸻

🧪 Fichier de test

Exécutez le fichier test.kc inclus pour essayer la syntaxe et la logique de Kucing :

./kucing test.kc

Il démontre les boucles de base, l’impression et la structure de la syntaxe.

⸻

