#pragma once
#include "shape.h"
#include "BasicShapes.h"
#include "CompositeShapes.h"
#include "gameConfig.h"
#include "game.h"
//class game
class RandomShape
{
		int n;
		ShapeType* PickedShapes;
		ShapeOperations soImplementOperation;
		point* BondaryPoints;
		game* pGame;
		

		//operation* op;
	public:
		RandomShape(game* r_pGame, int N = 1);
		void draw();
		ShapeType getRandomShapeTypes();
		int getNumberOfShapes();
		point getRandomPoint();
		void MakeRandomOperation(shape* sh);
		//point* getBoundaryPoints(shape* sh);
		int getRandomOperationIteration();
		void StoreShapes(shape* ns);
};




