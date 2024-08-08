#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	figName = "Rectangle";

}

float CRectangle::Area()
{
	return abs((Corner1.x - Corner2.x)*(Corner1.y - Corner2.y));
}

CRectangle::CRectangle(GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	figName = "Rectangle";
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	if (this->IsSahpeValid()) pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& OutFile)
{
	OutFile << figName << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << GetString(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? GetString(FigGfxInfo.FillClr) : "NO_COLOR") << endl;

}

void CRectangle::Load(ifstream& infile)
{
	string drawClr;
	string fillClr;
	infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> drawClr >> fillClr;
	FigGfxInfo.DrawClr = GetColor(drawClr);
	FigGfxInfo.FillClr = (fillClr == "NO_COLOR") ? GREEN : GetColor(fillClr);
	FigGfxInfo.isFilled = (fillClr == "NO_COLOR") ? false : true;
}


bool CRectangle::Belong(Point p) const
{
	return (p.x >= min(Corner1.x, Corner2.x) && p.x <= max(Corner1.x, Corner2.x) && p.y >= min(Corner1.y, Corner2.y) && p.y <= max(Corner1.y, Corner2.y));
}

bool CRectangle::MoveCenter(Point P)
{
	Point new_P1,new_P2 ,Center;
	Center = GetCenter();
	new_P1.x = Corner1.x - (Center.x - P.x);
	new_P1.y = Corner1.y - (Center.y - P.y);
	new_P2.x = Corner2.x - (Center.x - P.x);
	new_P2.y = Corner2.y - (Center.y - P.y);
	if (IsValid(new_P1) && IsValid(new_P2)) {
		Corner1 = new_P1;
		Corner2 = new_P2;
		return true;
	}
	return false;
}

bool CRectangle::IsSahpeValid() const {
	if (IsValid(Corner1) && IsValid(Corner2)) return true;
	return false;
}
Point CRectangle::GetCenter() const {
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	return Center;
}