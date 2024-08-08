#include "StopRecordAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
StopRecordAction::StopRecordAction(ApplicationManager* pApp):Action(pApp)
{

}

void StopRecordAction::ReadActionParameters()
{

}

void StopRecordAction::Execute()
{
	if (pManager->GetModRecord()) {
		pManager->DModRecord();
		pManager->GetOutput()->PrintMessage("Recorad Has Been Ended");
		Point p;
		pManager->GetInput()->GetPointClicked(p.x, p.y);
	}
}
