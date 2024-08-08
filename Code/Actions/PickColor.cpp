#include "PickColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <Windows.h>
pickColorAction::pickColorAction(ApplicationManager* pApp) : Action(pApp)
{
}

string pickColorAction::CLRtoSTR(color c)		//Change the color to string
{
	if (c == RED)
	{
		return "Red";
	}
	else if (c == BLACK)
	{
		return "Black";

	}
	else if (c == ORANGE)
	{
		return "Orange";

	}
	else if (c == GREEN)
	{
		return "Green";

	}
	else if (c == YELLOW)
	{
		return "Yellow";

	}
	else if (c == BLUE)
	{
		return "Blue";

	}

} 

void pickColorAction::ReadActionParameters()
{

	mainColor = pManager->getRandomClr();   //get rangom CLR from the Current Figs
}

void pickColorAction::Execute()
{
Output* pOut = pManager->GetOutput();//Get a Pointer to the Output Interfaces 
Input* pIn = pManager->GetInput();	//Get a Pointer to the Input  Interfaces 
if(pManager->getFilledShapesCount()>=2)        //Check if the shapes are enough
{
	int TrueATT = 0, FalseATT = 0;
	ReadActionParameters();
	int TotalShapes = pManager->ShapesWithClr(mainColor); //get the total shapes that have the Same main color
	string mainColorstr = CLRtoSTR(mainColor);
	pOut->PrintMessage("Select "+mainColorstr+" Figures");
	while (TotalShapes)    
	{
		pIn->GetPointClicked(p.x, p.y);
		if (p.y >= 0 && p.y < UI.ToolBarHeight)            //if Clicked on toolBar
		{

			if ((p.x / UI.MenuItemWidth) == 3)             //If clicked on Reset BTN
			{
				break;
			}
		}
		else
		{
			if (pManager->SelectByColor(mainColor, p)) //Check if Selected True Shape and hide it
			{
				pOut->PrintMessage("true Attempt ");
				if (pManager->GetVoice())
					PlaySound("voice\\Correct", NULL, SND_ASYNC);
				TrueATT++;
				TotalShapes--;
			}
			else                                        //If selected Wrong Choice
			{
				if (pManager->belongToShapes(p))		//Check if he clicked on shape
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
	pOut->PrintMessage("END OF THE GAME  True Attempts : " + numberofTrueATT + "  False Attempts : " + numberofFalseATT+" " + "Click to get back to the menue");
	if (!FalseATT)
		if (pManager->GetVoice())
			PlaySound("voice\\Win", NULL, SND_ASYNC);
	pManager->GetUserAction();
	pManager->ExecuteAction(RESET);
}
	else
	{
		pOut->PrintMessage("VERY FEW FILLED SHAPES , DRAM MORE AND COME AGIAN");
		pManager->ExecuteAction(pManager->GetUserAction());
	}
}
