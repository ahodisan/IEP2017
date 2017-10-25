#ifndef PIN_H
#define PIN_H


class Pin
{
public:
    Pin(int numar,int directia,int starea);  //starea - for input pins (pull-up)
    void change();
    void set(int p);
    int get(int stare);
protected:
    int numar;
    int directia;
    int stare;
};



#endif // PIN_H
