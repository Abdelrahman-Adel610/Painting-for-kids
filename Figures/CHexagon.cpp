#include "../Figures/CHexagon.h"

CHexagon::CHexagon(GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	figName = "Hexagon";
}

CHexagon::CHexagon(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = p;
	figName = "Hexagon";
}

void CHexagon::Draw(Output* pOut) const
{
	if(IsSahpeValid())	pOut->DrawHex(Center, FigGfxInfo, Selected);
}
float CHexagon::area(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << figName << " " << ID << " " << Center.x << " " << Center.y << " " << GetString(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? GetString(FigGfxInfo.FillClr) : "NO_COLOR") << endl;
}

void CHexagon::Load(ifstream& infile)
{
	string drawClr;
	string fillClr;
	infile >> ID >> Center.x >> Center.y >> drawClr >> fillClr;
	FigGfxInfo.DrawClr = GetColor(drawClr);
	FigGfxInfo.FillClr = (fillClr == "NO_COLOR") ? GREEN : GetColor(fillClr);
	FigGfxInfo.isFilled = (fillClr == "NO_COLOR") ? false : true;
}

bool CHexagon::MoveCenter(Point P)
{
	double length = 75;
	if(IsValid(P, sqrt(3) * length / 2.0,length)){
		Center = P;
		return true;
	}
	return false;
}

bool CHexagon::Belong(Point p) const
{
	double length = 75;
	int X[6] = { Center.x - length / 2,Center.x + length / 2,Center.x + length,Center.x + length / 2,Center.x - length / 2,Center.x - length };
	int Y[6] = { Center.y - sqrt(3) * length / 2.0, Center.y - sqrt(3) * length / 2.0,Center.y,Center.y + sqrt(3) * length / 2.0, Center.y + sqrt(3) * length / 2.0, Center.y };
	return (p.x >= X[0] && p.x <= X[1] && p.y >= Y[0] && p.y <= Y[3] || area(X[0], Y[0], X[4], Y[4], X[5], Y[5]) == area(p.x, p.y, X[4], Y[4], X[5], Y[5]) + area(X[0], Y[0], p.x, p.y, X[5], Y[5]) + area(X[0], Y[0], X[4], Y[4], p.x, p.y) || area(X[1], Y[1], X[2], Y[2], X[3], Y[3]) == area(p.x, p.y, X[2], Y[2], X[3], Y[3]) + area(X[1], Y[1], p.x, p.y, X[3], Y[3]) + area(X[1], Y[1], X[2], Y[2], p.x, p.y));

}


bool CHexagon::IsSahpeValid() const{
	if (IsValid(Center, sqrt(3) * 75 / 2.0, 75)) return true;
	return false;
}

Point CHexagon::GetCenter() const
{
	return Center;
}
