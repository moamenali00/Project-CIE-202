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
void Circ::PrintInfo(GUI* out) {
	out->ClearStatusBar();
	string msg;
	msg += "Center (";
	msg += to_string(Corner1.x);
	msg += ",";msg += to_string(Corner1.y);
	msg += ") , ";msg += "radius:";
	msg += to_string(sqrt((Corner2.x-Corner1.x) * (Corner2.x-Corner1.x) + (Corner2.y-Corner1.y) * (Corner2.y-Corner1.y)));
	out->PrintMessage(msg);
}

void Circ::stickimages(GUI* u)
{
	ShpGfxInfo.withimage = true;
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	string image = "images\\MenuIcons\\Menu_Play.jpg";
	u->draw_image(image, Corner1.x - 0.5 * rad, Corner1.y - 0.5 * rad, rad, rad);
}

void Circ::Save(ofstream& OutFile,int c) {
	OutFile << "Circ ";
	OutFile << " " << c<<"  ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
	if (ShpGfxInfo.isFilled) {
		OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue << " ";
	}
	else
		OutFile << "  No_fill  ";
	OutFile << ShpGfxInfo.BorderWdth << " ";
}

shape* Circ::copy()
{
	return new Circ(Corner1, Corner2, ShpGfxInfo);
}

void Circ::paste(int xx, int yy)
{
	int dx = Corner1.x - Corner2.x;
	int dy = Corner1.y - Corner2.y;
	Corner1.x = xx; Corner1.y = yy;
	Corner2.x = Corner1.x - dx;
	Corner2.y = Corner1.y - dy;
}