void setup() {
  Serial.begin(9600); //Start Serial Monitor to display current read value on Serial monitor
  pinMode(relay,OUTPUT);
  pinMode(relay_1,OUTPUT);
  pinMode(relay_2,OUTPUT);

  digitalWrite(relay, HIGH);
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);

  //check postion and reaction led
  pinMode(led,OUTPUT);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);

}

void loop() {
  check_current();
  check_temp();
}
