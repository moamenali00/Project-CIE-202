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
void Square::Save(ofstream& OutFile, int c) {
	OutFile << "Square ";
	OutFile << " " << c << "  ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
	if (ShpGfxInfo.isFilled) {
		OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue<<" ";
	}
	else
		OutFile << "  No_fill  ";
	OutFile << ShpGfxInfo.BorderWdth << " ";
}