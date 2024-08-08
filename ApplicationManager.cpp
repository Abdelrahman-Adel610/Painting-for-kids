#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\MoveFiguarAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ChangeDrawAction.h"
#include "Actions\ChangeFillAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\StartRecordAction.h"
#include "Actions\PlayRecordAction.h"
#include "Actions\StopRecordAction.h"
#include "Actions\PickColor.h"
#include "Actions\PickShape.h"
#include "Actions\PickShape&Clr.h"
#include "Actions\ResetAction.h"
#include "Actions\DragToMoveAction.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"
#include "Actions\VoiceAction.h"
#include "Actions\ExitAction.h"
#include "Actions\SwitchToPlayMAction.h"
#include "Actions\SwitchToDrawMAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	FigCount = 0;
	figID = 0;
	M_Record = false;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
	for (int i = 0; i < MaxRecordingAction; i++)
		Record[i] = NULL;
	for (int i = 0; i < MaxActionUndo; i++)
		Undo_RedoActions[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUARE:
			pAct = new AddSqrAction(this) ;
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case MOVE_FIGURE:
			if (GetSelected())
			{
				pAct = new MoveFiguarAction(this);
			}
			else
			{
				pOut->PrintMessage("Please select figure first, Click any where to continue");
				int x, y;
				pIn->GetPointClicked(x,y);
			}
			break;
		case DRAG_TO_MOVE:
			if (GetSelected())
			{
				pAct = new DragToMoveAction(this);
			}
			else
			{
				pOut->PrintMessage("Please select figure first, Click any where to continue");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
			break;
		case SELECT_FIGURE:
			pAct = new SelectAction(this);
			break;
		case DELETE_FIGURE:
			
			if (GetSelected())
			{
				pAct = new DeleteAction(this);
			}
			else
			{
				pOut->PrintMessage("Please select figure first, Click any where to continue");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case SAVE_GRAPH:
			if(!M_Record)	pAct = new SaveAction(this);
			break;
		case LOAD_GRAPH:
			if (!M_Record)	pAct = new LoadAction(this);
			break;
		case START_RECORDING:
			if (!M_Record)	pAct = new StartRecordAction(this);
			break;
		case STOP_RECORDING:
			if (M_Record)	pAct = new StopRecordAction(this);
			break;
		case PLAY_RECORD:
			if (!M_Record)	pAct = new PlayRecordAction(this);
			break;
		case CHANGE_DRAW_CLR:
		
			if (GetSelected())
			{
				pAct = new ChangeDrawAction(this);
			}
			else
			{
				pOut->PrintMessage("Please select figure first, Click any where to continue");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
			break;
		case CHANGE_FILL_CLR:
			if (GetSelected())
			{
				pAct = new ChangeFillAction(this);
			}
			else
			{
				pOut->PrintMessage("Please select figure first, Click any where to continue");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
			break;
		case ENABLE_VOICE:
			pAct = new VoiceAction(this);
			if (M_Record)
			{
				pAct->Execute();
				delete pAct;
				pAct = NULL;
			}
			break;
		case EXIT:
			pAct = new ExitAction(this);
			break;
		case CLEAR:
				pAct = new ClearAllAction(this);
				if (M_Record)
				{
					DModRecord();
					pAct->Execute();
					pOut->PrintMessage("The record has been ended, Click any where to continue");
							int x, y;
						pIn->GetPointClicked(x, y);
						delete pAct;
						pAct = NULL;
				}
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayMAction(this);
			break;
		case PICK_COLOR:
			ShowAllFigs();
			pAct = new pickColorAction(this);
			break;
		case PICK_FIGURE:
			ShowAllFigs();
			pAct = new pickShapeAction(this);
			break;
		case PICK_COLORED_FIGURE:
			ShowAllFigs();
			pAct = new PickShapeClrAction(this);
			break;
		case RESET:
			pAct = new ResetAction(this);
			break;
		case TO_DRAW:
			pAct = new SwitchToDrawMAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		if (IsUndo_RedoAction(ActType)&& pAct->getExcutionState())	AddUndo_RedoAction(pAct);
		else if (!(M_Record)) 
		{
			delete pAct;	//You may need to change this line depending to your implementation
		}
		if (M_Record && ActType != START_RECORDING&& ActType != EXIT&& pAct->getExcutionState()&&UI.InterfaceMode!=MODE_PLAY && ActType != TO_DRAW)	AddRecord(pAct);
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount){
		pFig->SetID(GetNextFigID());
		FigList[FigCount++] = pFig;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->Belong(P))
		{
			return FigList[i];
		}
	}
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->getHide())
		FigList[i]->Draw(pOut);	
	}  
	//Call Draw function (virtual member fn)
}
int ApplicationManager::GetLastFigID() const
{
	return figID;
}
void ApplicationManager::ClearFigList()
{
	figID = 0;
	FigCount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	
}
int ApplicationManager::GetNextFigID()
{
	return ++figID;
}
int ApplicationManager::GetModRecord() const
{
	return M_Record;
}
void ApplicationManager::AModRecord()
{
	M_Record = true;
}
void ApplicationManager::DModRecord()
{
	M_Record = false;
}
void ApplicationManager::AddRecord(Action* act)
{ 
	for (int i = 0; i < MaxRecordingAction; i++) {
		if (Record[i] == NULL)
		{
			Record[i] = act;
			act->setRecorded(true);
			if (i == 19) {
				act = new StopRecordAction(this);
				act->Execute();
			}
			break;
		}
	}
}
Action* ApplicationManager::getRecord(int i)
{
	return Record[i];
}
CFigure* ApplicationManager::GetFigureById(int id) const
{
	int i = GetFigureIndexById(id);
	return (i != -1) ? FigList[i] : NULL;
}
int ApplicationManager::GetFigureIndexById(int id) const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->GetID() == id)
			return i;
	}
	return -1;
}
void ApplicationManager::ShifLeft(int i)
{
	if (i < FigCount)
	{
		if (i == FigCount - 1)
		{
			FigCount--;
			return;
		}
		while (i < FigCount)
		{
			FigList[i] = FigList[i + 1];
			i++;
		}
		FigCount--;
	}
	else return;
}
void ApplicationManager::SaveAll(ofstream& out) const
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(out);
	}
}
void ApplicationManager::SetSelectedfig(CFigure* fig)
{
	SelectedFig = fig;
}
CFigure* ApplicationManager::GetSelected() const
{
	return SelectedFig;
}
int ApplicationManager::GetFigureCount()const {
	return FigCount;
}
color ApplicationManager::getRandomClr()
{
	srand(time(NULL));
	int randomIndex = rand() % 200;
	while (FigList[randomIndex]==NULL)
	{
		randomIndex = rand() % FigCount;
	}
	while (FigList[randomIndex]->isFilled()==0)
	{
		randomIndex = rand() % FigCount;
	}
	return FigList[randomIndex]->getFillClr();
	/*color randomClr;*/
	//bool NotFound = true;
	//while(NotFound)
	//{ 
	//randomClr=(Colors) rand() % 6;
	//
	//for (int i = 0; i < FigCount; i++)
	//{
	//	if (FigList[i]->getFillClr() == randomClr)
	//		NotFound = false;
	//}
	//}
	//return randomClr;
}

