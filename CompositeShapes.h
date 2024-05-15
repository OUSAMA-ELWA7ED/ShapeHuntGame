#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign : public shape
{
	Rect* base;
	Rect* top;
	point topRef;	
	point baseRef;
	int refpointx;
	int refpointy;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void rotate() override;
	virtual void move(int step, bool isVerical) override;
	virtual void flip() override;
	void resizeUp();
	void resizeDown();
	//void move();
	//virtual void move() override;

};




class I_Shape : public shape // Ref at mid rect
{
	Rect* base;
	Rect* top;
	Rect* rect_pMid;
	int refpointx;
	int refpointy;
public:
	I_Shape(game* r_pGame, point ref);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void rotate() override;
	virtual void move(int step, bool isVerical) override;
	virtual void flip() override;
	//virtual void move() override;

};

class cHouse : public shape
{
	Rect* base;
	Isso_triangle* head;
	point baseRef;
	point headRef;
	//circle* test;
	int refpointx;
	int refpointy;
public:
	cHouse(game* r_pGame, point ref);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void move(int step, bool isVerical) override;
	virtual void rotate() override;
	virtual void flip() override;
	void resizeUp();
	void resizeDown();
	//virtual void move() override;
};



class rocket : public shape
{
	point baseRectRef;
	point headTriRef;
	point RightLowerTriRef;
	point LeftLowerTriRef;
	Rect* baseRect;
	Isso_triangle* headIsso;
	Right_triangle* triangle_pBottomRight;
	Right_triangle* triangle_pBottomLeft;
	int refpointx;
	int refpointy;

public:
	rocket(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	void resizeUp();
	void resizeDown();
};


class Blender : public shape {
	point BodyRectRef;
	point TopRectRef;
	point TopCircleRef;
	point LowerRectRef;
	point RightLowerTriRef;
	point LeftLowerTriRef;
	circle* TopCircle;
	Rect* TopRect;
	Rect* BodyRect;
	Rect* LowerRect;
	Right_triangle* triangle_pBottomRight;
	Right_triangle* triangle_pBottomLeft;
	int refpointx;
	int refpointy;
public:
	Blender(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	void resizeUp();
	void resizeDown();
};



class Envelope : public shape
{
	point BodyRectRef;
	point TopRectRef;
	point UpperTriRightRef;
	point UpperTriLeftRef;
	Rect* BodyRect;
	Rect* TopRect;
	Right_triangle* TriRight;
	Right_triangle* TriLeft;
	int refpointx;
	int refpointy;
public:
	Envelope(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	void resizeUp();
	void resizeDown();
};



class Cap : public shape
{
	point MidTriRef;
	point TopCircleRef;
	point BaseRectRef;
	Rect* baseRect;
	Isso_triangle* midTri;
	circle* topCircle;
	int refpointx;
	int refpointy;
public:
	Cap(game* r_pGame, point ref);
	virtual void draw();
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	void resizeUp();
	void resizeDown();
};



















//class TrigInsideCircle : public shape
//{
//	circle* circ;
//	Isso_triangle* trig;
//public:
//	TrigInsideCircle(game* r_pGame, point ref) : shape(r_pGame, ref);
//	void virtual draw() const;
//};
