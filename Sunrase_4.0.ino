/*
 * SunRase 4.0 by: Reolfi Riccardo, Incolto Davide, Murialdo Andrea, Pastorino Simone.
 * Code by: Davide Incolto.
*/
int motDestraA = 2;
int motDestraI = 3;
int motSinistraA = 4;
int motSinistraI = 5;
int magnetic = 6;
int triggerUp = 9;
int echoUp = 10;
void setup() {
  pinMode(motDestraI, OUTPUT);
  pinMode(motDestraA, OUTPUT);
  pinMode(motSinistraI, OUTPUT);
  pinMode(motSinistraA, OUTPUT);
  pinMode(magnetic, INPUT);
  pinMode(triggerUp, OUTPUT);
  pinMode(echoUp, INPUT);
  Serial.begin(9600);
}
void loop() {
  AvantiTutta();
  if(checkMag() == true){
    gira();
    }
  if(checkUltra() == true){
    gira();
    }
 delay(5);
}
bool checkMag(){
  if(digitalRead(magnetic) == 1){
  return true;  
}
 else if(digitalRead(magnetic) == 0){
  return false;
 } 
}
bool checkUltra(){
  digitalWrite( triggerPort, LOW );
  digitalWrite( triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( triggerPort, LOW );
  long durata = pulseIn( echoPort, HIGH );
  long distanza = 0.034 * durata / 2;
  Serial.println(distanza);
  if(distanza < 10){
    return true;
}
  else if(distanza > 10){
    return false;
 }
}
void AvantiTutta(){
  digitalWrite(motDestraA, HIGH);
  digitalWrite(motSinistraA, HIGH);
}
