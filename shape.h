#pragma once
#include <string>

using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;
	
	// ==============> Applying rotation function <===============
	void rotate(point ref)
	{

		x -= ref.x;
		y -= ref.y;

		int temp = x;
		x = -y;
		y = temp;

		x += ref.x;
		y += ref.y;
		
	}
	// =====================> Applying flipping function to each point individually <================
	
	// ======================>Implementation of moving horizontally function <==========================
	void move(int step, bool isVertically=false) // move(30, true)
	{
		if (isVertically)
			y += step;
		else
			x += step;
	}

	void flip(point lowestPoint)
	{
		int temp = y;
		y = lowestPoint.y;
		lowestPoint.y = temp;
	}

	/*void moveVertically()
	{
		int const movementStep = 10;
		y += movementStep;
	}*/


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
	//virtual void resize() = 0;	//Resize the shape
	virtual void move(int step, bool isVertical) = 0;
	virtual void calcCorners() = 0; // function to make the calculations
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




