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

void Rect::resizeUp() 
{
	height *= 2;
	width *= 2;
	
	
	calcCorners();

}

void Rect::resizeDown() 
{
	height /= 2;
	width /= 2;
	
	
	calcCorners();
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
}

void Rect::setRefPoint(point newRef)
{
	RefPoint = newRef;
	calcCorners();
}


point* Rect::getLowerBottom() { return &lowerBottom; }
point* Rect::getUpperLeft() { return &upperLeft; }
ShapeType Rect::getShapeType() { return type = RCT; }





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
void circle::resizeUp()
{
	rad *= 2;
}

void circle::resizeDown()
{
	rad /= 2;
}

ShapeType circle::getShapeType() { return type = CRC; }
void circle::setRefPoint(point newRef)
{
	RefPoint = newRef;
	calcCorners();
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
void Equi_triangle::resizeUp()
{
	base *= 2;
	// Recalculate the vertices of the equilateral triangle
	upperPoint.y = RefPoint.y - sqrt(3) * (base / 2);
	leftLowerPoint.x = RefPoint.x - base / 2;
	rightLowerPoint.x = RefPoint.x + base / 2;
}

void Equi_triangle::resizeDown()
{
	base /= 2;
	// Recalculate the vertices of the equilateral triangle
	upperPoint.y = RefPoint.y - sqrt(3) * (base / 2);
	leftLowerPoint.x = RefPoint.x - base / 2;
	rightLowerPoint.x = RefPoint.x + base / 2;
}
void Equi_triangle::setRefPoint(point newRef)
{
	RefPoint = newRef;
	calcCorners();
}
ShapeType Equi_triangle::getShapeType() { return type = EQ_TRI; }

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

void Isso_triangle::move(int step, bool isVerical) 
{
	upperPoint.move(step,isVerical);
	leftLowerPoint.move(step, isVerical);
	rightLowerPoint.move(step, isVerical);
}


point* Isso_triangle::getUpperPoint() { return &upperPoint; }
point* Isso_triangle::getleftLower() { return &leftLowerPoint; }
point* Isso_triangle::getRightLower() { return &rightLowerPoint; }

void Isso_triangle::resizeUp() {
	// Resize factor (can be adjusted if needed)
	int resizeFactor = 2;

	// Calculate new height based on resize factor
	int newHeight = static_cast<int>(height * resizeFactor);

	// Calculate the difference in height
	int heightDiff = newHeight - height;

	// Calculate the new base width based on proportions
	int newBase = base * 2;

	// Update upper point based on new height
	upperPoint.y -= heightDiff;

	// Update reference point based on new height (considering odd height difference)
	RefPoint.y -= heightDiff / 2;
	// Alternative for odd height difference:
	// RefPoint.y -= (heightDiff + 1) / 2; // Add 1 to compensate for odd difference (optional)

	// Update height and base
	height = newHeight;
	base = newBase;
}



void Isso_triangle::resizeDown() {
	// Calculate new height and base
	int newHeight = height / 2;
	int newBase = base / 2;

	// Calculate the difference in height
	int heightDiff = height - newHeight;

	// Move the upper point downwards
	upperPoint.y += heightDiff;

	// Update the reference point
	RefPoint.y += heightDiff / 2;

	// Update the height and base
	height = newHeight;
	base = newBase;
}
void Isso_triangle::setRefPoint(point newRef)
{
	RefPoint = newRef;
	calcCorners();
}
ShapeType Isso_triangle::getShapeType() { return type = ISO_TRI; }

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

void Right_triangle::calcCorners(){
	upperPoint.x = RefPoint.x;
	upperPoint.y = RefPoint.y - height;

	leftLowerPoint.x = RefPoint.x + base;
	leftLowerPoint.y = RefPoint.y;


	rightLowerPoint.x = RefPoint.x ;
	rightLowerPoint.y = RefPoint.y ;
	
}

void Right_triangle::resizeUp()
{
	base *= 2; // Double the base
	height *= 2; // Double the height
	calcCorners();
}


void Right_triangle::resizeDown()
{
	base /= 2; // Halve the base
	height /= 2; // Halve the height
	calcCorners();
}

ShapeType Right_triangle::getShapeType() { return type = RIGHT_TRI; }





void Rect::flip() {
	int centerY = (upperLeft.y + lowerBottom.y) / 2;
	upperLeft.y = 2 * centerY - upperLeft.y;
	lowerBottom.y = 2 * centerY - lowerBottom.y;
	calcCorners();
}

void circle::flip() {
	RefPoint.y = -RefPoint.y;
	calcCorners();
}
void Isso_triangle::flip()
{
	upperPoint.flip(RefPoint);
	leftLowerPoint.flip(upperPoint);
}
void Equi_triangle::flip() {
	int centerY = (upperPoint.y + leftLowerPoint.y + rightLowerPoint.y) / 3;
	upperPoint.y = 2 * centerY - upperPoint.y;
	leftLowerPoint.y = 2 * centerY - leftLowerPoint.y;
	rightLowerPoint.y = 2 * centerY - rightLowerPoint.y;
	calcCorners();
}
void Right_triangle::flip() {
	int centerY = (upperPoint.y + leftLowerPoint.y + rightLowerPoint.y) / 3;
	upperPoint.y = 2 * centerY - upperPoint.y;
	leftLowerPoint.y = 2 * centerY - leftLowerPoint.y;
	rightLowerPoint.y = 2 * centerY - rightLowerPoint.y;
	calcCorners();
}
void Right_triangle::setRefPoint(point newRef)
{
	RefPoint = newRef;
	calcCorners();
}
//save collection by ebrahim 3
void Rect::save(ofstream& OutFile) {

}
void Right_triangle::save(ofstream& OutFile) {

}
void Isso_triangle::save(ofstream& OutFile) {

}
void Equi_triangle::save(ofstream& OutFile) {

}
void circle::save(ofstream& OutFile) {

}
