#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[]) {
	assert(argc == 3);
	FILE *fpin, *fpout;
	assert((fpin = fopen(argv[1], "r")) != NULL);
	assert((fpout = fopen(argv[2], "w")) != NULL);
	fprintf(fpout, "%s\n", "#include <stdio.h>");
	fprintf(fpout, "%s\n", "static int data[30000] = {};");
	fprintf(fpout, "%s\n", "int *ptr = data;");
	fprintf(fpout, "%s\n", "int main(void){");
	int c = fgetc(fpin);
	while (c != EOF) {
		switch (c) {
			case '>':{
				fprintf(fpout, "%s\n", "ptr++;");
				break;
			}
			case '<':{
				fprintf(fpout, "%s\n", "ptr--;");
				break;
			}
			case '+':{
				fprintf(fpout, "%s\n", "(*ptr)++;");
				break;
			}
			case '-':{
				fprintf(fpout, "%s\n", "(*ptr)--;");
				break;
			}
			case '.':{
				fprintf(fpout, "%s\n", "putchar(*ptr);");
				break;
			}
			case ',':{
				fprintf(fpout, "%s\n", "*ptr = getchar();");
				break;
			}
			case '[':{
				fprintf(fpout, "%s\n", "while(*ptr){");
				break;
			}
			case ']':{
				fprintf(fpout, "%s\n", "}");
				break;
			}
			default:{
				break;
			}
		}
		c = fgetc(fpin);
	}
	fprintf(fpout, "%s\n", "return 0;\n}");
	return 0;
}
