#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"

enum Levels
{
	LVL1 = 1,
	LVL2,
	LVL3,
	LVL4,
	LVL5,
};


class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	window* ExitWindow;
	Levels* lvl = nullptr;
	Levels currentLevel = LVL1;
	int NumberOfSteps = 5;
	int steps = 200;
	int score = 0;
	
	

public:
	game();
	~game();
	int* countSteps();
	int* getScore();
	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid
	int* getNumberOfSteps();
	operation* createRequiredOperation(toolbarItem clickedItem);
	Levels* getLevel();
	void setLevel(Levels level);
	void LevelIsChanging(Levels* level);
	void run();	//start the game

};

