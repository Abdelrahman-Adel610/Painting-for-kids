#include "PlayRecordAction.h"
#include "..\ApplicationManager.h"
#include<Windows.h>
#include"UndoAction.h"
#include"RedoAction.h"
#include"VoiceAction.h"
#include"SelectAction.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) :Action(pApp)
{
}
void PlayRecordAction::ReadActionParameters()
{

}
void PlayRecordAction::Execute()
{
	pManager->ClearFigList();
	pManager->ResetUndo_RedoActions();
	pManager->UpdateInterface();
	for (int i = 0; i < 20; i++) {
		Action* Record = pManager->getRecord(i);
		if (Record == NULL)	break;
		if (dynamic_cast<RedoAction*>(Record) || dynamic_cast<UndoAction*>(Record))
			Record->Execute();
		else Record->Redo();
		if (!dynamic_cast<SelectAction*>(Record) && !dynamic_cast<RedoAction*>(Record) && !dynamic_cast<UndoAction*>(Record))	pManager->AddUndo_RedoAction(Record);
		pManager->UpdateInterface();
		Sleep(1000);
	}
}
