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
void Sign::resizeUp()
{
	//base->resizeUp();
	//top->resizeUp();
	config.sighShape.topHeight *= 2;
	config.sighShape.topWdth *= 2;
	config.sighShape.baseHeight *= 2;
	config.sighShape.baseWdth *= 2;

	// Recalculate reference points
	baseRef = { refpointx, refpointy + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	topRef = { refpointx, refpointy };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::resizeDown()
{
	/*base->resizeDown();
	top->resizeDown();*/
	config.sighShape.topHeight /= 2;
	config.sighShape.topWdth /= 2;
	config.sighShape.baseHeight /= 2;
	config.sighShape.baseWdth /= 2;

	// Recalculate reference points
	baseRef = { refpointx, refpointy + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	topRef = { refpointx, refpointy };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
	
}


ShapeType Sign::getShapeType() { return type = SIGN; }


I_Shape::I_Shape(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	midRef = ref;
	topRef = {ref.x, ref.y - config.I_Shape.midHeight / 2 - config.I_Shape.topHeight / 2};
	baseRef = {ref.x, ref.y + config.I_Shape.baseHeight / 2 + config.I_Shape.midHeight / 2};
	// ==============================================================================
	rect_pMid = new Rect(pGame, midRef, config.I_Shape.midHeight, config.I_Shape.midWdth);
	top = new Rect(pGame, topRef, config.I_Shape.topHeight, config.I_Shape.topWdth);
	base = new Rect(pGame, baseRef, config.I_Shape.baseHeight, config.I_Shape.baseWdth);

}



void I_Shape::rotate()
{
	
}

void I_Shape::move(int step, bool isVerical)
{
	base->move(step,isVerical);
	top->move(step, isVerical);
	rect_pMid->move(step, isVerical);
	midRef.move(step, isVerical);
	
}

void I_Shape::draw() 
{
	base->draw();
	top->draw();
	rect_pMid->draw();
}



void I_Shape::calcCorners() 
{
	base->calcCorners();
	top->calcCorners();
	rect_pMid->calcCorners();
}
void I_Shape::resizeUp()
{
	//base->resizeUp();
	//top->resizeUp();
	//rect_pMid->resizeUp();
	//topRef = { ref.x/2, ((ref.y - config.I_Shape.midHeight / 2 - config.I_Shape.topHeight / 2)/2) };
	config.I_Shape.midHeight *= 2;
	config.I_Shape.topHeight *= 2;
	config.I_Shape.baseHeight *= 2;
	config.I_Shape.baseWdth *= 2;
	config.I_Shape.topWdth *= 2;
	config.I_Shape.midWdth *= 2;
	point midRef = { refpointx, refpointy };
	point topRef = { refpointx, refpointy - config.I_Shape.midHeight / 2 - config.I_Shape.topHeight / 2 };
	point baseRef = { refpointx, refpointy + config.I_Shape.baseHeight / 2 + config.I_Shape.midHeight / 2 };
	rect_pMid = new Rect(pGame, midRef, config.I_Shape.midHeight, config.I_Shape.midWdth);
	top = new Rect(pGame, topRef, config.I_Shape.topHeight, config.I_Shape.topWdth);
	base = new Rect(pGame, baseRef, config.I_Shape.baseHeight, config.I_Shape.baseWdth);
	calcCorners();
}

void I_Shape::resizeDown()
{
	/*base->resizeDown();
	top->resizeDown();
	rect_pMid->resizeDown();*/
	config.I_Shape.midHeight /= 2;
	config.I_Shape.topHeight /= 2;
	config.I_Shape.baseHeight /= 2;
	config.I_Shape.baseWdth /= 2;
	config.I_Shape.topWdth /= 2;
	config.I_Shape.midWdth /= 2;
	point midRef = { refpointx, refpointy };
	point topRef = { refpointx, refpointy - config.I_Shape.midHeight / 2 - config.I_Shape.topHeight / 2 };
	point baseRef = { refpointx, refpointy + config.I_Shape.baseHeight / 2 + config.I_Shape.midHeight / 2 };
	rect_pMid = new Rect(pGame, midRef, config.I_Shape.midHeight, config.I_Shape.midWdth);
	top = new Rect(pGame, topRef, config.I_Shape.topHeight, config.I_Shape.topWdth);
	base = new Rect(pGame, baseRef, config.I_Shape.baseHeight, config.I_Shape.baseWdth);
	calcCorners();
}

ShapeType I_Shape::getShapeType() { return type = I; }
cHouse::cHouse(game* r_pGame, point ref) : shape(r_pGame, ref)
{
	baseRef = ref;
	headRef = { ref.x, ref.y - config.House.baseHeight / 2 };
	// ===================================================================
	base = new Rect(pGame, baseRef, config.House.baseHeight, config.House.baseWidth);
	head = new Isso_triangle(pGame, headRef, config.House.headBase, config.House.headHeight);
	//test = new circle(pGame, headRef, 50);
}

void cHouse::draw()
{

	base->draw();
	head->SetColor(BLUE);
	head->draw();
	
	//test->draw();
}

void cHouse::calcCorners() 
{
	head->calcCorners();
	base->calcCorners();
}

void rocket::calcCorners() {}
void Blender::calcCorners() {}
void Envelope::calcCorners() {}
void Cap::calcCorners() {}

void cHouse::rotate()
{
	base->rotate();
	//head->rotate();

	head->getRightLower()->rotate(baseRef);
	head->getleftLower()->rotate(baseRef);
	head->getUpperPoint()->rotate(baseRef);

}
void cHouse::resizeUp()
{
	config.House.headBase *= 2;
	config.House.baseWidth *= 2;
	config.House.headHeight *= 2;
	config.House.baseHeight *= 2;
	headRef = { refpointx, refpointy - config.House.baseHeight /2 };
	// ===================================================================
	
	//draw();

	calcCorners();
}

void cHouse::resizeDown()
{
	/*ؤint resizeFactor = 0.5; // Decrease size by factor of 0.5

	// Update base dimensions
	base->resizeDown();

	// Update head reference point based on base resize
	int newHeadY = headRef.y + (config.House.baseHeight * resizeFactor) / 2;
	headRef = { headRef.x, newHeadY };

	// Resize head triangle
	head->resizeDown();*/
	head->resizeDown();
	base->resizeDown();
	config.House.headBase /= 2;
	config.House.baseWidth/=2;
	config.House.headHeight/=2;
	config.House.baseHeight /= 2;
	headRef = { refpointx, refpointy - config.House.baseHeight / 2 };
	// ===================================================================
	
	//draw();
	
	calcCorners();
}

void cHouse::move(int step, bool isVerical) 
{
	head->move(step, isVerical);
	base->move(step, isVerical);
	baseRef.move(step, isVerical);
}

ShapeType cHouse::getShapeType() { return type = House; }


rocket::rocket(game* r_pGame, point ref) : shape(r_pGame, ref)
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
void rocket::draw()  {
	baseRect->SetColor(BLACK);
	baseRect->draw();
	headIsso->SetColor(BLACK);
	headIsso->draw();
	triangle_pBottomRight->SetColor(BLACK);
	triangle_pBottomRight->draw();
	triangle_pBottomLeft->SetColor(BLACK);
	triangle_pBottomLeft->draw();

}

void rocket::rotate()
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
void rocket::resizeUp()
{
	baseRect->resizeUp();
	headIsso->resizeUp();
	triangle_pBottomRight->resizeUp();
	triangle_pBottomLeft->resizeUp();
	config.Rocket_Shape.baseRectHeight *= 2;
	config.Rocket_Shape.baseRectWidth *= 2;
	config.Rocket_Shape.headTriBase *= 2;
	config.Rocket_Shape.headTriHeight *= 2;
	config.Rocket_Shape.LowerRightTriWidth *= 2;
	config.Rocket_Shape.LowerRightTriHeight *= 2;
	point headTriRef = { refpointx, refpointy - (config.Rocket_Shape.baseRectHeight) / 2 };
	point RightLowerTriRef = { refpointx + (config.Rocket_Shape.baseRectWidth) / 2, refpointy + (config.Rocket_Shape.baseRectHeight) / 2 };
	point LeftLowerTriRef = { refpointx - (config.Rocket_Shape.baseRectWidth) / 2, refpointy + (config.Rocket_Shape.baseRectHeight) / 2 };
	baseRect = new Rect(pGame, baseRectRef, config.Rocket_Shape.baseRectHeight, config.Rocket_Shape.baseRectWidth);
	headIsso = new Isso_triangle(pGame, headTriRef, config.Rocket_Shape.headTriBase, config.Rocket_Shape.headTriHeight);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Rocket_Shape.LowerRightTriWidth, config.Rocket_Shape.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Rocket_Shape.LowerRightTriWidth), config.Rocket_Shape.LowerRightTriHeight);

	
	calcCorners();
}

void rocket::resizeDown()
{
	/*baseRect->resizeDown();
	headIsso->resizeDown();
	triangle_pBottomRight->resizeDown();
	triangle_pBottomLeft->resizeDown();*/
	config.Rocket_Shape.baseRectHeight /= 2;
	config.Rocket_Shape.baseRectWidth /= 2;
	config.Rocket_Shape.headTriBase /= 2;
	config.Rocket_Shape.headTriHeight /= 2;
	config.Rocket_Shape.LowerRightTriWidth /= 2;
	config.Rocket_Shape.LowerRightTriHeight /= 2;
	point headTriRef = { refpointx, refpointy - (config.Rocket_Shape.baseRectHeight) / 2 };
	point RightLowerTriRef = { refpointx + (config.Rocket_Shape.baseRectWidth) / 2, refpointy + (config.Rocket_Shape.baseRectHeight) / 2 };
	point LeftLowerTriRef = { refpointx - (config.Rocket_Shape.baseRectWidth) / 2, refpointy + (config.Rocket_Shape.baseRectHeight) / 2 };
	baseRect = new Rect(pGame, baseRectRef, config.Rocket_Shape.baseRectHeight, config.Rocket_Shape.baseRectWidth);
	headIsso = new Isso_triangle(pGame, headTriRef, config.Rocket_Shape.headTriBase, config.Rocket_Shape.headTriHeight);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Rocket_Shape.LowerRightTriWidth, config.Rocket_Shape.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Rocket_Shape.LowerRightTriWidth), config.Rocket_Shape.LowerRightTriHeight);

	
	calcCorners();
}


