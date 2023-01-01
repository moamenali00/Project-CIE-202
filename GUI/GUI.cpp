#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 70;
	MenuIconWidth = 70;

	FillStatus = false;
	Default_Drawcolor = BLUE;
	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
Point GUI::ReturnPointClicked() {
	return P;
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() 
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	P.x = x;
	P.y = y;
	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_PLAY: return TO_PLAY;
			case ICON_STICK:return STICKIMAGE;
			case ICON_LINE: return DRAW_LINE;
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_TRIANGLE: return DRAW_TRI;
			case ICON_SQUARE: return DRAW_SQUARE;
			case ICON_POLY: return DRAW_POLY;
			case ICON_IPOLY: return DRAW_IPOLY;
			case ICON_SAVE: return SAVE;
			case ICON_DELETE: return DEL;
			case ICON_LOAD: return LOAD;
			case ICON_FILL: return CHNG_FILL_CLR;
			case ICON_PEN: return CHNG_DRAW_CLR;
			case ICON_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_DRAW: return TO_DRAW;
			case ICON_START: return START;
			case ICON_HIDE: return HIDE;
			case ICON_UNHIDE: return UNHIDE;
			case ICON_MATCH: return MATCH;
			case ICON_RESTART: return RESTART;
			case ICON_EXIT2: return EXIT;

			default: return EMPTY;	
			}
		}

		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearToolBar() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, 70);
}

void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}

color GUI::CreateColorPallete()
{
	pWind->DrawImage("images\\Color_Palette.jpg", 140, 0, 1160, 70);
	pWind->DrawImage("images\\Undo.jpg", 0, 0, 70, 70);
	pWind->DrawImage("images\\Default.jpg", 70, 0, 70, 70);
	pWind->SetBuffering(0);
	GetPointClicked(P.x, P.y);
	color clr = pWind->GetColor(P.x, P.y);
	ClearToolBar();
	CreateDrawToolBar();
	return clr;
}

//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_PLAY] = "images\\MenuIcons\\Menu_Play.jpg";
	MenuIconImages[ICON_STICK] = "images\\MenuIcons\\menu_Stick.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_TRIANGLE] = "images\\MenuIcons\\Menu_Triangle.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Menu_Square.jpg";
	MenuIconImages[ICON_POLY] = "images\\MenuIcons\\Menu_Poly.jpg";
	MenuIconImages[ICON_IPOLY] = "images\\MenuIcons\\Menu_IPoly.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Del.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_PEN] = "images\\MenuIcons\\Menu_Pen.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_DRAW] = "images\\MenuIcons\\Menu_Draw.jpg";
	MenuIconImages[ICON_START] = "images\\MenuIcons\\Menu_Start.jpg";
	MenuIconImages[ICON_HIDE] = "images\\MenuIcons\\Menu_Hide.jpg";
	MenuIconImages[ICON_UNHIDE] = "images\\MenuIcons\\Menu_Unhide.jpg";
	MenuIconImages[ICON_MATCH] = "images\\MenuIcons\\Menu_Match.jpg";
	MenuIconImages[ICON_RESTART] = "images\\MenuIcons\\Menu_Restart.jpg";
	MenuIconImages[ICON_EXIT2] = "images\\MenuIcons\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

void GUI::setCrntFillColor(color clr) {
	FillColor = clr;
}

void GUI::setFilledStatus(bool y)
{
	FillStatus = y;
}

void GUI::setCrntPenColor(color clr) {
	DrawColor = clr;
}

bool GUI::getFilledStatus() const
{
	return FillStatus;
}

color GUI::getDefaultDrawColor() const
{
	return Default_Drawcolor;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGFxInfo) const
{
	color DrawingClr;
	if (LineGFxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = LineGFxInfo.DrawClr;
	pWind->SetPen(DrawingClr, LineGFxInfo.BorderWdth);

	drawstyle style;
	if (LineGFxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGFxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}



void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	if (RectGfxInfo.isstick) {
		string image = "images\\MenuIcons\\Menu_Exit.jpg";
		pWind->DrawImage(image, P1.x , P1.y, abs(P2.x-P1.x), abs(P2.y - P1.y));
	}

}

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGFxInfo) const
{
	color DrawingClr;
	if (TriGFxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriGFxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGFxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriGFxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGFxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	if (TriGFxInfo.isstick) {
		string image = "images\\MenuIcons\\Menu_Exit.jpg";
		pWind->DrawImage(image, P1.x , P1.y, abs(P2.x-P1.x), abs(P2.y - P1.y));
	}
}

void GUI::DrawCircle(Point P1, Point P2, GfxInfo CircGfxInfo) const 
{
	color DrawingClr;
	if (CircGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int rad;
	rad = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));
	/*double x, y;
	x = (P1.x + P2.x) / 2;
	y = (P1.y + P2.y) / 2;
	P1.x = x;
	P1.y = y;*/
	pWind->DrawCircle(P1.x, P1.y, rad, style);
	if (CircGfxInfo.isstick) {
		string image = "images\\MenuIcons\\Menu_Exit.jpg";
		pWind->DrawImage(image, P1.x - rad, P1.y, rad, rad);
	}
}

void GUI::DrawPolygon(int* X, int* Y, int iVertices, GfxInfo PolyGfxInfo) const
{
	color DrawingClr;
	if (PolyGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = PolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (PolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(X, Y, iVertices, style);
	if (PolyGfxInfo.isstick) {
		string image = "images\\MenuIcons\\Menu_Exit.jpg";
		pWind->DrawImage(image, X[0], Y[0], 10, 10);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

