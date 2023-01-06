#include "resize.h"
//#include"..\operations\resize.h"

resize::resize(controller* pCont) :operation(pCont)
{}
resize::~resize()
{}

//Execute the operation
void resize::Execute()
{
	float a;
	GUI* busy = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	busy->PrintMessage("Enter the ratio to resize: ");
	string s = busy->GetSrting();
	a = stof(s);
	pGr->resize(a);

}
void resize::Undo() {
	Graph* pGr = pControl->getGraph();
	pGr->Undo('s');
};
void resize::Redo() {
	Graph* pGr = pControl->getGraph();
	pGr->Redo('s');
}

