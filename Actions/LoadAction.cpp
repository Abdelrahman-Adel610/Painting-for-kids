#include "LoadAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	fileName = pManager->GetInput()->GetSrting(pManager->GetOutput());
}

void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	gfx.isFilled = false;
	pOut->PrintMessage("Enter The File Name That YOU Want To Load From : ");
	ReadActionParameters();
	file.open(fileName + ".txt");
	if (file.is_open())
	{
		pManager->UnSelect();
		pManager->ResetUndo_RedoActions();
		pManager->ResetRecordList();
		pManager->ClearFigList();
		file >> drawClr >> fillClr;
		gfx.DrawClr = pOut->strtoclr(drawClr);
		gfx.FillClr = pOut->strtoclr(fillClr);
		file >> num;
		for (int i = 0; i < num; i++)
		{
			file >> figName;
			if (figName == "Hexagon")
			{
				CFigure* tmp = new CHexagon(gfx);
				tmp->Load(file);
				pManager->AddFigure(tmp);
			}
			else if (figName == "Rectangle")
			{
				CFigure* tmp = new CRectangle(gfx);
				tmp->Load(file);
				pManager->AddFigure(tmp);
			}
			else if (figName == "Square")
			{
				CFigure* tmp = new CSquare(gfx);
				tmp->Load(file);
				pManager->AddFigure(tmp);
			}
			else if (figName == "Triangle")
			{
				CFigure* tmp = new CTriangle(gfx);
				tmp->Load(file);
				pManager->AddFigure(tmp);
			}
			else if (figName == "Circle")
			{
				CFigure* tmp = new CCircle(gfx);
				tmp->Load(file);
				pManager->AddFigure(tmp);
			}

		}
	}
	else
	{
		pManager->GetOutput()->PrintMessage("THERE IS NO FILE WITH THIS NAME"); return;
	}
	pManager->GetOutput()->PrintMessage("file (" + fileName + ") has been loaded sucssesfully");
	file.close();
}
