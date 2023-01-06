#include "Poly.h"
#include <vector>
Poly::Poly(int* Ix, int* Iy, int Ivertices, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	x = Ix;
	y = Iy;
	vertcies = Ivertices;

}
Poly::Poly(){
   
}

Poly::~Poly()
{
    delete[] x;delete[] y;
    x = nullptr;y = nullptr;
}

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
void Poly::stickimages(GUI* u)
{
    ShpGfxInfo.withimage = true;
    int maxx = x[0], minx = x[0], maxy = y[0], miny = y[0];
    for (int i = 0; i < vertcies; i++)
    {
        if (x[i] > maxx)
            maxx = x[i];
        else if (x[i] < minx)
            minx = x[i];
        if (y[i] > maxy)
            maxy = y[i];
        else if (y[i] < miny)
            miny = y[i];
    }
    string image = "images\\MenuIcons\\Menu_Play.jpg";
    u->draw_image(image, minx + 0.5 * abs(maxx - maxx), miny + 0.5 * abs(maxy - miny), 0.25 * abs(maxx - minx), 0.25 * abs(maxy - miny));

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
    OutFile << "Poly";
    OutFile << " " << c;
    OutFile << " " << vertcies << " ";
    for (int i = 0; i < vertcies; i++)
    {
        OutFile << x[i] << " " << y[i] << " ";
    }
    OutFile << (int)ShpGfxInfo.DrawClr.ucRed << " " << (int)ShpGfxInfo.DrawClr.ucGreen << " " << (int)ShpGfxInfo.DrawClr.ucBlue<<" ";
    if (ShpGfxInfo.isFilled) {
        OutFile << (int)ShpGfxInfo.FillClr.ucRed << " " << (int)ShpGfxInfo.FillClr.ucGreen << " " << (int)ShpGfxInfo.FillClr.ucBlue;

    }
    else
        OutFile <<"No_fill";
    OutFile <<" "<< ShpGfxInfo.BorderWdth;
}
void Poly::Load(string line) {
    stringstream ss(line);
    string word;
    int i = 0;
    int size = 2*(int)line[7] + 10;
    string* words = new string[size];
    while (getline(ss, word, ' ') && i < size) { words[i++] = word; }
    vertcies = stoi(words[2]);
    x = new int[vertcies];
    y = new int[vertcies];
    int d = 0;
    for (int c = 0;c < vertcies;c++, ++d) {
        x[c] = stoi(words[3 + 2 * d]);
        y[c] = stoi(words[4 + 2 * (d)]);
    }
    i = 3 + 2 * vertcies;
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
    delete[]words;
    words = nullptr;

}

void Poly::RotateShape(){}
shape* Poly::copy()
{
    int* xx = new int[vertcies];
    int* yy = new int[vertcies];
    for (int i = 0; i < vertcies; i++)
    {
        xx[i] = x[i];
        yy[i] = y[i];
    }
    return new Poly(xx, yy, vertcies, ShpGfxInfo);
}
void Poly::paste(int xx, int yy)
{
    ShpGfxInfo.isSelected = false;
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
}

void Poly::scramble()
{
    int z = rand() % 1200;
    int p = rand() % 500 + 100;
    vector <int> dx;
    vector <int> dy;
    for (int i = 1; i < vertcies; i++)
    {
        dx.push_back(x[0] - x[i]);
        dy.push_back(y[0] - y[i]);
    }
    x[0] = z; y[0] = p;
    for (int i = vertcies - 1; i > 0; i--)
    {
        x[i] = x[0] - dx.back();
        dx.pop_back();
        y[i] = y[0] - dy.back();
        dy.pop_back();
    }
    for (int i = vertcies - 1; i > 0; i--)
    {
        if (x[i] < 0 || x[i] > 1200)
        {
            scramble();
        }
        if (y[i] < 70 || y[i] > 600)
        {
            scramble();
        }
    }
}

void Poly::resize(float a)
{
    for (int i = 0; i < vertcies; i++)
    {
        int avgx, avgy;
        avgx = (x[i] + x[(i + 1) % vertcies]) / 2;
        avgy = (y[i] + y[(i + 1) % vertcies]) / 2;
        int dx;
        dx = abs(x[i] - x[(i + 1) % vertcies]) * a * 0.5;
        int dy;
        dy = abs(y[i] - y[(i + 1) % vertcies])* a * 0.5;
        if (x[i] < x[(i + 1) % vertcies])
        {
            x[i] = avgx - dx;
            x[(i + 1) % vertcies] = avgx + dx;
        }
        else
        {
            x[(i + 1) % vertcies] = avgx - dx;
            x[i] = avgx + dx;
        }
        if (y[i] < y[(i + 1) % vertcies])
        {
            y[i] = avgy - dy;
            y[(i + 1) % vertcies] = avgy + dy;
        }
        else
        {
            y[(i + 1) % vertcies] = avgy - dy;
            y[i] = avgy + dy;
        }
    }
}
void Poly::Move(int x1, int y2) {
    for (int i = 0;i < vertcies;i++) {
        x[i] =x[i] + x1;
        y[i] = y[i] + y2;
    } 
}


shape* Poly::duplicate(GUI* pGUI) {
    int* x1 = new int[vertcies];
    int* y1 =new int[vertcies];
    for (int i = 0; i < vertcies; i++)
    {
        x1[i] = x[i] +50;
        y1[i] = y[i] ;
    }
    GfxInfo info = ShpGfxInfo;
    ShpGfxInfo.isDuplicate = true;
    Poly* p = new Poly(x1, y1, vertcies, info);
    return p;
}
void Poly::Hide(GUI* pGUI) {
    ShpGfxInfo.isHidden = true;
    int min_x = x[0];
    int min_y=y[0];
    int max_x = x[0];
    int max_y = y[0];
    for (int i = 1; i < vertcies; i++)
    {
        if (x[i] < min_x)
            min_x = x[i];

        if (x[i] > max_x)
            max_x = x[i];
    }
    for (int i = 1; i < vertcies; i++)
    {
        if (y[i] < min_y)
            min_y = y[i];

        if (y[i] > max_y)
            max_y = y[i];
    }
    int rad = sqrt(((min_x - max_x) * (min_x - max_x)) + ((min_y -max_y) * (min_y - max_y)));
    string hide = "images\\Hide.jpg";
    pGUI->draw_image(hide, min_x,min_y,  rad, rad);
}

string Poly::get_type() {
    return "Poly";
}