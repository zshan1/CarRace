//
//  shapes.hpp
//  final project
//
//  Created by shan on 4/14/17.
//  Copyright © 2017 shan. All rights reserved.
//

#ifndef shapes_hpp
#define shapes_hpp

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>

using namespace std;


struct color {
    double red;
    double green;
    double blue;
};

class Game{
public:
    Game();
    virtual string getName() const;
    virtual void setName(string n);
    
private:
    string name;

};
class Map : public Game{
public:
    Map();
    Map(color f);
    Map(double r, double g, double b);
    
    virtual color getFill() const;
    virtual int getScore() const;
    virtual void setFill(color f);
    virtual void setFill(double r, double g, double b);
    virtual void setScore(int p);
    
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the shape on the canvas
     */
    virtual void draw() const = 0;
protected:
    color fill;
    int score;
};

class Point2D {
public:
    Point2D();
    Point2D(int xIn, int yIn);
    
    int getX() const;
    int getY() const;
    
    void setX(int xIn);
    void setY(int yIn);
    void setPoint(int xIn, int yIn);
    
    /**
     * Requires: nothing
     * Modifies: x and y
     * Effects: moves the point by xOffset units along the x-axis
     *          and yOffset units along the y-axis
     */
    void movePoint(int xOffset, int yOffset);
    
    // returns the distance between p1 and p2
    static double distance(const Point2D &p1, const Point2D &p2);
private:
    int x;
    int y;
};

class Coord{
public:
    Coord();
    
    
//    Point2D getCenter() const;
//    int getCenterX() const;
//    int getCenterY() const;
    
    Point2D getTopLeft() const;
    int getTopLeftX() const;
    int getTopLeftY() const;
    Point2D getTopRight() const;
    int getTopRightX() const;
    int getTopRightY() const;
    Point2D getBottomLeft() const;
    int getBottomLeftX() const;
    int getBottomLeftY() const;
    Point2D getBottomRight() const;
    int getBottomRightX() const;
    int getBottomRightY() const;
    
    
//    void setCenterX(int xIn);
//    void setCenterY(int yIn);
//    void setCenter(Point2D centerIn);
//    void setCenter(int xIn, int yIn);
    void setTopLeft(Point2D topLeftIn);
    void setTopLeft(int xIn, int yIn);
    void setTopRight(Point2D topRightIn);
    void setTopRight(int xIn, int yIn);
    void setBottomLeft(Point2D bottomLeftIn);
    void setBottomLeft(int xIn, int yIn);
    void setBottomRight(Point2D bottomRightIn);
    void setBottomRight(int xIn, int yIn);
    
    virtual void setHeight(double h);
    virtual void setWidth(double w);
    
    virtual double getHeight() const;
    virtual double getWidth() const;
    
    void setOutsideColor(double r, double g, double b);
//    void move(int xOffset, int yOffset);
    bool isOverlapping(const Point2D &p) const;
    bool isOverlapping(int xIn, int yIn) const;
    
    // requires r.getWidth() <= width and r.getHeight() <= height
    // returns true if the shape overlaps with the shape parameter
    // if any of the parameter's four corners overlap with the shape,
    // returns true. Otherwise returns false.
    bool isOverlapping(const Coord &r) const;
    bool isOverlapping(const Point2D &p1, const Point2D &p2, const Point2D &p3, const Point2D &p4) const;
    bool isOverlapping(int xIn1, int yIn1, int xIn2, int yIn2, int xIn3, int yIn3, int xIn4, int yIn4) const;

protected:
    double height;
    double width;
    
private:
//    Point2D center;
    Point2D topLeft;
    Point2D topRight;
    Point2D bottomLeft;
    Point2D bottomRight;
    
};

class Car : public Map{
public:
    Car();

    Coord a;
    Car(Coord coord);
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the shape on the canvas
     */
    void setCoord(Coord coord);
    virtual void draw() const override;
    virtual void move(int x, int y);

};

class Barrier : public Map{
public:
    Barrier();

    Coord a;
    Barrier(Coord coord);
   
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the shape on the canvas
     */
    void setCoord(Coord coord);
    virtual void draw() const override;
    virtual void move(int x, int y);
};

class Lane : public Map{
public:
    Lane();
    
    Coord a;
    Lane(Coord coord);
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the shape on the canvas
     */
    void setCoord(Coord coord);
    virtual void move(int x, int y);
    virtual void draw() const override;
};

class Button : public Map{
public:
    Button();
    
    Coord a;
    Button(Coord coord);
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: draws the shape on the canvas
     */
    void setCoord(Coord coord);
    virtual void draw() const override;
};


#endif /* shapes_hpp */
