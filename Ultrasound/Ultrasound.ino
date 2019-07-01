#include <Servo.h>

const int EchoPin = 5;
const int TriggerPin = 6;
const int BuzzerPin = 7;

const int redPin = 8;
const int greenPin = 9;
const int bluePin = 10;

const int servoPin = 11;

Servo centralServo;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(BuzzerPin, OUTPUT);
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);
   pinMode(EchoPin, INPUT);

   centralServo.attach(servoPin);
   centralServo.write(0);
}
 
void loop() {
   int distance = ping(TriggerPin, EchoPin);

   digitalWrite(BuzzerPin, LOW);
   
   Serial.print("Distancia: ");
   Serial.println(distance);

   digitalWrite(redPin, LOW);
   digitalWrite(bluePin, LOW);
   digitalWrite(greenPin, LOW);

   centralServo.write(0);
  
   if (distance <= 15){
      tone(BuzzerPin, 100, 100);
      digitalWrite(redPin, HIGH);
      centralServo.write(180);
      delay(100);
   }

   if (distance > 15 && distance < 50){
      tone(BuzzerPin, 40, 100);
      digitalWrite(bluePin, HIGH);
      centralServo.write(90);
      delay(200);
   }

   if(distance >= 50){
    digitalWrite(greenPin, HIGH);
    centralServo.write(45);
    delay(100);
   }
   
   delay(100);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
