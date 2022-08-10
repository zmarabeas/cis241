#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//len	=	strlen	(str); //	if	str	=	“FORKAB”,	then	len	=	6
// int	*	key_arr; //	declare	an	int	pointer
// key_arr	=	(int	*)	malloc	(len	*	sizeof(int));
//	allocate	space	for	an	int	array	of	len	elements

char encrypt(char ch, int k);

int main(int argc, char* argv[]){
	int choice, len;
//	int key;
	char* key;
	int	*	key_arr;
	char ch;
	FILE *fin, *fout;

	if (argc != 5){
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}

	choice = atoi(argv[1]);
	//key = atoi(argv[2]);
	key = argv[2];
	len	=	strlen	(key);
	key_arr	=	(int	*)	malloc	(len	*	sizeof(int));


	if (choice == 2){
		for(int i=0;i<len;i++){
			key_arr[i] = -toupper(key[i])+64; //convert key to 1-26
		}
	}else{
		for(int i=0;i<len;i++){
			key_arr[i] = toupper(key[i])-64;
		}
	}

	// for(int i=0;i<len;i++){
	// 	printf("%d\n",key_arr[i]);
	// }
  fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");

  if (fin ==  NULL || fout == NULL) {
		printf("File could not be opened\n");
		exit(1);
	}

	int n = 0;
	while ( fscanf(fin, "%c", &ch) != EOF ){
		fprintf(fout, "%c", encrypt(ch, key_arr[n%len]));
		n++;
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt(char ch, int k){
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';

	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';

	return ch;
}
