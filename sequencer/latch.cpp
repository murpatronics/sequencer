#include "latch.h"

Latch::Latch() :
  latched(false), 
  curValue(0){
  
}

Latch::Latch(int initial) : 
  latched(false),
  curValue(initial)
{
}

void Latch::Update(int value) {
  if (value != curValue) {
    latched = true;
  }
  if (!latched) {
    curValue = value;
  }
  if (latched && value == curValue) {
    latched = false;
  }
}

int Latch::Value(){
  return curValue;
}

void Latch::Force(int value){
  curValue = value;
}

