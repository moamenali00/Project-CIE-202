#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isstick = false;
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	bool isVisible=true;
	bool withimage = false;
	bool isDuplicate = false;
	bool isHidden = false;
	Point IP, FP;
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_PLAY,
		ICON_LINE,
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu
		ICON_TRIANGLE,
		ICON_SQUARE,
		ICON_POLY,	
		ICON_IPOLY,//Circle icon in menu
		ICON_SAVE,
		ICON_DELETE,
		ICON_LOAD,
		ICON_FILL,
		ICON_PEN,
		ICON_ROT,
		/*ICON_COLOR,
		ICON_LOAD,*/
		ICON_COPY,
		ICON_PASTE,
		ICON_SCRAMBLE,
		ICON_DUPLICATE,
		ICON_STICK,
		ICON_RESIZE,
		ICON_UNDO,
		ICON_REDO,
		//TODO: Add more icons names here

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here

		ICON_DRAW,
		ICON_START,
		ICON_HIDE,
		ICON_UNHIDE,
		ICON_MATCH,
		ICON_RESTART,
		//TODO: Add more icons names here
		ICON_EXIT2,

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu

	bool FillStatus;
	color Default_Drawcolor;
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed




public:
	Point P;
	window* pWind;
	GUI();
	Point ReturnPointClicked();
	void ReturnMouseCoordinates(Point&);
	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() ; //Read the user click and map to an operation
	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	color CreateColorPallete();
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void draw_image(string h, int k, int e, int z, int w);
	void ClearToolBar() const; 
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGFxInfo) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGFxInfo) const;
	//void DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo);
	void DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo) const;
	void DrawPolygon(int* X, int* Y, int iVertices, GfxInfo PolyGfxInfo) const;
	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	bool getFilledStatus() const;
	color getDefaultDrawColor() const;
	bool getGUIMode() const;

	void setCrntPenColor(color);
	void setCrntFillColor(color clr);
	void setFilledStatus(bool);

	~GUI();
};

