#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 26
#define FALSE 0
#define TRUE 1
#define EMPTY 0 
#define FULL 1
#define SECONDLINE 2
#define MAX_FILES 2

typedef struct huffTree {
	struct huffTree *left, *right;
	char character;
	int freq;
}Htree;

Htree *FileRead(int argc, char **argv, int size, Htree **q);
void InitialiseCharacters(Htree *h);
bool ValidChar(char c);
bool isFull(int position);
Htree *Pop(Htree ***q, int *size);
void Push(Htree ***queue, Htree *h, int *size);
Htree *BuildTree(Htree **queue, int size);
Htree *AddNode(Htree *tree, Htree *node);
Htree *Search(Htree *t,char c);
void PrintTree(Htree *h);


