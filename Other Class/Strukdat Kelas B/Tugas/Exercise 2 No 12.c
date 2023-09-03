#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char nrp[101];
	int a, b, c, d, e, f;	
}students;

char *read_file(char *filename)
{
  	FILE *file;
  	file = fopen(filename, "r");
  	if (file == NULL) return NULL;
  
  	fseek(file, 0, SEEK_END); 
  	int length = ftell(file);
  	fseek(file, 0, SEEK_SET);
  
  	char *string = malloc(sizeof(char) * (length+1));
  
 	char c;

  	int i = 0;

  	while ( (c = fgetc(file)) != EOF)
  	{
    	string[i] = c;
    	i++;
  	}	
  	string[i] = '\0';
  
  	fclose(file);
  	return string;
}

int main()
{
	FILE *course1 = fopen("CS20A.txt", "a+");
	FILE *course2 = fopen("CS21A.txt", "a+");
	FILE *course3 = fopen("CS29A.txt", "a+");
	FILE *course4 = fopen("CS30A.txt", "a+");
	FILE *course5 = fopen("CS35A.txt", "a+");
	FILE *course6 = fopen("CS36A.txt", "a+");
	students temp;
	
	for(int i = 0; ; i++)
	{	
		scanf("%s", temp.nrp);
		if(strcmp(temp.nrp, "END") == 0) break;
		scanf("%d %d %d %d %d %d", &temp.a, &temp.b, &temp.c, &temp.d, &temp.e, &temp.f);
		
		if(temp.a) fprintf(course1, "%s\n", temp.nrp);
		if(temp.b) fprintf(course2, "%s\n", temp.nrp);
		if(temp.c) fprintf(course3, "%s\n", temp.nrp);
		if(temp.d) fprintf(course4, "%s\n", temp.nrp);
		if(temp.e) fprintf(course5, "%s\n", temp.nrp);
		if(temp.f) fprintf(course6, "%s\n", temp.nrp);
	}
	
	fclose(course1);
	fclose(course2);
	fclose(course3);
	fclose(course4);
	fclose(course5);
	fclose(course6);
	
	char *read1 = read_file("CS20A.txt");
  	if (read1 == NULL)
  	{
    	printf("Error reading file.\n");
    	return 1;
  	}
  	printf("Students Enrolled in CS20A :\n%s\n", read1);
  	free(read1);
	
	char *read2 = read_file("CS21A.txt");
  	if (read2 == NULL)
  	{
    	printf("Error reading file.\n");
    	return 1;
  	}
  	printf("Students Enrolled in CS21A :\n%s\n", read2);
  	free(read2);
  	
  	char *read3 = read_file("CS29A.txt");
  	if (read3 == NULL)
  	{
    	printf("Error reading file.\n");
    	return 1;
  	}
  	printf("Students Enrolled in CS29A :\n%s\n", read3);
  	free(read3);
	
	char *read4 = read_file("CS30A.txt");
  	if (read4 == NULL)
  	{
    	printf("Error reading file.\n");
    	return 1;
  	}
  	printf("Students Enrolled in CS30A :\n%s\n", read4);
  	free(read4);
	
	char *read5 = read_file("CS35A.txt");
  	if (read5 == NULL)
  	{
    	printf("Error reading file.\n");
    	return 1;
  	}
  	printf("Students Enrolled in CS30A :\n%s\n", read5);
  	free(read5);
  	
  	char *read6 = read_file("CS36A.txt");
  	if (read6 == NULL)
  	{
    	printf("Error reading file.\n");
    	return 1;
  	}
  	printf("Students Enrolled in CS36A :\n%s\n", read6);
  	free(read6);
  	
	return 0;
}