#include <Servo.h>

#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN  2  
#define ECHO_PIN     4  
#define MAX_DISTANCE 100 
Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
void setup() {
  Serial.begin(115200); 
  myservo.attach(7);
}

void loop() {
  delay(50);                    
  Serial.print("jarak : ");
  Serial.print(sonar.ping_cm()); 
  Serial.println("cm");
 int jarak=0;
 jarak=sonar.ping_cm();
 Serial.print("ini jarak : ");
 Serial.println(jarak);
 myservo.write(360);
  if(jarak>0&&jarak<30) {
    Serial.println("Buka!!!");

    myservo.write(0);
    delay(3000);
    
  }
  
}
