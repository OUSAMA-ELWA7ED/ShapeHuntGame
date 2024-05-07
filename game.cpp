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

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
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
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case ITM_I:
		op = new operAddI_Shape(this);
		break;
	case ITM_HOUSE:
		op = new operAddHouse(this);
		break;
	case ITM_ROTATE:
		op = new operMakeRotation(this);
		break;
	case ITM_HINT:
		op = new operDeleteThisShape(this);
		break;
	case ITM_Rocket:
		op = new operAddRocket(this);
		break;
	case ITM_Blender:
		op = new operAddBlender(this);
		break;
	case ITM_Env:
		op = new operAddEnv(this);
		break;
	case ITM_Cap:
		op = new operAddCap(this);
		break;
		
	}
	

	return op;
}

//operation* game::createMoveOperation(keytype clickedArrow)
//{
//	char cKeyData = clickedArrow;
//	//operation* op2 = nullptr;
//	switch (cKeyData)
//	{
//	case 1:
//		//testWindow.DrawString(5, 30, "The End key was pressed.");
//
//		break;
//	case 2:
//		//testWindow.DrawString(5, 30, "The Down Arrow key was pressed.");
//
//		break;
//	case 3:
//		//testWindow.DrawString(5, 30, "The Page Down key was pressed.");
//		break;
//	case 4:
//		//testWindow.DrawString(5, 30, "The Left Arrow key was pressed.");
//		break;
//	case 5:
//		//testWindow.DrawString(5, 30, "The Center Keypad key was pressed.");
//		break;
//	case 6:
//		//testWindow.DrawString(5, 30, "The Right Arrow key was pressed.");
//		break;
//	case 7:
//		//testWindow.DrawString(5, 30, "The Home key was pressed.");
//		break;
//	case 8:
//		//testWindow.DrawString(5, 30, "The Up Arrow key was pressed.");
//		break;
//	case 9:
//		//testWindow.DrawString(5, 30, "The Page Up key was pressed.");
//	}
//	return op2;
//}

//////////////////////////////////////////////////////////////////////////////////////////

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
		ktype = pWind->GetKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13) {
			Label = "Enter";//ENTER key is pressed
			return Label;
		}
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


//operation* game::createMoveOperation(char cKey)
//{
//	operation* op2 = nullptr;
//
//	
//}



grid* game::getGrid() const
{
	
	// TODO: Add your implementation code here.
	return shapesGrid;
}


#include <iostream>
////////////////////////////////////////////////////////////////////////
void game::run() 
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("MY SHAPE HUNT (CIE 101 project) BY prof Dr Eng 3m_elNas Mohammed Maher ");
	toolbarItem clickedItem=ITM_CNT;
	do
	{
		//printMessage("Ready...");
		//1- Get user click

		
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		
		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem=gameToolbar->getItemClicked(x);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action
			
			shapesGrid->draw();
			pWind->FlushMouseQueue();
			pWind->FlushKeyQueue();
		}
		// you can make an if condition if the move icon clicked make the same operations.
		else // this should Allow you to move the object after clicked anywhere on the grid (away from the toolbar)
		{
			//pWind->SetBuffering(true);
			bool stillMoving = true;
			do {

				//pWind->SetBuffering(true);
				keytype ktinput;
				char anotherKey;
				operMove* op2;

				
				ktinput = pWind->WaitKeyPress(anotherKey);
				op2 = new operMove(this);
				if (ktinput == ARROW) {
					switch (anotherKey)
					{
					case 2:
						//testWindow.DrawString(5, 30, "The Down Arrow key was pressed.");
						op2->RealAct(30, true);
						stillMoving = true;
						break;
					case 4:
						//testWindow.DrawString(5, 30, "The Left Arrow key was pressed.");
						op2->RealAct(-30, false);
						stillMoving = true;
						break;
					case 6:
						//testWindow.DrawString(5, 30, "The Right Arrow key was pressed.");
						op2->RealAct(30, false);
						stillMoving = true;
						break;
					case 8:
						//testWindow.DrawString(5, 30, "The Up Arrow key was pressed.");
						op2->RealAct(-30, true);
						stillMoving = true;
						break;
					}
				
				}
				else if (ktinput == ESCAPE)
				{
					std::cout << ktinput << endl;
					std::cout << "stillMoving is true!" << endl;
					stillMoving = false;
				}


				/*if (ktinput == ASCII) {
					stillMoving = false;
					std::cout << "stillMoving is false" << endl;
					
				}
				else
				{
					std::cout << ktinput << endl;
					std::cout << "stillMoving is true!" << endl;
					stillMoving = true;
				}*/
				
				shapesGrid->draw();
				//pWind->UpdateBuffer();
				pWind->FlushMouseQueue();
				pWind->FlushKeyQueue();
			} while (stillMoving);
			//pWind->SetBuffering(false);

			std::cout << "while is disabled" << endl;

			
		}

		

	} while (clickedItem!=ITM_EXIT);



}






