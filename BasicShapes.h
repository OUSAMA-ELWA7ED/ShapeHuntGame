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
	virtual void resizeDown() override;
	virtual void resizeUp() override;
	void SetColor(color clr);
	virtual void rotate() override;
	virtual void move(int step, bool isVertical) override;
	virtual void flip() override;
	point* getUpperLeft();
	point* getLowerBottom();
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);

	void setRefPoint(point newRef);

	virtual void DontExceed() override;

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
	virtual void resizeDown() override;
	virtual void resizeUp() override;
	virtual void rotate() override;
	point* getRefPoint();
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	void setRefPoint(point newRef);

	virtual void DontExceed() override;

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
	virtual void flip() override;
	virtual void resizeDown() override;
	virtual void resizeUp() override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	void setRefPoint(point newRef);
	virtual void DontExceed() override;

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
	virtual void resizeDown() override;
	virtual void resizeUp() override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	void setRefPoint(point newRef);
	//virtual void move() override;
	virtual void DontExceed() override;
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
	virtual void resizeDown() override;
	virtual void resizeUp() override;
	virtual ShapeType getShapeType() override;
	virtual void save(ofstream& OutFile);
	void setRefPoint(point newRef);

	virtual void DontExceed() override;

};
