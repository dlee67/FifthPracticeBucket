#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include <vector>

//https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html#built-in-type-conversions
//Has a complete list of types that I can use.

using namespace emscripten;

extern "C" {
  int sum_up(int vals[]);
}
int EMSCRIPTEN_KEEPALIVE sum_up(int vals[]) {

  int res = 0;
  for(int i=0; i<10000000; i++) {
    res += 1;
  }

  return res;
}

std::vector<int> returnVectorData () {
  std::vector<int> v(10, 1);
  return v;
}

EMSCRIPTEN_BINDINGS(module) {
  emscripten::function("returnVectorData", &returnVectorData);

  // register bindings for std::vector<int>.
  // I guess, using a technique like this can get rid of needing to write a middleware.
  // For example, instead of writing a middleware that organizes and returns the JSON members to
  // increase the performance of project's front-end, I can just write a function here
  // and do an HTTP handshake to the REST API that I am trying to interact.
  emscripten::register_vector<int>("vector<int>");
}

// If I am using a cwrap for sum_up, this becomes pointless.
// Besides: https://stackoverflow.com/questions/20355880/emscripten-how-can-i-solve-unboundtypeerror
// It won't work anyway.
// EMSCRIPTEN_BINDINGS(sum_module) {
//     emscripten::function("sum_up", &sum_up, emscripten::allow_raw_pointers());
// }

// int main() {}