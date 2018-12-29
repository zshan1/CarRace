//
//  shapes.cpp
//  final project
//
//  Created by shan on 4/14/17.
//  Copyright © 2017 shan. All rights reserved.
//
#include "shapes.hpp"
#include "graphs.hpp"

Game::Game(){
    
}

string Game::getName() const{
    return name;
}

void Game::setName(string n){
    name = n;
}


Map::Map(){
    
}
Map::Map(color f) : fill(f) {
}

Map::Map(double r, double g, double b) : fill({r, g, b}) {
}

color Map::getFill() const {
    return fill;
}
void Map::setFill(color f) {
    fill = f;
}

void Map::setFill(double r, double g, double b) {
    fill = {r, g, b};
}

int Map::getScore() const{
    return score;
}

void Map::setScore(int p){
    score = p;
}
Point2D::Point2D() : x(0), y(0) {
}
Point2D::Point2D(int xIn, int yIn) : x(xIn), y(yIn) {
}
int Point2D::getX() const {
    return x;
}
int Point2D::getY() const {
    return y;
}
void Point2D::setX(int xIn) {
    x = xIn;
}
void Point2D::setY(int yIn) {
    y = yIn;
}
void Point2D::setPoint(int xIn, int yIn) {
    x = xIn;
    y = yIn;
}
void Point2D::movePoint(int xOffset, int yOffset) {
    x += xOffset;
    y += yOffset;
}
double Point2D::distance(const Point2D &p1, const Point2D &p2) {
    return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX()) +
                (p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
}

Coord::Coord() {
//    center = Point2D();
    topLeft = Point2D();
    topRight = Point2D();
    bottomLeft = Point2D();
    bottomRight = Point2D() ;
}

//Point2D Coord::getCenter() const{
//    return center;
//}

//int Coord::getCenterX() const {
//    return center.getX();
//}
//int Coord::getCenterY() const {
//    return center.getY();
//}
Point2D Coord::getTopLeft() const {
    return topLeft;
}
Point2D Coord::getTopRight() const {
    return topRight;
}
Point2D Coord::getBottomLeft() const {
    return bottomLeft;
}
Point2D Coord::getBottomRight() const {
    return bottomRight;
}
int Coord::getTopLeftX() const {
    return topLeft.getX();
}
int Coord::getTopLeftY() const {
    return topLeft.getY();
}
int Coord::getTopRightX() const {
    return topRight.getX();
}
int Coord::getTopRightY() const {
    return topRight.getY();
}
int Coord::getBottomLeftX() const {
    return bottomLeft.getX();
}
int Coord::getBottomLeftY() const {
    return bottomLeft.getY();
}
int Coord::getBottomRightX() const {
    return bottomRight.getX();
}
int Coord::getBottomRightY() const {
    return bottomRight.getY();
}
//void Coord::setCenter(Point2D centerIn) {
//    center = centerIn;
//}
//void Coord::setCenter(int xIn, int yIn) {
//    center.setPoint(xIn, yIn);
//}
void Coord::setTopLeft(Point2D topLeftIn) {
    topLeft = topLeftIn;
}
void Coord::setTopRight(Point2D topRightIn) {
    topRight = topRightIn;
}
void Coord::setBottomLeft(Point2D bottomLeftIn) {
    bottomLeft = bottomLeftIn;
}
void Coord::setBottomRight(Point2D bottomRightIn) {
    bottomRight = bottomRightIn;
}
void Coord::setTopLeft(int xIn, int yIn) {
    topLeft.setPoint(xIn, yIn);
}
void Coord::setTopRight(int xIn, int yIn) {
    topRight.setPoint(xIn, yIn);
}
void Coord::setBottomLeft(int xIn, int yIn) {
    bottomLeft.setPoint(xIn, yIn);
}
void Coord::setBottomRight(int xIn, int yIn) {
    bottomRight.setPoint(xIn, yIn);
}
//void Coord::move(int xOffset, int yOffset) {
//    center.setPoint(getCenterX() + xOffset, getCenterY() + yOffset);
//}
bool Coord::isOverlapping(const Point2D &p) const {
    return isOverlapping(p.getX(), p.getY());
}
bool Coord::isOverlapping(int xIn, int yIn) const {
    if (xIn < getTopLeftX()) {
        // out of bounds to the left of the coord
        return false;
    }
    if (xIn > getTopRightX()) {
        // out of bounds to the right of the coord
        return false;
    }
    if (yIn < getTopLeftY()) {
        // out of bounds above the coord
        return false;
    }
    if (yIn > getBottomLeftY()) {
        // out of bounds below the coord
        return false;
    }
    return true;
}
bool Coord::isOverlapping(const Coord &r) const {
    if (isOverlapping(r.getTopLeftX(), r.getTopLeftY())) {
        // the top left corner of r overlaps with the coord
        return true;
    }
    if (isOverlapping(r.getTopRightX(), r.getTopRightY())) {
        // the top right corner of r overlaps with the coord
        return true;
    }
    if (isOverlapping(r.getBottomLeftX(), r.getBottomLeftY())) {
        // the bottom right corner of r overlaps with the coord
        return true;
    }
    if (isOverlapping(r.getBottomRightX(), r.getBottomRightY())) {
        // the bottom left corner of r overlaps with the coord
        return true;
    }
    return false;
}

