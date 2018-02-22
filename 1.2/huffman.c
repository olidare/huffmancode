#include "1.2.h"

Htree *FileRead(int argc, char **argv, int size, Htree **q)
{
   FILE *fp;
   Htree *t;
   int i, charArray[MAX_CHARACTERS] = {0};
   char ch;

   if (argc > (MAX_FILES)) {
      fprintf(stderr, "Cannot open 2 files, %s\n Try again e.g. %s test.txt\n" , argv[2], argv[0]);
      exit(EXIT_FAILURE);
   }
   fp = fopen (argv[1], "r");
   if (fp == NULL) {
      fprintf(stderr, "Error opening file, try file name test.txt\n");
      exit(EXIT_FAILURE);
   }   
   /*reads characters in from file and counts their occurence*/
   while (TRUE) {
      ch = toupper(fgetc(fp));
	   if (ch == EOF) break; 
	   ValidChar(ch);
	   /* Take away 'A' so that A is in the first array cell */
	   charArray[ch-'A']++;
	}
	/*pushes all of the characters which appear into a priority queue.*/
	for (i = 0; i < MAX_CHARACTERS; ++i) {
		if(charArray[i]) {
		   Htree *h = malloc(sizeof(Htree));
		   /*add 'A' to 'i' so it matches the correct ASCI value . */
		   h->character = i + 'A';
		   h->freq = charArray[i];
		   Push(&q, h, &size);
		}
	}
   /*  Construct Huffman Tree */	
   t = BuildTree(q, size);
   return t;
}

/*Builds a huffman tree from priority queue nodes*/
Htree *BuildTree(Htree **queue, int size)
{
	Htree *tree = malloc(sizeof(Htree));
	tree->left = malloc(sizeof(Htree));
	tree->right = malloc(sizeof(Htree));

	while(size > EMPTY)
	{	/*Pops values from queue into nodes on the tree*/
		Htree *left = Pop(&queue, &size);
		Htree *right = Pop(&queue, &size);
      
		tree = AddNode(left, right);
		/* Pushes tree back onto the priority queue*/
		Push(&queue, tree, &size);
	}
	return tree;
}

Htree *Pop(Htree ***queue, int *size)
{
	/*Returns: the smallest element of the queue*/
	Htree *val = (*queue)[0];

	/* pointer keeping track of the queue size*/
	(*size)--;

	/*shifts queues index up by one due to value being removed*/
	(*queue)++;
	return val;
}

/*Pushes an element into priority queue  */
void Push(Htree ***queue, Htree *h, int *size)
{
	/* dereference size, increase it by one &
	add node into the newly malloced queue space*/
	int i, j, length = ++(*size);

	Htree *temp = malloc(sizeof(Htree));
	(*queue)[length-1] = malloc(sizeof(Htree));
	(*queue)[length-1] = h;

	/*bubble sort values, lowest first */
	for(i = 0; i < length - 1; i++) {
		for(j = i+1; j < length; j++){
			if((*queue)[i]->freq > (*queue)[j]->freq) {
				temp = (*queue)[j];
				(*queue)[j] = (*queue)[i];
				(*queue)[i] = temp;
			}
		}
	}
}

Htree *AddNode(Htree *tree, Htree *node)
{
	Htree *newNode = malloc(sizeof(Htree));
	newNode->left = newNode->right = malloc(sizeof(Htree));
	newNode->left = newNode->right = NULL;

	if(node == NULL) {
		return tree;
	}

	/*Puts nodes in left and right branches*/
	newNode->left = tree;
	newNode->right = node;

   /*Returns parent node which is the sum of its two children*/
	newNode->freq = tree->freq + node->freq;
	newNode->character = '#';
	
	return newNode;
}


int isLeaf(Htree *h)
{
   return !(h->left) && !(h->right) ;
}

/*Not out of bounds*/
bool isFull(int position)
{
   return position == MAX_CHARACTERS;
}

bool ValidChar(char c)
{
	if ('A' <= c && c <= 'Z') {
		return TRUE;
	}
	else {
      fprintf(stderr, "Error Invalid character, only A-Z permitted\n");
      exit(EXIT_FAILURE);
      return FALSE;
	}

}
