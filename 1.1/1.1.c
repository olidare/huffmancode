#include "1.1.h"

int main(int argc, char **argv)
{
   Htree **q = malloc(MAX_CHARACTERS * sizeof(Htree));
   Htree *t;
   int size = 0;
   t = FileRead(argc, argv,size, q);
   HuffmanCode(t);
   return 0;
}

void HuffmanCode(Htree *t)
{
   int CodeArray[MAX_CHARACTERS], top = EMPTY;
   int finalFreq = 0;

   /*Print encoded values using the Huffman tree built above*/
   printf("\n");
   Encode(t, CodeArray, top, &finalFreq);
   printf("%d Bytes \n\n\n", finalFreq);

}

void Encode(Htree *h, int *CodeArray, int top, int *finalFreq)
{
   /* Assign 0 to left edge and recurse */
   if (h->left) {
      CodeArray[top] = 0;
      Encode(h->left, CodeArray, top + 1, finalFreq);
   } 
   /* Assign 1 to right edge and recurse */
   if (h->right) {
      CodeArray[top] = 1;
      Encode(h->right, CodeArray, top + 1, finalFreq);
   }
   /* If a leaf node, then print character and its encoded value. */
   if (isLeaf(h)) {
   	printf("'%c' :\t", h->character);
      BinaryCode(h,CodeArray, top, finalFreq);
      printf(" * %d)\n", h->freq );
   }
}

/* prints out the the codeArray */
void BinaryCode(Htree *h, int *CodeArray, int n, int *finalFreq)
{
   int codeLength, multipliedLength;
   for (codeLength = 0; codeLength < n; ++codeLength) {
      printf("%d", CodeArray[codeLength]);
   }
   /*multplies codelength with frequency to get the total bytes*/
   multipliedLength = codeLength*h->freq;
   (*finalFreq)+= multipliedLength; 
   printf("\t ( %d", codeLength);
}


