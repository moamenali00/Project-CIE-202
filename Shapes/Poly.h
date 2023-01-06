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
	virtual void Load(string);
	void RotateShape();
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
	virtual void scramble();
	virtual void resize(float a);
	virtual void Move(int, int) ;
	virtual shape* duplicate(GUI* pGUI);
	virtual void Hide(GUI* pGUI);
	virtual string get_type();

};


