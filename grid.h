#pragma once
#include <vector>
#include <iostream>
using namespace std;
#include "CompositeShapes.h"
class game;
class grid
{
	enum { MaxShapeCount = 1000  };	//assuming max shape count = 1000
	int rows, cols;	//numner of rows and columns in the grid to draw grid points
	int height, width;
	point uprLeft;	//upper left point of the grid
	shape* shapeList[MaxShapeCount];	//2D array of shape pointers
	shape* activeShape;	//The shape that the user works on to match to the ranom shapes
	int MatchedShapeIndex;
	int shapeCount = 1;		//current number of shapes in the list
	game* pGame;
	vector<shape*> ShapeList; // Currently unused
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	void clearGridArea() const;
	bool addShape(shape* newShape);
	void setActiveShape(shape* actShape);
	shape* getActiveShape() const;
	void deleteActiveShape();
	void createRandomShape();
	bool matchingCheck();
	int getMatchedShapeIndex();
	void editShapeList(int Index, shape* Value, bool wannaRemove);
	void resetShapeCount();
};


