#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef HEADER_H
#define HEADER_H
#define PLAYERS 4
#define NB_ROLE 4
#define CARD_BACK "🂠"
#define SIZE_PLATEAU 5
#define EXTRA_SIZE 1
#define TOTAL_SIZE (SIZE_PLATEAU + EXTRA_SIZE)

typedef enum {
  FIRE_SWORD,
  STICK,
  FORBIDDEN_GRIMOIRE,
  SLEEP_DAGGER,
  TREASURE_CHEST,
  BASILISK,
  ZOMBIE,
  TROLL,
  HARPY,
  HIDDEN,
  PLAYERPOS,
  TELEPORT_MAGIC_PORTAL,
  TRANSMUTATION_TOTEM,
  EMPTY,
} T_Cards;

typedef enum {
  WARRIOR,
  RANGER,
  MAGE,
  THIEF,
} T_Role;

typedef enum {
  TORCH,
  SHIELD,
  AXE,
  BOW,
  NO_WEAPON,
} Weapon;

typedef struct {
  char name[50];
  int num;
  T_Role jrole;
  T_Cards role;
  Weapon weapon;
  int alive;
  int treasureFound;
  int nb_cases;
  int chest;
  int special_obj;
  int x;
  int y;
} Player;

void vide_buffer();

void rules();

int nb_players();

Weapon chooseWeapon(Player player);

void initialize_players(Player *players, int NB_PLAYER);

void copy_gameboard(T_Cards source[SIZE_PLATEAU][SIZE_PLATEAU], T_Cards destination[SIZE_PLATEAU][SIZE_PLATEAU]);

void player_turn(Player *player, T_Cards gameboard[SIZE_PLATEAU][SIZE_PLATEAU], copied_gameboard[SIZE_PLATEAU][SIZE_PLATEAU], int NB_PLAYER);

void create_table(T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU]);

void print_table(T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU]);

void return_cards(T_Cards gameBoard[SIZE_PLATEAU][SIZE_PLATEAU]);

void print_Plateau(T_Cards tab_plateau[SIZE_PLATEAU][SIZE_PLATEAU]);

#endif
