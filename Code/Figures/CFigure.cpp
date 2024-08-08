#include "CFigure.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "CRectangle.h"
#include "CSquare.h"
#include "CTriangle.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	recorded = false;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	hide = 1;
}

void CFigure::SetSelected(bool s)
{	
	Selected = s;
}

bool CFigure::IsSelected() const
{	
	return Selected; 
}

void CFigure::SetID(int id)
{		
	this->ID = id;
}
int CFigure::GetID() const
{
	return this->ID;
}
bool CFigure::IsRecorded() const
{
	return recorded;
}
void CFigure::SetRecorded(bool con)
{
	recorded = con;
}
void CFigure::ChngDrawClr(color Dclr)
{	
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}


color CFigure::GetColor(string str)
{
	if (str == "RED")
		return RED;
	else if (str == "BLACK")
		return BLACK;
	else if (str == "ORANGE")
		return ORANGE;
	else if (str == "GREEN")
		return GREEN;
	else if (str == "YELLOW")
		return YELLOW;
	else if (str == "BLUE")
		return BLUE;
}
string CFigure::GetString(color clr)
{
	if (clr == RED)
		return "RED";
	else if (clr == BLACK)
		return "BLACK";
	else if (clr == ORANGE)
		return "ORANGE";
	else if (clr == GREEN)
		return "GREEN";
	else if (clr == YELLOW)
		return "YELLOW";
	else if (clr == BLUE)
		return"BLUE";
}

bool CFigure::IsValid(Point p, double ly, double lx) const
{
	if (p.y > UI.ToolBarHeight + 3 + ly && p.y < UI.height - UI.StatusBarHeight - 3 - ly && p.x>0 + lx && p.x < UI.width - 20 - lx) return true;
	return false;
}

void CFigure::Hide()
{
	hide = 0;
}

bool CFigure::getHide()
{
	return hide;
}

void CFigure::setHide(bool h)
{
	hide = h;
}

color CFigure::getFillClr()
{
	return FigGfxInfo.FillClr;
}

bool CFigure::isFilled()
{
	return FigGfxInfo.isFilled;
}

string CFigure::getShapeName()
{
	if (dynamic_cast<CCircle*>(this))
		return "Circle";
	else if (dynamic_cast<CRectangle*>(this))
		return "Rectangle";
	else if (dynamic_cast<CTriangle*>(this))
		return "Triangle";
	else if (dynamic_cast<CSquare*>(this))
		return "Square";
	else if (dynamic_cast<CHexagon*>(this))
		return "Hexagon";
	else return"faild";
}

color CFigure::GetDrawingColor()
{
	return FigGfxInfo.DrawClr;
}

void CFigure::ResetFillColoer()
{
	FigGfxInfo.isFilled = 0;
}


