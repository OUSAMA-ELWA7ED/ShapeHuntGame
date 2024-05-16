#pragma once
#include "gameConfig.h"
#include "game.h"

//class game
class RandomShape
{
		int NumberOfShapes;
		ShapeType* PickedShapes;
		ShapeOperations soImplementOperation;
		point* BondaryPoints;
		game* pGame;
		Levels* currentLevel;
		

		//operation* op;
	public:
		RandomShape(game* r_pGame);
		void draw();
		ShapeType getRandomShapeTypes();
		int getNumberOfShapes(Levels* curnLvl);
		point getRandomPoint();
		void MakeRandomOperation(shape* sh);
		//point* getBoundaryPoints(shape* sh);
		//int getRandomOperationIteration();
		void StoreShapes(shape* ns);
		Levels* ShowLevel();
};

