#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H
#include "..\Figures\CHexagon.h"
#include "Action.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	int id;
	Point P1; //Hexagon Center
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
};

#endif