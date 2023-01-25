#include "simdjson/simdjson.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;
int main(void) {
   auto start = high_resolution_clock::now();
   simdjson::dom::parser parser;
   std::cout << parser.load("datasets/citylots.json").at_pointer("/tiger") << std::endl;
    auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start); 
       cout << "Time taken by function: "
     << duration.count() << " microseconds" << endl;
   return 0;
}

// Create a test suite for very large json
//"$.brewing.country.id", "datasets/small.json - 472 bytes - avg 118 microseconds
//"$.tiger" datasets/mid-pokemon.json - 24kb 
//$.koko", "datasets/half-pokemon.json - 85kb - 240 microseconds
//$.tiger", "datasets/pokemon.json" - 177 kb - 350 microseconds
//$.sol2.tiger", "datasets/payload.json - 561kb - 660 microseconds
// $.tiger ../dataset/test.json 26mb -  25213 microseconds
//// $.tiger ../dataset/citylots.json 189mb -  25213 microseconds