////
//// TNG033: Föreläsning 13
////
//// std::copy_if
////
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <iterator>
//
//struct Position {
//    int x;
//    int y;
//};
//
//int main() {
//    using const_vecIt = std::vector<Position>::const_iterator;
//
//    std::vector<Position> v = { {0, 0}, {0, 2}, {3, 2}, {1, 3}, {6, 2} };
//
//    // create a predicate, i.e. a bool function which returns true if 
//    // the y component of the position is equal to value
//    //
//    // This struct is only valid within the current control block.
//    struct Predicate {
//        Predicate(int v) : value(v) {}
//
//        bool operator()(const Position &pos) {
//            return (pos.y == value);
//        }
//
//        const int value;
//    };
//
//    std::vector<Position> dst;
//    // be sure that either the destination has enough space allocated or an
//    // insert iterator, e.g. std::back_inserter, is used
//    std::copy_if(v.begin(), v.end(), std::back_inserter(dst), Predicate(2));
//
//    std::cout << "Copied positions:\n";
//    for (const_vecIt it = dst.begin(); it != dst.end(); ++it) {
//        std::cout << " { " << it->x << ", " << it->y << " }\n";
//    }
//}
