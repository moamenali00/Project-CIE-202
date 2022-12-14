#pragma once 
#include "shape.h"

class Square : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	Square();
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual bool CheckSelect(int, int) const;
	virtual void Save(ofstream& OutFile,int c);
	virtual void PrintInfo(GUI*);
	virtual void Load(string);
	void RotateShape();
	virtual void stickimages(GUI* u);
	virtual shape* copy();
	virtual void paste(int xx, int yy);
	virtual void scramble();
	virtual void resize(float a);
	virtual shape* duplicate();
	virtual void Move(int, int) ;
	virtual void Hide(GUI* pGUI);
	virtual string get_type();

};
