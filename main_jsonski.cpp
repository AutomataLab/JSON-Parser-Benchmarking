#include "include/jsonski/RecordLoader.h"
#include "include/jsonski/QueryProcessor.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>


using namespace std;
using namespace std::chrono;


// Create a test suite for very large json
//"$.brewing.country.id", "datasets/small.json - 472 bytes - avg 118 microseconds
//"$.tiger" datasets/mid-pokemon.json - 24kb 
//$.koko", "datasets/half-pokemon.json - 85kb - 240 microseconds
//$.tiger", "datasets/pokemon.json" - 177 kb - 350 microseconds
//$.sol2.tiger", "datasets/payload.json - 561kb - 660 microseconds
// $.tiger ../dataset/test.json 26mb -  25213 microseconds
//// $.tiger ../dataset/citylots.json 189mb -  25213 microseconds



int main() {
  auto start = high_resolution_clock::now();
    char * file_path = strdup("./datasets/citylots.json");
    string query = "$.tiger";
    Record* rec = RecordLoader::loadSingleRecord(file_path);
    if (rec == NULL) {
        cout<<"record loading fails."<<endl;
        return -1;
    }
   

    
    QueryProcessor processor(query);
    string output = processor.runQuery(rec);
 auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
   
      cout<<output<<endl;
       cout << "Time taken by function: "
     << duration.count() << " microseconds" << endl;
    return 0;
   
       
   
}


