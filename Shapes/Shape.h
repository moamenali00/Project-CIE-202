#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include<fstream>
#include<sstream>

//Base class for all shapes
class shape
{
protected:
	int ID;//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	shape();
	void setId(int);
	int getId()const;
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	void SetVisible(bool);
	bool IsSelected() const;	//check whether fig is selected
	bool IsVisible()const;
	bool IsDuplicated() const;
	virtual void Draw(GUI* pUI) const  = 0 ;
	virtual void stickimages(GUI* u) = 0;//Draw the shape
	bool iswithimage();
	bool isHide();
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	virtual bool CheckSelect(int, int)const = 0;
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	

	virtual void Hide(GUI* pGUI) = 0;
	virtual void RotateShape() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	virtual void Move(int,int) = 0;		//Move the shape

	virtual void Save(ofstream &OutFile,int c) = 0;	//Save the shape parameters to the file
	virtual void Load(string) = 0;	//Load the shape parameters to the file

	virtual void PrintInfo(GUI*) = 0;	//print all shape info on the status bar
	virtual shape* copy() = 0;
	virtual void paste(int xx, int yy) = 0;
	virtual void scramble() = 0;
	virtual void resize(float a) = 0;
	virtual shape* duplicate(GUI* pGUI) = 0;
	/*virtual void scrabmle_image(int xx, int yy) = 0;*/
};

