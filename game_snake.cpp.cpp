#include <iostream>
#include <conio.h> // для отслевании нажатии
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20; // width of square
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; // тело змеи 
int nTail; // колво частей тел у змеи
enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() { // при старте что настроить все параметры
	gameOver = false;

	dir = STOP;
	x = width / 2 - 1; // - 1 потому что в циклах для заполнения верхней грани мы написали <= 
	y = height / 2 - 1;// начальная позиция змеи

	fruitX = rand() % width; // случайное местонахождение фруктов
	fruitY = rand() % height;
	score = 0;
}

void Draw() {
	system("cls"); // очищает терминал когда мы каждый раз вызываем Draw(), то есть карта рисуется каждый раз по новому 
	
	for (int i = 0; i <= width;i++) {// upper line
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) { // j координат по Х
			if (j == 0 || j == width-1) {
				cout << "|";
			}
			if (i == y && j == x) {
				cout << "0";
			}
			else if (i == fruitY && j == fruitX) {
				cout << "F";
			}
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if(!print) 
					cout << " ";;
			}
				
		}
		cout << endl;
		Sleep(1);
	}

	for (int i = 0; i <= width; i++) {// down line
		cout << "-";
	}
	cout << endl;
	cout <<"Score: " << score<<endl;
}

void Input() { // нажатия от пользователя 
	if (_kbhit()) { // если он нажал на какую то кнопку
		switch (_getch()) // отслеживания за нажатием
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() { // логика игры
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;// 2 элемент
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) { //цикл работает до длины змеи
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir) // движение 
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	//if (x > width || x < 0 || y > height || y<0) { // каждая итерация цикла движения двигает змею, что соответсвенно ось x y удлиняются
	//	gameOver = true;
	//}
	if (x >= width - 1) // -1 потому что сверху в циклах мы что то доавбляли к ширине, и поэтому змейка выходит на один элемент за границу
		x = 0; // с начала по оси Х
	else if (x < 0)
		x = width - 2; // с права карты выходим если х меньше 0 по оси Х
	                   // -2 потому что сверху в циклах мы что то доавбляли к ширине, и поэтому змейка выходит на один элемент за границу
	if (y >= height)
		y = 0;
	else if (y < 0)
		y = height - 1;
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) { // если мы съели свой хвост
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width; // случайное местонахождение фруктов
		fruitY = rand() % height; // update place of the fruit
		nTail++;
	}
}

int main() {
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
	}

	return 0;
}