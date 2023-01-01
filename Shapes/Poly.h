#pragma once

#include "shape.h"

class Poly : public shape
{
private:
	int*x;
	int* y;
	int vertcies;
public:
	Poly();
	Poly(int* Ix, int* Iy, int Ivertices, GfxInfo shapeGfxInfo);
	virtual ~Poly();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int , int ) const;
	virtual void Save(ofstream& OutFile, int);
	double polygonArea(int X[], int Y[], int n) const;
	virtual void PrintInfo(GUI*);
<<<<<<< HEAD
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
=======
	virtual void Load(string);
	void RotateShape();
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
};


