#pragma once
#include "gameConfig.h"
#include "game.h"

//class game
enum Levels;
class RandomShape
{
		int NumberOfShapes = 5;
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
		int* getNumberOfShapes();
		point getRandomPoint();
		void MakeRandomOperation(shape* sh);
		//point* getBoundaryPoints(shape* sh);
		//int getRandomOperationIteration();
		void StoreShapes(shape* ns);
		Levels* ShowLevel();
};

