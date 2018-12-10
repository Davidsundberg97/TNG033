///***************************************************************************
//* TNG033: Fö 13                                                            *
//* Defines a hierarchy of geometric figures                                 *
//* Class Figure has 3 sub-classes: Rectangle, Circle, and Triangle          *
//* virtual functions and dynamic binding is used                            *
//* **************************************************************************/
//
//#include <iostream>
//#include <string>
//
//// this is needed for accessing M_PI defined in <cmath>
//#ifndef _USE_MATH_DEFINES
//#define _USE_MATH_DEFINES
//#endif  // _USE_MATH_DEFINES
//
//#include <cmath>
//
///**************************
//* Figure Base class       *
//***************************/
//class Figure {
//public:
//    // default constructor provided by compiler
//    Figure() = default;
//
//    virtual ~Figure() {}  // virtual destructor since this is a polymorphic class
//
//                          // Not best programming practice:
//                          // you should not implement this function for Figures
//                          // We should use instead a pure virtual function
//    virtual double area() const {
//        std::cout << "Figure::area\n";
//        return 0.0;
//    }
//
//    // Better programming practice: pure virtual function
//    // virtual double area() const = 0;
//};
//
///**************************
//* Rectangle class         *
//***************************/
//class Rectangle : public Figure {
//public:
//    explicit Rectangle(double l1 = 0.0, double l2 = 0.0) : side1(l1), side2(l2) {}
//
//    virtual double area() const override {
//        std::cout << "Rectangle::area\n";
//        return side1 * side2;
//    }
//
//protected:
//    double side1;
//    double side2;
//};
//
///**************************
//* Circle class            *
//***************************/
//class Circle : public Figure {
//public:
//    explicit Circle(double r = 0.0) : radius(r) {}
//
//    virtual double area() const override {
//        std::cout << "Circle::area\n";
//        return M_PI * radius * radius;
//    }
//
//    double get_radius() { return radius; }
//
//protected:
//    double radius;
//};
//
///**************************
//* Triangle class          *
//***************************/
//class Triangle : public Figure {
//public:
//    explicit Triangle(double b = 0.0, double h = 0.0) : base(b), height(h) {}
//
//    virtual double area() const override {
//        std::cout << "Triangle::area\n";
//        return (base * height) / 2.0;
//    }
//
//protected:
//    double base;
//    double height;
//};
//
///**********************************
//* main()  -- testing              *
//***********************************/
//int get_option() {
//    int option;
//
//    std::cout << "\n*****************\n"
//        << "*1. Rectangle\n"
//        << "*2. Circle\n"
//        << "*3. Triangle\n"
//        << "*****************\n";
//
//    std::cout << "Option? ";
//    std::cin >> option;
//
//    return option;
//}
//
//int main() {
//    const int MAX = 20;
//
//    double side1, side2;
//    double h, b, r;
//
//    Figure* DB[MAX];
//    int howMany = 0;
//
//    std::cout << "How many figures? ";
//    std::cin >> howMany;
//
//    if (howMany > MAX) {
//        return 0;  // exit the program
//    }
//
//    for (int i = 0; i < howMany; i++) {
//        int option = get_option();
//
//        switch (option) {
//            case 1:  // create a Rectangle
//                std::cout << "Enter sides length: ";
//                std::cin >> side1 >> side2;
//
//                DB[i] = new Rectangle(side1, side2);
//                break;
//
//            case 2:  // create a Circle
//                std::cout << "Enter circle's radius: ";
//                std::cin >> r;
//
//                DB[i] = new Circle(r);
//                break;
//
//            case 3:  // Create a Rectangle
//                std::cout << "Enter triangle's height and base: ";
//                std::cin >> h >> b;
//
//                DB[i] = new Triangle(b, h);
//                break;
//
//            default:
//                return 0;  // exit the program
//        }
//    }
//
//    std::cout << "\nCalculating the area of the figures ...\n";
//    for (int i = 0; i < howMany; ++i) {
//        std::cout << DB[i]->area() << '\n';  // using dynamic binding
//    }
//
//    for (int i = 0; i < howMany; ++i) {
//        delete DB[i];  // deallocate the memory for each figure
//    }
//}
