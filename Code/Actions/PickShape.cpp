#include "PickShape.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <Windows.h>
pickShapeAction::pickShapeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void pickShapeAction::ReadActionParameters()
{

	mainShape = pManager->getRandomFig();//get rangom Fig from the Current Figs
}

void pickShapeAction::Execute()
{
Output* pOut = pManager->GetOutput();//Get a Pointer to the Output Interfaces 
Input* pIn = pManager->GetInput();	//Get a Pointer to the Input  Interfaces 
if(pManager->GetFigureCount()>=2)   //Check if the shapes are enough
{
	int TrueATT = 0, FalseATT = 0;

	ReadActionParameters();
	int TotalShapes = pManager->FIGcount(mainShape);//get the total shapes that have the Same main FIG
	pOut->PrintMessage("Select " + mainShape);

	while (TotalShapes)
	{
		pIn->GetPointClicked(p.x, p.y);
		if (p.y >= 0 && p.y < UI.ToolBarHeight)		//if Clicked on toolBar
		{

			if ((p.x / UI.MenuItemWidth) == 3)		//If clicked on Reset BTN
			{
				break;
			}
		}
		else
		{
			if (pManager->SelectByFig(mainShape, p)) //Check if Selected True Shape and hide it
			{
				pOut->PrintMessage("true Attempt ");
				if (pManager->GetVoice())
					PlaySound("voice\\Correct", NULL, SND_ASYNC);
				TrueATT++;
				TotalShapes--;
			}
			else                                        //If selected Wrong Choice
			{ 
				if (pManager->belongToShapes(p))
				{
					pOut->PrintMessage("False Attempt ");
					if (pManager->GetVoice())
						PlaySound("voice\\Failed", NULL, SND_ASYNC);
					FalseATT++;
				}
			}
		}
	}
	string numberofTrueATT = to_string(TrueATT);
	string numberofFalseATT = to_string(FalseATT);
	pOut->PrintMessage("END OF THE GAME  True Attempts : " + numberofTrueATT + "  False Attempts : " + numberofFalseATT+" "+ "Click to get back to the menue");
	if(!FalseATT)
		if (pManager->GetVoice())
			PlaySound("voice\\Win", NULL, SND_ASYNC);
	pManager->GetUserAction();
	pManager->ExecuteAction(RESET);
}
	else
	{
		pOut->PrintMessage("VERY FEW SHAPES , DRAM MORE AND COME AGIAN");
		pManager->ExecuteAction(pManager->GetUserAction());
	}
}
