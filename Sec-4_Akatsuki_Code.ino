#define gaspin 3
#define temppin A0
#define humiditypin A1

int redLED = 13;
int greenLED = 2;
int buzzer = 5;

int gas;
float humidityread,tempread,rh,humiditydata, gasread;
String gas_str,motion;

int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;

void setup() {

  pinMode(gaspin, INPUT);
  pinMode(temppin, INPUT);
  pinMode(humiditypin, INPUT);
  pinMode (redLED, OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(500);
  gas = digitalRead(gaspin);

  tempread = analogRead(temppin);
  float val = (tempread/1024.0)*5000;
  float tempdata=val/10;

  humidityread = analogRead(humiditypin);
  rh=((humidityread/1024.0)-0.1515)/0.00636;
  //float true_rh=(rh)/(1.0546-0.00216*tempdata);
  
  if(gas==HIGH){
    gas_str="Smoke Detected!";
    gasread = 1;
    digitalWrite(redLED,HIGH);
    digitalWrite(greenLED,LOW);
    tone(buzzer,1000,500);
    delay(50);
    noTone(buzzer);
        
  }else{
    gas_str="No Smoke";
    gasread = 0;
    digitalWrite(greenLED,HIGH);
    digitalWrite(redLED,LOW);   
  }

  Serial.println(tempdata);
  Serial.println(gasread);
  Serial.println(rh);

}
