#define encoderPinA 2
#define encoderPinB 4
int encoder_count = 0;

void doEncoderL() {  
  if(digitalRead(encoderPinB)==LOW)
  {
    //Serial.println("prawo");
    encoder_count++;
  } 
  else if (digitalRead(encoderPinB)==HIGH)
  {
    //Serial.println("lewo");
    encoder_count--;
  }
}

void setup()
{
  Serial.begin(9600);   //or 115200
  
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  // - interrupt 0 is connected to pin 2
  // - interrupt 1 is connected to pin 3
  attachInterrupt(digitalPinToInterrupt(2), doEncoderL, RISING);
  
  Serial.println("Licznik: ");
}


void loop()
{
  Serial.println(encoder_count);
  delay(1000);
}
