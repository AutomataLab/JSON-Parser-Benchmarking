# JsonSki vs simDjson vs RapidJson

This is a performance test to compare Jsonski, simdjson and rapidjson parsing times.

Download the dataset from here - https://drive.google.com/drive/folders/185SH188MJmmm-QTd14_8gq5QD-gyouNW

Compile, run and profile the main_jsonski.cpp application.

```sh
$ g++ -O3 -std=c++11 -mavx -mavx2 -msse -msse2 -msse4 -msse4.2 -mpclmul -o main_jsonski include/jsonski/*.cpp main_jsonski.cpp -lpthread -mcmodel=medium -static-libstdc++
$ ./main_jsonski

```

Compile, run and profile the main_simdjson.cpp application.

```sh
$ g++ -std=c++11 -Iinclude -O3 main_simdjson.cpp include/simdjson/simdjson.cpp -o main_simdjson
$ ./main_simdjson

```

Compile, run and profile the main_rapidjson.cpp application.

```sh
$ g++ -Iinclude -O3 main_rapidjson.cpp -o main_rapidjson
$ ./main_rapidjson
```
