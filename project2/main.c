#include "cipher.h"


int main(int argc, char *argv[]){
  FILE *fin, *fout;
  char ch;
  char* choice;
  char* alpha;
  char* key;
  char* key_arr;
  int i;

  if (argc != 5){
    printf("Invalid number of arguments\n");
    printf("Format example:  ./cipher e feather data.txt data.out");
		exit(1);
	}

  fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
  if (fin ==  NULL) {
		printf("%s could not be opened\n", argv[3]);
		exit(2);
	}
  if (fout == NULL) {
		printf("%s could not be opened\n", argv[4]);
		exit(2);
	}

  key = argv[2];
  for(i = 0; i < strlen(key); i++)
    if(!isalpha(key[i])){
      printf("Key can only contain letters\n");
      exit(3);
    }

  if (argv[1][0] == 'e'){
    alpha = genAlpha(1);
    key_arr = initEncryptArr(key, alpha);

		processFile(fin, fout, key_arr, alpha, 1);
	}else if (argv[1][0] == 'd'){
    alpha = genAlpha(1);
    key_arr = initEncryptArr(key, alpha);

    alpha = genAlpha(0);
		processFile(fin, fout, key_arr, alpha, 2);
	}else{
    printf("Invalid argument\n");
    printf("e for encrypt, d for decrypt\n");
    exit(4);
  }

  fclose(fin);
	fclose(fout);

  return 0;
}
