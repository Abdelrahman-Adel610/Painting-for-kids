
#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,
	DRAW_SQUARE,
	DRAW_TRIANGLE,
	DRAW_HEX,
	SELECT_FIGURE,
	CHANGE_DRAW_CLR,
	CHANGE_FILL_CLR,
	CHANGE_COLOR_dBLACK,
	CHANGE_COLOR_dRED,
	CHANGE_COLOR_dORANGE,
	CHANGE_COLOR_dBLUE,
	CHANGE_COLOR_dGREEN,
	CHANGE_COLOR_dYELLOW,
	CHANGE_COLOR_fBLACK,
	CHANGE_COLOR_fRED,
	CHANGE_COLOR_fORANGE,
	CHANGE_COLOR_fBLUE,
	CHANGE_COLOR_fGREEN,
	CHANGE_COLOR_fYELLOW,
	MOVE_FIGURE,
	DRAG_TO_MOVE,
	DELETE_FIGURE,
	UNDO,
	REDO,
	CLEAR,
	START_RECORDING,
	STOP_RECORDING,
	PLAY_RECORD,
	SAVE_GRAPH,
	LOAD_GRAPH,
	ENABLE_VOICE,
	PICK_FIGURE,
	PICK_COLOR,
	PICK_COLORED_FIGURE,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	RESET,
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar
	
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif