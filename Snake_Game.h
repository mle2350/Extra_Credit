#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;


class SnakeGame {
private:
	enum Direction {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	Direction SnakeDirection;
	int SnakeBodyCount;
	bool GameOver;
	bool BodyPrintFlag;
	const int Width;
	const int Height;
	int SnakeHeadX, SnakeHeadY, FruitX, FruitY;
	int SnakeX[100], SnakeY[100];
	static void DisplayMainMenu();
	static void DisplayGameOver();
	static void DisplayInstructions();
	static void DisplayCredits();
	void ControllerInput();
	void SetupGame();
	void PrintStage();
	void PlayStage();
	void PlayGame();
public:
	SnakeGame();
	void StartGame();
};

#endif // SNAKE_GAME_H
