#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>       
#include <sys/mman.h>
#include <fcntl.h>


off_t fsize(const char *filename){
	struct stat st;
	if (stat(filename, &st)==0)       
		return st.st_size;
	return -1;
}

int main(int argc, char *argv[]) {
	FILE *fp;
	char* filename = argv[1];
	long tam, i;
	char* mem;
	
	//Open the file
	fp = fopen(filename, "r+");
	if (fp == NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	//Get the size of the file
	tam = fsize(filename);
	printf("FITX TAM: %ld \n", tam);
	//Map the file to memory
	mem=mmap(NULL, tam, PROT_WRITE | PROT_READ,MAP_SHARED, fileno(fp), 0);
	   if (mem == MAP_FAILED) perror("mmap");
	//write to the file
	while (i<tam){
		mem[i]='0';
		i++;
	}
	//Ensure that the file updates now
	msync(mem, tam, MS_SYNC);
	//Unmap the file from memory and close it
	munmap(mem, tam);
	printf("Amaitu");
	fclose(fp);
	return 0;
}
