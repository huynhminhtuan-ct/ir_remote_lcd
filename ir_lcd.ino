#include <IRremote.h>
#include <Adafruit_LiquidCrystal.h>
int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;
Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
  lcd_1.begin(16, 2);
  lcd_1.print("Infor ir nak nha");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    printLCD((String) results.value);
    irrecv.resume(); // Receive the next value
  }
}

void printLCD(String value){
  lcd_1.setCursor(0, 1);
  lcd_1.print(value);
  lcd_1.setBacklight(1);
}