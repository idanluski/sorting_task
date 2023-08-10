#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void printMenu();
int checkString(char[]);
void printWords(char[][20], int);
void insertStrings(char[][20], int);
int getSize(int, int);
int asciiSum(char[]);
double asciiAvg(char[]);
void sortStringsLexicographic(char[][20], int);
void sortStringsByLength(char[][20], int);
void sortStringsByAsciiAvg(char[][20], int);
void sortStringsByAsciiSum(char[][20], int);
void sortEachString(char[][20], int);
void sortString(char[]);
void sortAllAsOne(char[][20], int);
int checkvalidnum(char[], int);






int main()
{
	int count = 0;
	//int num = 0;
	int flag = 1; //indicate if 1 section already pushed. 
	int input;
	int N;
	char arr[10][20];
	while (1)
	{
		
		
		
		do {
			printMenu();
		    input = getSize(0, 99);
			if (input > 8 || input < 0)
			{
				count++;
				printf("You made %d errors from 5, try again,\n", count);
			}
			else
				break;
		} while (count < 5);
		if (count == 5) {
			printf("5 errors, bye bye.");
			exit(0);
		}
			
		else if (flag)
		{

			if (input == 0) 
			{
				printf("You chose to end the program, bye!!!");
				exit(0);
			}
				
			else if (input == 1)
			{
				printf("Enter new word count,\n");
				flag = 0;
				printf("Please enter a number between 2 and 10:");
				N = getSize(2, 10);
				insertStrings(arr, N);

			}
			else
			{
				printf("There are no words, cannot operate.\n");
				continue;
			}
		}
		else
		{
			switch (input)
			{
			case 0:
				printf("You chose to end the program, bye!!!");
				exit(0);
			case 1:
				insertStrings(arr, N);
				break;
			case 2:
				printWords(arr, N);
				break;
			case 3:
				sortStringsLexicographic(arr, N);
				break;
			case 4:
				sortStringsByLength(arr, N);
				break;
			case 5:
				sortStringsByAsciiSum(arr, N);
				break;
			case 6:
				sortStringsByAsciiAvg(arr, N);
				break;
			case 7:
				sortEachString(arr, N);
				break;
			case 8:
				sortAllAsOne(arr, N);
				break;


			}

		}
	


	}
	return 0;
}
void printMenu() {
	printf("The menu:\n");
	printf("=========\n");
	printf("0. Exit\n");
	printf("1. Insert words\n");
	printf("2. Print words\n");
	printf("3. Sort words lexicographic\n");
	printf("4. Sort words by length\n");
	printf("5. Sort words by ascii sum\n");
	printf("6. Sort words by ascii average\n");
	printf("7. Sort each word by ascii\n");
	printf("8. Sort all words as one\n");
	printf("Please enter a number between 0 and 99:");

}
int checkString(char a[]) {
	/*A function that receives a stringand receives a string from the user, if the received string is
	   correct according to the job's settings.
		It will be copied to the received string and return 1, otherwise it will not be copiedand return 0.
		A string is invalid if it contains a character that is not a letter or more than
		20 characters including the 0.*/

	char arr_input[200];
	gets(arr_input);

	int size, i;
	size = strlen(arr_input);
	//printf("size is: %d\n", size);
	if (size > 19)
	{
		printf("Wrong input, try again:\n");
		return 0;
	}


	for (i = 0; i < size; i++)
	{
		if ((arr_input[i] >= 'a' && arr_input[i] <= 'z') || (arr_input[i] <= 'Z' && arr_input[i] >= 'A'))
		{
			
			continue;

		}
		else
		{
			printf("Wrong input, try again:\n");
			return 0;
		}
	}
	//printf("good word\n");
	strcpy(a, arr_input);
	return 1;
}
void printWords(char a[][20], int arrsize)
{
	int i;
	printf("The words are:\n==============\n");
	for (i = 0; i < arrsize; i++)
	{
		int j = 0;
		int ascii_sum = 0;
		double ascii_avg = 0.0;
		printf("%02d: ", i+1);
		printf("(ascii sum %d, ",asciiSum(a[i]));
		printf("ascii averege %.2lf)", asciiAvg(a[i]));
		printf("%s\n", a[i]);


	}
}
void insertStrings(char arr[][20], int N	)
{
	
	int count = 0;
	while (count < N) 
	{
		printf("pleas enter word #%d:\n",count+1);
		while (1)
		{
			if (checkString(arr[count]))
			{
				count++;
				break;
			}


		}
		
		

	}
		
			


}
int checkvalidnum(char arr[], int size)
{
	int i = 0;
	int flag = 1;
	if (size == 0)
	{
		return 0;
	}
	for (i = 0; ((arr[i] == 32) || (arr[i] == 9) || (arr[i] == 11))&& i<size ;i++);//skip the space and tabs
	for (;((arr[i] != 32) && (arr[i] != 9) && (arr[i] != 11)) && i < size;i++);//skip th chars
	if (arr[i] == '\0') return 1;
	for (;i < size;i++)
	{
		printf("cheeeecckk11");
		
		if ((arr[i] != 32) && (arr[i] != 9) && (arr[i] != 11)) return 0;
		
	}
	return 1;

			

}
int getSize(int Min, int Max)
{    
	char arr[200];
	
	

	while (1)
	{
		int flag = 0, count = 1;
		
		gets(arr);
		if (checkvalidnum(arr, strlen(arr)))
		{
			int i,size=strlen(arr),number =0;
			for (i = size-1; ((arr[i] == 32) || (arr[i] == 9) || (arr[i] == 11)) && i >= 0;i--);
			for (;((arr[i] != 32) && (arr[i] != 9) && (arr[i] != 11)) && i>=0; --i)
			{
				if (((arr[i] < '0') ||  (arr[i]>'9' )))
				{
					flag = 1;
					break;
				}
				number += (int)(arr[i] - '0') * count;
				count = count * 10;	

			}
			if (flag)
			{
				printf("Please enter a number between %d and %d:", Min, Max);
				continue;
			}
			if ((Min <= number && Max >= number))
			{
				return number;
			}
		
			

		}
		printf("Please enter a number between %d and %d:", Min, Max);
			


	}
	
}
int asciiSum(char a[])
{
	int i,num = 0;
	
	for (i = 0; i < strlen(a); i++) 
	{
		num += a[i];
	}
	return num;
	

}
double asciiAvg(char a[])
{
	double num = (double)asciiSum(a);
	return num/strlen(a) ;

}
void sortStringsLexicographic(char a[][20], int N)
{
	char temp[20];
	int i;
	int flag = 1;
	for (i = N - 1;(i > 0) && flag;i--)
	{
		int j;
		for (j = flag = 0; j < i; j++)

		{
			if (strcmp(a[j],a[j+1])>0)
			{
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
				flag = 1;

			}
		}
	}

}
void sortStringsByLength(char a[][20], int N)
{
	char temp[20];
	int i;
	int flag = 1;
	for (i = N - 1;(i > 0) && flag;i--)
	{
		int j;
		for (j = flag = 0; j < i; j++)

		{
			if (strlen(a[j]) > strlen(a[j + 1]))
			{
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
				flag = 1;

			}
		}

	}
}
void sortStringsByAsciiAvg(char a[][20], int N)
{
	char temp[20];
	int i;
	int flag = 1;
	for (i = N - 1;(i > 0) && flag;i--)
	{
		int j;
		for (j = flag = 0; j < i; j++)

		{
			if (asciiAvg(a[j]) > asciiAvg(a[j + 1]))
			{
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
				flag = 1;

			}
		}
	}
}
void sortStringsByAsciiSum(char a[][20], int N)
{
	char temp[20];
	int i;
	int flag = 1;
	for (i = N-1;(i > 0)&&flag;i--)
	{
		int j;
		for (j = flag = 0; j < i; j++)

		{
			if (asciiSum(a[j]) > asciiSum(a[j + 1]))
			{
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
				flag = 1;

			}
		}
		
	}

}
void sortEachString(char a[][20], int N)
{
	char temp;
	int i;
	for (i = 0;i < N;++i)
	{
		sortString(a[i]);
		
	}
}
void sortString(char a[])
{
	char chTemp;
	int i, j, len;
	len = strlen(a);
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < (len - 1); j++)
		{
			if (a[j] > a[j + 1])
			{
				chTemp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = chTemp;
			}
		}
	}
	
}
void sortAllAsOne(char a[][20], int N)
{
	
	int i;
	char temp[200];
	strcpy(temp, a[0]);
	for (i = 1; i < N; i++)
		strcat(temp, a[i]);
		
	sortString(temp);
	i = 0;
	int p=0;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j=0; j < strlen(a[i]); j++)
		{
			a[i][j] = temp[p];
			p++;
		}
	}
}
	


	


