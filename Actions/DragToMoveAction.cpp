#include "DragToMoveAction.h"
#include "..\ApplicationManager.h"
DragToMoveAction::DragToMoveAction(ApplicationManager* pApp) :Action(pApp)
{
}

void DragToMoveAction::ReadActionParameters()
{
}

void DragToMoveAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelected() != NULL)
	{
		id = pManager->GetSelected()->GetID();
		P0 = pManager->GetSelected()->GetCenter();
		pOut->PrintMessage(" Drag the figure to move it ");

		bool F1 = 1;
		while (!pIn->IsClicked(P3.x, P3.y))
		{
		}
		while (pIn->IsClicked(P3.x, P3.y))
		{

			if (F1)
			{
				P1 = P3;
				F1 = 0;
				if (!pManager->GetSelected()->Belong(P1))
				{
					pOut->PrintMessage("Invalid points, click to continue..");
					IsExcuted = 0;
					int x, y;
					pIn->GetPointClicked(x, y);
					break;
				}
			}

			P4.x = P0.x + (P3.x - P1.x);
			P4.y = P0.y + (P3.y - P1.y);
			if (pManager->GetSelected()->MoveCenter(P4))
			{
				P2 = P4;
				pManager->UpdateInterface();
			}
			Sleep(10);
		}

	}
}

void DragToMoveAction::Redo()
{
	CFigure* figure = pManager->GetFigureById(id);
	figure->MoveCenter(P2);
}

void DragToMoveAction::Undo()
{
	CFigure* figure = pManager->GetFigureById(id);
	figure->MoveCenter(P0);
}
