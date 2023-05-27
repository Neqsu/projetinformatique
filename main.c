#include <stdio.h>
#include "header.h"

int main() {

  // Copie du plateau de jeu original vers le plateau copi
  
  int NB_PLAYER;
  T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU];
  rules();
  create_table(gameBoard);
  T_Cards copied_gameboard[SIZE_PLATEAU][SIZE_PLATEAU];
  copy_gameboard(gameBoard, copied_gameboard);
  print_Plateau(gameBoard);
  print_Plateau(copied_gameboard);

  NB_PLAYER = nb_players();
  Player players[NB_PLAYER];
  initialize_players(players, NB_PLAYER);
  
  for (int i = 0; i < NB_PLAYER; i++) {
    Weapon weapon = chooseWeapon(players[i]);
    players[i].weapon = weapon;
  }

  for (int i = 0; i < NB_PLAYER; i++) {
    printf("\nPlayer %d : %s,\n Weapon : ", i + 1, players[i].name);

    switch (players[i].weapon) {
    case TORCH:
      printf("TORCH\n");
      break;
    case SHIELD:
      printf("SHIELD\n");
      break;
    case AXE:
      printf("AXE\n");
      break;
    case BOW:
      printf("BOW\n");
      break;
    }
  }

  printf("\nPlayers, are you ready ? (Yes/No): ");
  char ready[10];
  scanf("%s", ready);
  if (strcmp(ready, "Yes") == 0 || strcmp(ready, "YES") == 0) {
    return_cards(copied_gameboard);
    print_Plateau(copied_gameboard);
  } 
  else if(strcmp(ready, "No") == 0 || strcmp(ready, "No") == 0){
    printf("Too bad !\n");
    exit(1);
  }
  else{
    printf("Incorrect choice, please retry.\n");
    exit(1);
  }
  
  if(players->jrole == WARRIOR){
    
  }
  player_turn(players, gameBoard, copied_gameboard, NB_PLAYER);
  
  // Affichage du nouveau tableau avec la position du joueur mise à jour
  

  return 0;
}