string ApplicationManager::getRandomFig()
{
	srand(time(NULL));
	int randomIndex = rand() % 200;
	while (FigList[randomIndex] == NULL)
	{
		randomIndex = rand() % 200;
	}

	return FigList[randomIndex]->getShapeName();
}

int ApplicationManager::ShapesWithClr(color c)
{
	int counter = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getFillClr() == c)
			counter++;
	}
	return counter;
}

bool ApplicationManager::SelectByColor(color c,Point p)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->Belong(p) && FigList[i]->getFillClr() == c&&FigList[i]->getHide())
		{ 
			FigList[i]->Hide();
			UpdateInterface();
			return true;
		}
	}
	return false;
}

bool ApplicationManager::SelectByFig(string s,Point p)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->Belong(p) && FigList[i]->getShapeName() == s && FigList[i]->getHide())
		{
			FigList[i]->Hide();
			UpdateInterface();
			return true;
		}
	}
	return false;
}

bool ApplicationManager::SelectByFigClr(string s, color c, Point p)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->Belong(p) && FigList[i]->getShapeName() == s && FigList[i]->getHide()&&FigList[i]->getFillClr()==c)
		{
			FigList[i]->Hide();
			UpdateInterface();
			return true;
		}
	}
	return false;
}

bool ApplicationManager::belongToShapes(Point p)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->Belong(p)&&FigList[i]->getHide())
		{
			return true;
		}
	}
	return false;
}

