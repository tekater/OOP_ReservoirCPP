#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Reservoir {
    int length; int width; int depth; 

    char* name;

    int area;
    int size;

    bool same = false;
public:
    Reservoir(const char* uname, int len, int wid, int dep) {
        name = new char[strlen(uname + 1)];
        strcpy(name, uname);
        length = len;
        width = wid;
        depth = dep;
    }
    Reservoir():Reservoir("None", 10, 10, 20) {}

    Reservoir(Reservoir& r) {
        name = new char[strlen(r.name) + 1];
        length = r.length;
        width = r.width;
        depth = r.depth;
        strcpy(name, r.name);
    }

    void ReSize(Reservoir& r) {
        if (length <= 0 || width <= 0 || depth <= 0) {
            cout << "Заполните значения.\n";
        }
        else {
            size = length * width * depth;
            cout << "Объём равен: " << width << endl;
        }
    }

    void ReArea(Reservoir& r) {
        r.area = r.length * r.width;
        cout << "Площадь равна: " << r.area << endl;
    }

    void ReWater(Reservoir& r, Reservoir& d) {
        if ((r.size <= 15 && r.size > 0) && (d.size <= 15 && d.size > 0)) {
            cout << "Эти водоёмы являются - Бассейнами.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size <= 40 && r.size > 15) && (d.size <= 40 && d.size > 15)) {
            cout << "Эти водоёмы являются - Прудами.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size <= 60 && r.size > 40) && (d.size <= 60 && d.size > 40)) {
            cout << "Эти водоёмы являются - Озёрами.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size <= 100 && r.size > 60) && (d.size <= 100 && d.size > 60)) {
            cout << "Эти водоёмы являются - Морями.\n";
            d.same = true; r.same = true;
        }
        else if ((r.size > 100) && (d.size > 100)) {
            cout << "Эти водоёмы являются - Океанами.\n";
            d.same = true; r.same = true;
        }
        else {
            cout << "Эти водоёмы разные.\n";
        }
    }
    void Sravnenie(Reservoir& r, Reservoir& d) {
        if (r.area == d.area) {
            cout << "Площади равны\n";
        }
        else {
            cout << "Площади не равны\n";
        }
    }
    void CopyLength(Reservoir& r, Reservoir& d) {
        r.length = d.length;
    }
    void CopyWidth(Reservoir& r, Reservoir& d) {
        r.width = d.width;
    }
    void CopyDepth(Reservoir& r, Reservoir& d) {
        r.depth = d.depth;
        
    }
    void CopyObject(Reservoir& r, Reservoir& d) {
        r.size = d.size;
        r.width = d.width;
        r.size = d.size;
        delete[] r.name;
        r.name = new char[strlen(d.name)+1];
        strcpy(r.name, d.name);
    }
    ~Reservoir() {
        delete[] name;
    }
};

void main() {

    setlocale(0, "");
    srand(time(NULL));

    Reservoir lake("Duviri",30,30,60);
    Reservoir lake2("Deimos",30,30,60);

    lake.ReArea(lake); lake.ReSize(lake); cout << "\n";
    lake2.ReArea(lake2); lake2.ReSize(lake2); cout << "\n";

    lake.Sravnenie(lake, lake2); cout << "\n";

    lake.ReWater(lake, lake2);
}
