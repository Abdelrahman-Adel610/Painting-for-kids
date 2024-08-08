#include "../Figures/CTriangle.h"

CTriangle::CTriangle(GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	figName = "Triangle";
}

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;
	figName = "Triangle";
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

float CTriangle:: area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << figName << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << " " << Corner3.x << " " << Corner3.y << " " << GetString(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? GetString(FigGfxInfo.FillClr) : "NO_COLOR") << endl;
}

void CTriangle::Load(ifstream& infile)
{
	string drawClr;
	string fillClr;
	infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> drawClr >> fillClr;
	FigGfxInfo.DrawClr = GetColor(drawClr);
	FigGfxInfo.FillClr = (fillClr == "NO_COLOR") ? GREEN : GetColor(fillClr);
	FigGfxInfo.isFilled = (fillClr == "NO_COLOR") ? false : true;
}

bool CTriangle::MoveCenter(Point P)
{
	Point new_P1,new_P2,new_P3,Center;
	Center = GetCenter();
	new_P1.x = Corner1.x - (Center.x - P.x);
	new_P1.y = Corner1.y - (Center.y - P.y);
	new_P2.x = Corner2.x - (Center.x - P.x);
	new_P2.y = Corner2.y - (Center.y - P.y);
	new_P3.x = Corner3.x - (Center.x - P.x);
	new_P3.y = Corner3.y - (Center.y - P.y);
	if(IsValid(new_P1) && IsValid(new_P2) && IsValid(new_P3)){
		Corner1 = new_P1;
		Corner2 = new_P2;
		Corner3 = new_P3;
		return true;
	}
	return false;
}

bool CTriangle::IsSahpeValid() const
{
	if (IsValid(Corner1) && IsValid(Corner2) && IsValid(Corner3)) return true;
	return false;
}

bool CTriangle::Belong(Point p) const
{
	return (area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y) == area(p.x, p.y, Corner2.x, Corner2.y, Corner3.x,Corner3.y)+ area(Corner1.x, Corner1.y, p.x, p.y, Corner3.x, Corner3.y) + area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, p.x, p.y))	;
}
Point CTriangle::GetCenter()const {
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return Center;
}