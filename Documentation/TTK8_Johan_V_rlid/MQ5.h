#define GAS_SENSOR 69
float gas_value;

float getGasValue(){
  return analogRead(GAS_SENSOR);
  }
