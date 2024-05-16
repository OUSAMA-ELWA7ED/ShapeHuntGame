#include "RandomShape.h"
//#include "gameConfig.h"
#include <cstdlib>
#include <time.h>
RandomShape::RandomShape(game* r_pGame)
{
	pGame = r_pGame;
	NumberOfShapes = 5;
	PickedShapes = new ShapeType[NumberOfShapes];

	for (int i = 0; i < NumberOfShapes; i++)
	{
		PickedShapes[i] = getRandomShapeTypes();
	}
	
}

void RandomShape::draw()
{
	for (int i = 0; i < 5; i++) 
	{
		switch (PickedShapes[1])
		{
		case SIGN:
		{
			Sign* NewSign = new Sign(pGame, getRandomPoint());
			NewSign->calcCorners();
			NewSign->draw();
			StoreShapes(NewSign);
			break;
		}
		case RCT:
		{
			Rect* NewRect = new Rect(pGame, getRandomPoint(), 100, 70);
			NewRect->calcCorners();
			NewRect->draw();
			StoreShapes(NewRect);
			break;
		}
		case CRC:
		{
			circle* NewCircle = new circle(pGame, getRandomPoint(), 70);
			NewCircle->calcCorners();
			NewCircle->draw();
			break;
		}
		case EQ_TRI:
		{
			Equi_triangle* NewEqTrig = new Equi_triangle(pGame, getRandomPoint(), 75);
			NewEqTrig->calcCorners();
			NewEqTrig->draw();
			break;
		}
		case ISO_TRI:
		{
			Isso_triangle* NewIsoTrig = new Isso_triangle(pGame, getRandomPoint(), 100,80);
			NewIsoTrig->calcCorners();
			NewIsoTrig->draw();
			break;
		}
		case I:
		{
			break;
		}
		case House:
		{
			break;
		}
		case cap:
		{
			break;
		}
		case envelop:
		{
			break;
		}
		case Rocket:
		{
			break;
		}
		}
	}
}
#include <iostream>

ShapeType RandomShape::getRandomShapeTypes()
{
	srand(time(0));
	int Min = 0;
	int Max = 4;
	int x = (Min + rand() % (Max - Min + 1));
	ShapeType stShape = ShapeType(x);
	std::cout << to_string(stShape) << endl;
	return stShape;

}

//void RandomShape::setNumberOfShapes(Levels* curnLvl)
//{
//	int n = int(curnLvl);
//	NumberOfShapes = 5;
//}

int* RandomShape::getNumberOfShapes() { return &NumberOfShapes; }


point RandomShape::getRandomPoint()
{
	point rndmPoint;
	int constant = 100;
	rndmPoint.x = rand() % (config.windWidth - constant + 1);
	rndmPoint.y = config.gridHeight + rand() % (config.windHeight - config.gridHeight + 1);
	return rndmPoint;
}

void RandomShape::MakeRandomOperation(shape* sh)
{
	ShapeOperations RandomOperation = ShapeOperations(rand() % (OperationEnds + 1));
	switch (RandomOperation)
	{
	case Rotate:
		sh->rotate();
		break;
	/*case Resize:
		sh->resize();*/
	}

}


void RandomShape::StoreShapes(shape* ns)
{
	grid* pGrid = pGame->getGrid();
	pGrid->addShape(ns);
}

Levels* RandomShape::ShowLevel()
{
	Levels* currentLvl = new Levels(LVL1);
	return currentLvl;
}