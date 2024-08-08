#ifndef CSQR_H
#define CSQR_H

#include "../Figures/CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	string figName;
public:
	CSquare(GfxInfo FigureGfxInfo);
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point p) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& infile);
	virtual bool MoveCenter(Point P);
	virtual bool IsSahpeValid() const;
	Point GetCenter()const;
};

#endif