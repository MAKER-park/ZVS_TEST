int relay = 8, relay_1 = 9, relay_2 = 10;
int led = 5, led_1 = 6, led_2 = 7;

unsigned int x = 0;
float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0;
float AcsValue_1 = 0.0, Samples_1 = 0.0, AvgAcs_1 = 0.0, AcsValueF_1 = 0.0;
float AcsValue_2 = 0.0, Samples_2 = 0.0, AvgAcs_2 = 0.0, AcsValueF_2 = 0.0;

void check_current() {
  for (int x = 0; x < 150; x++) { //Get 150 samples
    AcsValue = analogRead(A0);     //Read current sensor values
    Samples = Samples + AcsValue;  //Add samples together

    AcsValue_1 = analogRead(A1);     //Read current sensor values
    Samples_1 = Samples_1 + AcsValue_1;  //Add samples together

    AcsValue_2 = analogRead(A2);     //Read current sensor values
    Samples_2 = Samples_2 + AcsValue_2;  //Add samples together

  }
  AvgAcs = Samples / 150.0; //Taking Average of Samples

  AvgAcs_1 = Samples_1 / 150.0; //Taking Average of Samples

  AvgAcs_2 = Samples_2 / 150.0; //Taking Average of Samples

  /*((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
    //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
    //out to be 2.5 which is out offset. If your arduino is working on different voltage than
    //you must change the offset according to the input voltage)
    0.185v(185mV) is rise in output voltage when 1A current flows at input*/
  AcsValueF = (2.5 - (AvgAcs * (5.0 / 1024.0)) ) / 0.66;

  AcsValueF_1 = (2.5 - (AvgAcs_1 * (5.0 / 1024.0)) ) / 0.66;

  AcsValueF_2 = (2.5 - (AvgAcs_2 * (5.0 / 1024.0)) ) / 0.66;


  Serial.print("current_sensor1 : ");//Print the read current on Serial monitor
  Serial.println(AcsValueF);//Print the read current on Serial monitor

  Serial.print("current_sensor2 : ");//Print the read current on Serial monitor
  Serial.println(AcsValueF_1);//Print the read current on Serial monitor

  //아직센서 안옴
  //Serial.print("current_sensor3 : ");//Print the read current on Serial monitor
  //Serial.println(AcsValueF_2);//Print the read current on Serial monitor

}

void check_temp() {
  int ThermistorPin = 3, ThermistorPin_1 = 4, ThermistorPin_2 = 5;
  int V0, V1, V2;
  float R1 = 10000;
  float logR2, R2, logR2_1, R2_1, logR2_2, R2_2, T, T1, T2, Tc, Tc_1, Tc_2;
  float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

  V0 = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)V0 - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;

  V1 = analogRead(ThermistorPin_1);
  R2_1 = R1 * (1023.0 / (float)V1 - 1.0);
  logR2_1 = log(R2_1);
  T1 = (1.0 / (c1 + c2 * logR2_1 + c3 * logR2_1 * logR2_1 * logR2_1));
  Tc_1 = T1 - 273.15;

  V2 = analogRead(ThermistorPin_2);
  R2_2 = R1 * (1023.0 / (float)V2 - 1.0);
  logR2_2 = log(R2_2);
  T2 = (1.0 / (c1 + c2 * logR2_2 + c3 * logR2_2 * logR2_2 * logR2_2));
  Tc_2 = T2 - 273.15;

  Serial.print("Temperature1: ");
  Serial.print(Tc);
  Serial.println(" C");

  Serial.print("Temperature2: ");
  Serial.print(Tc_1);
  Serial.println(" C");

  //아직 센서 안옴
  //Serial.print("Temperature3: ");
  //Serial.print(Tc_2);
  //Serial.println(" C");

  if (Tc > 120 || Tc_1 > 120 || Tc_2 > 120) {
    relay_off();
  }
  if (Tc < 100) {
    relay1_on();
  }
  if (Tc_1 < 100) {
    relay2_on();
  }

  //sensor not yet...
  /*if(Tc_2<100){
    relay3_on();
    }*/


}
