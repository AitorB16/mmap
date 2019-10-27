#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

//This function returns the size of the file
off_t fsize(const char *filename){
	struct stat st;
	if (stat(filename, &st)==0)       
		return st.st_size;
	return -1;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	char* filename = argv[1];
	char* list;
	long i=0;
	long tam;
	//Open the file
	fp = fopen(filename, "r+");
	if (fp == NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	
	//Get the size of the file
	tam =fsize(filename);
	printf("FITX TAM: %ld \n", tam);
	
	//Alocate memory for the data-structure
	list=malloc(tam);
	
	//Read the file into the data-structure and replace 
	//all the characters with '0'
	fread(list,sizeof(char),tam,fp);
	while (i<tam){
		list[i]='0';
		i++;
	}
	
	//Point to the start of the file and write there
	//the modified data-structure
	rewind(fp);
	fwrite(list, sizeof(char), tam, fp);
	
	printf("Amaitu");
	fclose(fp);
	free(list);

	return 0;
}
