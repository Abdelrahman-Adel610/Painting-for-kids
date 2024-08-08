#include "SaveAction.h"
SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	pManager->GetOutput()->PrintMessage("Enter The File Name : ");
	filename = pManager->GetInput()->GetSrting(pManager->GetOutput());
}

void SaveAction::Execute()
{
	
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	out.open(filename + ".txt");
	out << pOut->clrtostr(pManager->GetOutput()->getCrntDrawColor()) << " " << pOut->clrtostr(pManager->GetOutput()->getCrntFillColor()) << endl;
	out << pManager->GetFigureCount() << endl;
	pManager->SaveAll(out);
	pManager->GetOutput()->PrintMessage("file named : (" + filename + ") has been saved");
	out.close();
}
