#include "opAddscramble_image.h"
#include"..\operations\opAddcopy.h"

opAddscramble_image::opAddscramble_image(controller* pCont) :operation(pCont)
{}
opAddscramble_image::~opAddscramble_image()
{}

//Execute the operation
void opAddscramble_image::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	pGr->scramble_image();

}