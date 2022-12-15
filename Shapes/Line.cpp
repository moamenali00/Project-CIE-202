#include "Line.h"
#include<fstream>
#define getName(var)  #var

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}

bool Line::CheckSelect(int x, int y) const {
	double dis = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	double dis_2 = sqrt(((Corner1.x - x) * (Corner1.x - x)) + ((Corner1.y - y) * (Corner1.y - y)));
	double slope = (Corner1.x - Corner2.x) / (Corner1.y - Corner2.y);
	double slope_2 = (Corner1.x - x) / (Corner1.y - y);
	if (dis > dis_2 && slope == slope_2) return true;
	else return false;
}
void Line::Save(ofstream& OutFile,int c) {
	OutFile << "Line ";
	OutFile << " "<<c<<"  ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue;	
	if (ShpGfxInfo.isFilled) {
		OutFile << "  Fill  ";
	}
	else
		OutFile << "  No_fill  ";
	OutFile << ShpGfxInfo.BorderWdth;
}