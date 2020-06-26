class Pyramid {
 private:
  int length;
  int width;
  int height;

 public:
  Pyramid(int l, int w, int h) : length(l), width(w), height(h) {}
  int getLength() const { return length; }
};