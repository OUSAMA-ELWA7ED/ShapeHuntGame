//Header file for Basic shapes in the game
#pragma once
#include "shape.h"
//#include "GraphicsLib\\color.h"




class Rect:public shape
{
	int height, width;	
	point upperLeft, lowerBottom;
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void calcCorners() override;
	virtual void draw();
	virtual void resize();
	void SetColor(color clr);
	virtual void rotate() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	virtual void resizeUp() override;
	virtual void rotate() override;
	point* getUpperLeft();
	point* getLowerBottom();
	//point* getRefPoint();
};



class circle :public shape
{
	int rad;

public:	
	circle(game* r_pGame, point ref, int r);	
	virtual void draw();
	virtual void calcCorners() override;
	void SetColor(color clr);
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	//virtual void resize();
	virtual void resizeUp() override;
	virtual void rotate() override;
	virtual void rotate() override;
	point* getRefPoint();
};

class Equi_triangle : public shape
{
	int base;
public:
	Equi_triangle(game* r_pGame, point ref, int Base);
	point upperPoint, leftLowerPoint, rightLowerPoint;
	virtual void draw();
	virtual void calcCorners() override;
	void SetColor(color clr);
	virtual void move(int step, bool isVertical) override;
	virtual void rotate() override;
	virtual void resizeUp() override;
	virtual void rotate() override;
	virtual void flip() override;
	//virtual void move() override;
};
class Isso_triangle : public shape
{
	int base, height;
	point upperPoint, leftLowerPoint, rightLowerPoint;
public:
	Isso_triangle(game* r_pGame, point ref, int Base,int Height);
	virtual void draw();
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void rotate() override;
	virtual void flip() override;
	void SetColor(color clr);
	point* getUpperPoint();
	point* getleftLower();
	point* getRightLower();
	virtual void resizeUp() override;
	virtual void rotate() override;
	//virtual void move() override;
};



class Right_triangle : public shape
{
	int base, height;
	point upperPoint, leftLowerPoint, rightLowerPoint;
public:
	Right_triangle(game* r_pGame, point ref, int Base, int Height);
	virtual void draw();
	void SetColor(color clr);
	virtual void rotate() override;
	virtual void calcCorners() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	point* getUpperPoint();
	point* getleftLower();
	point* getrightLowerPoint();
	virtual void resizeUp() override;
	virtual void rotate() override;
};
