#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find(char c, char *arr, int size){
	for (size_t i = 0; i < size; i++) {
		if(arr[i] == c) return 1;
	}
	return 0;
}

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}
	size_t buffer_size = 24;
	size_t capacity = 1024;
	char *buffer = malloc(sizeof(char)*buffer_size);
	char *str = malloc(capacity*sizeof(char));
	int counter[128] = {0,}; // map ascii code -> nb of occurences
	char chars[128] = {0,};
	int chars_size = 0;
	int length = 0;
	int total_length= 0;
	for(int i=1; i< argc; i++){
		FILE *fp = fopen(argv[i], "r");
		if(fp == NULL){
			printf("wzip: cannot open file\n");
			exit(1);
		}
		while(fgets(str+total_length, capacity - length, fp)){
			total_length += strlen(str + total_length);
			
			if(total_length + 1 >= capacity){
				capacity *=2;
				if((str = realloc(str, capacity)) == NULL){
					printf("little memoery");
					return -1;
				}
			}
			strcat(str, buffer);
		}
		fclose(fp);
	}
	for(int i=0; str[i]; i++){
		chars[chars_size++] = str[i];
		counter[(int)str[i]] = 1;
		while(str[i] == str[i+1]){
			counter[(int)str[i]]++;
			i++;
		}
	}
	for(int i = 0; i < chars_size; i++){
		fwrite(&counter[(int)chars[i]], sizeof(int), 1, stdout);
		fwrite(&chars[i], sizeof(char), 1, stdout);
	}
	return 0;
}

