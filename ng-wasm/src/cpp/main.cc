#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include <vector>

//https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#built-in-type-conversions
//Has a complete list of types that I can use.
#include <iostream>
#include <vector>

double multiply(double a, double b) {
    return a * b;
}

void sumonemill(){
  int res = 0;
  for (int i = 0; i < 10000000; i++) {
      res += 1;
  }
}

float findLargestFloat(const std::vector<float>& array) {
    float largest = array[0];
    for (size_t i = 1; i < array.size(); ++i) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    return largest;
}

EMSCRIPTEN_BINDINGS(floatmax_wrappers) {
    emscripten::register_vector<float>("VectorFloat");
    emscripten::function("findLargestFloat", &findLargestFloat);
}

EMSCRIPTEN_BINDINGS(multiply_module) {
    emscripten::function("multiply", &multiply);
}

EMSCRIPTEN_BINDINGS(sumonemill_module) {
    emscripten::function("sumonemill", &sumonemill);
}
