#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_DRAW_DRAW_CLR,	
	MODE_DRAW_FILLCLR,	
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,		//CIRCLE item in menu
	ITM_SQUARE,     //SQUARE item in menu
	ITM_TRIANGLE,   //TRIANGLE item in menu
	ITM_HEX,		//hexagon item in menu
	ITM_SELECT,     //Select figure
	ITM_COLORd,      //CHANGE color
	ITM_COLORf,
	ITM_MOVE,       //move figuers
	ITM_DRAG,
	ITM_DELETE,     //delete figuers
	ITM_UNDO,		//undo item in menu
	ITM_REDO,		//Redo item
	ITM_CLEAR,      //delete all figuers
	ITM_RECORD,     //start recording
	ITM_STOP_RECORDING,       //stop recording
	ITM_PLAY_RECORD,       //play record
	ITM_SAVEGRAPH,  //save graph
	ITM_LOADGRAPH,  //load graph
	ITM_VOICE,
	ITM_PLAY_MODE,    //switch to play mode
	ITM_EXIT1,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_PICK_FIGURE,
	ITM_PICK_COLOR,
	ITM_PICK_COLORED_FIGURE,
	ITM_RESET,
	ITM_VOICE1,
	ITM_DRAW_MODE,
	ITM_EXIT2,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum Colors
{
	orange,
	red,
	green,
	blue,
	yellow,
	black

};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif