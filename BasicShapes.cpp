#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	height = r_hght;
	width = r_wdth;
	calcCorners();
}


void Rect::calcCorners() {
	upperLeft.x = RefPoint.x - width / 2;
	upperLeft.y = RefPoint.y - height / 2;
	lowerBottom.x = RefPoint.x + width / 2;
	lowerBottom.y = RefPoint.y + height / 2;
}

void Rect::SetColor(color clr)
{
	window* pW = pGame->getWind();
	pW->SetPen(clr, config.penWidth);
	pW->SetBrush(clr);
}

void Rect::draw()
{
	//calcCorners();
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor); // 7amada is a big batekh as well as Osama <3
	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
	//pW->DrawRectangle(RefPoint.x - width / 2, RefPoint.y - height / 2, RefPoint.x + width / 2, RefPoint.y + height / 2, FILLED);
	
}


void Rect::resize()
{
	
}

void Rect::rotate()
{
	upperLeft.rotate(RefPoint);
	lowerBottom.rotate(RefPoint);
}

void Rect::move(int step, bool isVerical)
{
	upperLeft.move(step, isVerical);
	lowerBottom.move(step, isVerical);
	//RefPoint.move(step, isVerical);
}



point* Rect::getLowerBottom() { return &lowerBottom; }
point* Rect::getUpperLeft() { return &upperLeft; }






circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	rad = r;
}

void circle::draw() 
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}

void circle::SetColor(color clr)
{
	window* pW = pGame->getWind();
	pW->SetPen(clr, config.penWidth);
	pW->SetBrush(clr);
}


void circle::calcCorners(){}

void circle::rotate()
{
	RefPoint.rotate(RefPoint);
}
point* circle::getRefPoint() { return &RefPoint; }
void circle::move(int step, bool isVertical)
{
	RefPoint.move(step, isVertical);
}






Equi_triangle::Equi_triangle(game* r_pGame, point ref, int Base) : shape(r_pGame, ref)
{
	pGame = r_pGame;
	base = Base;
	calcCorners();
	
}

void Equi_triangle::draw() 
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	pW->DrawTriangle(upperPoint.x, upperPoint.y, leftLowerPoint.x, leftLowerPoint.y, rightLowerPoint.x, rightLowerPoint.y, FILLED);
}

void Equi_triangle::SetColor(color clr)
{
	window* pW = pGame->getWind();
	pW->SetPen(clr, config.penWidth);
	pW->SetBrush(clr);
}


void Equi_triangle::calcCorners()
{
	upperPoint.x = RefPoint.x;
	upperPoint.y = RefPoint.y - sqrt(3) * (base / 2);
	leftLowerPoint.x = RefPoint.x - base / 2;
	leftLowerPoint.y = RefPoint.y;
	rightLowerPoint.x = RefPoint.x + base / 2;
	rightLowerPoint.y = RefPoint.y;
}

void Equi_triangle::rotate()
{
	upperPoint.rotate(RefPoint);
	leftLowerPoint.rotate(RefPoint);
	rightLowerPoint.rotate(RefPoint);

}


void Equi_triangle::move(int step, bool isVerical) {}
// void Equi_triangle::move(){}



Isso_triangle::Isso_triangle(game* r_pGame, point ref, int Base,int Height) : shape(r_pGame, ref)
{
	pGame = r_pGame;
	base = Base;
	height = Height;
	calcCorners();
	
}

void Isso_triangle::SetColor(color clr)
{
	window* pW = pGame->getWind();
	pW->SetPen(clr, config.penWidth);
	pW->SetBrush(clr);
}
void Isso_triangle::draw()
{
	window* pW = pGame->getWind();	//get interface window
	/*pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);*/
	pW->DrawTriangle(upperPoint.x, upperPoint.y, leftLowerPoint.x, leftLowerPoint.y, rightLowerPoint.x, rightLowerPoint.y, FILLED);
}

void Isso_triangle::calcCorners()
{
	upperPoint.x = RefPoint.x;
	upperPoint.y = RefPoint.y - height;
	leftLowerPoint.x = RefPoint.x - base / 2;
	leftLowerPoint.y = RefPoint.y;
	rightLowerPoint.x = RefPoint.x + base / 2;
	rightLowerPoint.y = RefPoint.y;
}

void Isso_triangle::rotate()
{
	upperPoint.rotate(RefPoint);
	leftLowerPoint.rotate(RefPoint);
	rightLowerPoint.rotate(RefPoint);
	
	
}

void Isso_triangle::move(int step, bool isVerical) {}


point* Isso_triangle::getUpperPoint() { return &upperPoint; }
point* Isso_triangle::getleftLower() { return &leftLowerPoint; }
point* Isso_triangle::getRightLower() { return &rightLowerPoint; }


Right_triangle::Right_triangle(game* r_pGame, point ref, int Base, int Height) : shape(r_pGame, ref)
{
	pGame = r_pGame;
	base = Base;
	height = Height;

	upperPoint.x = RefPoint.x;
	upperPoint.y = RefPoint.y - height;
	leftLowerPoint.x = RefPoint.x;
	leftLowerPoint.y = RefPoint.y;
	rightLowerPoint.x = RefPoint.x + base;
	rightLowerPoint.y = RefPoint.y;
}

void Right_triangle::SetColor(color clr)
{
	window* pW = pGame->getWind();
	pW->SetPen(clr, config.penWidth);
	pW->SetBrush(clr);
}
void Right_triangle::draw() 
{
	window* pW = pGame->getWind();	//get interface window
	//pW->SetPen(config.penColor, config.penWidth);
	//pW->SetBrush(config.fillColor);
	pW->DrawTriangle(upperPoint.x, upperPoint.y, leftLowerPoint.x, leftLowerPoint.y, rightLowerPoint.x, rightLowerPoint.y, FILLED);
};

void Right_triangle::rotate() {}
void Right_triangle::move(int step, bool isVertical) {}

point* Right_triangle::getUpperPoint() { return &upperPoint; }
point* Right_triangle::getleftLower() { return &leftLowerPoint; }
point* Right_triangle::getrightLowerPoint() { return &rightLowerPoint; }

void Right_triangle::calcCorners(){}








void Rect::flip(){}
void circle::flip(){}
void Isso_triangle::flip()
{
	upperPoint.flip(RefPoint);
	leftLowerPoint.flip(upperPoint);
}
void Equi_triangle::flip(){}
void Right_triangle::flip(){}