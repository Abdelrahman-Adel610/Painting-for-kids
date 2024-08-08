#include"ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ClearAllAction::ReadActionParameters()
{}

void ClearAllAction::Execute()
{
	pManager->UnSelect();              //Release the Selected shape ptr             
	pManager->ResetUndo_RedoActions(); //Clean the undo & Redo Array
	pManager->ResetRecordList();	   //Clean the Record Array
	pManager->ClearFigList();		   //Clean The Figure list
	
}


