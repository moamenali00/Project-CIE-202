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
	double dis = sqrt(((Corner1.x - Corner2.x) * (Corner1.x - Corner2.x)) + ((Corner1.y - Corner2.y) * (Corner1.y - Corner2.y)));
	double dis_2 = sqrt(((Corner1.x - x) * (Corner1.x - x)) + ((Corner1.y - y) * (Corner1.y - y)));
	double slope = (Corner1.x - Corner2.x) / (Corner1.y - Corner2.y);
	double slope_2 = (Corner1.x - x) / (Corner1.y - y);
	if (dis > dis_2 && slope == slope_2) return true;
	else return false;
}
void Line::PrintInfo(GUI* out) {
	out->ClearStatusBar();
	string msg;
	msg = "The First Point:(";
	msg += to_string(Corner1.x);msg += ",";
	msg += to_string(Corner1.y);msg += ")  ,  ";
	msg += "The Second Point:(";
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