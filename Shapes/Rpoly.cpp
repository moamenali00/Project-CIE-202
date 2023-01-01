#include "Rpoly.h"
<<<<<<< HEAD
#include <vector>

=======
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
Rpoly::Rpoly(Point Icenter, Point Ivertex, int Ivertices, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
    center = Icenter;
    vertex=Ivertex;
    vertcies = Ivertices;
    x = new int[vertcies];
    y = new int[vertcies];
    this->set_x_y();
}
Rpoly::Rpoly() {
    
}
Rpoly::~Rpoly()
{    delete[] x;delete[] y;
    x = nullptr;y = nullptr;
}

Point Rpoly::rotate_point(double cx, double cy, double angle, Point p)
{
    float s = sin(angle);
    float c = cos(angle);

    // translate point back to origin:
    p.x -= cx;
    p.y -= cy;

    // rotate point
    float xnew = p.x * c - p.y * s;
    float ynew = p.x * s + p.y * c;

    // translate point back:
    p.x = int(xnew + cx);
    p.y = int(ynew + cy);
    return p;
}

void Rpoly::set_x_y() {
    for (int i = 0; i < vertcies; i++)
    {
        Point p = rotate_point(center.x, center.y, (i+1) * (4* acos(0.0) / vertcies), vertex);
        x[i] = p.x;
        y[i] = p.y;
    }
}

void Rpoly::Draw(GUI* pUI) const
{
    //Call Output::DrawRect to draw a rectangle on the screen	
    pUI->DrawPolygon(x, y, vertcies, ShpGfxInfo);
}

double Rpoly::RpolygonArea(int X[], int Y[], int n) const
{
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

bool Rpoly::CheckSelect(int x0, int y0) const {
    int j = vertcies - 1;
    double area = 0.0;
    for (int i = 0; i < vertcies; i++)
    {
        area = area + abs(0.5 * ((x0 * y[i]) - (x[i] * y0) + (x[i] * y[j]) - (x[j] * y[i]) + (x[j] * y0) - (x0 * y[j])));
        j = i;
    };
    double area2 = RpolygonArea(x, y, vertcies);
    if (area2 == area) return true;
    else return false;
}
void Rpoly::PrintInfo(GUI* out) {
    out->ClearStatusBar();
    string msg;
    msg = "The number of vertices:";
    msg += to_string(vertcies);msg += " , ";
    msg += "The Area:";
    msg += to_string((int)RpolygonArea(x,y,vertcies));
    out->PrintMessage(msg);
}

void Rpoly::stickimages(GUI* u)
{
    ShpGfxInfo.withimage = true;
    string image = "images\\MenuIcons\\Menu_Play.jpg";
    u->draw_image(image, x[0] + 0.1 * abs(x[0] - x[2]), y[0] + 0.1 * abs(y[0] - y[1]), 0.5 * abs(x[0] - x[2]), 1.5 * abs(y[0] - y[1]));
}
    

void Rpoly::Save(ofstream& OutFile, int c) {
    OutFile << "RPoly";
    OutFile << " " << c << " ";
    OutFile << vertcies << " "<<center.x<<" "<<center.y<<" "<<vertex.x<<" "<<vertex.y;
    OutFile << " " << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
    if (ShpGfxInfo.isFilled) {
        OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue;
    }
    else
<<<<<<< HEAD
        OutFile << "  No_fill  ";
    OutFile << ShpGfxInfo.BorderWdth;
}

shape* Rpoly::copy()
{
    return new Rpoly(center, vertex, vertcies, ShpGfxInfo);
}
void Rpoly::paste(int xx, int yy)
{
    vector <int> dx;
    vector <int> dy;
    for (int i = 1; i < vertcies; i++)
    {
        dx.push_back(x[0] - x[i]);
        dy.push_back(y[0] - y[i]);
    }
    x[0] = xx; y[0] = yy;
    for (int i = vertcies - 1; i > 0; i--)
    {
        x[i] = x[0] - dx.back();
        dx.pop_back();
        y[i] = y[0] - dy.back();
        dy.pop_back();
    }
=======
        OutFile << "No_fill";
    OutFile <<" "<< ShpGfxInfo.BorderWdth;
}
void Rpoly::Load(string line) {
    stringstream ss(line);
    string word;
    int i = 0;
    string words[14];
    while (getline(ss, word, ' ') && i < 14) { words[i++] = word; }
    i = 2;
    vertcies = stoi(words[i++]);
    center.x = stoi(words[i++]);
    center.y = stoi(words[i++]);
    vertex.x = stoi(words[i++]);
    vertex.y = stoi(words[i++]);
    unsigned Red = (unsigned char)atol(words[i++].c_str());
    unsigned Green = (unsigned char)atol(words[i++].c_str());
    unsigned Blue = (unsigned char)atol(words[i++].c_str());
    ShpGfxInfo.DrawClr = color(Red, Green, Blue);
    if (words[i] == "No_fill") {
        ShpGfxInfo.isFilled = false;
        ShpGfxInfo.BorderWdth = stoi(words[++i]);
    }
    else {
        ShpGfxInfo.isFilled = true;
        unsigned char Red = (unsigned char)atol(words[i++].c_str());
        unsigned char Green = (unsigned char)atol(words[i++].c_str());
        unsigned char Blue = (unsigned char)atol(words[i++].c_str());
        ShpGfxInfo.BorderWdth = stoi(words[i]);
        ShpGfxInfo.FillClr = color(Red, Green, Blue);
    }
        x = new int[vertcies];
        y = new int[vertcies];
        this->set_x_y();
    }

void Rpoly::RotateShape(){
    Point p1;
    p1 = rotate_point(center.x, center.y, acos(0), vertex);
    vertex = p1;
    set_x_y();
>>>>>>> abfe30e4dfbd771719b66cdc148e004e5e8eccb8
}