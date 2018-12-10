///***************************************************************************
//* TNG033: Fö 13                                                            *
//* Curiously Recurring Template Pattern (CRTP)                              *
//*                                                                          *
//* Classes X and Y derive from the template base class Counter.             *
//* This will keep count of each instance of X or Y.                         *
//* **************************************************************************/
//
//#include <iostream>
//
//template <typename T>
//class Counter {
//public:
//    static int objects_created;
//    static int objects_alive;
//
//protected:
//    // making either Constructor or Destructor protected, prevents users from creating 
//    // instances of Counter. 
//    // That is, writing "Counter<X> tmp;" will generate a compile errror since its 
//    // constructors/destructor is hidden.
//    Counter() { 
//        ++objects_created;
//        ++objects_alive;
//    }
//
//    Counter(const Counter&) {
//        ++objects_created;
//        ++objects_alive;
//    }
//
//    ~Counter() { --objects_alive; }
//};
//
//// static member initialization
//template <typename T>
//int Counter<T>::objects_created = 0;
//template <typename T>
//int Counter<T>::objects_alive = 0;
//
//class X : private Counter<X> {  // X derives from Counter<X>
//    // ...
//};
//
//class Y : private Counter<Y> {  // Y derives from Counter<Y>
//    // ...
//};
//
//int main() {
//    X x1;
//
//    {
//        X x2, x3;
//        x2 = x1;
//        Y y1;
//
//        std::cout << "X: created / alive: " 
//            << Counter<X>::objects_created 
//            << " / " << Counter<X>::objects_alive << '\n'; // -> 3 created, 3 alive
//    }
//    std::cout << "X: created / alive: "
//        << Counter<X>::objects_created
//        << " / " << Counter<X>::objects_alive << '\n'; // -> 3 created, 1 alive (x2 and x3 got destroyed)
//
//    X x4;
//    Y y2;
//    Y y3 = y2;
//
//    std::cout << "X: created / alive: " 
//        << Counter<X>::objects_created 
//        << " / " << Counter<X>::objects_alive << '\n'; // -> 4 created, 2 alive
//
//    std::cout << "Y: created / alive: " 
//        << Counter<Y>::objects_created 
//        << " / " << Counter<Y>::objects_alive << '\n'; // -> 3 created, 2 alive (y1 got destroyed earlier)
//}
