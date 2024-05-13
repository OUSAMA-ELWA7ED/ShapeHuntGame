#pragma once
#include "gameConfig.h"

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;
public:
	operation(game* r_pGame);
	~operation();
	virtual void Act() = 0;
	//virtual ARROWS getPressedArrow(ARROWS clckdArrow);
};



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

class BuildRandomShape : public operation
{
public:
	BuildRandomShape(game* r_pGame);
	virtual void Act() override;
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

