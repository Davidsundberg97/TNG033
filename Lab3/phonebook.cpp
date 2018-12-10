////
//// TNG033: Föreläsning 13
////
//// Phone book example using std::map, std::vector nested inside 
//// a std::map, and std::for_each
////
//
//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <string>
//#include <vector>
//#include <iomanip>
//
//// simple function object for emptying the entries of the "advanced phone book"
//struct ClearNumbers {
//    void operator()(std::pair<const std::string, std::vector<int>> &element) {
//        // access the second element of the pair (the vector) and clear it
//        element.second.clear();
//    }
//};
//
//// function object for printing a single entry of the "advanced phone book"
//struct PrintEntry {
//
//    // each phone book entry is a key-value pair (same types as used for the map itself)
//    void operator()(const std::pair<const std::string, std::vector<int>> &entry) {
//        // entry.first holds the key (std::string, the entry name)
//        // entry.second holds the vector with all the phone numbers
//        std::cout << std::left << std::setw(10) << entry.first;
//        for (std::size_t i = 0; i < entry.second.size(); ++i) {
//            if (i > 0) {
//                std::cout << std::setw(10) << "";
//            }
//            std::cout << entry.second[i] << '\n';
//        }
//    }
//};
//
//int main() {
//    // phone book holding a name (key) and a single number (value) in a map (Lecture 12)
//    std::map<std::string, int> phoneBookSimple;
//
//    // add entries for Erik and Lisa
//    phoneBookSimple["Erik"] = 1234;
//    phoneBookSimple.insert(std::make_pair("Lisa", 3399));
//
//    // change Erik's phone number
//    phoneBookSimple["Erik"] = 1323;
//
//    // print all entries
//    std::cout << "Name       Phone number\n";
//    using mapIt = std::map<std::string, int>::const_iterator;
//    for (mapIt it = phoneBookSimple.begin(); it != phoneBookSimple.end(); ++it) {
//        std::cout << std::left << std::setw(10) << it->first << " " << it->second << '\n';
//    }
//
//    // more advanced phone book, where each entry can hold multiple phone numbers (Lecture 13)
//    // Therefore, the map consists of pairs of a std::string (the key used in the map) and a
//    // vector of int for holding a variable number of phone numbers.
//    std::map<std::string, std::vector<int>> phoneBook;
//
//    // add entries for Erik and his two numbers
//    phoneBook["Erik"].push_back(1234);
//    phoneBook["Erik"].push_back(353535);
//
//    // create entry for Marie and add her number
//    phoneBook["Marie"].push_back(4444);
//
//    // print entries, this time using for_each
//    std::cout << "\nName       Phone number\n";
//    std::for_each(phoneBook.begin(), phoneBook.end(), PrintEntry());
//
//    // clear all phone numbers of each entry in the phone book
//    std::for_each(phoneBook.begin(), phoneBook.end(), ClearNumbers());
//
//    std::cout << "\nName       Phone number\n";
//    std::for_each(phoneBook.begin(), phoneBook.end(), PrintEntry());
//    std::cout << "---\nDone\n";
//}
