#ifndef CCIRC_H
#define CCIRC_H

#include "../Figures/CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point point;
	string figName;
public:
	CCircle(GfxInfo FigureGfxInfo);
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point p) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& infile);
	virtual bool MoveCenter(Point P);
	virtual bool IsSahpeValid() const;
	float Area();
	double GetRadius() const;
	Point GetCenter()const;
};

#endif
