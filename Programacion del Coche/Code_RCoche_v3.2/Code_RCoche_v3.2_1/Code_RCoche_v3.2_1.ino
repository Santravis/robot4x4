#include <AFMotor.h>


#include <Servo.h>

Servo myservo; 

AF_DCMotor motor1(1);  / DD
AF_DCMotor motor2(2);  / DI
AF_DCMotor motor3(3);  / AI
AF_DCMotor motor4(4);  / AD

#define ECHO 2       // Pin para recibir el pulso de eco
#define TRIGGER 13     // Pin para enviar el pulso de disparo

int obstamax =14;
int obstamin= 2;
int i=0;

int ledPin0 =  A0; 
int ledPin1 =  A1; 
int ledPin2 =  A2; 
int ledPin3 =  A3; 

int estado =0; 
int tt = 0; 
int duracion;
int distancia;
int CMD;
int CMC;
int CMI;
int CM;

int angizq= 150;
int angdere= 30;
int angcent=90;
int a = 0;
int velocidad =245;

void setup()
{

myservo.attach(9);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);

myservo.write(angcent);
delay(3000);
motor_stop();
}

void loop() 
{

        leer_obstaculo();// lee distancia y almacena obstaculo
       
}

int DISTACM()//funcion que regresa un valor entero de la distancia para su comparacion
{
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW); 
  duracion = pulseIn(ECHO, HIGH); //Medición del ancho de pulso recibido en el pin Echo
  distancia =  (float (duracion))/53;
  delay(5);
  
  return distancia;
  
  
}
////////////////////////////////////////////////
void motor_stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
/////////////////////////////////////////////////
void motor_atras()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
////////////////////////////////////////////////
void motor_adelante()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
//////////////////////////////////
void motor_izquierda()//gerena un pequeño tiempo girando debe parar
{
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(BACKWARD);
   
  
}
//////////////////////////////////
void motor_derecha()//gerena un pequeño tiempo girando debe parar
{
 
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(FORWARD);
    
}
//////////////////////////////////
void leer_obstaculo()
{
 //// leera 2 POSICIONES DERECHA E IZQUIERDA
 /////poscicion uno
 // motor_stop();//parar los motores
 CM = DISTACM();//lee la funcion de leer los centimetros
 
if(CM <= obstamax && CM >=obstamin )//verifica si hay obstaculos menos a 14 cm
        {
        /////poscicion dos
         motor_stop();
         myservo.write(angdere);//servomotor derecha
         delay(1000);
         CMD = DISTACM();//lee la funcion de leer los centimetros
         myservo.write(angizq);//servomotor derecha
         delay(1000);
         CMI = DISTACM();//lee la funcion de leer los centimetros
         
          if(CMI > CMD)//HAY OBSTA EN DERECHA
          {
           myservo.write(angcent);//servomotor en 180 grados izquierda
           delay(1000);
           motor_izquierda();
           delay(500);
           
          }
          if(CMI < CMD)//OBSTA IZQ
          {
           myservo.write(angcent);//servomotor en 180 grados izquierda
           delay(1000);
           motor_derecha();
           delay(500);
          }
        }
//////////////////////////////////////

  else 
   {
      // myservo.write(angcent);//servomotor en 180 grados izquierda
       motor_adelante();

   }
  }
 
