#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <time.h>
#include <cstdlib>
#include "gameConfig.h"




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

	int xGrid = (config.RefX);
	int yGrid = (config.RefY);
	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid, yGrid };
	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* psh = new class Sign(pGame, signShapeRef);
	
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

	int xGrid = (config.RefX + 50);
	int yGrid = (config.RefY + 30);

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

	int xGrid = (config.RefX);
	int yGrid = (config.RefY);

	//take the aligned point as the sign shape ref point
	point House_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pHouse = new class House(pGame, House_ShapeRef);

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

	int xGrid = (config.RefX);
	int yGrid = (config.RefY);

	//take the aligned point as the sign shape ref point
	point Rocket_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pRocket = new class Rocket(pGame, Rocket_ShapeRef);

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

	int xGrid = (config.RefX);
	int yGrid = (config.RefY);

	//take the aligned point as the sign shape ref point
	point Blender_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pBlender = new class Blender(pGame, Blender_ShapeRef);

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

	int xGrid = (config.RefX);
	int yGrid = (config.RefY);

	//take the aligned point as the sign shape ref point
	point Env_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pEnv = new class Envelope(pGame, Env_ShapeRef);

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

	int xGrid = (config.RefX);
	int yGrid = (config.RefY);

	//take the aligned point as the sign shape ref point
	point Cap_ShapeRef = { xGrid, yGrid };

	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
	shape* pCap = new class Cap(pGame, Cap_ShapeRef);

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

operMove::operMove(game* r_pGame) : operation(r_pGame)
{

}
//ARROWS operMove::getPressedArrow(ARROWS clickedArrow)
//{
//	if (clickedArrow == RightArrow)
//		return RightArrow;
//	else if (clickedArrow == LeftArrow)
//		return LeftArrow;
//	else if (clickedArrow == UpArrow)
//		return UpArrow;
//	else if (clickedArrow == DownArrow)
//		return DownArrow;
//}


void operMove::Act()
{
	
}

void operMove::RealAct(int step, bool isVertical)
{
	window* pMove = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->getActiveShape()->move(step, isVertical);
	pGrid->draw();
}



operFlip::operFlip(game* r_pGame) : operation(r_pGame)
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
	window* pWind = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(nullptr);
}




//operAddRect::operAddRect(game* r_pGame) : operation(r_pGame)
//{
//}
//
//void operAddRect::Act()
//{
//	window* pRectt = pGame->getWind();
//
//	//TODO:
//	// Don't allow adding new shape if there is alreday an active shape
//
//
//	//align reference point to the nearest grid point
//
//	int xGrid = (config.RefX);
//	int yGrid = (config.RefY);
//
//	//take the aligned point as the sign shape ref point
//	point rectRef = { xGrid, yGrid };
//
//	//create a sign shape ==========================================> what's the purpose of the pointer to object shape
//	shape* pRec = new class Rect(pGame, rectRef, config.Rectangle.Height,config.Rectangle.Width);
//
//	//Add the shape to the grid
//	grid* pGrid = pGame->getGrid();
//	pGrid->setActiveShape(pRec);
//}