void rocket::move(int step, bool isVerical)
{
}

ShapeType rocket::getShapeType() { return type = Rocket; }

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
void Blender::resizeUp()
{
	/*BodyRect->resizeUp();
	TopRect->resizeUp();
	TopCircle->resizeUp();
	LowerRect->resizeUp();
	triangle_pBottomRight->resizeUp();
	triangle_pBottomLeft->resizeUp();*/
	config.Blender.BodyRectHeight *= 2;
	config.Blender.BodyRectWidth *= 2;
	config.Blender.TopRectHight *= 2;
	config.Blender.TopRectWidth *= 2;
	config.Blender.TopCircleRad *= 2;
	config.Blender.LowerRectHeight *= 2;
	config.Blender.LowerRectWidth *= 2;
	config.Blender.LowerRightTriWidth *= 2;
	config.Blender.LowerRightTriHeight *= 2;

	point TopRectRef = { refpointx, refpointy - (config.Blender.TopRectHight) / 2 };
	point TopCircleRef = { refpointx, refpointy - ((config.Blender.BodyRectHeight / 2) + config.Blender.TopRectHight + (config.Blender.TopCircleRad / 8)) };
	point LowerRectRef = { refpointx, refpointy + (config.Blender.BodyRectHeight) / 2 };
	point RightLowerTriRef = { refpointx + (config.Blender.BodyRectWidth) / 2, refpointy + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	point LeftLowerTriRef = { refpointx - (config.Blender.BodyRectWidth) / 2, refpointy + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	BodyRect = new Rect(pGame, BodyRectRef, config.Blender.BodyRectHeight, config.Blender.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Blender.TopRectHight, config.Blender.TopRectWidth);
	TopCircle = new circle(pGame, TopCircleRef, config.Blender.TopCircleRad);
	LowerRect = new Rect(pGame, LowerRectRef, config.Blender.LowerRectHeight, config.Blender.LowerRectWidth);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Blender.LowerRightTriWidth, config.Blender.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Blender.LowerRightTriWidth), config.Blender.LowerRightTriHeight);
	calcCorners();
}
void Blender::resizeDown()
{
	/*BodyRect->resizeDown();
	TopRect->resizeDown();
	TopCircle->resizeDown();
	LowerRect->resizeDown();
	triangle_pBottomRight->resizeDown();
	triangle_pBottomLeft->resizeDown();*/
	config.Blender.BodyRectHeight /= 2;
	config.Blender.BodyRectWidth /= 2;
	config.Blender.TopRectHight /= 2;
	config.Blender.TopRectWidth /= 2;
	config.Blender.TopCircleRad /= 2;
	config.Blender.LowerRectHeight /= 2;
	config.Blender.LowerRectWidth /= 2;
	config.Blender.LowerRightTriWidth /= 2;
	config.Blender.LowerRightTriHeight /= 2;
	point TopRectRef = { refpointx, refpointy - (config.Blender.TopRectHight) / 2 };
	point TopCircleRef = { refpointx, refpointy - ((config.Blender.BodyRectHeight/2 ) + config.Blender.TopRectHight + (config.Blender.TopCircleRad/8 )) };
	point LowerRectRef = { refpointx, refpointy + (config.Blender.BodyRectHeight) / 2 };
	point RightLowerTriRef = { refpointx + (config.Blender.BodyRectWidth) / 2, refpointy + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	point LeftLowerTriRef = { refpointx - (config.Blender.BodyRectWidth) / 2, refpointy + ((config.Blender.BodyRectHeight) / 2) + config.Blender.LowerRectHeight / 2 };
	BodyRect = new Rect(pGame, BodyRectRef, config.Blender.BodyRectHeight, config.Blender.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Blender.TopRectHight, config.Blender.TopRectWidth);
	TopCircle = new circle(pGame, TopCircleRef, config.Blender.TopCircleRad);
	LowerRect = new Rect(pGame, LowerRectRef, config.Blender.LowerRectHeight, config.Blender.LowerRectWidth);
	triangle_pBottomRight = new Right_triangle(pGame, RightLowerTriRef, config.Blender.LowerRightTriWidth, config.Blender.LowerRightTriHeight);
	triangle_pBottomLeft = new Right_triangle(pGame, LeftLowerTriRef, -(config.Blender.LowerRightTriWidth), config.Blender.LowerRightTriHeight);
	calcCorners();

}

ShapeType Blender::getShapeType() { return type = blender; }

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
void Envelope::resizeUp()
{
	/*BodyRect->resizeUp();
	TopRect->resizeUp();
	TriRight->resizeUp();
	TriLeft->resizeUp();*/
	config.Envelope.BodyRectHight *= 2;
	config.Envelope.BodyRectWidth *= 2;
	config.Envelope.TopRectHight *= 2;
	config.Envelope.TopRectWidth *= 2;
	config.Envelope.TriWidth *= 2;
	config.Envelope.TriHeight *= 2;

	point TopRectRef = { refpointx, refpointy - (config.Envelope.TopRectHight) / 2 };
	point UpperTriRightRef = { refpointx + (config.Envelope.TopRectWidth) / 2, refpointy - (config.Envelope.BodyRectHight) / 2 };
	point UpperTriLeftRef = { refpointx - (config.Envelope.TopRectWidth) / 2, refpointy - (config.Envelope.BodyRectHight) / 2 };
	BodyRect = new Rect(pGame, BodyRectRef, config.Envelope.BodyRectHight, config.Envelope.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Envelope.TopRectHight, config.Envelope.TopRectWidth);
	TriRight = new Right_triangle(pGame, UpperTriRightRef, config.Envelope.TriWidth, config.Envelope.TriHeight);
	TriLeft = new Right_triangle(pGame, UpperTriLeftRef, -config.Envelope.TriWidth, config.Envelope.TriHeight);
	calcCorners();
}
void Envelope::resizeDown()
{
	/*BodyRect->resizeDown();
	TopRect->resizeDown();
	TriRight->resizeDown();
	TriLeft->resizeDown();*/
	config.Envelope.BodyRectHight /= 2;
	config.Envelope.BodyRectWidth /= 2;
	config.Envelope.TopRectHight /= 2;
	config.Envelope.TopRectWidth /= 2;
	config.Envelope.TriWidth /= 2;
	config.Envelope.TriHeight /= 2;

	point TopRectRef = { refpointx, refpointy - (config.Envelope.TopRectHight) / 2 };
	point UpperTriRightRef = { refpointx + (config.Envelope.TopRectWidth) / 2, refpointy - (config.Envelope.BodyRectHight) / 2 };
	point UpperTriLeftRef = { refpointx - (config.Envelope.TopRectWidth) / 2, refpointy - (config.Envelope.BodyRectHight) / 2 };
	BodyRect = new Rect(pGame, BodyRectRef, config.Envelope.BodyRectHight, config.Envelope.BodyRectWidth);
	TopRect = new Rect(pGame, TopRectRef, config.Envelope.TopRectHight, config.Envelope.TopRectWidth);
	TriRight = new Right_triangle(pGame, UpperTriRightRef, config.Envelope.TriWidth, config.Envelope.TriHeight);
	TriLeft = new Right_triangle(pGame, UpperTriLeftRef, -config.Envelope.TriWidth, config.Envelope.TriHeight);
	calcCorners();
}

void Envelope::move(int step, bool isVerical){}
ShapeType Envelope::getShapeType() { return type = envelop; }

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
void Cap::resizeUp()
{
	/*midTri->resizeUp();
	topCircle->resizeUp();
	baseRect->resizeUp();*/
	config.Cap.midTriHeight *= 2;
	config.Cap.topCircleRad *= 2;
	config.Cap.baseRectHeight *= 2;
	config.Cap.baseRectWidth *= 2;

	point MidTriRef = {refpointx, refpointy};
	point TopCircleRef = { refpointx, refpointy - config.Cap.midTriHeight };
	point BaseRectRef = { refpointx, refpointy + config.Cap.baseRectHeight / 2 };
	midTri = new Isso_triangle(pGame, MidTriRef, config.Cap.midTriHeight, config.Cap.midTriHeight);
	topCircle = new circle(pGame, TopCircleRef, config.Cap.topCircleRad);
	baseRect = new Rect(pGame, BaseRectRef, config.Cap.baseRectHeight, config.Cap.baseRectWidth);
	calcCorners();
}

void Cap::resizeDown()
{
	/*midTri->resizeDown();
	topCircle->resizeDown();
	baseRect->resizeDown();*/
	config.Cap.midTriHeight /= 2;
	config.Cap.topCircleRad /= 2;
	config.Cap.baseRectHeight /= 2;
	config.Cap.baseRectWidth /= 2;

	point MidTriRef = { refpointx, refpointy };
	point TopCircleRef = { refpointx, refpointy - config.Cap.midTriHeight };
	point BaseRectRef = { refpointx, refpointy + config.Cap.baseRectHeight / 2 };
	midTri = new Isso_triangle(pGame, MidTriRef, config.Cap.midTriHeight, config.Cap.midTriHeight);
	topCircle = new circle(pGame, TopCircleRef, config.Cap.topCircleRad);
	baseRect = new Rect(pGame, BaseRectRef, config.Cap.baseRectHeight, config.Cap.baseRectWidth);
	calcCorners();

}


void Cap::move(int step, bool isVerical){}

ShapeType Cap::getShapeType() { return type = cap; }





void Sign::flip() {}
void cHouse::flip()
{
	point* mine = base->getLowerBottom();
	head->getUpperPoint()->flip(*base->getLowerBottom());
	base->getLowerBottom()->flip(*head->getUpperPoint());
}


void I_Shape::flip()
{

}
void Envelope::flip() 
{

}

void rocket::flip() {}
void Blender::flip() {}
void Cap::flip() {}
//save collection by ebrahim3
//=====================================================
void Cap::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 10 << endl;
	OutFile << MidTriRef.x << endl;
	OutFile << MidTriRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void Envelope::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 20 << endl;
	OutFile << BodyRectRef.x << endl;
	OutFile << BodyRectRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void Blender::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 30 << endl;
	OutFile << BodyRectRef.x << endl;
	OutFile << BodyRectRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void rocket::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 40 << endl;
	OutFile << baseRectRef.x << endl;
	OutFile << baseRectRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void cHouse::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 50 << endl;
	OutFile << baseRef.x << endl;
	OutFile << baseRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void I_Shape::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 60 << endl;
	OutFile << midRef.x << endl;
	OutFile << midRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
void Sign::save(ofstream& OutFile) {
	OutFile.open("savedata.txt");
	OutFile << 70 << endl;
	OutFile << topRef.x << endl;
	OutFile << topRef.y << endl;
	OutFile << iResizeCalls << endl;
	OutFile << iRotationAngle << endl;
	OutFile.close();
}
