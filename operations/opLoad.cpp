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
	stringstream ss(line);
	string words[10];
	int i = 0;
	while (getline(ss, word, ' ') && i < 13) { words[i++] = word; }
	i = 0;
	unsigned Red = (unsigned char)atol(words[i++].c_str());
	unsigned Green = (unsigned char)atol(words[i++].c_str());
	unsigned Blue = (unsigned char)atol(words[i++].c_str());
	UI->setCrntPenColor(color(Red, Green, Blue));
	if (words[i++] == "fill") {
		UI->setFilledStatus(true);
		unsigned Red = (unsigned char)atol(words[i++].c_str());
		unsigned Green = (unsigned char)atol(words[i++].c_str());
		unsigned Blue = (unsigned char)atol(words[i++].c_str());
		UI->setCrntFillColor(color(Red, Green, Blue));
	}
	else UI->setFilledStatus(false);
	shape* R;
	getline(inFile, line);
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
}