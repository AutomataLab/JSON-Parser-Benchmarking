#include "rapidjson/document.h"
#include "rapidjson/pointer.h"
#include "rapidjson/writer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <chrono>

#include<vector>


using namespace std;
using namespace std::chrono;

int main() {
  auto start = high_resolution_clock::now();
   FILE* fp = fopen("datasets/citylots.json", "r");

   char *buffer = new char [189778220];
   rapidjson::FileReadStream is(fp, buffer, 189778220);

   rapidjson::Document d;
   d.ParseStream(is);

   if(rapidjson::Value *value = GetValueByPointer(d, "/tiger")) { 
      rapidjson::StringBuffer sb;
      rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
      value->Accept(writer);
      std::cout << sb.GetString() << std::endl;
   }
 auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
   
     
       cout << "Time taken by function: "
     << duration.count() << " microseconds" << endl;
   fclose(fp);
   delete[] buffer;

}
