// Лекция 14 Бинарные файлы
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class Point
{
    double x, y;
public:
    double rast0()
    {
        return sqrt(x*x + y*y);
    }
    int prov()
    {
        if(x>0 && y>0) return 1;
        else if(x<0 && y>0) return 2;
        else if(x<0 && y<0) return 3;
        else if(x>0 && y<0) return 4;
    }
    double rast(Point& t)
    {
        return sqrt((x-t.x)*(x-t.x) + (y-t.y)*(y-t.y));
    }
    Point(){}
    Point(double xv, double yv)
    {
        x = xv;
        y = yv;
    }
    Point(Point& t)
    {
        x = t.x;
        y = t.y;
    }
    void print()
    {
        cout<< x << " " << y << endl;
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
    void set(double xv, double yv)
    {
        x = xv;
        y = yv;
    }
};

class File 
{
public:
    File(){}
    void file_bin_sozd(string st, Point* t, int n)
    {
        fstream f;
        int i;
        f.open(st, ios::binary | ios::out);
        // int size = sizeof(Point);
        for(int i =0; i < n; i++)
        {
            f.write((char*)& t[i], (int)sizeof(Point)); // столько то байтов (sizeof) записать побайтово (char*) и взять их из t[i]
        }
        f.close();
    }
    void wwod_f(string st)
    {
        fstream f;
        int i, len;
        Point p;
        f.open(st, ios::binary | ios::in);
        len = sizeof(Point);
        cout << endl;
        while(f.read((char*)& p, len))
        {
            cout << p.get_x() << " " << p.get_y() << endl;
        }
    }
    Point* nwod_bin(string st)
    {
        Point* z;
        fstream f;
        int i, j, len, size, m;
        f.open(st, ios::binary | ios::in | ios::out); //! открытый таким образом файл не затирается
        f.seekg(0, ios::end);
        len = f.tellg();
        size = sizeof(Point);
        m = len/ size;

        f.seekg(0, ios::beg);
        z = new Point[m];
        cout << endl;
        for(i = 0; i < m; i++)
        {
            f.read((char*)&z[i], size);
            cout << z[i].get_x() << " " << z[i].get_y() << endl;
        }
        f.close();
        return z;
    }
    void file_bin_mod(string st)
    {
        fstream f;
        int len, i, m, size;
        Point p;
        f.open(st, ios::binary | ios::in | ios::out);
        f.seekg(0, ios::end);
        len = f.tellg();
        size = sizeof(Point);
        m = len/ size;

        f.seekg(0, ios::beg);
        for(i = 0; i < m; i++)
        {
            f.seekg(size*i, ios::beg);
            f.read((char*)&p, size);
            
            p.set(p.get_x() + i, p.get_y() + i);
            f.seekg(-size, ios::cur);
            f.write((char*)&p, size);
        }

    }
};

int main()
{

    double xc[] = {4,3,7,1,9,5};
    double yc[] = {5,8,1,9,3,1};
    int n = 6;

    Point* p = new Point[n];

    for(int i = 0; i < n; i++)
    {
        p[i].set(xc[i],yc[i]);
        p[i].print();
    }
    
    File f;
    string file_name = "4.File_v1.dat";
    f.file_bin_sozd(file_name,p,n);
    f.wwod_f(file_name);

    Point* pp = f.nwod_bin(file_name);

    f.file_bin_mod(file_name);
    f.wwod_f(file_name);

    delete [] p;
    delete [] pp;

    return 0;
}