#pragma once
#include<iostream>
#include<string>
using namespace std;

#define TOTALTEAM 6 

struct game
{
	string teamName;
	int teamScore;
	int point;
	int win;
	int lose;
	int draw;
};

//prototypes
void add_score(game records[]);
void print_standing(game records[]);