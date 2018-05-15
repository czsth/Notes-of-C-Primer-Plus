#include <stdio.h>
#include <stdlib.h>		//defined prototype of exit()
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *in, *out;

	//check cmd-line argument
	if(argc < 2){
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(1);
	}

	//open in file
	if((in = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Fail to open %s\n", argv[1]);
		exit(2);
	}

	char name[40];		//output file name
	strcpy(name, argv[1]);
	strcat(name, ".rdu");
	if((out = fopen(name, "w")) == NULL){
		fprintf(stderr, "Fail to creat output file.\n");
		exit(3);
	}

	//write to output
	int ch, count = 0;
	while((ch = getc(in)) != EOF){
		if(count++ % 3 == 0)		//reduce file size to 1/3
			putc(ch, out);
	}

	//close file
	if(fclose(in) != 0 || fclose(out) != 0){	//the mark of unsuccess must be 0, while success's may not be EOF
		fprintf(stderr, "Error in closing files.\n");
	}

	return 0;
}
