#pragma once
#include "gameConfig.h"
class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;
	ARROWS clickedArrow;
public:
	operation(game* r_pGame);
	~operation();
	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
	//virtual ARROWS getPressedArrow(ARROWS clckdArrow);
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};

class operAddI_Shape : public operation
{
public:
	operAddI_Shape(game* r_pGame);
	virtual void Act();
};


class operAddHouse : public operation
{
public:
	operAddHouse(game* r_pGame);
	virtual void Act();
};

class operMakeRotation : public operation
{
public:
	operMakeRotation(game* r_pGame);
	virtual void Act();
};


class operAddRocket : public operation
{
public:
	operAddRocket(game* r_pGame);
	virtual void Act();
};
class operAddBlender : public operation
{
public:
	operAddBlender(game* r_pGame);
	virtual void Act();
};
class operAddEnv : public operation
{
public:
	operAddEnv(game* r_pGame);
	virtual void Act();
};
class operAddCap : public operation
{
public:
	operAddCap(game* r_pGame);
	virtual void Act();
};

class operMove : public operation
{
	//int step = config.gridSpacing;
	bool isVertical;
	int step;
public:
	operMove(game* r_pGame, int stp = 0);
	virtual void Act();
	void isItVertical(bool isIt); // set isVertical
	void moveStep(int stp);
};

class operFlip :public operation
{
public:
	operFlip(game* r_pGame);
	virtual void Act();
};

class operDeleteThisShape : public operation
{
public:
	operDeleteThisShape(game* r_pGame);
	virtual void Act();

};


//class operAddRect : public operation
//{
//public:
//	operAddRect(game* r_pGame);
//	virtual void Act();
//};


// file operation.h
class operSelect_level:public operation
{
public:
operSelect_level(game* r_pGame);
virtual void Act();
};

