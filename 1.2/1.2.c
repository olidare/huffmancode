#include "1.2.h"

int main(int argc, char **argv)
{
   Htree **q = malloc(MAX_CHARACTERS * sizeof(Htree));
   Htree *t;
   int size = 0;
   t = FileRead(argc, argv,size, q);
   PrintTree(t);
   return 0;
}

void PrintTree(Htree *root)
{ 
   Htree **q = malloc(MAX_CHARACTERS * sizeof(Htree));
   Htree *current = malloc(sizeof(Htree));
   int l = EMPTY, r = EMPTY;
   int size = 1;
   int count = 1;

   /*enqueue root*/    
   q[0] = malloc(sizeof(Htree));
   q[0] = root;    
   /*while queue  not empty */
	while (size-- > EMPTY) {
      l = r = EMPTY;
		count++;
      printf(" %c:%d ", q[size]->character, q[size]->freq);
      current = q[size];
      /*for each adjacent non empty node
		  enqueue and repeat  */
      if(current->right != NULL) {
         q[size] = malloc(sizeof(Htree));
         q[size] = current->right;
         ++size;
         r = FULL;
      }
      if(count%2 == FULL && count > SECONDLINE){
     		printf("--");    
      }
      if(current->left != NULL) {
         q[size] = malloc(sizeof(Htree));
         q[size] = current->left;
         ++size;	
         l = FULL;
      }
      if(l && r == FULL){
  		   printf(" \n   |   | \n");    
   	}
   }
   printf("\n\n\n");
}

