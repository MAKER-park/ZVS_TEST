void relay_on(){
  digitalWrite(relay, HIGH);
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
}

void relay1_on(){
  digitalWrite(relay, HIGH);
}

void relay2_on(){
  digitalWrite(relay_1, HIGH);
}

void relay3_on(){
  digitalWrite(relay_2, HIGH);
}

void relay_off(){
  digitalWrite(relay, LOW);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
}
