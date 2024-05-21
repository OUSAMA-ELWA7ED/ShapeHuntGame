#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"




/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


operation::~operation()
{
	delete pGame;
	pGame = nullptr;
}



/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}



void operAddSign::Act()
{

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape
	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;
	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid, yGrid };
	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* psh = new Sign(pGame, signShapeRef);
	
	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

operAddI_Shape::operAddI_Shape(game* r_pGame) : operation(r_pGame)
{
}


void operAddI_Shape::Act()
{
	window* pi = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;

	//take the aligned point as the sign shape ref point
	point I_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pI = new I_Shape(pGame, I_ShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pI);

}



operAddHouse::operAddHouse(game* r_pGame) :operation(r_pGame)
{
}



void operAddHouse::Act()
{
	window* pHouses = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape


	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;

	//take the aligned point as the sign shape ref point
	point House_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pHouse = new cHouse(pGame, House_ShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pHouse);

}




operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}


void operAddRocket::Act()
{
	window* pRockete = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape


	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;

	//take the aligned point as the sign shape ref point
	point Rocket_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pRocket = new rocket(pGame, Rocket_ShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pRocket);

}
operAddBlender::operAddBlender(game* r_pGame) :operation(r_pGame)
{
}


void operAddBlender::Act()
{
	window* pBlendere = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape


	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;

	//take the aligned point as the sign shape ref point
	point Blender_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pBlender = new Blender(pGame, Blender_ShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pBlender);

}
operAddEnv::operAddEnv(game* r_pGame) : operation(r_pGame)
{

}
void operAddEnv::Act()
{
	window* pEnvelop = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape


	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;

	//take the aligned point as the sign shape ref point
	point Env_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pEnv = new Envelope(pGame, Env_ShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pEnv);

}


operAddCap::operAddCap(game* r_pGame) : operation(r_pGame)
{

}
void operAddCap::Act()
{
	window* pCaps = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape


	//align reference point to the nearest grid point

	int xGrid = config.RefX - config.RefX % config.gridSpacing;;
	int yGrid = config.RefX - config.RefX % config.gridSpacing;;

	//take the aligned point as the sign shape ref point
	point Cap_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pCap = new Cap(pGame, Cap_ShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(pCap);
}











operMakeRotation::operMakeRotation(game* r_pGame) : operation(r_pGame)
{

}

void operMakeRotation::Act()
{
	window* pRotate = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->rotate();
	pGrid->draw();
}



operMove::operMove(game* r_pGame, int stp) : operation(r_pGame)
{
	step = stp;
}

void operMove::Act()
{
	//window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->move(step, isVertical);
}

void operMove::isItVertical(bool isIt)
{
	isVertical = isIt;
}

void operMove::moveStep(int stp)
{
	step = stp;
}

operFlip::operFlip(game* r_pGame) : operation(r_pGame)
{

}
operResizeUp::operResizeUp(game* r_pGame) : operation(r_pGame)
{
}

void operResizeUp::Act()
{
	window* presizeDown = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->resizeUp();
}

/////////////////////////////////// class operResizeDown  //////////////////

operResizeDown::operResizeDown(game* r_pGame) : operation(r_pGame)
{
}

void operResizeDown::Act()
{
	window* presizeDown = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	
	pGrid->getActiveShape()->resizeDown();
	
}
operExit::operExit(game* r_pGame) : operation(r_pGame)
{
}
	

void operExit::Act()
{
	
}
		
void operFlip::Act()
{
	window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->flip();
}


operDeleteThisShape::operDeleteThisShape(game* r_pGame) : operation(r_pGame)
{}


void operDeleteThisShape::Act()
{
	//window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->deleteActiveShape();
}

//BuildRandomShape::BuildRandomShape(game* r_pGame) : operation(r_pGame)
//{}
//
//void BuildRandomShape::Act()
//{
//	grid* pGrid = pGame->getGrid();
//	RandomShape* rndmShape = new RandomShape(pGame);
//	pGrid->setRandomShape(rndmShape);
//
//}

#include <iostream>
//file operation.cpp
operSelect_level::operSelect_level(game* r_pGame):operation(r_pGame)
{}
void operSelect_level::Act()
{
	char cKeyData;
	keytype ktInput;
	window* pWind = pGame->getWind();
	ktInput = pWind->WaitKeyPress(cKeyData);
	Levels* lvl = pGame->getLevel();
	if (ktInput == ASCII && (cKeyData == '1' || cKeyData == '2' || cKeyData == '3' || cKeyData == '4' || cKeyData == '5'))
	{
		switch (cKeyData)
		{
		case '1':
			pGame->setLevel(LVL1);
			break;
		case '2':
			pGame->setLevel(LVL2);
			break;
		case '3':
			pGame->setLevel(LVL3);
			break;
		case '4':
			pGame->setLevel(LVL4);
			break;
		case '5':
			pGame->setLevel(LVL5);
			break;
		}
	}
	pGame->clearStatusBar();
}

CallHint::CallHint(game* r_pGame) : operation(r_pGame){}
void CallHint::Act(){}

Refresh::Refresh(game* r_pGame) : operation(r_pGame)
{}

void Refresh::Act()
{
	window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->resetShapeCount();
	pGrid->createRandomShape();
}