void Coord::setWidth(double w){
    width = w;
}
void Coord::setHeight(double h){
    height = h;
}
double Coord::getHeight() const{
    return height;
}
double Coord::getWidth() const{
    return width;
}

Car::Car(){
    
}

Car::Car(Coord coord){
    a = coord;
}

void Car::setCoord(Coord coord){
    a = coord;
}

void Car::move(int x, int y){
    a.setBottomLeft(a.getBottomLeftX()+x,a.getBottomLeftY()+y);
    a.setBottomRight(a.getBottomRightX()+x,a.getBottomRightY()+y);
    a.setTopLeft(a.getTopLeftX()+x,a.getTopLeftY()+y);
    a.setTopRight(a.getTopRightX()+x,a.getTopRightY()+y);
}
void Car::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    glVertex2i(a.getTopLeftX(), a.getTopLeftY());
    glVertex2i(a.getTopRightX(), a.getTopRightY());
    glVertex2i(a.getBottomRightX(), a.getBottomRightY());
    glVertex2i(a.getBottomLeftX(), a.getBottomLeftY());
    glEnd();
}

Barrier::Barrier(){
    
}
Barrier::Barrier(Coord coord){
    a = coord;
}

void Barrier::setCoord(Coord coord){
    a = coord;
}

void Barrier::move(int x, int y){
    a.setBottomLeft(a.getBottomLeftX()+x,a.getBottomLeftY()+y);
    a.setBottomRight(a.getBottomRightX()+x,a.getBottomRightY()+y);
    a.setTopLeft(a.getTopLeftX()+x,a.getTopLeftY()+y);
    a.setTopRight(a.getTopRightX()+x,a.getTopRightY()+y);
}

void Barrier::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    glVertex2i(a.getTopLeftX(), a.getTopLeftY());
    glVertex2i(a.getTopRightX(), a.getTopRightY());
    glVertex2i(a.getBottomRightX(), a.getBottomRightY());
    glVertex2i(a.getBottomLeftX(), a.getBottomLeftY());
    glEnd();
}

Lane::Lane(){
    
}

Lane::Lane(Coord coord){
    a = coord;
}

void Lane::setCoord(Coord coord){
    a = coord;
}

void Lane::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    glVertex2i(a.getTopLeftX(), a.getTopLeftY());
    glVertex2i(a.getTopRightX(), a.getTopRightY());
    glVertex2i(a.getBottomRightX(), a.getBottomRightY());
    glVertex2i(a.getBottomLeftX(), a.getBottomLeftY());
    glEnd();
}

void Lane::move(int x, int y){
    a.setBottomLeft(a.getBottomLeftX()+x,a.getBottomLeftY()+y);
    a.setBottomRight(a.getBottomRightX()+x,a.getBottomRightY()+y);
    a.setTopLeft(a.getTopLeftX()+x,a.getTopLeftY()+y);
    a.setTopRight(a.getTopRightX()+x,a.getTopRightY()+y);
}


Button::Button(){
    
}

Button::Button(Coord coord){
    a = coord;
}

void Button::setCoord(Coord coord){
    a = coord;
}

void Button::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    glVertex2i(a.getTopLeftX(), a.getTopLeftY());
    glVertex2i(a.getTopRightX(), a.getTopRightY());
    glVertex2i(a.getBottomRightX(), a.getBottomRightY());
    glVertex2i(a.getBottomLeftX(), a.getBottomLeftY());
    glEnd();
}

