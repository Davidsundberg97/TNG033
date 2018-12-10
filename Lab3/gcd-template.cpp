////
//// TNG033: Föreläsning 13
////
//// greatest common denominator (template metaprogram)
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
//// template metaprogram for GCD
//// gcd(m, n) = gcd(n, m mod n)
//template <int M, int N> 
//struct gcd {
//    static const int value = gcd<N, M % N>::value;
//};
//
//// gcd(m, 0) = m    used to terminate the recursion
//template <int M>
//struct gcd<M, 0> {
//    static const int value = M;
//};
//
//int main() {
//    // results of gcd_func() have to be computed when the program is running
//    std::cout << "gcd(6,2): " << gcd_func(6, 2) << '\n';
//    
//    std::cout << "gcd(14,49): " << gcd_func(14, 49) << "\n\n";
//
//    std::cout << "gcd<14,49>: " << gcd<14, 49>::value << '\n';
//
//    // the results of the gcd template function are available at compile time
//    int i = gcd<20414, 17>::value;
//}
