
class Latch{
  private:
    int curValue;
    bool latched;
  public:
    Latch();
    Latch(int intial);
    int Value();
    void Update(int value);
    void Force(int value);
};

