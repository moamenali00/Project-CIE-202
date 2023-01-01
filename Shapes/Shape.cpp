#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 

	ShpGfxInfo = shapeGfxInfo;
	ShpGfxInfo.isSelected = false;
	//Default status is non-filled.
}
shape::shape(){}
void shape::SetVisible(bool s) {
	ShpGfxInfo.isVisible = s;
 }
bool shape::IsVisible()const {
	return ShpGfxInfo.isVisible;
}
void shape::setId(int x) {
	ID = x;
}
int shape::getId()const {
	return ID;
}
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }



void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

bool shape::iswithimage()
{
	return ShpGfxInfo.withimage;
}

