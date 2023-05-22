#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#define SIZE_PLATEAU 5

void game_turn(int choice){
	Normal_Weapons a;
	a.torch = 1;
	a.reflective_shield = 2;
	a.stone_axe = 3;
	a.longbow = 4;
	while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
		printf("Veuillez choisir une arme : \n");
	  	printf("1 - Torche");
	  	printf("2 - Bouclier\n");
	  	printf("3 - Hache\n");
		printf("4 - Arc\n");
  	}
        scanf("%d", &choice);

int main() {
    srand(time(NULL)); // Initialisation de la graine pour la génération aléatoire
	
    T_cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU];

    // Création d'un tableau contenant tous les éléments de l'énumération
    T_cards allCards[] = {
        FIRE_SWORD,
        STICK,
        FORBIDDEN_GRIMOIRE,
        SLEEP_DAGGER,
        TREASURE_CHEST,
        TREASURE_CHEST,
        BASILISK,
        BASILISK,
        BASILISK,
        BASILISK,
        ZOMBIE,
        ZOMBIE,
        ZOMBIE,
        ZOMBIE,
        TROLL,
        TROLL,
        TROLL,
        TROLL,
        HARPIE,
        HARPIE,
        HARPIE,
        HARPIE,
        TELEPORT_MAGIC_PORTAL,
        TRANSMUTATION_TOTEM,
        TRANSMUTATION_TOTEM
    };

  char symbol_card[10][10]= {"⚔","|","≡","↗","☒","〠","🧟","㋡","👾","◆","⚜"};

    int numCards = sizeof(allCards) / sizeof(allCards[0]);
    int cardCounts[numCards];
    for (int i = 0; i < numCards; i++) {
        cardCounts[i] = 0;
    }

    // Mélange des cartes
    for (int i = 0; i < numCards; i++) {
        int randomIndex = rand() % numCards;
        T_cards temp = allCards[i];
        allCards[i] = allCards[randomIndex];
        allCards[randomIndex] = temp;
    }

    // Remplissage du tableau 2D à partir du tableau mélangé
    int cardIndex = 0;
    for (int i = 0; i < SIZE_PLATEAU; i++) {
        for (int j = 0; j < SIZE_PLATEAU; j++) {
            gameBoard[i][j] = allCards[cardIndex];
            cardIndex++;
        }
    }

    // Affichage du tableau 2D
    for (int i = 0; i < SIZE_PLATEAU; i++) {
        for (int j = 0; j < SIZE_PLATEAU; j++) {
            printf("%s\t", symbol_card[gameBoard[i][j]]);
        }
        printf("\n");
    }
	
    return 0;
}