void ApplicationManager::ShowAllFigs()
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->setHide(1);
	}
}

int ApplicationManager::getFilledShapesCount()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isFilled())
			count++;
	}


	return count;
}

int ApplicationManager::FIGcount(string s)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getShapeName()==s)
			count++;
	}
	return count;
}

int ApplicationManager::figClrCount(string s, color c)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getShapeName() == s && FigList[i]->getFillClr() == c)
			count++;
	}
		return count;
}
void ApplicationManager::AddUndo_RedoAction(Action* act)
{

	if (LastActionIndex < MaxActionUndo && LastActionIndex == Undo_RedoActionsNumber)
	{
		Undo_RedoActions[LastActionIndex++] = act;
		Undo_RedoActionsNumber++;
	}
	else if (LastActionIndex < MaxActionUndo && LastActionIndex < Undo_RedoActionsNumber)
	{
		for (int i = LastActionIndex; i < Undo_RedoActionsNumber; i++)
		{
			if (!(Undo_RedoActions[i]->getRecorded()))	delete Undo_RedoActions[i];
		}
		Undo_RedoActions[LastActionIndex++] = act;
		Undo_RedoActionsNumber = LastActionIndex;
	}
	else if (LastActionIndex == MaxActionUndo && LastActionIndex == Undo_RedoActionsNumber)
	{
		if (!Undo_RedoActions[0]->getRecorded())	delete Undo_RedoActions[0];
		for (int i = 0; i < MaxActionUndo - 1; i++)
		{
			Undo_RedoActions[i] = Undo_RedoActions[i + 1];
		}
		Undo_RedoActions[MaxActionUndo - 1] = act;
	}

}
bool ApplicationManager::IsUndo_RedoAction(ActionType act)
{
	return act == DRAW_RECT || act == DRAW_SQUARE || act == DRAW_TRIANGLE || act == DRAW_CIRC || act == DRAW_HEX || act == CHANGE_FILL_CLR || act == CHANGE_DRAW_CLR || act == DELETE_FIGURE || act == MOVE_FIGURE ||act == DRAG_TO_MOVE;
}
Action* ApplicationManager::GetLastActionToUndo()
{
	return Undo_RedoActions[LastActionIndex - 1];
}
Action* ApplicationManager::GetLastActionToRedo()
{
	return Undo_RedoActions[LastActionIndex];
}
int ApplicationManager::GetLastActionIndex()
{
	return LastActionIndex;
}
int ApplicationManager::GetUndo_RedoActionsNumber()
{
	return Undo_RedoActionsNumber;
}
void ApplicationManager::ResetUndo_RedoActions()
{
	for (int i = 0; i < MaxActionUndo; i++)
	{
		if (Undo_RedoActions[i] != NULL)
			if(!Undo_RedoActions[i]->getRecorded())
				delete Undo_RedoActions[i];
		Undo_RedoActions[i] = NULL;
	}
	LastActionIndex = 0;
	Undo_RedoActionsNumber = 0;

}
void ApplicationManager::ResetRecordList()
{
	for (int i = 0; i < MaxRecordingAction; i++)
	{
		if (Record[i] == NULL) break;
		delete Record[i];
		Record[i] = NULL;
	}
}
void ApplicationManager::UndoLastAction()
{
	LastActionIndex--;
}
void ApplicationManager::RedoLastAction()
{
	LastActionIndex++;
}

void ApplicationManager::UnSelect()
{
	if (SelectedFig)
	{
		SelectedFig->SetSelected(0);
		SelectedFig = NULL;
	}
}


void ApplicationManager::SetVoice()
{
	if (Voice)
		Voice = 0;
	else
		Voice = 1;
}

bool ApplicationManager::GetVoice()
{
	return Voice;
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < Undo_RedoActionsNumber; i++)
		delete Undo_RedoActions[i];
	delete pIn;
	delete pOut;
	
}
bool Action::isFilled = 0;