#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include<fstream>
#include<sstream>

//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	shape();
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	void SetVisible(bool);
	bool IsSelected() const;	//check whether fig is selected
	bool IsVisible()const;
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	void stickimages();
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	virtual bool CheckSelect(int, int)const = 0;
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	virtual void RotateShape() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void Save(ofstream &OutFile,int c) = 0;	//Save the shape parameters to the file
	virtual void Load(string) = 0;	//Load the shape parameters to the file

	virtual void PrintInfo(GUI*) = 0;	//print all shape info on the status bar
};

