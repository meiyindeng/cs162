//
// Created by Meiyin Deng on 11/10/18.
//

#ifndef CHAPTER13OVERLOAD_RECTANGLE_H
#define CHAPTER13OVERLOAD_RECTANGLE_H


class Rectangle {
    friend void area(Rectangle rec);



    public:
    //function overload return the object
    //returnType operator#(const className&) const;

    Rectangle& operator= (Rectangle& rec);
    Rectangle operator+(const Rectangle& rec);
    Rectangle();
    Rectangle(int l, int w);
    void setWidth(int w);
    void setLength(int l);
    int getWidth(){
        return width;
    }

    int getLength(){
        return length;
    }


    private:
    int length;
    int width;


};


#endif //CHAPTER13OVERLOAD_RECTANGLE_H
