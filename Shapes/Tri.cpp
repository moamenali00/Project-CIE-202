#include "Tri.h"

Tri::Tri(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Tri::~Tri()
{}

void Tri::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2,Corner3, ShpGfxInfo);
}

bool Tri::CheckSelect(int x, int y) const {
	double slope_1 = (Corner1.x - Corner2.x) / (Corner1.y - Corner2.y);
	double slope_2 = (Corner2.x - Corner3.x) / (Corner2.y - Corner3.y);
	double slope_3 = (Corner3.x - Corner1.x) / (Corner3.y - Corner1.y);
	double slope_4 = (Corner1.x - x) / (Corner1.y - y);
	double slope_5 = (Corner2.x - x) / (Corner2.y - y);
	if (slope_4 > slope_1) return true;
	else return false;
}
