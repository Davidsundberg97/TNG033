////
//// TNG033: Föreläsning 13
////
//// greatest common denominator (recursive implementation)
////
//
//#include <iostream>
//
//// recursive function implementing Euclid's algorithm
//int gcd_func(int m, int n) {
//    if (n == 0) {
//        return m;
//    }
//
//    return gcd_func(n, m % n);
//}
//
//int main() {
//    // results of gcd_func() have to be computed when the program is running
//    std::cout << "gcd(6,2): " << gcd_func(6, 2) << '\n';
//    
//    std::cout << "gcd(14,49): " << gcd_func(14, 49) << "\n\n";
//}
