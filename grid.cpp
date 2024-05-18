#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include "CompositeShapes.h"
#include <cstdlib>
#include <time.h>
//#include "RandomShape.h"

grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;
	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	pWind->SetPen(config.gridDotsColor, 1);
	pWind->SetBrush(config.gridDotsColor);
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
	//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
		if (shapeList[i]) {
			shapeList[i]->draw();
		}

	//Draw the active shape
	if (activeShape) {
		activeShape->draw();
	}
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}


bool grid::matchingCheck()
{
	for (int i = 0; i < 7; i++)
	{
		if (!shapeList[i])
			continue;
		if (activeShape->getShapeType() == shapeList[i]->getShapeType())
		{
			//if (activeShape->getNumberOfResizeCalls() == shapeList[i]->getNumberOfResizeCalls())
				//if (activeShape->getRotationAngle() == shapeList[i]->getRotationAngle())
			if (activeShape->getReferencePoint() == shapeList[i]->getReferencePoint())
			{
				MatchedShapeIndex = i;
				return true;

			}
		}
	}
	return false;

}

int grid::getMatchedShapeIndex() { return MatchedShapeIndex; }
void grid::editShapeList(int Index, shape* Value, bool wannaRemove)
{
	if (wannaRemove)
	{
		delete shapeList[Index];
		shapeList[Index] = Value;
	}
	else
		shapeList[Index] = Value;
}

//Adds a shape to the randomly created shapes list.
bool grid::addShape(shape* newShape)
{
	//TODO:
	// 1- Check that the shape can be drawn witout being clipped by grid boundaries
	// 2- check shape count doesn't exceed maximum count
	// return false if any of the checks fail
	/*for (int i = 0; i < shapeCount; i++)
		shapeList[i] = ;*/
	/*if (shapeList[shapeCount])
	{
		delete shapeList[shapeCount];
		shapeList[shapeCount] = nullptr;
	}*/

	
	//Here we assume that the above checks are passed
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::resetShapeCount() { shapeCount = 0; }

void grid::setActiveShape(shape* actShape)
{
	/*if (activeShape)
		delete activeShape;*/
	activeShape = actShape;
}


shape* grid::getActiveShape() const { return activeShape; }

void grid::deleteActiveShape()
{
	delete activeShape;
	activeShape = nullptr;
}
#include <iostream>
void grid::createRandomShape()
{
	Levels CurrentLevel = LVL4;
	//Levels CurrentLevel = *pGame->getLevel();
	int NumberOfShapes = int(CurrentLevel) * 2 - 1;
	for (int i = 0; i < NumberOfShapes+1; i++)
	{
		if (shapeList[i])
		{
			delete shapeList[i];
			shapeList[i] = nullptr;
		}
	}
	
	// randomChoice
	srand(time(0));
	for (int i = 0; i < NumberOfShapes; i++)
	{
		
		point refPoint = { rand() % (config.windWidth + 1), config.gridHeight + rand() % (config.windHeight - config.GameStatusHeight - config.gridHeight + 1) };
		point RequiredRefPoint = { refPoint.x - refPoint.x % config.gridSpacing, refPoint.y - refPoint.y % config.gridSpacing };
		point* ShapesRefPoints = new point[NumberOfShapes];
		ShapeType stDetector = ShapeType(rand() % (ShapeEnd - 1));
		switch (stDetector)
		{
		case SIGN:
		{
			Sign* NewSign = new Sign(pGame, RequiredRefPoint);
			NewSign->calcCorners();
			NewSign->draw();
			addShape(NewSign);
			break;
		}
		case I:
		{
			I_Shape* NewI = new I_Shape(pGame, RequiredRefPoint);
			NewI->calcCorners();
			NewI->draw();
			addShape(NewI);
			break;
		}
		case House:
		{
			cHouse* NewHouse = new cHouse(pGame, RequiredRefPoint);
			NewHouse->calcCorners();
			NewHouse->draw();
			addShape(NewHouse);
			break;
		}
		case cap:
		{
			Cap* NewCap = new Cap(pGame, RequiredRefPoint);
			NewCap->calcCorners();
			NewCap->draw();
			addShape(NewCap);
			break;
		}
		case envelop:
		{
			Envelope* NewEnv = new Envelope(pGame, RequiredRefPoint);
			NewEnv->calcCorners();
			NewEnv->draw();
			addShape(NewEnv);
			break;
		}
		case Rocket:
		{
			rocket* NewRocket = new rocket(pGame, RequiredRefPoint);
			NewRocket->calcCorners();
			NewRocket->draw();
			addShape(NewRocket);
			break;
		}
		case blender:
		{
			Blender* NewBlender = new Blender(pGame, RequiredRefPoint);
			NewBlender->calcCorners();
			NewBlender->draw();
			addShape(NewBlender);
			break;
		} 
		default:
		{
			Blender* NewBlender = new Blender(pGame, RequiredRefPoint);
			NewBlender->calcCorners();
			NewBlender->draw();
			addShape(NewBlender);
			break;
		}
		}
	}
}

void grid::countSteps(shape* avtv)
{
	int steps = 0;
	

}