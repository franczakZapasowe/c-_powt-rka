#ifndef WEKTOR_H
#define WEKTOR_H

class Wektor {
    double m_x;
    double m_y;

public:
    // Konstruktory
    Wektor() : m_x(0.0), m_y(0.0) {}
    Wektor(double x, double y) : m_x(x), m_y(y) {}

    // Gettery
    double getX() const { return m_x; }
    double getY() const { return m_y; }

    // Settery
    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }
};


#endif // WEKTOR_H