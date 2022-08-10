#include "cipher.h"


char encrypt(char ch, char* key_arr){
  ch = toupper(ch);
  return key_arr[ch%65];
}

char decrypt(char ch, char* key_arr, char* alpha){
  int index, i;
	ch = toupper(ch);
  index = targetFound(key_arr, 26, ch);

	return alpha[index];
}

int	targetFound(char charArr[],	int	num,	char target){
  int i;
  for(i=0; i<num; i++)
    if(charArr[i] == target)
      return i;
  return 0;
}

void processFile(FILE *fin, FILE *fout, char* key_arr, char* alpha, int choice){
  char ch;
	while ( fscanf(fin, "%c", &ch) != EOF ){
    if(isalpha(ch))
      if(choice == 1)
		    fprintf(fout, "%c", encrypt(ch, key_arr));
      else
        fprintf(fout, "%c", decrypt(ch, key_arr, alpha));
	  else
      fprintf(fout, "%c", ch);
    }
}

void removeDup(char* input){
  int i,j,k;
  for(i = 0;input[i] != '\0'; i++)
    for(j = i+1; input[j] != '\0'; j++)
      if(input[j] == input[i]){
        i--; //check for more than 2 of the same character
        for(k = j; input[k] != '\0'; k++)
          input[k] = input[k+1];
      }
}

char* initEncryptArr(char* key, char* alpha){
  int i, len;
  char* encryptArr;
  removeDup(key);
  len = strlen(key);
  encryptArr = (char*)malloc((len+26)*sizeof(int));

  for(i = 0; key[i] != '\0'; i++)
    encryptArr[i] = toupper(key[i]);
  for(i = len; i < 26 + len; i++)
    encryptArr[i] = alpha[i-len];
  removeDup(encryptArr);

  return encryptArr;
}

char* genAlpha(int reversed){
  int i;
  char* alpha = (char*)malloc(26*sizeof(char));
  if(reversed == 0){
    for(i = 0; i < 26; i++)
      alpha[i] = 65 + i; //ascii for capitol letters starts at 65
  }else{
    for(i = 0; i < 26; i++)
      alpha[i] = 90-i; //ends at 90
  }
  return alpha;
}
