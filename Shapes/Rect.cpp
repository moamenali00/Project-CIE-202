#include "Rect.h"
Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
bool Rect::CheckSelect(int x, int y) const
{
	if (x<Corner1.x && x>Corner2.x && y<Corner1.y && y>Corner2.y || x > Corner1.x && x<Corner2.x && y<Corner1.y && y>Corner2.y || x<Corner1.x && x>Corner2.x && y>Corner1.y && y<Corner2.y || x>Corner1.x && x<Corner2.x && y>Corner1.y && y < Corner2.y) {
		return true;
	}
	else
		return false;

}
void Rect::Save(ofstream& OutFile,int c) {
	OutFile << "Rect ";
	OutFile << " " << c<<"  ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed<< " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue;
	if (ShpGfxInfo.isFilled) {
		OutFile << "  Fill  ";
	}
	else
		OutFile << "  No_fill  ";
	OutFile << ShpGfxInfo.BorderWdth;
}
