#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include <vector>

//https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#built-in-type-conversions
//Has a complete list of types that I can use.

using namespace emscripten;

double multiply(double a, double b) {
    return a * b;
}

void sumonemill(){
  int res = 0;
  for (int i = 0; i < 10000000; i++) {
      res += 1;
  }
}

EMSCRIPTEN_BINDINGS(multiply_module) {
    emscripten::function("multiply", &multiply);
}

EMSCRIPTEN_BINDINGS(sumonemill_module) {
    emscripten::function("sumonemill", &sumonemill);
}
