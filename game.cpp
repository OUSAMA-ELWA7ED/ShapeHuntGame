#include "game.h"
#include "gameConfig.h"



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();

}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y)
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}


void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op = nullptr;
case ITM_SIGN:
	op = new operAddSign(this);
	game::printMessage("You Clicked on 'Add Sign Shape'");
	break;
case ITM_I:
	op = new operAddI_Shape(this);
	game::printMessage("You Clicked on 'Add I Shape'");
	break;
case ITM_HOUSE:
	op = new operAddHouse(this);
	game::printMessage("You Clicked on 'Add House Shape'");
	break;
//by ebrahim
case ITM_Rocket:
	op = new operAddRocket(this);
	game::printMessage("You Clicked on 'Add Rocket Shape'");
	break;
case ITM_Blender:
	op = new operAddBlender(this);
	game::printMessage("You Clicked on 'Add Blender Shape'");
	break;
case ITM_Env:
	op = new operAddEnv(this);
	game::printMessage("You Clicked on 'Add Env Shape'");
	break;
case ITM_Cap:
	op=new operAddCap(this);
	game::printMessage("You Clicked on 'Add Cap Shape'");
	break;
case ITM_ROTATE:
	op = new operMakeRotation(this);
	game::printMessage("You Clicked on 'Rotate' Operation");
	break;
case ITM_DCR:
	op = new operResizeDown(this);
	game::printMessage("You Clicked on 'Resize Down' Operation");
	break;
case ITM_INCR:
	op = new operResizeUp(this);
	game::printMessage("You Clicked on 'Resize Up' Operation");
	break;
case ITM_EXIT:
	op = new operExit(this);
	break;
case ITM_HNT:
	op = new operDeleteThisShape(this);
	game::printMessage("You Clicked on 'Hint' Operation");
	break;
case ITM_DEL:
	op = new operDeleteThisShape(this);
	game::printMessage("You Clicked on 'Delete' Operation");
	break;
	}
	return op;
}




void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}




Levels* game::getLevel()
{
	return lvl;
}

void game::setLevel(Levels level)
{
	lvl = new Levels(level);
}

void game::run()
{
	int x, y;
	bool isExit = false;
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem = ITM_CNT;
	setLevel(LVL1);
	operation* buildRandShape = new BuildRandomShape(this);
	buildRandShape->Act();
	
	//operation* buildRandShape = new RandomShape(this)
	do
	{
		pWind->WaitMouseClick(x, y);
		//new by ebrahim2
		gameToolbar->GameStat();
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();
			shapesGrid->draw();
			pWind->FlushMouseQueue();
			pWind->FlushKeyQueue();

		}

		else
		{
			bool stillMoving = true;
			bool isItVertical;
			do {


				int step = config.gridSpacing;
				keytype ktinput;
				char anotherKey;
				pWind->FlushMouseQueue();
				pWind->FlushKeyQueue();


				ktinput = pWind->WaitKeyPress(anotherKey);
				operMove* pMove = new operMove(this);
				if (ktinput == ARROW) {
					switch (anotherKey)
					{
					case 2: // down
						isItVertical = true;
						pMove->isItVertical(isItVertical);
						pMove->moveStep(step);
						pMove->Act();
						stillMoving = true;
						break;
					case 4: // Left
						isItVertical = false;
						pMove->isItVertical(isItVertical);
						pMove->moveStep(-step);
						pMove->Act();
						stillMoving = true;
						break;
					case 6: // right
						isItVertical = false;
						pMove->isItVertical(isItVertical);
						pMove->moveStep(step);
						pMove->Act();
						stillMoving = true;
						break;
					case 8: //up
						isItVertical = true;
						pMove->isItVertical(isItVertical);
						pMove->moveStep(-step);
						pMove->Act();
						stillMoving = true;
						break;
					}

				}
				else if (ktinput == ESCAPE)
				{
					stillMoving = false;
				}

				shapesGrid->draw();

			} while (stillMoving);
		}

	} while (clickedItem != ITM_EXIT);
}
