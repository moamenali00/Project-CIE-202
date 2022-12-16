#include"opLoad.h"
#include<fstream>
#include<sstream>
#include "..\shapes\Rect.h"
#include "..\shapes\Square.h"
#include"..\Shapes\Line.h"
#include<iostream>
opLoad::opLoad(controller* pCont) : operation(pCont)
{}
opLoad::~opLoad()
{}

void opLoad::Execute() {
	Point P1;Point P2;Point P3;
	ifstream inFile;
	string line;
	string fline;
	Graph* pGr = pControl->getGraph();
	GUI* UI = pControl->GetUI();
	inFile.open("output.txt");
	getline(inFile, fline);
	int size=stoi(fline);
	if (!inFile) {
		UI->PrintMessage("File operation faliure");
		return;
	}
	string** words = new string * [size+1];
	for (int i = 0;i < size+1;i++) {
		words[i] = new string[11];
	}
	int j = 1;
	while (getline(inFile, line)) {
		stringstream ss(line);
		string word;
		for (int i = 0;i < 11 && j < size+1;i++) {
			ss >> word;
			words[j][i] = word;
		}
		j++;
	}
	for (int j = 1;j < size+1;j++) {
		if (words[j][0] == "Rect") {
			GfxInfo RectGfxInfo;
			P1.x = stoi(words[j][2]);
			P1.y = stoi(words[j][3]);
			P2.x = stoi(words[j][4]);
			P2.y = stoi(words[j][5]);
			RectGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][6].c_str());
			RectGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][7].c_str());
			RectGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][8].c_str());
			RectGfxInfo.BorderWdth = stoi(words[j][10]);
			if (words[j][9] == "Fill")
				RectGfxInfo.isFilled = true;
			Rect* R = new Rect(P1, P2, RectGfxInfo);
			pGr->Addshape(R);
		}
		else if (words[j][0] == "Square") {
				GfxInfo SquareGfxInfo;
				P1.x = stoi(words[j][2]);
				P1.y = stoi(words[j][3]);
				P2.x = stoi(words[j][4]);
				P2.y = stoi(words[j][5]);
				SquareGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][6].c_str());
				SquareGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][7].c_str());
				SquareGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][8].c_str());
				SquareGfxInfo.BorderWdth = stoi(words[j][10]);
				if (words[j][9] == "Fill")
					SquareGfxInfo.isFilled = true;
				Square* R = new Square(P1, P2, SquareGfxInfo);
				pGr->Addshape(R);
		}
		else if (words[j][0] == "Line") {
			GfxInfo LineGfxInfo;
			P1.x = stoi(words[j][2]);
			P1.y = stoi(words[j][3]);
			P2.x = stoi(words[j][4]);
			P2.y = stoi(words[j][5]);
			LineGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][6].c_str());
			LineGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][7].c_str());
			LineGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][8].c_str());
			LineGfxInfo.BorderWdth = stoi(words[j][10]);
			if (words[j][9] == "Fill")
				LineGfxInfo.isFilled = true;
			Line* R = new Line(P1, P2, LineGfxInfo);
			pGr->Addshape(R);
		}


	}
}