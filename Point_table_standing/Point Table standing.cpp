#include<iostream>
#include "mylib.h"
#include<string>
using namespace std;

int main()
{
	struct game G[50];
	int	input;
	do {
		cout << "Input function (1= add scores, 2= print standings, 3= exit program): ";
		cin >> input;
		switch (input)
		{
		case 1: add_score(G);
			break;
		case 2: print_standing(G);
			break;
		case 3: break;
		}
	} while (input != 3);
}
