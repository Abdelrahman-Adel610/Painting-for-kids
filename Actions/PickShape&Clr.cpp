#include "PickShape&Clr.h"
#include "PickColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <Windows.h>
PickShapeClrAction::PickShapeClrAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PickShapeClrAction::ReadActionParameters()
{
	do
	{ 
		mainShape.mainClr = pManager->getRandomClr();		//get rangom CLR from the Current Figs
		mainShape.mainShape = pManager->getRandomFig();		//get rangom Fig from the Current Figs
	} 
	while (pManager->figClrCount(mainShape.mainShape, mainShape.mainClr) == 0);
}

void PickShapeClrAction::Execute()
{
Output* pOut = pManager->GetOutput();//Get a Pointer to the Output Interfaces 
Input* pIn = pManager->GetInput();	//Get a Pointer to the Input  Interfaces 
if(pManager->getFilledShapesCount() >= 2)
{
	int TrueATT = 0, FalseATT = 0;
	ReadActionParameters();
	string mainColorstr = pickColorAction::CLRtoSTR(mainShape.mainClr);
	pOut->PrintMessage("Select " + mainColorstr+" "+mainShape.mainShape);
	int TotalShapes = pManager->figClrCount(mainShape.mainShape, mainShape.mainClr); //get the total shapes that have the Same mainFig & mainCLr
	while (TotalShapes)
	{
		pIn->GetPointClicked(p.x, p.y);
		if (p.y >= 0 && p.y < UI.ToolBarHeight)                    //if clicked on the toolbar
		{

			if ((p.x / UI.MenuItemWidth) == 3)					//if clicke on reset btn
			{ 
				break;
			}
		}
		else
		{
		if (pManager->SelectByFigClr(mainShape.mainShape,mainShape.mainClr,p))     //if true Choice
		{
			pOut->PrintMessage("true Attempt ");
			if (pManager->GetVoice())
				PlaySound("voice\\Correct", NULL, SND_ASYNC);
				TrueATT++;
				TotalShapes--;
		}
		else
        {
			if(pManager->belongToShapes(p))
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
	if (!FalseATT)
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
