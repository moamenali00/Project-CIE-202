#include"opLoad.h"
#include<fstream>
#include<sstream>
#include "..\shapes\Rect.h"
#include "..\shapes\Square.h"
#include"..\Shapes\Line.h"
opLoad::opLoad(controller* pCont) : operation(pCont)
{}
opLoad::~opLoad()
{}

void opLoad::Execute() {
	Point P1;Point P2;
	ifstream inFile;
	string line;
	string words[10][10];
	Graph* pGr = pControl->getGraph();
	GUI* UI = pControl->GetUI();
	inFile.open("output.txt");
	int i = 0;int j = 0;
	if (!inFile) {
		UI->PrintMessage("File operation faliure");
		return;
	}

	while (getline(inFile, line)) {
		stringstream ss(line);
		string word;
		while (ss >> word) {
			words[j++][i++] = word;
		}
	}

	for (int j = 1;j < 10;j++) {
		if (words[j][0] == "Rect") {
			GfxInfo RectGfxInfo;
			P1.x = stoi(words[j][2]);
			P1.y = stoi(words[j][3]);
			P2.x = stoi(words[j][4]);
			P2.y = stoi(words[j][5]);
			RectGfxInfo.DrawClr.ucRed = stoi(words[j][6]);
			RectGfxInfo.DrawClr.ucGreen = stoi(words[j][7]);
			RectGfxInfo.DrawClr.ucBlue = stoi(words[j][8]);
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
				SquareGfxInfo.DrawClr.ucRed = stoi(words[j][6]);
				SquareGfxInfo.DrawClr.ucGreen = stoi(words[j][7]);
				SquareGfxInfo.DrawClr.ucBlue = stoi(words[j][8]);
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
			LineGfxInfo.DrawClr.ucRed = stoi(words[j][6]);
			LineGfxInfo.DrawClr.ucGreen = stoi(words[j][7]);
			LineGfxInfo.DrawClr.ucBlue = stoi(words[j][8]);
			LineGfxInfo.BorderWdth = stoi(words[j][10]);
			if (words[j][9] == "Fill")
				LineGfxInfo.isFilled = true;
			Line* R = new Line(P1, P2, LineGfxInfo);
			pGr->Addshape(R);
		}


	}
}