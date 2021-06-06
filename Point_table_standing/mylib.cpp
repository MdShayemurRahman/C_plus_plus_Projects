#include "mylib.h"

void add_score(game records[])
{
	/// initially team point, win, lose, draw 0..
	for (int i = 0; i < TOTALTEAM; i++)
	{
		records[i].point = 0; records[i].win = 0; records[i].lose = 0; records[i].draw = 0; records[i].teamScore = 0;
	}
	for (int i = 0, j = i + 1, k = 1; i < TOTALTEAM, j < TOTALTEAM, k <= TOTALTEAM / 2; i++, j++, k++)
	{
		cout << "\n# MATCH - " << k << "\n";
		cout << "Home team: ";
		getline(cin.ignore(), records[i].teamName);
		cout << "Away team: ";
		getline(cin, records[j].teamName);
		cout << "Home teamScore: ";
		cin >> records[i].teamScore;
		cout << "Away teamScore: ";
		cin >> records[j].teamScore;

		if (records[i].teamScore > records[j].teamScore)
		{
			// winning team will be added 3 points.
			records[i].point += 3; records[i].win++; records[j].lose++;
			cout << records[i].teamName << " won " << records[i].teamScore << "-" << records[j].teamScore << "! Score added";
		}
		else if (records[i].teamScore < records[j].teamScore)
		{
			// winning team will be added 3 points.
			records[j].point += 3; records[j].win++; records[i].lose++;
			cout << records[j].teamName << " won " << records[j].teamScore << "-" << records[i].teamScore << "! Score added";
		}
		else
		{
			// if draw both team gains 1 point..
			records[i].point++; records[j].point++; records[i].draw++; records[j].draw++;
			cout << "match drown by " << records[j].teamScore << "-" << records[i].teamScore << "!\n";
		}
		i++, j++; // incerement..
		cout << "\n";
	}
	cout << "\n";
}
void print_standing(game records[])
{
	/// Sorting by team points in  ascending order..
	int temp1, temp2, temp3, temp5;
	string temp4;
	for (int i = 0; i < TOTALTEAM; i++)
	{
		for (int j = i; j < TOTALTEAM; j++)
		{
			if (records[i].point < records[j].point) ///team having more points will go top..
			{
				temp1 = records[j].point;
				records[j].point = records[i].point;
				records[i].point = temp1;

				temp2 = records[j].win;
				records[j].win = records[i].win;
				records[i].win = temp2;

				temp3 = records[j].draw;
				records[j].draw = records[i].draw;
				records[i].draw = temp3;

				temp4 = records[j].teamName;
				records[j].teamName = records[i].teamName;
				records[i].teamName = temp4;

				temp5 = records[j].lose;
				records[j].lose = records[i].lose;
				records[i].lose = temp5;
			}
		}
	}

	///point table standing..
	cout << "\nTeam  \tWon\tLost\tDraw\tPoints\n";
	cout << "---------------------------------------\n";
	for (int i = 0; i < TOTALTEAM; i++)
	{
		cout << records[i].teamName << "\t" << records[i].win << "\t " << records[i].lose << "\t " << records[i].draw
			<< "\t " << records[i].point << "\n";
	}
	cout << "\n";
}

