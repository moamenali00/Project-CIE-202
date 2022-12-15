#include "Tri.h"
#include<fstream>
#define getName(var)  #var
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
	double area = 0.5 * abs((Corner1.x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y - Corner2.y)));
	double area_2 = 0.5 * abs((x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - y)) + (Corner3.x * (y - Corner2.y)));
	double area_3 = 0.5 * abs((Corner1.x * (y - Corner3.y)) + (x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y -y)));
	double area_4 = 0.5 * abs((Corner1.x * (Corner2.y - y)) + (Corner2.x * (y - Corner1.y)) + (x * (Corner1.y - Corner2.y)));
	if (area == (area_2 + area_3 + area_4)) return true;
	else return false;
}

void Tri::Save(ofstream& OutFile,int c) {
	OutFile << "Tri ";
	OutFile << " " << c<<" ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y;
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue;
	if (ShpGfxInfo.isFilled) {
		OutFile << "  Fill  ";
	}
	else
		OutFile << "  No_fill  ";
	OutFile << ShpGfxInfo.BorderWdth;
}