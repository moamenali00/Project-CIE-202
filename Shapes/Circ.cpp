#include "Circ.h"

Circ::Circ(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Circ::~Circ()
{}

void Circ::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Corner1, Corner2, ShpGfxInfo);
}

bool Circ::CheckSelect(int x, int y) const {
	double rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	double rad_2 = sqrt(((Corner1.x - x) * (Corner1.x - x)) + ((Corner1.y - y) * (Corner1.y - y)));
	if (rad_2 < rad) return true;
	else return false;
}
