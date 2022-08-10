#ifndef CIPHER_H
#define CIPHER_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char encrypt(char ch, char* key_arr);
char decrypt(char ch, char* key_arr, char* alpha);
void processFile(FILE* fin, FILE* fout, char* key_arr, char* alpha, int choice);
void removeDup(char* input);
char* initEncryptArr(char* key_arr, char* alpha);
int	targetFound(char*	charArr,	int	num,	char	target);
char* genAlpha(int reversed);

#endif //CIPHER_H
