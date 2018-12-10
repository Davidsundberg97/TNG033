////
//// TNG033: Föreläsning 13
////
//// std::for_each
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// definitions of various function objects which can be used by std::for_each
//// 
//// std::for_each will ignore the return value of the functor operator().
//
//template <typename T>
//struct Sum {
//    void operator() (T n) { sum += n; }
//    T sum = 0;
//};
//
//struct TimesTwo {
//    // this functor modifies the given element and multiplies it by 2
//    void operator() (int &n) { n *= 2; }
//};
//
//struct Display {
//    void operator() (int value) {
//        std::cout << " " << value;
//    }
//};
//
//int main() {
//    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    // compute the sum, std::for_each returns the functor holding the result
//    Sum<int> s = std::for_each(v.begin(), v.end(), Sum<int>());
//    std::cout << "The sum of the vector is: " << s.sum << '\n';
//
//    // multiply each element of the vector by 2
//    std::for_each(v.begin(), v.end(), TimesTwo());
//
//    // use for_each to print all elements of the vector
//    std::cout << "\nVector x 2:";
//    std::for_each(v.begin(), v.end(), Display());
//    std::cout << '\n';
//
//    s = std::for_each(v.begin(), v.end(), Sum<int>());
//    std::cout << "The new sum is: " << s.sum << '\n';
//}
