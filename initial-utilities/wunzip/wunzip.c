#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if (argc < 2) {
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}
	int nb;
	char c;
	//TODO: add multiple files to one big string
	for(int k = 1; k < argc; k++){
	FILE *fp = fopen(argv[k], "r");
	if(fp == NULL){
		exit(1);
	}
	while( fread(&nb, sizeof(nb), 1, fp) && fread(&c, sizeof(c), 1, fp)){
		for(int i=0; i < nb; i++){
			printf("%c", c);
		}
	}
	}

	return 0;
}
