#define BLYNK_TEMPLATE_ID           "TMPL6aVsmTOmx"
#define BLYNK_TEMPLATE_NAME         "kapasitas"
#define BLYNK_AUTH_TOKEN            "_anyFRdZXrirvgHj9Bf-RFpMsWy_TjWK"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define trig D5   // Trig pin
#define echo D6 
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HARMOKO 2";
char pass[] = "IYA BENTAR";
int depth =20;

BlynkTimer timer;
 
void kapasitas()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Serial.println(cm);
  long kapasitas= depth-cm;
  if (kapasitas<0)
  kapasitas=0;
  kapasitas = map(kapasitas,0,depth-3,0,100);
  Blynk.virtualWrite(V0, kapasitas);
}

 
void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, kapasitas);
  
}

void loop()
{
 
  Blynk.run();
  timer.run();
  }
