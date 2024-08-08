#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	static bool isFilled;           //Flag Needed for change filling action && AddFig 
	bool IsRecorded;				//Flag to know if the action is recorded
	bool IsExcuted;					//Flag to know if the action completely excuted successfully
public:
	bool getExcutionState();
	Action(ApplicationManager* pApp) { pManager = pApp; IsRecorded = false; IsExcuted = true; }	//constructor
	
	virtual void ReadActionParameters() =0; //Reads parameters required for action to execute (code depends on action type)
	virtual void Execute() =0;             	//Execute action (code depends on action type)
	virtual void Redo();					//Redo action (code depends on some action type) not all action have Redo
	virtual void Undo();                    //Undo action (code depends on some action type) not all action have Undo
	bool getRecorded()const;               //to get recording state
	void setRecorded(bool b);			   //to set recording state
};
#endif
