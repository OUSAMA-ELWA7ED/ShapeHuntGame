#pragma once
#include <string>
#include "gameConfig.h"
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;


	void rotate(point ref)
	{


		int temp_virtual;  // virtual means that I want to test the result before use it.
		int x1 = x, y1 = y; // transformation matrix ==> 
		x1 -= ref.x;
		y1 -= ref.y;
		temp_virtual = x1;
		x1 = -y1;
		y1 = temp_virtual;
		x1 += ref.x;
		y1 += ref.y;
		bool what = isItExceeded(x1, y1);
		if (isItExceeded(x1, y1) == false) {
			x -= ref.x;
			y -= ref.y;

			int temp = x;
			x = -y;
			y = temp;

			x += ref.x;
			y += ref.y;
		}
		else
			return;
	}
	void move(int step,bool isVertical)
	{
		int x1 = x, y1 = y;
		x1 += config.gridSpacing; y1 += config.gridSpacing;

		if (isItExceeded(x1, y1) == false) {
			if (isVertical == false)
				x += step; //int = 30;
			else if (isVertical == true)
				y += step;
		}
		else
			return;
	}

	void flip(point pnt)
	{
		int temp = y;
		y = pnt.y;
		pnt.y = temp;

	}

	bool isItExceeded(int xs, int ys)
	{
		if (xs > config.windWidth || xs < 0 || ys < 0 || ys > config.windHeight)
			return true;
		else
			return false;
	}


};

enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	EQ_TRI,	//triangle
	ISO_TRI,
	SIGN,
	I,
	House,
	cap,
	envelop,
	Rocket,
	blender,
	ShapeEnd,
};

enum ShapeOperations
{
	Rotate,
	Resize,
	OperationEnds,

};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
	game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	int iRotationAngle = 0;
	int iResizeCalls = 0;
	//int iRotationCalls = 0;
public:
	shape(game* r_pGame, point ref);
	~shape();
	virtual void draw() = 0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	virtual void calcCorners() = 0;
	virtual void rotate() = 0;
	virtual void move(int step, bool isVertical);
	//virtual bool isExceeded() = 0;
	//virtual point* getBoundaryBox() = 0;
	virtual void flip() = 0;
	//virtual void resize() = 0;
	int getRotationAngle();
	int getNumberOfResizeCalls();
	virtual void resizeUp() = 0;     //Resize the shape up
	virtual void resizeDown() = 0;	//Resize the shape down 
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




