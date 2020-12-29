#include <emscripten.h>
#include <emscripten/bind.h>
#include <string>
#include <vector>

using namespace emscripten;

double multiply(double a, double b) {
    return a * b;
}

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

int get_length(std::string text) {
    return text.length();
}

extern "C" {
  int sum_up(int vals[], int size);
}
int EMSCRIPTEN_KEEPALIVE sum_up(int vals[], int size) {
  int res = 0;
  for(int i=0; i<size; i++) {
    res += vals[i];
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

EMSCRIPTEN_BINDINGS(lerp_module) {
    emscripten::function("lerp", &lerp);
}

EMSCRIPTEN_BINDINGS(multiply_module) {
    emscripten::function("multiply", &multiply);
}

EMSCRIPTEN_BINDINGS(get_length_module) {
    emscripten::function("get_length", &get_length);
}

// If I am using a cwrap for sum_up, this becomes pointless.
// Besides: https://stackoverflow.com/questions/20355880/emscripten-how-can-i-solve-unboundtypeerror
// It won't work anyway.
// EMSCRIPTEN_BINDINGS(sum_module) {
//     emscripten::function("sum_up", &sum_up, emscripten::allow_raw_pointers());
// }

// int main() {}