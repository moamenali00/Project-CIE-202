#include "shape.h"
#include<ctime>
#include <chrono>
#include <thread>


	

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;
	ShpGfxInfo.isstick = false;
	//Default status is non-filled.
}
shape::shape(){}
void shape::SetVisible(bool s) {
	ShpGfxInfo.isVisible = s;
 }
bool shape::IsVisible()const {
	return ShpGfxInfo.isVisible;
}
bool shape::isHide() {
	if (ShpGfxInfo.isHidden) return true;
	else return false;
}
bool shape:: IsDuplicated() const {
	if (ShpGfxInfo.isDuplicate) { return true; }
	else return false;
}
void shape::unHide(GUI* pGUI) {
	ShpGfxInfo.isHidden = false;
	
	//ShpGfxInfo.isHidden = true;
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

bool shape::iswithimage()
{
	return ShpGfxInfo.withimage;
}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

