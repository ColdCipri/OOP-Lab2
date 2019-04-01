#pragma once
#include <stdio.h>
#include <string.h>

typedef struct
{
	int arr[100];
	int len;
} Vector;


//input nr1, nr2;
//output greatesc common divisor of the numbers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		gcd(b, a%b);
	}
}

//input nr1, nr2;
//output	1 if nr1 and nr2 are relatively prime
//			0 if nr1 and nr2 are not relatively prime
int isRelativelyPrime(int number1, int number2) {
	if (gcd(number1, number2) == 1)
		return 1;
	else
		return 0;
}

/*
Reads the vector.
input - none
output- vector
*/
Vector read() {
	int i = 0, nr = -1;
	Vector vect;
	vect.len = 0;
	while (nr != 0) {
		printf("vect[%d] = ", i);
		scanf("%d", &nr);
		if (nr == 0) {
			vect.arr[i] = nr;
			break;
		}
		if (nr != 0) {
			vect.arr[i] = nr;
			vect.len++;
			i++;
		}
		
	}
	return vect;
}

int subjARead() {
	int number = 0;
	printf("Input number: ");
	scanf("%d", &number);
	while (number == 0) {
		printf("Number can not be 0!\n");
		printf("Input number: ");
		scanf("%d", &number);
	}
	return number;
}

void subjAPrint(int number) {
	printf("%d, ", number);
}

void subjAFunction() {
	int number = subjARead();
	int counter = 0;
	while (counter < number) {
		if (isRelativelyPrime(counter, number)) {
			subjAPrint(counter);
		}
		counter += 1;
	}
}


void printVector(Vector v) {
	for (int i = 0; i <= v.len; i++) {
		printf("%d ", v.arr[i]);
	}
}

void subjBFunction() {
	Vector v = read();
	int maxSoFar = -999, maxEndingHere = 0, i = 0, startPoint = 0, endPoint = 0, j = 0;
	for (i = 0; i <= v.len; i++)
	{
		maxEndingHere += v.arr[i];
		if (maxSoFar < maxEndingHere) {
			maxSoFar = maxEndingHere;
			endPoint = i;
		}
		if (maxEndingHere < 0) {
			maxEndingHere = 0;
			startPoint = i + 1;
		}
	}
	Vector v1;
	v1.len = 0;
	i = startPoint;
	for (i; i <= endPoint; i++) {
		v1.arr[j] = v.arr[i];
		j++;
		v1.len++;
	}
	v1.len--;

	printVector(v1);
}

void subjCFunction() {
	Vector v = read();
	int i = 0, startPoint = 0, lung = 0, lungMax = 0, j = 0;
	for (i = 0; i <= v.len; i++)
	{
		if (isRelativelyPrime(v.arr[i], v.arr[i + 1]))
			lung++;
		else
		{
			if (lung >= lungMax)
			{
				lungMax = lung;
				startPoint = i - lungMax + 1;
			}
			lung = 1;
		}
	}
	Vector v1;
	v1.len = 0;
	i = startPoint;
	for (i; i < lungMax + startPoint; i++) {
		v1.arr[j] = v.arr[i];
		j++;
		v1.len++;
	}
	v1.len--;

	printVector(v1);
}


/*
Prints the menu
input - none
output- menu
*/
void menu() {
	printf("\n0.\tExit\n");
	printf("1.\tDetermine all the numbers smaller than a given natural and non-null number n and that are relatively prime to n\n");
	printf("2.\tGiven a vector of numbers, find the longest contiguous subsequence with the maximum sum\n");
	printf("3.\tGiven a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.\n");
}

/*
Reads the command:
input - none
output- command
*/
int readInput() {
	int input = 0;
	printf("Waiting for input... (0/1/2/3)\n");
	scanf("%d", &input);
	return input;
}

//input - none
//output - the main function

void show() {
	int whiletrue = 1, input = 0, nr1 = 0, nr2 = 0;;
	while (whiletrue) {
		menu();
		input = readInput();
		switch (input) 
		{
			case 0:
				printf("App is exiting...\n");
				whiletrue = 0;
				break;
			case 1:
				subjAFunction();
				break;
			case 2:
				subjBFunction();
				break; 
			case 3:
				subjCFunction();
				break;
			default:
				printf("Invalid input! Expected 0/1/2/3 !\n");
		}
	}
}