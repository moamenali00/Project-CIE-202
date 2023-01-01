#include "Tri.h"
Tri::Tri(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
Tri::Tri(){}
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
	msg += to_string(p2.x);msg += ",";
	msg += to_string(p2.y);msg += ") , (";
	msg += to_string(p3.x);msg += ",";
	msg += to_string(p3.y);msg += ")";
	out->PrintMessage(msg);
}
void Tri::Save(ofstream& OutFile,int c) {
	OutFile << "Tri";
	OutFile << " " << c<<" ";
	OutFile << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y;
	OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue;
	if (ShpGfxInfo.isFilled) {
		OutFile <<" " << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue;
	}
	else
		OutFile <<" "<<"No_fill";
	OutFile <<" " << ShpGfxInfo.BorderWdth << " ";
	
}
void Tri::Load(string line) {
	stringstream ss(line);
	string words[17];
	string word;
	int i = 0;
	while (getline(ss, word, ' ') && i < 17) {
		words[i++] = word;
	}
	i = 2;
	Corner1.x = stoi(words[i++]);
	Corner1.y = stoi(words[i++]);
	Corner2.x = stoi(words[i++]);
	Corner2.y = stoi(words[i++]);
	Corner3.x = stoi(words[i++]);
	Corner3.y = stoi(words[i++]);
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

void Tri::RotateShape(){}