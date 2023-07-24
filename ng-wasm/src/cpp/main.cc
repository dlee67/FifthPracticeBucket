#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/emscripten.h>
#include <string>
#include <vector>
#include <iostream>

// em++ -O3 --bind ./main.cc -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 -s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap']" -s EXPORTED_FUNCTIONS="['_malloc', '_free']" -o ./webassembly.js

struct StringNNumber {
    std::string label;
    int num;
};

std::map<int, std::string> m;
std::vector<float> vec;

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
    float largest = vec.front();
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > largest) {
            largest = vec[i];
        }
    }
    return largest;
}

std::map<int, std::string> returnMapData (int number, std::string someString) {
  std::map<int, std::string> m;
  m.insert(std::pair<int, std::string>(number, someString));
  return m;
}

void populate() {
    int size = sizeof(myFloatArray) / sizeof(myFloatArray[0]);

    // Create a vector and use the std::copy function to move elements from the array to the vector.
    vec.reserve(size); // Reserve space in the vector for efficiency (optional).

    std::copy(myFloatArray, myFloatArray + size, std::back_inserter(vec));

    // Print the elements in the vector (optional).
    for (const float& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
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

EMSCRIPTEN_BINDINGS(populate_module) {
    emscripten::function("populate", &populate);
}

EMSCRIPTEN_BINDINGS(interface_mock) {
    emscripten::function("returnMapData", &returnMapData);
    emscripten::register_map<int, std::string>("map<int, string>");
}