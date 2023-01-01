#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Rect::Rect(){}

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
void Rect::PrintInfo(GUI* out) {
	out->ClearStatusBar();
	string msg;
	Point p1, p2, p3, p4;
	p1.x = Corner1.x;p1.y = Corner1.y;
	p2.x = Corner1.x;p2.y = Corner2.y;
	p3.x = Corner2.x;p3.y = Corner1.y;
	p4.x = Corner2.x;p4.y = Corner2.y;
	msg = "The Vertices:(";
	msg += to_string(p1.x);msg += ",";
	msg += to_string(p1.y);msg += ") , (";
	msg += to_string(p2.x);msg += ",";
	msg += to_string(p2.y);msg += ") , (";
	msg += to_string(p3.x);msg += ",";
	msg += to_string(p3.y);msg += ") , (";
	msg += to_string(p4.x);msg += ",";
	msg += to_string(p4.y);msg += ")";
	out->PrintMessage(msg);
}
void Rect::stickimages(GUI*u)
{
	ShpGfxInfo.withimage = true;
	int minx, miny;
	if (Corner1.x > Corner2.x) {
		minx = Corner2.x;
	}
	else {
		minx = Corner1.x;
	}
	if (Corner1.y > Corner2.y) {
		miny = Corner2.y;
	}
	else {
		miny = Corner1.y;
	}
	string image = "images\\MenuIcons\\Menu_Play.jpg";
	u->draw_image(image, minx + 0.1 * abs(Corner2.x - Corner1.x), miny + 0.1 * abs(Corner2.y - Corner1.y), abs(Corner2.x - Corner1.x) * 0.7, abs(Corner2.y - Corner1.y) * 0.7);
}
void Rect::Save(ofstream& OutFile,int c) {
	OutFile << "Rect";
	OutFile << " " << c<<" ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y;
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed<< " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
	if (ShpGfxInfo.isFilled) {
		OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue;
	}
	else
		OutFile << "No_fill";
	OutFile <<" " << ShpGfxInfo.BorderWdth;

}
<<<<<<< HEAD

shape* Rect::copy()
{
	return new Rect(Corner1, Corner2, ShpGfxInfo);
}
void Rect::paste(int xx, int yy)
{
	int dx = Corner1.x - Corner2.x;
	int dy = Corner1.y - Corner2.y;
	Corner1.x = xx; Corner1.y = yy;
	Corner2.x = Corner1.x - dx;
	Corner2.y = Corner1.y - dy;
=======
void Rect::Load(string line) {
	stringstream ss(line);
	string words[13];
	string word;
	int i = 0;
	while (getline(ss, word, ' ')&&i<13) {
		words[i++] = word;
	}
	i = 2;
	Corner1.x = stoi(words[i++]);
	Corner1.y = stoi(words[i++]);
	Corner2.x = stoi(words[i++]);
	Corner2.y = stoi(words[i++]);
	unsigned Red = (unsigned char)atol(words[i++].c_str());
	unsigned Green = (unsigned char)atol(words[i++].c_str());
	unsigned Blue = (unsigned char)atol(words[i++].c_str());
	ShpGfxInfo.DrawClr = color(Red, Green, Blue);
	if (words[i] == "No_fill") {
		ShpGfxInfo.isFilled = false;
		ShpGfxInfo.BorderWdth = stoi(words[++i]);
	}
	else {
		ShpGfxInfo.isFilled = true;
		unsigned char Red = (unsigned char)atol(words[i++].c_str());
		unsigned char Green = (unsigned char)atol(words[i++].c_str());
		unsigned char Blue = (unsigned char)atol(words[i++].c_str());
		ShpGfxInfo.BorderWdth = stoi(words[i]);
		ShpGfxInfo.FillClr = color(Red, Green, Blue);
	}
}
Point Rect::rotate_point(double cx, double cy, double angle, Point p) {
	double s = sin(angle);
	double c = cos(angle);

	// translate point back to origin:
	p.x -= cx;
	p.y -= cy;

	// rotate point
	double xnew = p.x * c - p.y * s;
	double ynew = p.x * s + p.y * c;

	// translate point back:
	p.x = double(xnew + cx);
	p.y = double(ynew + cy);
	return p;
}

void Rect::RotateShape(){
	Point center, p1, p2;
	center.x = (Corner1.x + Corner2.x) / 2.0;
	center.y = (Corner1.y + Corner2.y) / 2.0;
	Corner1 = rotate_point(center.x, center.y, (2 * atan(1)), Corner1);
	Corner2 = rotate_point(center.x, center.y, (2 * atan(1)), Corner2);
	/*Corner1 = p1;
	Corner2 = p2;*/

>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
}