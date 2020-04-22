#include <Servo.h>

const int LED = 13;
const int BTPWR = 12;

char nombreBT[11] = "San";
char pin[5] = "0000";
char velocidad = '4'; // la velocidad 9600 se corresponde con el num. 4
char modo='1';        // '0' para esclavo y '1' para maestro

Servo servo_mira;
Servo servo_base;

const int pwmPinMira = 4; // un servo en el pin 4
const int pwmPinBase = 6; // otro servo en el pin 6

char val;
String grados;
int angulo;


void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTPWR, OUTPUT);

  Serial.begin(38400);  // velocidad de BT en modo de configuración.
  
  /*solo pulsador */
  // bluetooth con pulsador y sin conectar por cable EN ó KEY
  digitalWrite(LED, HIGH);
  delay(4000);
  digitalWrite(LED, LOW);
  //++++++++++++++++++++++/

  digitalWrite(BTPWR, HIGH);
  delay(3000);
  Serial.print("AT\r\t");  // con \r\t le indicamos que ha terminado la linea de codigo

  Serial.print("AT+NAME:");
  Serial.print(nombreBT);
  Serial.print("\r\t");

  Serial.print("AT+PIN:");  // ó AT+PSWD:
  Serial.print(pin);
  Serial.print("\r\t");

  Serial.print("AT+BAUD:");
  Serial.print(velocidad);
  Serial.print("\r\t");

  Serial.print("AT+Mode:");
  Serial.print(modo);
  Serial.print("\r\t");

  digitalWrite(LED, HIGH);

  pinMode(pwmPinMira, OUTPUT);
  pinMode(pwmPinBase, OUTPUT);
  servo_mira.attach(pwmPinMira);
  servo_base.attach(pwmPinBase);
  
}

void loop(){

if( Serial.available() ) {
val = Serial.read();
if (isDigit(val)) { grados += (char)val; }
if (val == '\n') {
angulo = grados.toInt();
Serial.println(angulo);
if( angulo == 0 )
{
servo_mira.write(angulo);
}
if( angulo == 90 )
{
servo_mira.write(angulo);
}
if( angulo == 180 )
{
servo_mira.write(angulo);
}
if( angulo == 1 )
{
servo_base.write(angulo);
}
if( angulo == 91 )
{
servo_base.write(angulo);
}
if( angulo == 181 )
{
servo_base.write(angulo);
}

grados = "";

}
} 

} // => Fin Loop
