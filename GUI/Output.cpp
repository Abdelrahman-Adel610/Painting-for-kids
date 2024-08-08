#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;
	string x = "images\\MenuItems\\White.jpg";
	pWind->DrawImage(x, UI.MenuItemWidth, 0, 20 * UI.MenuItemWidth, UI.ToolBarHeight);
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hex.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\selection.jpg";
	MenuItemImages[ITM_COLORd] = "images\\MenuItems\\DRAWCLR.jpg";
	MenuItemImages[ITM_COLORf] = "images\\MenuItems\\FILL.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_DRAG] = "images\\MenuItems\\drag.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\bin.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\clean.jpg";
	MenuItemImages[ITM_RECORD] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAY_RECORD] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_VOICE] = "images\\MenuItems\\voice.jpg";
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\games.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\logout.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth - 8, UI.ToolBarHeight - 4);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateDrawToolBarFill()const
{
	UI.InterfaceMode = MODE_DRAW_FILLCLR;
	string x = "images\\MenuItems\\White.jpg";
	pWind->DrawImage(x, UI.MenuItemWidth, 0, 20 * UI.MenuItemWidth, UI.ToolBarHeight);
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hex.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\selection.jpg";
	MenuItemImages[ITM_COLORd] = "images\\MenuItems\\DRAWCLR.jpg";
	MenuItemImages[ITM_COLORf] = "images\\MenuItems\\drawcolors.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_DRAG] = "images\\MenuItems\\drag.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\bin.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\clean.jpg";
	MenuItemImages[ITM_RECORD] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAY_RECORD] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_VOICE] = "images\\MenuItems\\voice.jpg";
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\games.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\logout.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth - 8, UI.ToolBarHeight - 4);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
void Output::CreateDrawToolBarDraw()const
{
	UI.InterfaceMode = MODE_DRAW_DRAW_CLR;
	string x = "images\\MenuItems\\White.jpg";
	pWind->DrawImage(x, UI.MenuItemWidth, 0, 20 * UI.MenuItemWidth, UI.ToolBarHeight);
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem

	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\square.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\hex.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\selection.jpg";
	MenuItemImages[ITM_COLORd] = "images\\MenuItems\\drawcolors.jpg";
	MenuItemImages[ITM_COLORf] = "images\\MenuItems\\FILL.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_DRAG] = "images\\MenuItems\\drag.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\bin.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\clean.jpg";
	MenuItemImages[ITM_RECORD] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLAY_RECORD] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_VOICE] = "images\\MenuItems\\voice.jpg";
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\games.jpg";
	MenuItemImages[ITM_EXIT1] = "images\\MenuItems\\logout.jpg";

	//TODO: Prepare images for each menu item and add it to the list
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth - 8, UI.ToolBarHeight - 4);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string x = "images\\MenuItems\\White.jpg";
	pWind->DrawImage(x, UI.MenuItemWidth, 0, 25 * UI.MenuItemWidth, UI.ToolBarHeight);
	string MenuItemImage[PLAY_ITM_COUNT];
	MenuItemImage[ITM_PICK_FIGURE] = "images\\MenuItems\\shapes.jpg";
	MenuItemImage[ITM_PICK_COLOR] = "images\\MenuItems\\rgb.jpg";
	MenuItemImage[ITM_PICK_COLORED_FIGURE] = "images\\MenuItems\\shapes1.jpg";
	MenuItemImage[ITM_RESET] = "images\\MenuItems\\undo.jpg";
	MenuItemImage[ITM_VOICE1] = "images\\MenuItems\\voice.jpg";
	MenuItemImage[ITM_DRAW_MODE] = "images\\MenuItems\\draw.jpg";
	MenuItemImage[ITM_EXIT2] = "images\\MenuItems\\logout.jpg";
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImage[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth - 10, UI.ToolBarHeight - 5);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
bool Output::isValid(Point p, double ly, double lx)const
{
	Input pIn(pWind);
	if (p.y > UI.ToolBarHeight + 3 + ly && p.y < UI.height - UI.StatusBarHeight - 3 - ly && p.x>0 + lx && p.x < UI.width - 20 - lx)
	{
		return true;
	}
	else
	{
		PrintMessage("Invalid Points , Can't Draw The Shape Out Of Drawing Area !");
		pIn.GetPointClicked(p.x, p.y);
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
string Output::clrtostr(color c)
{
	if (c == RED)
		return "RED";
	else if (c == BLACK)
		return "BLACK";
	else if (c == ORANGE)
		return "ORANGE";
	else if (c == GREEN)
		return "GREEN";
	else if (c == YELLOW)
		return "YELLOW";
	else if (c == BLUE)
		return"BLUE";
	else
		return "NO_COLOR";
}
color Output::strtoclr(string s)
{
	if (s == "RED")
		return RED;
	else if (s == "BLACK")
		return BLACK;
	else if (s == "ORANGE")
		return ORANGE;
	else if (s == "GREEN")
		return GREEN;
	else if (s == "YELLOW")
		return YELLOW;
	else if (s == "BLUE")
		return BLUE;
	else
		return LIGHTBLUE;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected) const
{
	double HFlength = 75;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(P1.x - HFlength, P1.y - HFlength, P1.x + HFlength, P1.y + HFlength, style);
}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TritGfxInfo, bool selected) const
{
	color DrawingClr;
	drawstyle style;

	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = TritGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	if (TritGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TritGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawHex(Point P1, GfxInfo HexGfxInfo, bool selected) const
{
	double length = 75;
	color DrawingClr;
	drawstyle style;
	int x[6] = { P1.x - length / 2,P1.x + length / 2,P1.x + length,P1.x + length / 2,P1.x - length / 2,P1.x - length };
	int y[6] = { P1.y - sqrt(3) * length / 2.0, P1.y - sqrt(3) * length / 2.0,P1.y,P1.y + sqrt(3) * length / 2.0, P1.y + sqrt(3) * length / 2.0, P1.y };
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 1);
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else style = FRAME;
	pWind->DrawPolygon(x, y, 6, style);
}

void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	double radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}
Output::~Output()
{
	delete pWind;
}