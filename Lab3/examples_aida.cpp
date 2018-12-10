//Aida Nordman
//Examples coded live during the lecture

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <sstream>
#include <utility>

struct TimesThree
{
    void operator()(int &n)
    {
        n *= 3;
    }
};

//struct Sum
//{
//    void operator()(int n)
//    {
//        sum += n;
//    }
//
//    int sum = 0;
//};

template <typename T> //type T must support an operator +=
struct Sum
{
    void operator()(T n)
    {
        sum += n;
    }

    T sum = 0;
};

int h(int i)
{
    if (i%2 == 1) return -1;

    return i;
}

class Odd
{
public:

    void operator()(int &i)
    {
        if (i%2 == 1)
        {
            i = -1; //modify i to -1
            ++counter;
        }
    }

    int get_counter() const
    {
        return counter;
    }

private:

    int counter = 0;
};


using Table_Entry = std::pair<std::string, std::set<int>>;

//std::ostream& operator<<(std::ostream &os, const Table_Entry& e)
//{
//    os << e.first << ": ";
//
//    std::ostream_iterator<int> outIt(os, " ");
//
//    std::copy(std::begin(e.second), std::end(e.second), outIt);
//
//   return os;
//}

void display_entry(const Table_Entry& e)
{
    std::cout << e.first << ": ";

    std::ostream_iterator<int> outIt(std::cout, " ");

    std::copy(std::begin(e.second), std::end(e.second), outIt);

    std::cout << "\n";
}

/* ******************************* */

int main()
{
    //Read a file on integers and display the values read sorted

    std::ifstream in{ "ex2_values.txt" };

    if ( !in )
    {
        // print error message to std::cerr (the error output stream)
        std::cerr << "Could not open file\n";
        return 1;
    }

    //Read the file into a set/multiset

    //std::set<int> S;          //sorted, non-repeated values
    //std::multiset<int> S;     //sorted, repeated values are allowed

    // create stream iterators operating on the file
    std::istream_iterator<int> inIt{ in };
    std::istream_iterator<int> inItEnd;

    std::set<int> S{ inIt, inItEnd };
    //std::copy(inIt, inItEnd, std::inserter(S, std::end(S)));

    //Display the S to cout
    std::ostream_iterator<int> outIt(std::cout, " ");

    std::cout << "Number of unique values: " << S.size() << "\n";
    std::cout << "Values: ";
    std::copy(std::begin(S), std::end(S), outIt);

    std::cout << "\n";

    /* ***************************** */

    //Function objects

//    TimesThree t{ };
//    int i = 5;
//
//    t(i); //function object
//
//    std::cout << i << "\n";

    std::vector<int> V{ std::begin(S), std::end(S) };
    //std::vector<int> V(S.size());
    //std::copy(std::begin(S), std::end(S), std::begin(V));

    //Multiply all values in V by 3
    std::for_each(std::begin(V), std::end(V), TimesThree());

    /*
    auto it1 = std::begin(V);
    TimesThree t{ };

    while ( it1 != std::end(V) )
    {
        t(*it1);
        ++it1;
    }
    */

    //Display V to cout
    std::cout << "Values * 3: ";
    std::copy(std::begin(V), std::end(V), outIt);

    std::cout << "\n";

    /* ***************************** */

    //Sum the values in V

    //version 1
    //auto f = std::for_each(std::begin(V), std::end(V), Sum());
    auto f = std::for_each(std::begin(V), std::end(V), Sum<int>()); //std::or_each returns the function object

    std::cout << "Sum = " << f.sum << "\n\n";

    //version 2
    //std::cout << "Sum = " << std::accumulate(std::begin(V), std::end(V), 0) << "\n\n";

    /* ***************************** */

    //All odd values in V should be made -1 and count also the number of odd values

    //Version 1: two passes over the vector are required
    //std::transform(std::begin(V), std::end(V), std::begin(V), h);
    //int n = std::count(std::begin(V), std::end(V), -1);
    //
    //std::cout << "Number of odd values = " << n << "\n";

    //Version 2: one pass over the vector
    auto g = std::for_each(std::begin(V), std::end(V), Odd());  //std::for_each returns the function object
    std::cout << "Number of odd values = " << g.get_counter() << "\n";

    std::cout << "Values: " ;
    std::copy(std::begin(V), std::end(V), outIt);

    std::cout << "\n\n";

    /* ***************************** */

    //Create a table with the lines where each word in a text occurs

    std::ifstream textF{ "text.txt" };

    if ( !textF )
    {
        // print error message to std::cerr (the error output stream)
        std::cerr << "Could not open file\n";
        return 1;
    }

    std::map<std::string, std::set<int>> table;

    std::string line;
    int line_counter = 0;

    //Read text file and create table or words
    while ( std::getline(textF, line) )
    {
        line_counter++;

        std::istringstream is{ line };

        std::string word;

        while (is >> word)
        {
            table[word].insert(line_counter);
        }
    }

    //Display the table to cout

    //std::ostream_iterator<Table_Entry> outIt1(std::cout, "\n");
    //std::copy(std::begin(table), std::end(table), outIt1);  //<-- does not compile cause it cannot find an operator<< for table entries, even if we provide one

    std::for_each(std::begin(table), std::end(table), display_entry);

    std::cout << "\n";

    return 0;
}
