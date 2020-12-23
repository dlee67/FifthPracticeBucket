#include <string.h>
#include <emscripten/emscripten.h>

double EMSCRIPTEN_KEEPALIVE multiply(double a, double b) {
    return a * b;
}

int EMSCRIPTEN_KEEPALIVE get_length(const char* text) {
    return strlen(text);
}

int main() {}