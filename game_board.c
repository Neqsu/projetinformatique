
#include "header.h"

void create_table(T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU]) {
  // Seed initialization for random generation
  srand(time(NULL));
  T_Cards allCards[] = {FIRE_SWORD,
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
                        HARPY,
                        HARPY,
                        HARPY,
                        HARPY,
                        TELEPORT_MAGIC_PORTAL,
                        TRANSMUTATION_TOTEM,
                        TRANSMUTATION_TOTEM,
                        PLAYERPOS};

  int numCards = sizeof(allCards) / sizeof(allCards[0]);

  // Shuffling of cards
  for (int i = 0; i < numCards; i++) {
    int randomIndex = rand() % numCards;
    T_Cards temp = allCards[i];
    allCards[i] = allCards[randomIndex];
    allCards[randomIndex] = temp;
  }

  // Filling 2D array from shuffled array
  int cardIndex = 0;
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < SIZE_PLATEAU; j++) {
      gameBoard[i][j] = allCards[cardIndex];
      cardIndex++;
    }
  }
}

// 2D array display
void print_table(T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU]) {
  char symbol_card[10][10] = {"⚔","|","≡","↗","☒","〠","🧟","㋡","👾","◆","?"};
    for (int i = 0; i < SIZE_PLATEAU;i++){
      for (int j = 0; j < SIZE_PLATEAU;j++){
          printf("%s\t", symbol_card[gameBoard[i][j]]);
        }
      printf("\n");
    }
}

// Turn over all the cards in the array
void return_cards(T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU]) {
  for (int i = 0; i < SIZE_PLATEAU; i++) {
    for (int j = 0; j < SIZE_PLATEAU; j++) {
      gameBoard[i][j] = HIDDEN;
    }
  }
}

// Construction of the game board with the position of the players
void print_Plateau(T_Cards tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]) {
  char symbol_card[13][10] = {
    "⚔️", "🏹", "📜", "🗡️", "🎁", "🐍", "🧟", "🧞", "🧚", "📦", "🦁", "👴", "🕹"
  };

  printf("\n");
  printf("          \U0001F7EA "); // Purple square

  for (int i = 0; i < SIZE_PLATEAU; i++) {
    printf("\n");

    if (i == 1) {
      printf("\U0001F7E9"); // Green square
    } else {
      printf("  ");
    }

    for (int j = 0; j < SIZE_PLATEAU; j++) {
      printf("%s ", symbol_card[tab_plateau[i][j]]);
    }

    if (i == SIZE_PLATEAU - 2) {
      printf("\U0001F7E7"); // Orange square
    }
  }

  printf("\n");
  printf("    \U0001F7EB\n"); // Brown square
  printf("\n");
}
