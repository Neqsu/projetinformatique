#include "header.h"

void vide_buffer(){
	while(getchar()!='\n'){
	}
}

// Rules of the game
void rules(){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Welcome to CY_Memory-RPG !\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nThe aim of the game for adventurers is to navigate the maze in search of a treasure chest and an ancient weapon, without getting killed by the monsters.\nThere are 4 adventurers who seek 4 weapons : the warrior seeks the sword, the ranger the staff, the magician the grimoire and the thief the dagger.\nYou can kill the monsters : the basilisk with a mirror, the zombie with a torch, the troll with an ax and the harpy with a bow\n");
}

// Choice of the number of players
int nb_players() {
  int NB_PLAYER;
  printf("Select the number of players (2-4) : \n");
  scanf("%d", &NB_PLAYER);
  if (NB_PLAYER < 2 || NB_PLAYER > 4) {
    while (NB_PLAYER < 2 || NB_PLAYER > 4) {
      printf("ERROR : Please choose between 2 and 4\n");
      scanf("%d", &NB_PLAYER);
    }
  }
  return NB_PLAYER;
}

// Choice of weapons for players
Weapon chooseWeapon(Player player) {
  
  printf("\n\n%s, choose a weapon : \n\n", player.name);
  printf("0. TORCH\n");
  printf("1. SHIELD\n");
  printf("2. AXE\n");
  printf("3. BOW\n");

  int choix;

  while(scanf("%d",&choix) != 1 || (choix != 0 && choix != 1 && choix != 2 && choix != 3 )){
  printf("Invalid choice. Please choose again :\n");
  vide_buffer();
  }
  

   switch (choix) {
    case TORCH:
      return TORCH;
    case SHIELD:
      return SHIELD;
    case AXE:
      return AXE;
    case BOW:
      return BOW;
  }
      return -1; // Invalid return value to indicate an error
  
}

// Initialization of players for their roles and game elements like chests or special items
void initialize_players(Player *players, int NB_PLAYER) {
    for (int i = 0; i < NB_PLAYER; i++) {
        switch (i) {
            case WARRIOR:
                players[i].jrole = RANGER;
                printf("Enter the name of the ranger: ");
                break;
            case RANGER:
                players[i].jrole = WARRIOR;
                printf("Enter the name of the warrior: ");
                break;
            case MAGE:
                players[i].jrole = MAGE;
                printf("Enter the name of the mage: ");
                break;
            case THIEF:
                players[i].jrole = THIEF;
                printf("Enter the name of the thief: ");
                break;
        }
        scanf("%s", players[i].name);
        players[i].x = i == WARRIOR ? 0 : (i == RANGER ? 3 : (i == MAGE ? 4 : 1));
        players[i].y = i == WARRIOR ? 1 : (i == RANGER ? 0 : (i == MAGE ? 3 : 4));
        players[i].weapon = NO_WEAPON;
        players[i].special_obj = 0;
        players[i].chest = 0;
        players[i].alive = 1;
    }
}

