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

std::vector<int> returnVectorData () {
  std::vector<int> v(10, 1);
  return v;
}

EMSCRIPTEN_BINDINGS(module) {
  function("returnVectorData", &returnVectorData);

  // register bindings for std::vector<int>.
  // I guess, using a technique like this can get rid of needing to write a middleware.
  // For example, instead of writing a middleware that organizes and returns the JSON members to
  // increase the performance of project's front-end, I can just write a function here
  // and do an HTTP handshake to the REST API that I am trying to interact.
  register_vector<int>("vector<int>");
}

EMSCRIPTEN_BINDINGS(lerp_module) {
    function("lerp", &lerp);
}

EMSCRIPTEN_BINDINGS(multiply_module) {
    function("multiply", &multiply);
}

EMSCRIPTEN_BINDINGS(get_length_module) {
    function("get_length", &get_length);
}

int main() {}