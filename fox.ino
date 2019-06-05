int latchPin = 8;

int clockPin = 12;

int dataPin = 11;

byte colDataMatrix[8] = { 
  B01111111,

B10111111,

B11011111,

B11101111,

B11110111,

B11111011,

B11111101,

B11111110

};

byte rowDataMatrix[8] = { 
  B11111111,

B10000001,

B10000001,

B10000001,

B10000001,

B10000001,

B10000001,

B11111111

};

byte colMatrix[8] = { 
 B01111111,

B10111111,

B11011111,

B11101111,

B11110111,

B11111011,

B11111101,

B11111110

};

byte rowMatrix[8] = { 
  B01100110,
  B01111110,
  B01000010,
  B10100101,
  B10100101,
  B01000010,
  B00100100,
  B00011000

};




// 定義顯示器顯示的時間 (延遲時間), 預設 1ms

int delay_time = 1;
int pushButton = 2;
int buttonState = 0;

void setup() {

pinMode(latchPin,OUTPUT);

pinMode(clockPin,OUTPUT);

pinMode(dataPin,OUTPUT);

pinMode(pushButton, INPUT);

}

void loop() {
  
int buttonState = digitalRead(pushButton);
if(buttonState == HIGH){
  for(int i = 0; i < 8 ; i++){

//byte colData = colMatrix[i];

digitalWrite(latchPin,LOW);

// pickDigit(i);

shiftOut(dataPin, clockPin, MSBFIRST, colMatrix[i]);

shiftOut(dataPin, clockPin, MSBFIRST, rowMatrix[i]);

//shiftOut(dataPin, clockPin, MSBFIRST, colMatrix[i]);

digitalWrite(latchPin,HIGH);

delay(delay_time);

}
  
}
else if(buttonState==LOW)
{
for(int i = 0; i < 8 ; i++){

//byte colData = colDataMatrix[i];

digitalWrite(latchPin,LOW);

// pickDigit(i);

shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);

//shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);

digitalWrite(latchPin,HIGH);

delay(delay_time);
}
}

}

void pickDigit(int x) {

byte rowByte = 1 << x;

shiftOut(dataPin, clockPin, MSBFIRST, rowByte);
}
