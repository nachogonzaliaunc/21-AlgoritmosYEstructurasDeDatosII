unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size);
/*  
 * calculate array length and read the values inside the file
*/


void sort_letters(unsigned int indexes[], char letters[], char sorted[], unsigned int length);
/* 
 * sort the letters to make the phrase
*/


void dump(char a[], unsigned int length);
/*
 * dump the phrase
*/