// Copy of the game board to reveal cards
void copy_gameboard(T_Cards source[SIZE_PLATEAU][SIZE_PLATEAU], T_Cards destination[SIZE_PLATEAU][SIZE_PLATEAU]) {
    for (int i = 0; i < SIZE_PLATEAU; i++) {
        for (int j = 0; j < SIZE_PLATEAU; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

// Player turn
void player_turn(Player *player, T_Cards gameboard[SIZE_PLATEAU][SIZE_PLATEAU], copied_gameboard[SIZE_PLATEAU][SIZE_PLATEAU], int NB_PLAYER) {
    char direction;
    return_cards(copied_gameboard);
    const char* role_names[] = {
        "WARRIOR",
        "RANGER",
        "MAGE",
        "THIEF"
    };

    printf("Player role: %s\n", role_names[player->jrole]);

const char* weapon_names[] = {
    "TORCH",
    "SHIELD",
    "AXE",
    "BOW",
};

printf("Weapon: %s\n", weapon_names[player->weapon]);

if (player->jrole == WARRIOR) {
    printf("You are the warrior and you start on the green square, you are automatically teleported to the nearest square\n");
    player->x = 0;
    player->y = 1;
} else if (player->jrole == RANGER) {
    printf("You are the ranger and you start on the purple square, you are automatically teleported to the nearest square\n");
    player->x = 3;
    player->y = 0;
} else if (player->jrole == MAGE) {
    printf("You are the mage and you start on the orange square, you are automatically teleported to the nearest square\n");
    player->x = 4;
    player->y = 3;
} else {
    printf("You are the thief and you start on the brown square, you are automatically teleported to the nearest square\n");
    player->x = 1;
    player->y = 4;
}

printf("\nChoose a direction:\n\n          z)UP\n  q) LEFT      d) RIGHT\n         s)DOWN\n\n");

do {
    getchar();
    scanf(" %c", &direction);

    switch (direction) {
        case 'z':
            if (player->y > 0) {
                player->y--;
            } else {
                printf("Stay on the plateau!\n");
                continue;
            }
            break;

        case 'q':
            if (player->x > 0) {
                player->x--;
            } else {
                printf("Stay on the plateau!\n");
                continue;
            }
            break;

        case 's':
            if (player->y < (SIZE_PLATEAU - 1)) {
                player->y++;
            } else {
                printf("Stay on the plateau!\n");
                continue;
            }
            break;

        case 'd':
            if (player->x < (SIZE_PLATEAU - 1)) {
                player->x++;
            } else {
                printf("Stay on the plateau!\n");
                continue;
            }
            break;

        default:
            printf("Please choose an element between : z, q, s, and d\n");
            exit(1);
            break;
    }

    printf("Info position (%d, %d)\n\n", player->x, player->y);

    T_Cards card = gameboard[player->y][player->x];
    print_Plateau(copied_gameboard);
    printf("Card: %d\n", card);

    // Update copied_gameboard box with corresponding gameboard value
    copied_gameboard[player->y][player->x] = card;

    switch (card) {
        case ZOMBIE:
            if (player->weapon == TORCH) {
                printf("Congratulations! You have killed a zombie!\n");
            } else {
                printf("You have been killed by a zombie. Game over.\n");
                player->alive = 0;
                return;
            }
            break;

        case TROLL:
            if (player->weapon == AXE) {
                printf("Congratulations! You have killed a troll!\n");
            } else {
                printf("You have been killed by a troll. Game over.\n");
                player->alive = 0;
                return;
            }
            break;

        case BASILISK:
            if (player->weapon == SHIELD) {
                printf("Congratulations! You have killed a basilisk!\n");
            } else {
                printf("You have been killed by a basilisk. Game over.\n");
                player->alive = 0;
                return;
            }
            break;

        case HARPY:
            if (player->weapon == BOW) {
                printf("Congratulations! You have killed a harpy!\n");
            } else {
                printf("You have been killed by a harpy. Game over.\n");
                player->alive = 0;
                return;
            }
            break;

        case FIRE_SWORD:
            if (player->jrole == WARRIOR) {
                printf("Congratulations! You have found your secret weapon!\n");
                player->special_obj++;
            }
            break;

        case STICK:
            if (player->jrole == RANGER) {
                printf("Congratulations! You have found your secret weapon!\n");
                player->special_obj++;
            }
            break;

        case FORBIDDEN_GRIMOIRE:
            if (player->jrole == MAGE) {
                printf("Congratulations! You have found your secret weapon!\n");
                player->special_obj++;
            }
            break;

        case SLEEP_DAGGER:
            if (player->jrole == THIEF) {
                printf("Congratulations! You have found your secret weapon!\n");
                player->special_obj++;
            }
            break;

        case TREASURE_CHEST:
            printf("Congratulations! You have found a legendary chest!\n");
            player->chest++;
            break;

        case TELEPORT_MAGIC_PORTAL:
            printf("You have found a portal! Choose coordinates for the teleportation:\n");
            printf("Enter x coordinate: ");
            scanf("%d", &player->x);
            printf("Enter y coordinate: ");
            scanf("%d", &player->y);
            break;

        case TRANSMUTATION_TOTEM:
            printf("You have found the transmutation totem. Choose a hidden square:\n");
            player->alive = 0; // Le joueur n'est pas mort, mais le tour se termine ici.
            break;

        default:
            break;
    }
} while (player->alive && !player_win(*player));
}

int player_win(Player player){
    return (player.x == SIZE_PLATEAU - 1 && player.y == SIZE_PLATEAU - 1 && player.treasureFound);
}
