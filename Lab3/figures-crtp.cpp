///***************************************************************************
//* TNG033: Fö 13                                                            *
//* Defines a hierarchy of geometric figures                                 *
//* Class Figure has 3 sub-classes: Rectangle, Circle, and Triangle          *
//*                                                                          *
//* The Curiously Recurring Template Pattern (CRTP) is used to implement     *
//* static polymorphism and static binding.                                  *
//* **************************************************************************/
//
//// this is needed for accessing M_PI defined in <cmath>
//#ifndef _USE_MATH_DEFINES
//#define _USE_MATH_DEFINES
//#endif  // _USE_MATH_DEFINES
//
//#include <iostream>
//#include <string>
//#include <cmath>
//
///**********************************
//* Figure template base class      *
//***********************************/
//// a common base class is needed in this example to store all objects in the same array
//class Figure {
//public:
//    virtual double area() const = 0;
//};
//
//template <typename T>
//class FigureBase : public Figure {
//public:
//    // default constructor provided by compiler
//    FigureBase() = default;
//
//    double area() const {
//        std::cout << "FigureBase::area\n";
//        // call implementation of derived classes
//        // use template argument T to convert the this pointer into a pointer
//        // of type T, i.e. the derived class
//        const T *derived = static_cast<const T *>(this);
//        // call member function of derived class
//        return derived->area_implementation();
//    }
//};
//
///**************************
//* Rectangle class         *
//***************************/
//class Rectangle : public FigureBase<Rectangle> {
//public:
//    explicit Rectangle(double l1 = 0.0, double l2 = 0.0) : side1(l1), side2(l2) {}
//
//    double area_implementation() const {
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
//class Circle : public FigureBase<Circle> {
//public:
//    explicit Circle(double r = 0.0) : radius(r) {}
//
//    double area_implementation() const {
//        std::cout << "Circle::area\n";
//        return 3.14159 * radius * radius;
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
//class Triangle : public FigureBase<Triangle> {
//public:
//    explicit Triangle(double b = 0.0, double h = 0.0) : base(b), height(h) {}
//
//    double area_implementation() const {
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
//    Figure *DB[MAX];
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
//        std::cout << DB[i]->area() << '\n';  // using simulated dynamic binding
//    }
//
//    for (int i = 0; i < howMany; ++i) {
//        delete DB[i];  // deallocate the memory for each figure
//    }
//}
