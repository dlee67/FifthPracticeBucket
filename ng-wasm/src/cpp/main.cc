#include <string.h>
#include <emscripten/bind.h>

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