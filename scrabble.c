#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//Array of points(note: points[26] = 0 ):-
int POINTS[27] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10,0};

int count_score(string word);

int main()
{
		while(true)
		{
		//prompt users for words
		string word1 = get_string("Player1: ");
		string word2 = get_string("Player2: ");
		//score words
		int score1 = count_score(word1);
		int score2 = count_score(word2);
		//the Winner:-
		if (score1 > score2)
		{
			printf("Player1 Wins!\n");
		}
		else if (score2 > score1)
		{
			printf("Player2 Wins!\n");
		}
		else if (score1 == score2)
		{
			printf("Tie!\n");
		}
		}
}

int count_score(string word)
{
	//A loop which converts uppercase letters(if any) to lowercase
	int i;
	for (i = 0; i < strlen(word); i++)
	{
		word[i] = tolower(word[i]);
	}
	//score computation:-
	int score = 0;
	int j;
	int x = 0;
	for (i = 0; i < strlen(word); i++)
	{
		//this condition will assign 0 score to all characters except alphabets
		if (word[i] < 'a' || word[i]>'z')
		{
			word[i] = '?';
		//value of points[26] = 0
			x = 26;
		}
		//this loop will provide the xth element of the array "points"
		for (j = 'a'; j != word[i] && word[i]!='?';  j++)
		{
			x++;
		}
		//points[x] is the score of the character word[i]
		//sum is the total score of the word written by the player
		score = score + POINTS[x];
		x = 0;
	}
	return score;
}
