// Description:

// A traveling salesman has to visit clients. He got each client's address e.g. "432 Main Long Road St. Louisville OH 43071" as a list.

// The basic zipcode format usually consists of two capital letters followed by a white space and five digits. The list of clients to visit was given as a string of all addresses, each separated from the others by a comma, e.g. :

// "123 Main Street St. Louisville OH 43071,432 Main Long Road St. Louisville OH 43071,786 High Street Pollocksville NY 56432".

// To ease his travel he wants to group the list by zipcode.

// Task

// The function travel will take two parameters r (list of all clients' addresses) and zipcode and returns a string in the following format:

// zipcode:street and town,street and town,.../house number,house number,...

// The street numbers must be in the same order as the streets where they belong.

// If a given zipcode doesn't exist in the list of clients' addresses return "zipcode:/"

// Examples

// r = "123 Main Street St. Louisville OH 43071,432 Main Long Road St. Louisville OH 43071,786 High Street Pollocksville NY 56432"

// travel(r, "OH 43071") --> "OH 43071:Main Street St. Louisville,Main Long Road St. Louisville/123,432"

// travel(r, "NY 56432") --> "NY 56432:High Street Pollocksville/786"

// travel(r, "NY 5643") --> "NY 5643:/"
// Note: You can see the list of all addresses and zipcodes in the test cases.

using namespace std;

class SalesmanTravel {
public:
    static std::string travel(const std::string& orgr, std::string zipcode);
};


string SalesmanTravel::travel(const string& orgr, string zipcode) {
  size_t head, temp, tail = orgr.find(zipcode);
  if(tail == string::npos || zipcode.length() != 8) return zipcode + ":/";

  string res1 = zipcode + ':' , res2 = "/";

  while(tail != string::npos) {
    head = orgr.rfind(',', tail);
    if(head == string::npos) head = 0;
    else head ++;

    temp = orgr.find(' ', head);
    res2 = res2 + orgr.substr(head, temp - head) + ',';
    res1 = res1 + orgr.substr(temp + 1, tail - temp - 2) + ',';
    tail = orgr.find(zipcode, tail + 1);
  }
  res1.erase(res1.end() - 1);
  res2.erase(res2.end() - 1);

  return res1 + res2;
}
