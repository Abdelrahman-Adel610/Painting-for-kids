#ifndef CHEX_H
#define CHEX_H

#include "../Figures/CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
	string figName;
public:
	CHexagon(GfxInfo FigureGfxInfo);
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point p) const;
	float area(int x1, int y1, int x2, int y2, int x3, int y3) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& infile);
	virtual bool MoveCenter(Point P);
	virtual bool IsSahpeValid() const;
	Point GetCenter()const;
};

#endif