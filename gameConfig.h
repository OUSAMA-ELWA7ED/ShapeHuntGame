#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"
#include <time.h>
#include <cstdlib>


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	
	
	int RefX = windWidth *  (1.0 / 3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;

	struct {
		int baseWdth = 80, baseHeight = 20;
		int topWdth = 80, topHeight = 20;
		int midWdth = 30, midHeight = 70;
	}I_Shape;

	struct {
		int baseWidth = 90, baseHeight = 50;
		int headBase = baseWidth, headHeight = 70;
	}House;

	struct {
		int baseRectWidth = 30, baseRectHeight = 80;
		int headTriBase = baseRectWidth, headTriHeight = 40;
		int LowerRightTriWidth = 20, LowerRightTriHeight = 30;
	}Rocket_Shape;
	struct {
		int BodyRectWidth = 60, BodyRectHeight = 150;
		int TopRectWidth = 80, TopRectHight = 10;
		int TopCircleRad = 10;
		int LowerRectWidth = 90, LowerRectHeight = 40;
		int LowerRightTriWidth = 40, LowerRightTriHeight = 40;
	}Blender;
	struct
	{
		int TopRectWidth = 50, TopRectHight = 60;
		int BodyRectWidth = 100, BodyRectHight = 50;
		int TriWidth = 25, TriHeight = 35;
	}Envelope;
	struct
	{
		int baseRectWidth = 80, baseRectHeight = 15;
		int midTriWidth = 60, midTriHeight = 70;
		int topCircleRad = 15;

	}Cap;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here


	ITM_INCR,
	ITM_ROTATE,
	ITM_HINT,
	ITM_RELOAD,
	ITM_LVLS,
	ITM_DCR, //Sign shape item
	ITM_EXIT,		//Exit item
	ITM_SIGN,
	ITM_I,
	ITM_HOUSE,
	ITM_Rect,
	ITM_Rocket,
	ITM_Blender,
	ITM_Env,
	ITM_Cap,
	//TODO: Add more items names here
	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};

enum ARROWS
{
	LeftArrow = 37,
	UpArrow,
	RightArrow,
	DownArrow,
};

