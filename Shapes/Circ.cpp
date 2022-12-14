#include "Circ.h"
Circ::Circ(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Circ::Circ()
{}
Circ::~Circ()
{}

void Circ::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Corner1, Corner2, ShpGfxInfo);
}

bool Circ::CheckSelect(int x, int y) const {
	if (!ShpGfxInfo.isHidden) {
		double rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
		double rad_2 = sqrt(((Corner1.x - x) * (Corner1.x - x)) + ((Corner1.y - y) * (Corner1.y - y)));
		if (rad_2 < rad) return true;
		else return false;
	}
	else if(ShpGfxInfo.isHidden) {
		Point ICorner1;Point ICorner2;
		ICorner1.x = Corner1.x - 175 / 2;ICorner1.y = Corner1.y - 175 / 2;
		ICorner2.x = Corner1.x + 175 / 2;ICorner2.y = Corner1.y + 175 / 2;
		if (x<ICorner1.x && x>ICorner2.x && y<ICorner1.y && y>ICorner2.y || x > ICorner1.x && x<ICorner2.x && y<ICorner1.y && y>ICorner2.y || x<ICorner1.x && x>ICorner2.x && y>ICorner1.y && y<ICorner2.y || x>ICorner1.x && x<ICorner2.x && y>ICorner1.y && y < ICorner2.y) {
			return true;
		}
		else
			return false;

	}
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

void Circ::Save(ofstream& OutFile,int c) {
	OutFile << "Circ";
	OutFile << " " << c<<" ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y;
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
	if (ShpGfxInfo.isFilled) {
		OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue;
	}
	else
		OutFile << "No_fill";
	OutFile <<" " << ShpGfxInfo.BorderWdth;
}
void Circ::Load(string line) {
	stringstream ss(line);
	string words[13];
	string word;
	int i = 0;
	while (getline(ss, word, ' ') && i < 13) { words[i++] = word; }
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

void Circ::RotateShape(){}

shape* Circ::copy()
{
	return new Circ(Corner1, Corner2, ShpGfxInfo);
}
void Circ::stickimages(GUI* u)
{
	ShpGfxInfo.withimage = true;
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	string image = "images\\MenuIcons\\Menu_Play.jpg";
	u->draw_image(image, Corner1.x - 0.5 * rad, Corner1.y - 0.5 * rad, rad, rad);
}

void Circ::paste(int xx, int yy)
{
	ShpGfxInfo.isSelected = false;
	int dx = Corner1.x - Corner2.x;
	int dy = Corner1.y - Corner2.y;
	Corner1.x = xx; Corner1.y = yy;
	Corner2.x = Corner1.x - dx;
	Corner2.y = Corner1.y - dy;
}

void Circ::scramble()
{
	int z = rand() % 1200;
	int p = rand() % 500 + 100;
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	Corner1.x = z;
	Corner1.y = p;
	Corner2.x = Corner1.x - rad;
	Corner2.y = Corner1.y;
	if (Corner1.x-rad < 0 || Corner1.x+rad > 1200)
	{
		scramble();
	}
	if (Corner1.y-rad < 70 || Corner1.y+rad > 600)
	{
		scramble();
	}
}

void Circ::resize(float a)
{
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	Corner2.y = Corner1.y;
	Corner2.x = Corner1.x - a * rad;
}

shape* Circ::duplicate() {
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	Point corner3;
	corner3.x = Corner1.x + 2* rad;
	corner3.y = Corner1.y;
	Point corner4;
	corner4.x = Corner2.x + 2 * rad;
	corner4.y = Corner2.y;
	GfxInfo info = ShpGfxInfo;
	ShpGfxInfo.isDuplicate = true;
	Circ* c = new Circ(corner3, corner4, info);
	return c;
}
void Circ::Move(int x, int y) {
	Corner1.x = Corner1.x + x;
	Corner2.x = Corner2.x + x;
	Corner1.y = Corner1.y + y;
	Corner2.y = Corner2.y + y;
}
void Circ::Hide(GUI* pGUI) {
	ShpGfxInfo.isHidden = true;
	int rad = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	string hide = "images\\Hide.jpg";
	pGUI->draw_image(hide, Corner1.x-(175/2), Corner1.y-(175/2), 175, 175);
}

string Circ::get_type() {
	return "Circ";
}

