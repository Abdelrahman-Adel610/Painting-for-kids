#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	string figName;
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(GfxInfo FigureGfxInfo);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	float Area();
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(Point p) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& infile);
	virtual bool MoveCenter(Point P);
	virtual bool IsSahpeValid() const;
	Point GetCenter()const;

};

#endif