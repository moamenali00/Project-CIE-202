#include "Poly.h"

Poly::Poly(Point NP1, Point NP2, Point NP3, Point NP4, Point NP5, GfxInfo PolyGFxInfo) :shape(PolyGFxInfo)
{
	P1 = NP1;
	P2 = NP2;
	P3 = NP3;
	P4 = NP4;
	P5 = NP5;
}

Poly::~Poly() {
}

void Poly::Draw(GUI* pUI) const {
	pUI->DrawIrregularPoly(P1, P2, P3, P4, P5, ShpGfxInfo);
}