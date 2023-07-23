#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <string>
#include <vector>
#include <iostream>

struct StringNNumber {
    std::string label;
    int num;
};

std::map<int, std::string> m;

const int size = 560;
float myFloatArray[size] = {
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
    1.1f, 2.2f, 3.3f, 4.4f, 5.5f,
};

//https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#built-in-type-conversions
//Has a complete list of types that I can use.

double multiply(double a, double b) {
    return a * b;
}

void sumonemill(){
  int res = 0;
  for (int i = 0; i < 10000000; i++) {
      res += 1;
  }
}

float findLargestFloat() {
    float largest = myFloatArray[0];
    for (size_t i = 1; i < size; ++i) {
        if (myFloatArray[i] > largest) {
            largest = myFloatArray[i];
        }
    }
    return largest;
}

std::map<int, std::string> returnMapData (int number, std::string someString) {
  std::map<int, std::string> m;
  m.insert(std::pair<int, std::string>(number, someString));
  return m;
}

EMSCRIPTEN_BINDINGS(floatmax_wrappers) {
    emscripten::function("findLargestFloat", &findLargestFloat, emscripten::allow_raw_pointer<float>());
}

EMSCRIPTEN_BINDINGS(multiply_module) {
    emscripten::function("multiply", &multiply);
}

EMSCRIPTEN_BINDINGS(sumonemill_module) {
    emscripten::function("sumonemill", &sumonemill);
}

EMSCRIPTEN_BINDINGS(interface_mock) {
    emscripten::function("returnMapData", &returnMapData);
    emscripten::register_map<int, std::string>("map<int, string>");
}