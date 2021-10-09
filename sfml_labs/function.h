#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <time.h>
#include <iostream>

using namespace sf;
using namespace std;

const int n = 100;
const int window_x = 1000;
const int window_y = 1000;
int choice = 0;
int choice_lab = 0;

class tPoint {
public:
    void object();
    void motion();
    void motion_Rand();
    void initialization();
    void direction();
    CircleShape circle[n];
private:
    int x[n];
    int y[n];
    int dir_x[n];
    int dir_y[n];
    int radius = 5;
    int speed = 2;
    unsigned char col_1[n];
    unsigned char col_2[n];
    unsigned char col_3[n];
};

class Point {
public:
    void motion();
    void initialization();
    void direction();
    void object();
    void rotation();
    CircleShape fig;
protected:
    float speed = 0.2;
    float x;
    float y;
    unsigned char col_1;
    unsigned char col_2;
    unsigned char col_3;
    float dir_x;
    float dir_y;
private:
    int radius = 5;
};
class Circle :public Point {
public:
    void object();
    void motion();
    void initialization();
private:
    int radius = 50;
};
class Triangle :public Circle {
public:
    void object();
};
class Rhombus :public Circle {
public:
    void object();
};
class Rectangle :public Point {
public:
    RectangleShape fig;
    void initialization();
    void object();
    void motion();
    void rotation();
protected:
    int x_len;
    int y_len;

};
class Section :public Rectangle {
public:
    void initialization();
};

