#include <stdio.h>
#include "header.h"

void game_turn(int choice){
	Normal_Weapons a;
	a.torch = 1;
	a.reflective_shield = 2;
	a.stone_axe = 3;
	a.longbow = 4;
	while(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
		printf("Veuillez choisir une arme : \n");
	  	printf("1 - Torche");
	  	printf("2 - Bouclier\n");
	  	printf("3 - Hache\n");
		printf("4 - Arc\n");
  	}
        scanf("%d", &choice);
