
#define Y_STICK 67
#define X_STICK 69

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }

 int getJoyX(){
  int X=analogRead(X_STICK);
  //X=treatValue(X);
  return X;
  }
 int getJoyY(){
  int Y=analogRead(Y_STICK);
 //Y=treatValue(Y);
  return Y;
  }
  
