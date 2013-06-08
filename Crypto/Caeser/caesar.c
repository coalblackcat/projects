#include <stdio.h>

void doCaesar(char* plaintext, int offset);

int main()
{
	int caesarOffset = -5;
	char plaintext[100] = "Ymj%vznhp%gwt|s%kt}%ozruji%t{jw%ymj%q~%itl3";

	doCaesar(&plaintext[0], caesarOffset);

	printf("\n");

	for(int i=0; i<58; i++)
	{
		printf("%c\n",'A' + i);
	}
}

void doCaesar(char* plaintext, int offset)
{
	//for each character in the string
	for(int i=0; i<100; i++)
	{
		if(*plaintext + offset > 57)
		{
			stayWithinBounds(
		//write its value - offset by the caesar number chosen
		printf("%c",*(plaintext+i) + offset);
	}
}
