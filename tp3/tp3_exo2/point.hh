#pragma once

class point
{
public:
    point(const int &x, const int &y);
    point(point const &p);
    ~point();
    int const & getX()const {return _x;}
    int const & getY()const {return _y;}
    void afficher()const;
private:
    int _x;
    int _y;
};
