# huffmancode

Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. 

The variable-length codes assigned to input characters are Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not the prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bitstream. 



Code description.

The codes are split in two folders for their respective question. In both folders it contains an identical 'Huffman.c' which builds the Huffman tree, I have split it in this way so the codes can be accessed and reused separately if you only wished to use a certain bit. In both folders there is a specific makefile to compile the code.

1.1

In 1.1, it pairs the huffman binary tree with '1.1.c' which assigns 0 and 1 values to the tree nodes and works out the total number of bytes.

1.2

In 1.2, it prints out the Huffman binary tree. 
