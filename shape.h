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
	//Composite shapes
	SIGN,	//a street sign
	I,
	House,
	//TODO: Add more types
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
	// point pntLinkingPoint; // this linking point are responsable for link each peace of the shape together
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
public:
    shape(game* r_pGame, point ref);
    virtual void draw() = 0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	//point* getRefPoint();
	// friend class Sign;               === shape says that Sign is my friendo , don't hurt him. D:
	~shape();
							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	virtual void flip() = 0;
	virtual void rotate() = 0;	//Rotate the shape
	virtual void move(int step, bool isVertical) = 0;
	virtual void calcCorners() = 0; // function to make the calculations
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




