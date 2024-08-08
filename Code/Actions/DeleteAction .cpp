#include"DeleteAction.h"
#include"SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CCircle.h"
DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{
	fig = NULL;
}

void DeleteAction::ReadActionParameters()
{
}


void DeleteAction::Execute()
{
	fig = pManager->GetSelected();									//Get the Selected Fig
	id = fig->GetID();												//Get the id of the selected Shape
	pManager->ShifLeft(pManager->GetFigureIndexById(fig->GetID())); //Delete it by Shifting FIGS after it at the array
	pManager->GetSelected()->SetSelected(0);						//Make no fig is selected
	pManager->SetSelectedfig(NULL);									//Nullify the Selected Fig ptr
	
	
}

void DeleteAction::Redo()
{
	fig = pManager->GetFigureById(id);
	if (fig->IsSelected())
	{
		fig->SetSelected(0);
		pManager->SetSelectedfig(NULL);
	}
	pManager->ShifLeft(pManager->GetFigureIndexById(fig->GetID()));
}

void DeleteAction::Undo()
{
	pManager->AddFigure(fig);
	fig->SetID(id);

}

DeleteAction::~DeleteAction()
{
	delete fig;
}
