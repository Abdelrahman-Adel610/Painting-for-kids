#include "../Figures/CSquare.h"

CSquare::CSquare(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = p;
	figName = "Square";
}

CSquare::CSquare(GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	figName = "Square";
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::Belong(Point p) const
{
	double HFlength = 75;
	return (p.x>=Center.x-HFlength&& p.x <= Center.x + HFlength && p.y>=Center.y - HFlength && p.y <= Center.y + HFlength);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << figName << " " << ID << " " << Center.x << " " << Center.y << " " << GetString(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? GetString(FigGfxInfo.FillClr) : "NO_COLOR") << endl;
}

void CSquare::Load(ifstream& infile)
{
	string drawClr;
	string fillClr;
	infile >> ID >> Center.x >> Center.y >> drawClr >> fillClr;
	FigGfxInfo.DrawClr = GetColor(drawClr);
	FigGfxInfo.FillClr = (fillClr == "NO_COLOR")? GREEN : GetColor(fillClr);
	FigGfxInfo.isFilled = (fillClr == "NO_COLOR") ? false : true;
	
}

bool CSquare::MoveCenter(Point P)
{
	double HFlength = 75;
	if (IsValid(P, HFlength, HFlength)) {
		Center = P;
		return true;
	}
	return false;
}

bool CSquare::IsSahpeValid() const
{
	if (IsValid(Center, 75, 75)) return true;
	return false;
}

Point CSquare::GetCenter() const
{
	return Center;
}
