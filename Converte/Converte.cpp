// Converte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int convertebinario(int dec);

int 
main(int arg, char **args)
{
	int x = 0;
	int y = 0;
	char *str_decimais;
	char decimal[2] = {0,0};

	printf("Arg: %d \n",arg);
	printf("Args: %s\n",args[1]);
	//args[1] = "0238000000410010";
	str_decimais = args[1];
	x = _mbstrlen(str_decimais) / 2;
	do
	{
		decimal[0] = str_decimais[y];
		y++;
		decimal[1] = str_decimais[y];

		convertebinario(atoi(decimal));
		y++;
		x--;
	} while (x > 0);
	
	return 0;
}

int 
convertebinario(int dec)
{
	int i, q[80], r[80]; 
	i = 0;
	if (dec == 0) {
		printf("00000000");
		return 0;
	}
	while (dec != 1) {
		q[i] = dec / 2;    
		r[i] = dec % 2;  
		dec = q[i]; 
		i++;
	}
	if (i < 7) {		
		for (int x = i; x < 7; x++) {
			printf("0");
		}
	}
	i--;
	while (i >= 0) {
		if (q[i] == 1) {
			printf("1%d", r[i]);
		}
		else {
			printf("%d", r[i]);
		}
		i--;
	}
	return(0);
}

