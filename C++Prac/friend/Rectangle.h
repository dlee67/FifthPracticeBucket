class Rectangle {
    int width, height;
  public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    // friend classes and functions enables me to modify entities those are declared in private.
    friend Rectangle duplicate (const Rectangle&);
};