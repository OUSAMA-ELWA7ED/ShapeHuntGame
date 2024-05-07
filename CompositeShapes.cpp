#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	topRef = ref;	//top rect ref is the same as the sign
	baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::calcCorners() {}

void Sign::draw() 
{
	base->SetColor(BEIGE);
	base->draw();
	top->SetColor(BEIGE);
	top->draw();

}

void Sign::rotate()
{
	top->rotate();
	base->getLowerBottom()->rotate(topRef);
	base->getUpperLeft()->rotate(topRef);
	
}

void Sign::move(int step, bool isVerical)
{
	top->move(step, isVerical);
	base->move(step, isVerical);
	topRef.move(step, isVerical);
	//RefPoint.move(step, isVerical);

}


//void Sign::move()
//{
//	top->move();
//	base->move();
//}


I_Shape::I_Shape(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	point midRef = ref;
	point topRef = {ref.x, ref.y - config.I_Shape.midHeight / 2 - config.I_Shape.topHeight / 2};
	point baseRef = {ref.x, ref.y + config.I_Shape.baseHeight / 2 + config.I_Shape.midHeight / 2};
	// ==============================================================================
	rect_pMid = new Rect(pGame, midRef, config.I_Shape.midHeight, config.I_Shape.midWdth);
	top = new Rect(pGame, topRef, config.I_Shape.topHeight, config.I_Shape.topWdth);
	base = new Rect(pGame, baseRef, config.I_Shape.baseHeight, config.I_Shape.baseWdth);

}



void I_Shape::rotate()
{

}

void I_Shape::move(int step, bool isVerical){}

void I_Shape::draw() 
{
	base->draw();
	top->draw();
	rect_pMid->draw();
}

//void I_Shape::move(){}

void I_Shape::calcCorners() {}

House::House(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	baseRef = ref;
	headRef = { ref.x, ref.y - config.House.baseHeight / 2 };
	// ===================================================================
	base = new Rect(pGame, baseRef, config.House.baseHeight, config.House.baseWidth);
	head = new Isso_triangle(pGame, headRef, config.House.headBase, config.House.headHeight);
	//test = new circle(pGame, headRef, 50);
}

void House::draw() 
{

	base->draw();
	head->SetColor(BLUE);
	head->draw();
	
	//test->draw();
}

void House::calcCorners() {}
void Rocket::calcCorners() {}
void Blender::calcCorners() {}
void Envelope::calcCorners() {}
void Cap::calcCorners() {}

void House::rotate()
{
	base->rotate();
	//head->rotate();

	head->getRightLower()->rotate(baseRef);
	head->getleftLower()->rotate(baseRef);
	head->getUpperPoint()->rotate(baseRef);

}

void House::move(int step, bool isVerical) {}

//void House::move(){}


Rocket::Rocket(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	baseRectRef = ref;
	headTriRef = { ref.x, ref.y - (config.Rocket_Shape.baseRectHeight) / 2 };
	RightLowerTriRef = { ref.x + (config.Rocket_Shape.baseRectWidth) / 2, ref.y + (config.Rocket_Shape.baseRectHeight) / 2 };
	LeftLowerTriRef = { ref.x - (config.Rocket_Shape.baseRectWidth) / 2, ref.y + (config.Rocket_Shape.baseRectHeight) / 2 };
	//=========================================================================
	baseRect = new Rect(pGame, baseRectRef, config.Rocket_Shape.baseRectHeight, config.Rocket_Shape.baseRectWidth);
	headIsso = new Isso_triangle(pGame, headTriRef, config.Rocket_Shape.headTriBase, config.Rocket_Shape.headTriHeight);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Rocket_Shape.LowerRightTriWidth, config.Rocket_Shape.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Rocket_Shape.LowerRightTriWidth), config.Rocket_Shape.LowerRightTriHeight);
}
void Rocket::draw()  {
	baseRect->SetColor(BLACK);
	baseRect->draw();
	headIsso->SetColor(BLACK);
	headIsso->draw();
	triangle_pBottomRight->SetColor(BLACK);
	triangle_pBottomRight->draw();
	triangle_pBottomLeft->SetColor(BLACK);
	triangle_pBottomLeft->draw();

}

void Rocket::rotate()
{
	baseRect->rotate();
	headIsso->getUpperPoint()->rotate(baseRectRef);
	headIsso->getleftLower()->rotate(baseRectRef);
	headIsso->getRightLower()->rotate(baseRectRef);
	triangle_pBottomLeft->getUpperPoint()->rotate(baseRectRef);
	triangle_pBottomLeft->getleftLower()->rotate(baseRectRef);
	triangle_pBottomLeft->getrightLowerPoint()->rotate(baseRectRef);
	triangle_pBottomRight->getUpperPoint()->rotate(baseRectRef);
	triangle_pBottomRight->getleftLower()->rotate(baseRectRef);
	triangle_pBottomRight->getrightLowerPoint()->rotate(baseRectRef);
}


void Rocket::move(int step, bool isVerical)
{
}

Blender::Blender(game* r_pGame, point ref) : shape(r_pGame, ref) {
	BodyRectRef = ref;
	TopRectRef = { ref.x, ref.y - (config.Blender.BodyRectHeight) / 2 };
	TopCircleRef = { ref.x,ref.y - ((config.Blender.BodyRectHeight / 2) + config.Blender.TopRectHight + (config.Blender.TopCircleRad / 2)) };
	LowerRectRef = { ref.x, ref.y + (config.Blender.BodyRectHeight) / 2 };
	RightLowerTriRef = { ref.x + (config.Blender.BodyRectWidth) / 2, ref.y + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	LeftLowerTriRef = { ref.x - (config.Blender.BodyRectWidth) / 2, ref.y + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	//=================================================
	BodyRect = new Rect(pGame, BodyRectRef, config.Blender.BodyRectHeight, config.Blender.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Blender.TopRectHight, config.Blender.TopRectWidth);
	TopCircle = new circle(pGame, TopCircleRef, config.Blender.TopCircleRad);
	LowerRect = new Rect(pGame, LowerRectRef, config.Blender.LowerRectHeight, config.Blender.LowerRectWidth);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Blender.LowerRightTriWidth, config.Blender.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Blender.LowerRightTriWidth), config.Blender.LowerRightTriHeight);
}

