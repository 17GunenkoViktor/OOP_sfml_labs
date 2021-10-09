#include "function.h"

void tPoint::initialization() {
    for (int i = 0; i < n; i++) {
        x[i] = 1 + rand() % (window_x - 1);
        y[i] = 1 + rand() % (window_y - 1);
        col_1[i] = rand() % 256;
        col_2[i] = rand() % 256;
        col_3[i] = rand() % 256;
    };
}

void tPoint::direction() {
    for (int i = 0; i < n; i++) {
        dir_x[i] = speed * pow(-1, rand() % 2) * pow(0, rand() % 2);
        dir_y[i] = speed * pow(-1, rand() % 2) * pow(0, rand() % 2);
        if (dir_x[i] == 0 && dir_y[i] == 0) dir_x[i] = speed * pow(-1, rand() % 2);
    };
}

void tPoint::object() {
    for (int i = 0; i < n; i++) {
        circle[i].setRadius(radius);
        circle[i].setPosition(x[i], y[i]);
        circle[i].setFillColor(Color(col_1[i], col_2[i], col_3[i]));
    }
}

void tPoint::motion_Rand()
{
    for (int i = 0; i < n; i++) {
        if (x[i] > window_x || x[i] < 0) dir_x[i] *= -1;
        if (y[i] > window_y || y[i] < 0) dir_y[i] *= -1;
        direction();
        x[i] += dir_x[i];
        y[i] += dir_y[i];

        if (x[i] == 0 && y[i] == 0) x[i] += dir_x[i] * pow(-1, rand() % 2);
    }
}

void tPoint::motion()
{
    for (int i = 0; i < n; i++) {
        if (x[i] > window_x || x[i] < 0) dir_x[i] *= -1;
        if (y[i] > window_y || y[i] < 0) dir_y[i] *= -1;
        x[i] += dir_x[i];
        y[i] += dir_y[i];
    }
}

void Menu_lab3() {
    cout << "menu" << endl;
    cout << "1) horizontal move with reflection from window" << endl;
    cout << "2) random move" << endl;
    cout << "3) exit" << endl;
    cin >> choice;
}

void Choice(tPoint& point) {
    if (choice == 1) point.motion();
    if (choice == 2) point.motion_Rand();
}
int lab_3() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    tPoint point;
    Menu_lab3();
    while (choice != 3) {
        point.initialization();
        point.direction();
        RenderWindow window(VideoMode(window_x, window_y), "Lab 3");
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }
            window.clear(Color(0, 0, 0, 0));
            point.object();

            for (int i = 0; i < n; i++) {
                window.draw(point.circle[i]);
            }

            Choice(point);
            window.display();
        }
        system("cls");
        Menu_lab3();
    }
    system("cls");
    return 0;
}
void Menu_lab4() {
    cout << "menu" << endl;
    cout << "1) horizontal move with reflection from window" << endl;
    cout << "2) rotation" << endl;
    cout << "3) exit" << endl;
    cin >> choice;
}

void Choice_4(Point& point, Section& point2, Rectangle& point3, Circle& point4, Triangle& point5, Rhombus& point6) {
    if (choice == 1) {
        point.motion();
        point2.motion();
        point3.motion();
        point4.motion();
        point5.motion();
        point6.motion();
    };
    if (choice == 2) {
        point2.rotation();
        point3.rotation();
        point4.rotation();
        point5.rotation();
        point6.rotation();
    };
}
void Point::initialization() {
   
    x = 1 + rand() % (window_x - 1);
    y = 1 + rand() % (window_y - 1);
    col_1 = rand() % 256;
    col_2 = rand() % 256;
    col_3 = rand() % 256;
    
}

void Point::direction() {
    
    dir_x = speed * pow(-1, rand() % 2) * pow(0, rand() % 2);
    dir_y = speed * pow(-1, rand() % 2) * pow(0, rand() % 2);
    if (dir_x == 0 && dir_y == 0) dir_x = speed * pow(-1, rand() % 2);
    
}

