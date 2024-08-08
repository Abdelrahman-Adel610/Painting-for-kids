#ifndef CTRI_H
#define CTRI_H

#include "../Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	string figName;
public:
	CTriangle(GfxInfo FigureGfxInfo);
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point p) const;
	float area(int x1, int y1, int x2, int y2, int x3, int y3) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& infile);
	virtual bool MoveCenter(Point P);
	virtual bool IsSahpeValid() const;
	Point GetCenter() const;
};

#endif