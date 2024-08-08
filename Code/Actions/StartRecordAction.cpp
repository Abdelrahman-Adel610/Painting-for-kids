#include "StartRecordAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
StartRecordAction::StartRecordAction(ApplicationManager* pApp):Action(pApp)
{

}

void StartRecordAction::ReadActionParameters()
{

}

void StartRecordAction::Execute()
{
	if (pManager->GetLastFigID() == 0) {
		pManager->AModRecord();
		pManager->GetOutput()->PrintMessage("Recorad Has Been Started");
		Point p;
		pManager->GetInput()->GetPointClicked(p.x, p.y);
	}
}
