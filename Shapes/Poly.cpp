#include "Poly.h"

Poly::Poly(int* Ix, int* Iy, int Ivertices, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	x = Ix;
	y = Iy;
	vertcies = Ivertices;

}

Poly::~Poly()
{}

void Poly::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawPolygon(x, y, vertcies, ShpGfxInfo);
}

double Poly::polygonArea(int X[], int Y[], int n) const
{
    // Initialize area
    double area = 0.0;

    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area / 2.0);
}
void Poly::PrintInfo(GUI* out) {
    out->ClearStatusBar();
    string msg;
    msg = "The number of vertices:";
    msg += to_string(vertcies);msg += " , ";
    msg += "The Area:";
    msg += to_string((int)polygonArea(x, y, vertcies));
    out->PrintMessage(msg);
}

bool Poly::CheckSelect(int x0, int y0) const {
    double area = 0;
    int j = vertcies - 1;
    for (int i = 0; i < vertcies; i++)
    {
        area = area + abs(0.5 * ((x0 * y[i]) - (x[i] * y0) + (x[i] * y[j]) - (x[j] * y[i]) + (x[j] * y0) - (x0 * y[j])));
        j = i;
    };
    double area2 = polygonArea(x, y, vertcies);
    if (area2 == area) return true;
    else return false;

}
void Poly::Save(ofstream& OutFile, int c) {
    OutFile << "Poly ";
    OutFile << " " << c << "  ";
    OutFile << " " << vertcies << " ";
    for (int i = 0; i < vertcies; i++)
    {
        OutFile << x[i] << " " << y[i] << " ";
    }
    OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
    if (ShpGfxInfo.isFilled) {
        OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue << " ";

    }
    else
        OutFile << "  No_fill  ";
    OutFile << ShpGfxInfo.BorderWdth;
}