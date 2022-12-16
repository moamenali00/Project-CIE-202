#include "Poly.h"

Poly::Poly(int* Ix, int* Iy, int Ivertices, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	x = Ix;
	y = Iy;
	vertcies = Ivertices;

}

Poly::~Poly()
{}

void Poly::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawPolygon(x, y, vertcies, ShpGfxInfo);
}