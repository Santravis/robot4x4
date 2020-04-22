int EnA = 5;  // conectado PWM para controlar la velocidad
int in1 = 2;  // Pin que controla el sentido de giro Motor A
int in2 = 3;  // Pin que controla el sentido de giro Motor A
int in3 = 7;  // Pin que controla el sentido de giro Motor B
int in4 = 8;  // Pin que controla el sentido de giro Motor B
int EnB = 9;  // conectado a PWM para controlar la velocidad

int VELOCIDAD;

void setup ()
{
  pinMode(EnA, OUTPUT);
  pinMode(in1, OUTPUT);    // Configura  los pines como salida
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);    // Configura  los pines como salida
  pinMode(in4, OUTPUT);
  pinMode(EnB, OUTPUT);
  
}
void loop(){
  VELOCIDAD = 100;
  aAvance(VELOCIDAD);
  bAvance(VELOCIDAD);
  delay(3000);
  detieneAmbos();
  delay(2000);
}

void aAvance(int veloc){
   analogWrite(EnA, veloc);
   digitalWrite(in1, LOW);
   digitalWrite(in2, HIGH);
}

void bAvance(int veloc){
  analogWrite(EnB, veloc);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
}
  
void detieneAmbos(){
  analogWrite(EnA, 0);
  analogWrite(EnB, 0);
}