void Blender::draw() {
	BodyRect->SetColor(GREEN);
	BodyRect->draw();
	TopRect->SetColor(GREEN);
	TopRect->draw();
	TopCircle->SetColor(GREEN);
	TopCircle->draw();
	triangle_pBottomRight->SetColor(GREEN);
	triangle_pBottomRight->draw();
	triangle_pBottomLeft->SetColor(GREEN);
	triangle_pBottomLeft->draw();
	LowerRect->SetColor(GREEN);
	LowerRect->draw();
}
void Blender::rotate()
{
	BodyRect->rotate();
	TopRect->getLowerBottom()->rotate(BodyRectRef);
	TopRect->getUpperLeft()->rotate(BodyRectRef);
	triangle_pBottomLeft->getUpperPoint()->rotate(BodyRectRef);
	triangle_pBottomLeft->getleftLower()->rotate(BodyRectRef);
	triangle_pBottomLeft->getrightLowerPoint()->rotate(BodyRectRef);
	triangle_pBottomRight->getUpperPoint()->rotate(BodyRectRef);
	triangle_pBottomRight->getleftLower()->rotate(BodyRectRef);
	triangle_pBottomRight->getrightLowerPoint()->rotate(BodyRectRef);
	LowerRect->getLowerBottom()->rotate(BodyRectRef);
	LowerRect->getUpperLeft()->rotate(BodyRectRef);
	TopCircle->getRefPoint()->rotate(BodyRectRef);

}

void Blender::move(int step, bool isVerical){}


Envelope::Envelope(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	BodyRectRef = ref;
	TopRectRef = { ref.x, ref.y - (config.Envelope.TopRectHight) / 2 };
	UpperTriRightRef = { ref.x + (config.Envelope.TopRectWidth) / 2,ref.y - (config.Envelope.BodyRectHight) / 2 };
	UpperTriLeftRef = { ref.x - (config.Envelope.TopRectWidth) / 2,ref.y - (config.Envelope.BodyRectHight) / 2 };
	//=================================================================================
	BodyRect = new Rect(pGame, BodyRectRef, config.Envelope.BodyRectHight, config.Envelope.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Envelope.TopRectHight, config.Envelope.TopRectWidth);
	TriRight = new Right_triangle(pGame, UpperTriRightRef, config.Envelope.TriWidth, config.Envelope.TriHeight);
	TriLeft = new Right_triangle(pGame, UpperTriLeftRef, -config.Envelope.TriWidth, config.Envelope.TriHeight);
}


void Envelope::draw() 

{
	BodyRect->SetColor(BROWN);
	BodyRect->draw();
	TopRect->SetColor(BROWN);
	TopRect->draw();
	TriRight->SetColor(BROWN);
	TriRight->draw();
	TriLeft->SetColor(BROWN);
	TriLeft->draw();
}

void Envelope::rotate()
{
	BodyRect->rotate();
	TopRect->getLowerBottom()->rotate(BodyRectRef);
	TopRect->getUpperLeft()->rotate(BodyRectRef);
	TriRight->getUpperPoint()->rotate(BodyRectRef);
	TriRight->getleftLower()->rotate(BodyRectRef);
	TriRight->getrightLowerPoint()->rotate(BodyRectRef);
	TriLeft->getUpperPoint()->rotate(BodyRectRef);
	TriLeft->getleftLower()->rotate(BodyRectRef);
	TriLeft->getrightLowerPoint()->rotate(BodyRectRef);
}

void Envelope::move(int step, bool isVerical){}


Cap::Cap(game* r_pGame, point ref) :shape(r_pGame, ref) {

	MidTriRef = ref;
	TopCircleRef = { ref.x,ref.y - config.Cap.midTriHeight };
	BaseRectRef = { ref.x, ref.y + config.Cap.baseRectHeight / 2 };

	//=========================================================================================
	midTri = new Isso_triangle(pGame, MidTriRef, config.Cap.midTriHeight, config.Cap.midTriHeight);
	topCircle = new circle(pGame, TopCircleRef, config.Cap.topCircleRad);
	baseRect = new Rect(pGame, BaseRectRef, config.Cap.baseRectHeight, config.Cap.baseRectWidth);

}


void Cap::draw() 

{
	midTri->SetColor(PINK);
	midTri->draw();
	topCircle->SetColor(PINK);
	topCircle->draw();
	baseRect->SetColor(PINK);
	baseRect->draw();

}

void Cap::rotate()
{
	midTri->rotate();
	baseRect->getLowerBottom()->rotate(MidTriRef);
	baseRect->getUpperLeft()->rotate(MidTriRef);
	topCircle->getRefPoint()->rotate(MidTriRef);

}


void Cap::move(int step, bool isVerical){}







void Sign::flip() {}
void House::flip() 
{
	point* mine = base->getLowerBottom();
	head->getUpperPoint()->flip(*base->getLowerBottom());
	//head->getRightLower()->flip(headRef);
	//head->getleftLower()->flip()
	base->getLowerBottom()->flip(*head->getUpperPoint());
}
void I_Shape::flip() {}
void Envelope::flip() {}
void Rocket::flip() {}
void Blender::flip() {}
void Cap::flip() {}