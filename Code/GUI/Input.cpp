#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->FlushMouseQueue();
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);

	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEX: return DRAW_HEX;
			case ITM_SELECT: return SELECT_FIGURE;
			case ITM_COLORd:return CHANGE_DRAW_CLR;
			case ITM_COLORf:return CHANGE_FILL_CLR;
			case ITM_MOVE: return MOVE_FIGURE;
			case ITM_DRAG: return DRAG_TO_MOVE;
			case ITM_DELETE: return DELETE_FIGURE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_CLEAR: return CLEAR;
			case ITM_RECORD: return START_RECORDING;
			case ITM_STOP_RECORDING: return STOP_RECORDING;
			case ITM_PLAY_RECORD: return PLAY_RECORD;
			case ITM_SAVEGRAPH: return SAVE_GRAPH;
			case ITM_LOADGRAPH: return LOAD_GRAPH;
			case ITM_VOICE:return ENABLE_VOICE;
			case ITM_PLAY_MODE: return TO_PLAY;
			case ITM_EXIT1: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PICK_FIGURE: return PICK_FIGURE;
			case ITM_PICK_COLOR: return PICK_COLOR;
			case ITM_PICK_COLORED_FIGURE: return PICK_COLORED_FIGURE;
			case ITM_RESET:return RESET;
			case ITM_VOICE1:return ENABLE_VOICE;
			case ITM_DRAW_MODE: return TO_DRAW;
			case ITM_EXIT2: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}

		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	else if (UI.InterfaceMode == MODE_DRAW_DRAW_CLR)	//GUI is in PLAY mode
	{

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEX: return DRAW_HEX;
			case ITM_SELECT: return SELECT_FIGURE;
			case ITM_COLORd:
				if (y <= 23)
				{
					if (x <= 314)
						return CHANGE_COLOR_dBLACK;
					else if (x <= 328)
						return CHANGE_COLOR_dRED;
					else if (x <= 342)
						return CHANGE_COLOR_dORANGE;
				}
				else
				{
					if (x <= 314)
						return CHANGE_COLOR_dBLUE;
					else if (x <= 328)
						return CHANGE_COLOR_dGREEN;
					else if (x <= 342)
						return CHANGE_COLOR_dYELLOW;
				}
			case ITM_COLORf:return CHANGE_FILL_CLR;
			case ITM_MOVE: return MOVE_FIGURE;
			case ITM_DRAG: return DRAG_TO_MOVE;
			case ITM_DELETE: return DELETE_FIGURE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_CLEAR: return CLEAR;
			case ITM_RECORD: return START_RECORDING;
			case ITM_STOP_RECORDING: return STOP_RECORDING;
			case ITM_PLAY_RECORD: return PLAY_RECORD;
			case ITM_SAVEGRAPH: return SAVE_GRAPH;
			case ITM_LOADGRAPH: return LOAD_GRAPH;
			case ITM_VOICE:return ENABLE_VOICE;
			case ITM_PLAY_MODE: return TO_PLAY;
			case ITM_EXIT1: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	else if (UI.InterfaceMode == MODE_DRAW_FILLCLR)	
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEX: return DRAW_HEX;
			case ITM_SELECT: return SELECT_FIGURE;
			case ITM_COLORd:return CHANGE_DRAW_CLR;
			case ITM_COLORf:
				if (y <= 23)
				{
					if (x <= 364)
						return CHANGE_COLOR_fBLACK;
					else if (x <= 378)
						return CHANGE_COLOR_fRED;
					else if (x <= 392)
						return CHANGE_COLOR_fORANGE;
				}
				else
				{
					if (x <= 364)
						return CHANGE_COLOR_fBLUE;
					else if (x <= 378)
						return CHANGE_COLOR_fGREEN;
					else if (x <= 392)
						return CHANGE_COLOR_fYELLOW;
				}
			case ITM_MOVE: return MOVE_FIGURE;
			case ITM_DRAG: return DRAG_TO_MOVE;
			case ITM_DELETE: return DELETE_FIGURE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_CLEAR: return CLEAR;
			case ITM_RECORD: return START_RECORDING;
			case ITM_STOP_RECORDING: return STOP_RECORDING;
			case ITM_PLAY_RECORD: return PLAY_RECORD;
			case ITM_SAVEGRAPH: return SAVE_GRAPH;
			case ITM_LOADGRAPH: return LOAD_GRAPH;
			case ITM_VOICE:return ENABLE_VOICE;
			case ITM_PLAY_MODE: return TO_PLAY;
			case ITM_EXIT1: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		//if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		//{
		//	return DRAWING_AREA;
		//}

		////[3] User clicks on the status bar
		//return STATUS;
	}
}
bool Input::IsClicked(int& x, int& y)
{
	return pWind->GetButtonState(LEFT_BUTTON,x,y);
	
}
void Input::GetMouseCoord(int& x, int& y)
{
	pWind->GetMouseCoord(x, y);
}
Input::~Input()
{
}

