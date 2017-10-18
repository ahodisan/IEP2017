#ifndef PIN_H
#define PIN_H

class Pin
{
    public:
        int get();
        void set(int pinNo);
        void changeDirection(int dir);

    private:
        int pinNo;
        int direction; //0-input; 1-output
        int pullUpState;  //for input pins

    protected:
}

#endif // PIN_H
