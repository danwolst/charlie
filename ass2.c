#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int Inputcheck(int x)  //Checks the input is within the range allowed
{
	if (x>0&&x < 1000) {
	return x;}
	else
	{printf("Error - Please enter values within the range of 0 to 1000.\n");
	exit(1);
	};
}


int main() //Main body of the program
{
	int z = 0;
	do
	{
		//Defines variables required in the main function.
		float ans;
		char expression[128];
		int a,b,c;
		char opa,opb;
		
		
		
		//Input of data and seperation into different data groups.
		printf ("Enter an expression:\n ");
		fgets(expression, sizeof expression, stdin);
		
		sscanf(expression,"%d %c %d %c %d", &a, &opa, &b, &opb, &c);
		
		
		
		//Checks the validity of the input values (Are they within the range supported?)
		Inputcheck(a);
		Inputcheck(b);
		Inputcheck(c);
	
	
	
		//Checks the operators and then performs the calculations with the correct order of operation.
		switch(opa)
		{
			case'+':{
				switch(opb)
				{
					case '/':
						{if (c==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = a + ((float)b / (float)c); break;}}
					case '*':
						{ans = a + (b * c); break;}
					case '+':
						{ans = a + b + c;   break;}
					case '-':
						{ans = (a + b) - c; break;}
					default:{printf("Please only use the specified operators or format.\n");
					exit(1);}
			}break;}
			case'-':{			
				switch(opb)
				{
					case '/':
						{if (c==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = a - ((float)b / (float)c); break;}}
					case '*':
						{ans = a - (b * c); break;}
					case '+':
						{ans = a - (b + c); break;}
					case '-':
						{ans = a - b - c ;  break;}
					default:{printf("Please only use the specified operators or format.\n");
					exit(1);}
			}break;}
			case'*':{
				switch(opb)
				{
					case '/':
						{if (c==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = a * ((float)b / (float)c); break;}}
					case '*':
						{ans = a * b * c;   break;}
					case '+':
						{ans = (a * b) + c; break;}
					case '-':
						{ans = (a * b) - c; break;}
					default:{printf("Please only use the specified operators or format.\n");
					exit(1);}
			}break;}
			case'/':{
				switch(opb)
				{
					case '/':
						{if (c==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {if (b==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = ((float)a / (float)b) / (float)c; break;}}}
					case '*':
						{if (b==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = ((float)a / (float)b) * c; break;}}
					case '+':
						{if (b==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = ((float)a / (float)b) + c; break;}}
					case '-':
						{if (b==0){
						printf("Unable to divide by 0.\n");
						exit(2);}
						else {ans = ((float)a / (float)b) - c; break;}}
					default:{printf("Please only use the specified operators or format.\n");
					exit(1);}
			}break;}
			default:{printf("Please only use the specified operators or format.\n");
			exit(1);
		}}
		
		
		//Prints the output of the calculation and prompts the user to interact with the exit procedure.
		printf ("\nThe result is %f\n",ans); 
		printf ("Enter '~' into the prompt to close the program.\n");
		printf ("Do you wish to enter a new expression?\n");
			
			
			
		//Terminates the loop.
		char cont;
		cont=getchar();
		if(cont=='~')
		{
			break;
		}
		else;
	}while(z == 0);
	return 0;
}
