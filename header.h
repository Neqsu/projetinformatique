#ifndef HEADER_H
#define HEADER_H

typedef struct{
	int warrior;
	int ranger;
	int wizard;
	int thief;
}Adventurers;

typedef struct{
	int fire_sword;
	int pet_control_stick;
	int forbidden_grimoire;
	int sleep_dagger;
}Antique_Weapons;

typedef struct{
	int reflective_shield;
	int torch;
	int longbow;
	int stone_axe;
}Normal_Weapons;

typedef struct{
	int basilisks;
	int zombies;
	int trolls;
	int harpies;
}Monsters_Categories;

typedef struct{
	Antique_Weapons boxes;
	int treasure_chests;
	Monsters_Categories monsters;
	int teleport_magic_portal;
	int transmutation_totems;
}Maze_boxes;

#endif
