#include "Shape.h"
#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
bool Square::CheckSelect(int x, int y) const
{
	if (x<Corner1.x && x>Corner2.x && y<Corner1.y && y>Corner2.y || x > Corner1.x && x<Corner2.x && y<Corner1.y && y>Corner2.y || x<Corner1.x && x>Corner2.x && y>Corner1.y && y<Corner2.y || x>Corner1.x && x<Corner2.x && y>Corner1.y && y < Corner2.y) {
		return true;
	}
	else
		return false;

}