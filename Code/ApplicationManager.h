#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 ,  MaxRecordingAction = 20 , MaxActionUndo = 5};
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	int figID;
	CFigure* SelectedFig; //Pointer to the selected figure
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Action* Record[MaxRecordingAction];
	bool M_Record;
	Action* Undo_RedoActions[MaxActionUndo];
	Action* LastAction;
	int Undo_RedoActionsNumber = 0;
	int LastActionIndex = 0;
	bool Voice = 1;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(Point P) const; //Search for a figure given a point inside the figure
	CFigure* GetSelected() const;
	void SetSelectedfig(CFigure* fig);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	int GetLastFigID()const;
	void ClearFigList();
	int GetNextFigID();
	int GetModRecord()const;
	void AModRecord();
	void DModRecord();
	void AddRecord(Action*);
	Action* getRecord(int i);
	CFigure* GetFigureById(int id)const;
	void ShifLeft(int i);
	int GetFigureIndexById(int id)const;
	void SaveAll(ofstream& out) const;
	int GetFigureCount()const;
	color getRandomClr();
	string getRandomFig();
	int ShapesWithClr(color c);
	bool SelectByColor(color c, Point p);
	bool SelectByFig( string s, Point p);
	bool SelectByFigClr( string s, color c,Point p);
	bool belongToShapes(Point p);
	void ShowAllFigs();
	int getFilledShapesCount();
	int FIGcount(string s);
	int figClrCount(string s, color c);
	void AddUndo_RedoAction(Action* act);
	bool IsUndo_RedoAction(ActionType act);
	Action* GetLastActionToUndo();
	Action* GetLastActionToRedo();
	int GetLastActionIndex();
	int GetUndo_RedoActionsNumber();
	void ResetUndo_RedoActions();
	void ResetRecordList();
	void UndoLastAction();
	void RedoLastAction();
	void UnSelect();
	void SetVoice();
	bool GetVoice();
};

#endif