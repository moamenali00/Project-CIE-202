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
	double area = 0.5 * abs((Corner1.x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y - Corner2.y)));
	double area_2 = 0.5 * abs((x * (Corner2.y - Corner3.y)) + (Corner2.x * (Corner3.y - y)) + (Corner3.x * (y - Corner2.y)));
	double area_3 = 0.5 * abs((Corner1.x * (y - Corner3.y)) + (x * (Corner3.y - Corner1.y)) + (Corner3.x * (Corner1.y -y)));
	double area_4 = 0.5 * abs((Corner1.x * (Corner2.y - y)) + (Corner2.x * (y - Corner1.y)) + (x * (Corner1.y - Corner2.y)));
	if (area == (area_2 + area_3 + area_4)) return true;
	else return false;
}
void Tri::PrintInfo(GUI* out) {
	out->ClearStatusBar();
	string msg;
	Point p1, p2, p3;
	p1.x = Corner1.x;p1.y = Corner1.y;
	p2.x = Corner2.x;p2.y = Corner2.y;
	p3.x = Corner3.x;p3.y = Corner3.y;
	msg = "The Vertices:(";
	msg += to_string(p1.x);msg += ",";
	msg += to_string(p1.y);msg += ") , (";
	msg += to_string(p2.x);msg += ")";
	msg += to_string(p2.y);msg += ") , (";
	msg += to_string(p3.x);msg += ",";
	msg += to_string(p3.y);msg += ")";
	out->PrintMessage(msg);
}

void Tri::stickimages(GUI* u)
{
	ShpGfxInfo.withimage = true;
	int minx, miny,maxx,maxy;
	if (Corner1.x <= Corner2.x && Corner1.x <= Corner3.x) {
		minx = Corner1.x;
	}
	else if (Corner3.x <= Corner2.x && Corner3.x <= Corner1.x) {
		minx = Corner3.x;
	}
	else {
		minx = Corner2.x;
	}
	if (Corner1.y <= Corner2.y && Corner1.y <= Corner3.y) {
		miny = Corner1.y;
	}
	else if (Corner3.y <= Corner2.y && Corner3.y <= Corner1.y) {
		miny = Corner3.y;
	}
	else {
		miny = Corner2.y;
	}
	if (Corner1.x >= Corner2.x && Corner1.x >= Corner3.x) {
		maxx = Corner1.x;
	}
	else if (Corner3.x >= Corner2.x && Corner3.x >= Corner1.x) {
		maxx = Corner3.x;
	}
	else {
		maxx = Corner2.x;
	}
	if (Corner1.y >= Corner2.y && Corner1.y >= Corner3.y) {
		maxy = Corner1.y;
	}
	else if (Corner3.y >= Corner2.y && Corner3.y >= Corner1.y) {
		maxy = Corner3.y;
	}
	else {
		maxy = Corner2.y;
	}
	string image = "images\\MenuIcons\\Menu_Play.jpg";
	u->draw_image(image, minx + 0.4 * (maxx - minx), miny + 0.4 * (maxy - miny), 0.5 * abs(Corner2.x - Corner1.x), 0.5 * abs(Corner2.y - Corner1.y));
}
void Tri::Save(ofstream& OutFile,int c) {
	OutFile << "Tri ";
	OutFile << " " << c<<" ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y<<" ";
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
	if (ShpGfxInfo.isFilled) {
		OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue<<" ";
	}
	else
		OutFile << "  No_fill  ";
	OutFile << ShpGfxInfo.BorderWdth << " ";
	
}

shape* Tri::copy()
{
	return new Tri(Corner1, Corner2, Corner3, ShpGfxInfo);
}
void Tri::paste(int xx, int yy)
{
	int dx = Corner1.x - Corner2.x;
	int dy = Corner1.y - Corner2.y;
	int dx1 = Corner1.x - Corner3.x;
	int dy1 = Corner1.y - Corner3.y;
	Corner1.x = xx; Corner1.y = yy;
	Corner2.x = Corner1.x - dx;
	Corner2.y = Corner1.y - dy;
	Corner3.x = Corner1.x - dx1;
	Corner3.y = Corner1.y - dy1;
}