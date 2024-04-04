#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  {
	char character;
	int count;
}Tuple;

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
	//size_t buffer_size = 24;
	size_t capacity = 1024;
	//char *buffer = malloc(sizeof(char)*buffer_size);
	char *str = malloc(capacity*sizeof(char)+1);
	size_t chars_size = 0;
	//int length = 0;
	int total_length= 0;
	// adding all files to one string
	for(int i=1; i< argc; i++){
		FILE *fp = fopen(argv[i], "r");
		if(fp == NULL){
			printf("wzip: cannot open file\n");
		}
		while(fgets(str + total_length, capacity - total_length, fp)){
			total_length += strlen(str + total_length);

			if(total_length + 1 >= capacity){
				capacity *=2;
				if((str = realloc(str, capacity)) == NULL){
					printf("little memoery\n");
					exit(1);
				}
			}
			//strcat(str, buffer);
		}
		fclose(fp);
	}
	size_t len = 0;
	for(int i=0; str[i]; i++){
		len++;
	}
	int count;
	char c;
 	for(size_t i=0; i<len; i++){
		count = 1;
		c = str[i];
 		while(i+1 < len && str[i] == str[i+1]){
			count++;
 			i++;
 		}
		//printing the output
 		fwrite(&count, sizeof(int), 1, stdout);
 		fwrite(&c, sizeof(char), 1, stdout);
 	}
	return 0;
}

