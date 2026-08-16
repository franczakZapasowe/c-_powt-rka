#include <iostream>
#include <array>
#include <cmath>


class Punk2d {
    double x_,y_;
public:
    Punk2d():x_(0),y_(0){}
    Punk2d(double x,double y):x_(x),y_(y){}
    void setX(double x){x_=x;}
    void setY(double y){y_=y;}
    void setXY(double x,double y){setX(x);setY(y);}
    double getX()const{return x_;}
    double getY()const{return y_;}
    std::array<double,2> getXY()const {
        std::array<double,2> p={x_,y_};
        return p;
    }
    void przesunPunkt(double x,double y) {
        x_+=x;
        y_+=y;
    }
    double odlegoscOdPunktu(const Punk2d& punktu) {
        return sqrt((punktu.x_ - x_) * (punktu.x_ - x_) + (punktu.y_ - y_) * (punktu.y_ - y_) );
    }

    Punk2d& operator =(const Punk2d& punktu) {
        x_=punktu.x_;
        y_=punktu.y_;
        return *this;
    }

    friend bool operator==(const Punk2d& punktu, const Punk2d& punktu2);
    friend bool operator!=(const Punk2d& punktu, const Punk2d& punktu2);
    friend bool operator<(const Punk2d& punktu, const Punk2d& punktu2);
    friend bool operator>(const Punk2d& punktu, const Punk2d& punktu2);
    friend bool operator<=(const Punk2d& punktu, const Punk2d& punktu2);
    friend bool operator>=(const Punk2d& punktu, const Punk2d& punktu2);
};

bool operator==(const Punk2d& punktu, const Punk2d& punktu2) {
    if (punktu.x_ == punktu2.x_ && punktu.y_ == punktu2.y_)
        return true;
    return false;
}

bool operator!=(const Punk2d& punktu, const Punk2d& punktu2) {
    if (punktu.x_ != punktu2.x_ || punktu.y_ != punktu2.y_)
        return true;
    return false;
}

bool operator<(const Punk2d& punktu, const Punk2d& punktu2) {
    double d1 = sqrt(punktu.x_ * punktu.x_ + punktu.y_ * punktu.y_);
    double d2 = sqrt(punktu2.x_ * punktu2.x_ + punktu2.y_ * punktu2.y_);
    if (d1 < d2)
        return true;
    return false;
}

bool operator>(const Punk2d& punktu, const Punk2d& punktu2) {
    double d1 = sqrt(punktu.x_ * punktu.x_ + punktu.y_ * punktu.y_);
    double d2 = sqrt(punktu2.x_ * punktu2.x_ + punktu2.y_ * punktu2.y_);
    if (d1 > d2)
        return true;
    return false;
}

bool operator<=(const Punk2d& punktu, const Punk2d& punktu2) {
    double d1 = sqrt(punktu.x_ * punktu.x_ + punktu.y_ * punktu.y_);
    double d2 = sqrt(punktu2.x_ * punktu2.x_ + punktu2.y_ * punktu2.y_);
    if (d1 <= d2)
        return true;
    return false;
}

bool operator>=(const Punk2d& punktu, const Punk2d& punktu2) {
    double d1 = sqrt(punktu.x_ * punktu.x_ + punktu.y_ * punktu.y_);
    double d2 = sqrt(punktu2.x_ * punktu2.x_ + punktu2.y_ * punktu2.y_);
    if (d1 >= d2)
        return true;
    return false;
}

int main() {


    return 0;
}