# Dante

Outils de génération et résolution de labyrinthes

### Pré-requis

```
gcc
make
```

### Installation

Voici comment lancer le projet sur votre ordinateur:

Compilation

```
make
```

Lancement génération

```
./generator/generator [height] [width] [perfect/imperfect]
```

Vous pouver aussi lancer le script shell qui génère des labyrinthes et les stocke dans le dossier mazes

```
./generator/maps_gen.sh
```

Puis finalement lancer le script enhancer qui va transfomer les labyrinthes en images (.ppm)

```
./generator/txt_to_ppm.sh [from] [to]
```

Lancement du solveur

```
./solver/solver [maze]
```

## Auteurs

* **Jean-Yanis Jeffroy**
* **Thibaut Hebert--Henriette**
