#include"opLoad.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include "..\shapes\Rect.h"
#include "..\shapes\Square.h"
#include"..\Shapes\Line.h"
#include"..\Shapes\Tri.h"
#include"..\Shapes\Circ.h"
#include"..\Shapes\Poly.h"
#include"..\Shapes\Rpoly.h"
opLoad::opLoad(controller* pCont) : operation(pCont)
{}
opLoad::~opLoad()
{}

void opLoad::Execute() {
	ifstream inFile;
	string word;
	string line;
	Graph* pGr = pControl->getGraph();
	GUI* UI = pControl->GetUI();
	UI->PrintMessage("Enter the file name(relative address)");
	inFile.open(UI->GetSrting());
	if (inFile.fail()) {
		UI->PrintMessage("File operation faliure");
		return;
	}
	UI->ClearStatusBar();
	getline(inFile, line);
	int size = stoi(line);
	shape* R;
	while (getline(inFile, line)) {
		stringstream ss(line);
		ss >> word;
		if (word == "Rect") R = new Rect();
		else if (word == "Square") R = new Square();
		else if (word == "Line") R = new Line();
		else if (word == "Circ") R = new Circ();
		else if (word == "Tri") R = new Tri();
		else if (word == "Poly") R = new Poly();
		else if (word == "RPoly")R = new Rpoly();
		R->Load(line);
		R->SetSelected(false);
		pGr->Addshape(R);

	}
	inFile.close();
}/*
		}
		else if (words[j][0] == "RPoly") {
			GfxInfo RPolyGfxInfo;
			int vertices = stoi(words[j][i++]);
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			unsigned Red = (unsigned char)atol(words[j][i++].c_str());
			unsigned Green = (unsigned char)atol(words[j][i++].c_str());
			unsigned Blue = (unsigned char)atol(words[j][i++].c_str());
			RPolyGfxInfo.DrawClr = color(Red, Green, Blue);
			if (words[j][i] == "No_fill") {
				RPolyGfxInfo.isFilled = false;
				RPolyGfxInfo.BorderWdth = stoi(words[j][++i]);
			}
			else {
				RPolyGfxInfo.isFilled = true;
				unsigned char Red = (unsigned char)atol(words[j][i++].c_str());
				unsigned char Green = (unsigned char)atol(words[j][i++].c_str());
				unsigned char Blue = (unsigned char)atol(words[j][i++].c_str());
				RPolyGfxInfo.BorderWdth = stoi(words[j][i]);
				RPolyGfxInfo.FillClr = color(Red, Green, Blue);
			}
			Rpoly* R = new Rpoly(P1, P2,vertices, RPolyGfxInfo);
			R->SetSelected(false);
			pGr->Addshape(R);
		}
		

	}
}*/