void Point::object() {

    fig.setRadius(radius);
    fig.setPosition(x, y);
    fig.setFillColor(Color(col_1, col_2, col_3));

}
void Circle::object() {

    Point::object();
    fig.setRadius(Circle::radius);
    

}
void Circle::initialization() {
    Point::initialization();
    x = 1 + rand() % (window_x - radius);
    y = 1 + rand() % (window_y - radius);
    if (choice == 2) {
        x = window_x / 2 + (1 + rand() % 200) * pow(-1, rand() % 2);
        y = window_y / 2 + (1 + rand() % 400) * pow(-1, rand() % 2);
    }
}
void Triangle::object() {

    Circle::object();
    fig.setPointCount(3);
}
void Rhombus::object() {

    Circle::object();
    fig.setPointCount(4);
}
void Rectangle::initialization() {
    Point::initialization();
    y_len = 30 + rand() % 100;
    x_len = y_len + 10 + rand() % 100;
    if (rand() % 2 == 0) {
        int f = y_len;
        y_len = x_len;
        x_len = f;
    }
    x = 1 + rand() % (window_x - x_len);
    y = 1 + rand() % (window_y - y_len);
    if (choice == 2) {
        x = window_x / 2 + (1 + rand() % 150) * pow(-1, rand() % 2);
        y = window_y / 2 + (1 + rand() % 200) * pow(-1, rand() % 2);
    }
    
}
void Section::initialization() {
    Rectangle::initialization();
    x_len *= 2;
    y_len = 3;
    x = 1 + rand() % (window_x - x_len);
    y = 1 + rand() % (window_y - y_len);
    if (choice == 2) {
        x = window_x / 2 + (1 + rand() % 200) * pow(-1, rand() % 2);
        y = window_y / 2 + (1 + rand() % 300) * pow(-1, rand() % 2);
    }
}
void Rectangle::object() {

    fig.setSize(Vector2f(x_len, y_len));
    fig.setPosition(x, y);
    fig.setFillColor(Color(col_1, col_2, col_3));
}

void Point::motion()
{
    
    if (x > window_x || x < 0) dir_x *= -1;
    if (y > window_y || y < 0) dir_y *= -1;
    x += dir_x;
    y += dir_y;
    
}
void Circle::motion()
{
    if (x+2*radius > window_x || x < 0) dir_x *= -1;
    if (y+2*radius > window_y || y < 0) dir_y *= -1;
    x += dir_x;
    y += dir_y;

}
void Rectangle::motion() {
    if (x+x_len > window_x || x < 0) dir_x *= -1;
    if (y+y_len > window_y || y < 0) dir_y *= -1;
    x += dir_x;
    y += dir_y;
    
}
void Point::rotation() {
    fig.setOrigin(fig.getRadius(), fig.getRadius());
    fig.rotate(0.1);
}
void Rectangle::rotation() {
    fig.setOrigin(x_len/2, y_len/2);
    fig.rotate(0.1);
}
int lab_4() {
    Point point;
    Section section;
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
    Rhombus rhombus;
    srand(time(NULL));
    Menu_lab4();
    while (choice != 3) {
        point.initialization();
        point.direction();
        section.initialization();
        section.direction();
        circle.initialization();
        circle.direction();
        rectangle.initialization();
        rectangle.direction();
        triangle.initialization();
        triangle.direction();
        rhombus.initialization();
        rhombus.direction();
        RenderWindow window(VideoMode(window_x, window_y), "Lab 3");
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }
            window.clear(Color(0, 0, 0, 0));
            point.object();
            section.object();
            circle.object();
            rectangle.object();
            triangle.object();
            rhombus.object();
            
            if(choice!=2)window.draw(point.fig);
            window.draw(section.fig);
            if (choice != 2)window.draw(circle.fig);
            window.draw(rectangle.fig);
            window.draw(triangle.fig);
            window.draw(rhombus.fig);
            

            Choice_4(point,section,rectangle,circle,triangle,rhombus);
            window.display();
        }
        system("cls");
        Menu_lab4();
    }
    system("cls");
    return 0;
}
void Menu() {
    cout << "menu" << endl;
    cout << "1)lab_3" << endl;
    cout << "2)Lab_4" << endl;
    cout << "3)exit" << endl;
    cin >> choice_lab;
    system("cls");
    switch (choice_lab)
    {
    case 1:lab_3();
    case 2:lab_4();
    case 3: return ;
    default:
        break;
    }
    
}
int main()
{
 
    while (choice_lab != 3) {
        Menu();
    };
    return 0;
}

