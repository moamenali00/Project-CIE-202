#include "Line.h"

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Line::Line(){}
Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawLine(Corner1, Corner2, ShpGfxInfo);
}

bool Line::CheckSelect(int x, int y) const {
	if (!ShpGfxInfo.isHidden) {
		double dis = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
		double dis_2 = sqrt(((Corner1.x - x) * (Corner1.x - x)) + ((Corner1.y - y) * (Corner1.y - y)));
		double slope = (Corner1.x - Corner2.x) / (Corner1.y - Corner2.y);
		double slope_2 = (Corner1.x - x) / (Corner1.y - y);
		if (dis > dis_2 && slope == slope_2) return true;
		else return false;
	}
	else if (ShpGfxInfo.isHidden) {
	Point ICorner1;Point ICorner2;
	Point center;
	center.x = abs(Corner1.x + Corner2.x) / 2;
	center.y = abs(Corner1.y + Corner2.y) / 2;
	ICorner1.x = center.x - 175 / 2;ICorner1.y = center.y - 175 / 2;
	ICorner2.x = center.x + 175 / 2;ICorner2.y = center.y + 175 / 2;
	if (x<ICorner1.x && x>ICorner2.x && y<ICorner1.y && y>ICorner2.y || x > ICorner1.x && x<ICorner2.x && y<ICorner1.y && y>ICorner2.y || x<ICorner1.x && x>ICorner2.x && y>ICorner1.y && y<ICorner2.y || x>ICorner1.x && x<ICorner2.x && y>ICorner1.y && y < ICorner2.y) {
		return true;
	}
	else
		return false;

	}
}

void Line::PrintInfo(GUI* out) {
	out->ClearStatusBar();
	string msg;
	msg = "The Initial Point:(";
	msg += to_string(Corner1.x);msg += ",";
	msg += to_string(Corner1.y);msg += ") , ";
	msg += "The Final Point:(";
	msg += to_string(Corner2.x);msg += ",";
	msg += to_string(Corner2.y);msg += ")";
	out->PrintMessage(msg);
}
void Line::Save(ofstream& OutFile,int c) {
	OutFile << "Line";
	OutFile << " "<<c<<" ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
	OutFile <<(int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
	OutFile << "No_fill";
	OutFile <<" "<< ShpGfxInfo.BorderWdth;

}
void Line::Load(string line) {
	stringstream ss(line);
	string words[13];
	string word;
	int i = 0;
	while (getline(ss, word, ' ') && i < 13) {words[i++] = word;}
	i = 2;
	Corner1.x = stoi(words[i++]);
	Corner1.y = stoi(words[i++]);
	Corner2.x = stoi(words[i++]);
	Corner2.y = stoi(words[i++]);
	unsigned Red = (unsigned char)atol(words[i++].c_str());
	unsigned Green = (unsigned char)atol(words[i++].c_str());
	unsigned Blue = (unsigned char)atol(words[i++].c_str());
	ShpGfxInfo.DrawClr = color(Red, Green, Blue);
	ShpGfxInfo.BorderWdth = stoi(words[++i]);
	ShpGfxInfo.isFilled = false;
}

Point Line::rotate_point(double cx, double cy, double angle, Point p)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	p.x -= cx;
	p.y -= cy;

	// rotate point
	float xnew = p.x * c - p.y * s;
	float ynew = p.x * s + p.y * c;

	// translate point back:
	p.x = int(xnew + cx);
	p.y = int(ynew + cy);
	return p;
}
void Line::RotateShape() {
	Point center,p1,p2;
	center.x = abs(Corner1.x + Corner2.x) / 2;
	center.y = abs(Corner1.y + Corner2.y) / 2;
	p1 = rotate_point(center.x, center.y, acos(0), Corner1);
	p2 = rotate_point(center.x, center.y, acos(0), Corner2);
	Corner1 = p1;
	Corner2 = p2;
}
void Line::stickimages(GUI* u)
{
}
shape* Line::copy()
{
	return new Line(Corner1, Corner2, ShpGfxInfo);
}
void Line::paste(int xx, int yy)
{
	ShpGfxInfo.isSelected = false;
	int dx = Corner1.x - Corner2.x;
	int dy = Corner1.y - Corner2.y;
	Corner1.x = xx; Corner1.y = yy;
	Corner2.x = Corner1.x - dx;
	Corner2.y = Corner1.y - dy;
}

void Line::scramble()
{
	int z = rand() % 1200;
	int p = rand() % 500 + 100;
	int dx = Corner1.x - Corner2.x;
	int dy = Corner1.y - Corner2.y;
	Corner1.x = z;
	Corner1.y = p;
	Corner2.x = Corner1.x - dx;
	Corner2.y = Corner1.y - dy;
	if (Corner2.x < 0 || Corner2.x > 1200)
	{
		scramble();
	}
	if (Corner2.y < 70 || Corner2.y > 600)
	{
		scramble();
	}
}

void Line::resize(float a)
{
	int avgx, avgy;
	avgx = (Corner1.x + Corner2.x) / 2;
	avgy = (Corner1.y + Corner2.y) / 2;
	int dx;
	dx = abs(Corner1.x - Corner2.x) * a * 0.5;
	int dy;
	dy = abs(Corner1.y - Corner2.y) * a * 0.5;
	if (Corner1.x < Corner2.x)
	{
		Corner1.x = avgx - dx;
		Corner2.x = avgx + dx;
	}
	else
	{
		Corner2.x = avgx - dx;
		Corner1.x = avgx + dx;
	}
	if (Corner1.y < Corner2.y)
	{
		Corner1.y = avgy - dy;
		Corner2.y = avgy + dy;
	}
	else
	{
		Corner2.y = avgy - dy;
		Corner1.y = avgy + dy;
	}
}
void Line::Move(int x, int y) {
	Corner1.x = Corner1.x + x;
	Corner2.x = Corner2.x + x;
	Corner1.y = Corner1.y + y;
	Corner2.y = Corner2.y + y;
}



shape* Line::duplicate() {
	Point p1, p2;
	p1.x = Corner1.x + 25;
	p1.y = Corner1.y;
	p2.x = Corner2.x + 25;
	p2.y = Corner2.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicate = true;
	Line* L = new Line(p1, p2, info);
	return L;
}

void Line::Hide(GUI* pGUI) {
	Point center;
	center.x = abs(Corner1.x + Corner2.x) / 2;
	center.y = abs(Corner1.y + Corner2.y) / 2;
	ShpGfxInfo.isHidden = true;
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	string hide = "images\\Hide.jpg";
	pGUI->draw_image(hide, center.x-(175/2), center.x - (175 / 2), 175, 175);
}

string Line::get_type() {
	return "Line";
}