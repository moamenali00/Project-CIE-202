#include"opLoad.h"
#include<fstream>
#include<sstream>
#include "..\shapes\Rect.h"
#include "..\shapes\Square.h"
#include"..\Shapes\Line.h"
#include"..\Shapes\Tri.h"
#include"..\Shapes\Circ.h"
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
	UI->ClearDrawArea();
	inFile.open("output.txt");
	getline(inFile, fline);
	int size = stoi(fline);
	if (!inFile) {
		UI->PrintMessage("File operation faliure");
		return;
	}
	string** words = new string * [size + 1];
	for (int i = 0;i < size + 1;i++) {
		words[i] = new string[17];
	}
	int j = 1;
	while (getline(inFile, line)) {
		stringstream ss(line);
		string word;
		for (int i = 0;i < 14 && j < size + 1;i++) {
			ss >> word;
			words[j][i] = word;
		}
		j++;
	}
	for (int j = 1;j < size + 1;j++) {
		int i = 2;
		if (words[j][0] == "Rect") {
			GfxInfo RectGfxInfo;
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			RectGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			RectGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			RectGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				RectGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				RectGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				RectGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			RectGfxInfo.BorderWdth = stoi(words[j][i]);
			Rect* R = new Rect(P1, P2, RectGfxInfo);
			pGr->Addshape(R);
		}
		else if (words[j][0] == "Square") {
			GfxInfo SquareGfxInfo;
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			SquareGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			SquareGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			SquareGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				SquareGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				SquareGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				SquareGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			SquareGfxInfo.BorderWdth = stoi(words[j][i++]);
			Square* R = new Square(P1, P2, SquareGfxInfo);
			pGr->Addshape(R);
		}
		else if (words[j][0] == "Line") {
			GfxInfo LineGfxInfo;
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			LineGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			LineGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			LineGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				LineGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				LineGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				LineGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			LineGfxInfo.BorderWdth = stoi(words[j][i++]);
			Line* R = new Line(P1, P2, LineGfxInfo);
			pGr->Addshape(R);
		}
		else if (words[j][0] == "Circ") {
			GfxInfo CircGfxInfo;
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			CircGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			CircGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			CircGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				CircGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				CircGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				CircGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			CircGfxInfo.BorderWdth = stoi(words[j][i++]);
			Circ* R = new Circ(P1, P2, CircGfxInfo);
			pGr->Addshape(R);

		}
		else if (words[j][0] == "Tri") {
			GfxInfo TriGfxInfo;
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			P3.x = stoi(words[j][i++]);
			P3.y = stoi(words[j][i++]);
			TriGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			TriGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			TriGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				TriGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				TriGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				TriGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			TriGfxInfo.BorderWdth = stoi(words[j][i++]);
			Tri* R = new Tri(P1, P2, P3, TriGfxInfo);
			pGr->Addshape(R);
		}

	}
}