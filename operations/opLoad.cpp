#include"opLoad.h"
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
	Point P1;Point P2;Point P3;
	ifstream inFile;
	string line;
	string fline;
	Graph* pGr = pControl->getGraph();
	GUI* UI = pControl->GetUI();
	UI->PrintMessage("Enter the file name(relative address)");
	inFile.open(UI->GetSrting());
	getline(inFile, fline);
	int size = stoi(fline);
	if (!inFile) {
		UI->PrintMessage("File operation faliure");
		return;
	}
	string** words = new string * [size + 1];
	for (int i = 0;i < size + 1;i++) {
		words[i] = new string[300];
	}
	int j = 1;
	while (getline(inFile, line)) {
		stringstream ss(line);
		string word;
		for (int i = 0;i < 300 && j < size + 1;i++) {
			ss >> word;
			words[j][i] = word;
		}
		j++;
	}
	inFile.close();
	for (int j = 1;j < size + 1;j++) {
		int i = 2;
		if (words[j][0] == "Rect") {
			GfxInfo RectGfxInfo;
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			unsigned Red = (unsigned char)atol(words[j][i++].c_str());
			unsigned Green = (unsigned char)atol(words[j][i++].c_str());
			unsigned Blue = (unsigned char)atol(words[j][i++].c_str());
			RectGfxInfo.DrawClr=color(Red, Green, Blue);
			if (words[j][i] == "fill") {
				unsigned char Red = (unsigned char)atol(words[j][++i].c_str());
				unsigned char Green = (unsigned char)atol(words[j][++i].c_str());
				unsigned char Blue = (unsigned char)atol(words[j][++i].c_str());
				RectGfxInfo.FillClr = color(Red, Green, Blue);
			}
			else {
				RectGfxInfo.isFilled = false;
			}
			RectGfxInfo.BorderWdth = stoi(words[j][++i]);
			Rect* R = new Rect(P1, P2, RectGfxInfo);

			R->SetSelected(false);
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
			if (words[j][i] == "fill") {
				SquareGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				SquareGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				SquareGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i].c_str());
			}
			SquareGfxInfo.BorderWdth = stoi(words[j][++i]);
			Square* R = new Square(P1, P2, SquareGfxInfo);
			R->SetSelected(false);
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
			LineGfxInfo.BorderWdth = stoi(words[j][i++]);
			Line* R = new Line(P1, P2, LineGfxInfo);
			R->SetSelected(false);
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
			R->SetSelected(false);
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
			R->SetSelected(false);
			pGr->Addshape(R);
		}
		else if (words[j][0] == "Poly") {
			GfxInfo PolyGfxInfo;
			int vertices = stoi(words[j][2]);
			int* X = new int[vertices];
			int* Y = new int[vertices];
			int d = 0;
			for (int c = 0;c < vertices;c++,++d) {
				X[c] = stoi(words[j][3+2*d]);
				Y[c] = stoi(words[j][4+2*(d)]);
			}
			int i = 3 + 2 * vertices;
			PolyGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			PolyGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			PolyGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				PolyGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				PolyGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				PolyGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			PolyGfxInfo.BorderWdth = stoi(words[j][i++]);
			Poly* R = new Poly(X,Y,vertices, PolyGfxInfo);
			R->SetSelected(false);
			pGr->Addshape(R);
		}
		else if (words[j][0] == "RPoly") {
			GfxInfo RPolyGfxInfo;
			int vertices = stoi(words[j][i++]);
			P1.x = stoi(words[j][i++]);
			P1.y = stoi(words[j][i++]);
			P2.x = stoi(words[j][i++]);
			P2.y = stoi(words[j][i++]);
			RPolyGfxInfo.DrawClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
			RPolyGfxInfo.DrawClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
			RPolyGfxInfo.DrawClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			if (words[j][i++] == "fill") {
				RPolyGfxInfo.FillClr.ucRed = (unsigned char)atol(words[j][i++].c_str());
				RPolyGfxInfo.FillClr.ucGreen = (unsigned char)atol(words[j][i++].c_str());
				RPolyGfxInfo.FillClr.ucBlue = (unsigned char)atol(words[j][i++].c_str());
			}
			RPolyGfxInfo.BorderWdth = stoi(words[j][i]);
			Rpoly* R = new Rpoly(P1, P2, vertices, RPolyGfxInfo);
			R->SetSelected(false);
			pGr->Addshape(R);
		}

	}
}