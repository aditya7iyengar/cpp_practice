// Given an array of positive or negative integers

// I= [i1,..,in]

// you have to produce a sorted array P of the form

// [ [p, sum of all ij of I for which p is a prime factor (p positive) of ij] ...]

// P will be sorted by increasing order of the prime numbers. The final result has to be given as a string in Java, C# or C++ and as an array of arrays in other languages.

// Example:

// I = {12, 15}; // result = "(2 12)(3 27)(5 15)"
// [2, 3, 5] is the list of all prime factors of the elements of I, hence the result.

// Notes: It can happen that a sum is 0 if some numbers are negative!

// Example: I = [15, 30, -45] 5 divides 15, 30 and (-45) so 5 appears in the result, the sum of the numbers for which 5 is a factor is 0 so we have [5, 0] in the result amongst others.

// MY SOLUTION:
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

class SumOfDivided {
public:
  static std::string sumOfDivided(std::vector<int> &lst) {
    stringstream strStream;
    set<int> primes;

    auto factor = [](int num) {
      set<int> strStream;

      for( ; num % 2 == 0; num /= 2)
        strStream.insert(2);

      for(int i = 3; i <= sqrt(abs(num)); i += 2) {
        for( ; num % i == 0; num/= i)
          strStream.insert(i);
      }

      if(abs(num) > 2) strStream.insert(abs(num));

      return strStream;
    };

    for(auto x : lst) {
      set<int> currSet = factor(x);
      primes.insert(currSet.begin(), currSet.end());
    }

    for(auto vec = primes.begin(); vec != primes.end(); vec++) {
      strStream << "(" << *vec << " ";
      int sum = 0;

      for(auto x : lst)
        if(x % *vec == 0) sum += x;
      strStream << sum << ")";
    }

  return strStream.str();
  }
};
