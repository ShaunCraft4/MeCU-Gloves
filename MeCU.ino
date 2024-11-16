#define BUZZER_PIN 8
#define VIBRATOR 7
#define POTENT_VAL A6
#define FLAME_PIN 10
long readUltrasonicDistance(int triggerPin, int echoPin)
{
pinMode(triggerPin, OUTPUT);
digitalWrite(triggerPin, LOW);
delay(2);
digitalWrite(triggerPin, HIGH);
delay(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);
return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(VIBRATOR ,OUTPUT);
  pinMode(POTENT_VAL,INPUT);
  pinMode(FLAME_PIN,INPUT);
}

void loop()
{
  int FLAME_VAL = digitalRead(FLAME_PIN);
  int distance = 0.01723 * readUltrasonicDistance(3,4);
  float POTENT_READ = analogRead(POTENT_VAL);
  float percentChange = (( POTENT_READ / 1023.0 ) * 100.0);
  float limit = (50.0 + (50.0 * (percentChange/100.0)));
  float Intensity = (( distance / limit ) * 100 );
  Serial.println(FLAME_VAL);
  if (FLAME_VAL==1){
    tone(BUZZER_PIN,4500);
    digitalWrite(VIBRATOR,HIGH);
    delay(75);
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
    delay(75);
  }else{
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
  }
  if (Intensity<=25.0){
    tone(BUZZER_PIN,1000);
    digitalWrite(VIBRATOR,HIGH);
    delay(100);
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
    delay(100);
  }else if (Intensity>25.0 & Intensity<=50.0){
    tone(BUZZER_PIN,1000);
    digitalWrite(VIBRATOR,HIGH);
    delay(100);
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
    delay(250);
  }else if (Intensity>50.0 & Intensity<=75.0){
    tone(BUZZER_PIN,1000);
    digitalWrite(VIBRATOR,HIGH);
    delay(100);
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
    delay(500);
  }else if (Intensity>75.0 & Intensity<=90.0){
    tone(BUZZER_PIN,1000);
    digitalWrite(VIBRATOR,HIGH);
    delay(100);
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
    delay(1000);
  }else if (Intensity>90.0 & Intensity<=100.0){
    tone(BUZZER_PIN,1000);
    digitalWrite(VIBRATOR,HIGH);
    delay(100);
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
    delay(2000);
  }else{
    noTone(BUZZER_PIN);
    digitalWrite(VIBRATOR,LOW);
  }
}
