#include "../Figures/CCircle.h"

CCircle::CCircle(GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	figName = "Circle";
}

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = p1;
	point = p2;
	figName = "Circle";
}

void CCircle::Draw(Output* pOut) const
{
	if(this->IsSahpeValid())
		pOut->DrawCircle(Center, point, FigGfxInfo, Selected);
}

bool CCircle::Belong(Point p) const
{
	return ((p.x-Center.x)* (p.x - Center.x)+ (p.y - Center.y) * (p.y - Center.y)<= (point.x - Center.x) * (point.x - Center.x) + (point.y - Center.y) * (point.y - Center.y));
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << figName << " " << ID << " " << Center.x << " " << Center.y << " " << point.x << " " << point.y << " " << GetString(FigGfxInfo.DrawClr) << " " << (FigGfxInfo.isFilled ? GetString(FigGfxInfo.FillClr) : "NO_COLOR") << endl;
}

void CCircle::Load(ifstream& infile)
{
	string drawClr;
	string fillClr;
	infile >> ID >> Center.x >> Center.y >> point.x >> point.y >> drawClr >> fillClr;
	FigGfxInfo.DrawClr = GetColor(drawClr);
	FigGfxInfo.FillClr = (fillClr == "NO_COLOR") ? GREEN : GetColor(fillClr);
	FigGfxInfo.isFilled = (fillClr == "NO_COLOR") ? false : true;
}


bool CCircle::MoveCenter(Point P) {
	Point new_P1;
	new_P1.x= point.x - (Center.x - P.x);
	new_P1.y = point.y - (Center.y - P.y);
	 if(IsValid(P, GetRadius(), GetRadius()) && IsValid(new_P1)){
		 Center = P;
		 point = new_P1;
		 return true;
	 }
	 return false;
}

bool CCircle::IsSahpeValid() const
{
	if (IsValid(Center, GetRadius(), GetRadius())) return true;
	return false;
}
float CCircle::Area()
{
	return 3.14*GetRadius()*GetRadius();
}
double CCircle::GetRadius() const {
	return sqrt((point.x - Center.x) * (point.x - Center.x) + (point.y - Center.y) * (point.y - Center.y));
}

Point CCircle::GetCenter() const
{
	return Center;
}
