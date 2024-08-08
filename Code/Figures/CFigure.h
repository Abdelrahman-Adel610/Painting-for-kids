#ifndef CFIGURE_H
#define CFIGURE_H
#include <fstream>
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;												//Each figure has an ID
	bool Selected;										//true if the figure is selected.
	GfxInfo FigGfxInfo;									//Figure graphis info
	bool recorded;
	bool hide;
														/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);							//select/unselect the figure
	bool IsSelected() const;							//check whether fig is selected
	void SetID(int id);									// set id of shape
	int GetID()const;									// get id of shape
	void SetRecorded(bool con);
	bool IsRecorded() const;
	void ChngDrawClr(color Dclr);						//changes the figure's drawing color
	void ChngFillClr(color Fclr);						//changes the figure's filling color
	bool IsValid(Point p, double ly = 0, double lx = 0) const; // validate a point
	color GetColor(string str);							//return enum of color string 
	string GetString(color clr);						//return string of enum 
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure
	virtual void Draw(Output* pOut) const = 0;			//Draw the figure
	virtual bool Belong(Point p)const = 0;					//if the point belong to shape
	virtual void Save(ofstream&) = 0;					//Save the figure parameters to the file
	virtual void Load(ifstream&) = 0;					//Load the figure parameters to the file
	virtual bool MoveCenter(Point P) = 0;				// move center of shape
	virtual bool IsSahpeValid() const = 0;	// check if the shape is valid
	virtual Point GetCenter()const=0;
	void Hide();
	bool getHide();
	void setHide(bool h);
	color getFillClr();
	bool isFilled();
	string getShapeName();
	color GetDrawingColor();
	void ResetFillColoer();
	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif