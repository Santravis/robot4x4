
#include <SoftwareSerial.h>
#include <AFMotor.h>     // Llama a la librería del Shield L293D
#include <Servo.h>       // Llama a la librería del Servo

Servo PingServo;      // creamos un objeto tipo Servo que llamamos PingServo
AF_DCMotor motor1(1); // Motor 1 - Delante Derecha conectado al Puerto 1
AF_DCMotor motor2(2); // Motor 2 - Delante Izquierda conectado al Puerto 2
AF_DCMotor motor3(3); // Motor 3 - Atrás Izquierda conectado al Puerto 3
AF_DCMotor motor4(4); // Motor 4 - Atrás Derecha conectado al Puerto 4

int minDistGuardada = 15 ; 
// Mínima distancia para el sensor ultrasónico de la orden de parar y girar.
int trigger = 13; // trigger conectado al pin 13 digital
int eco = 2;      // eco conectado al pin 2 digital
int centroDist, izqDist, drchDist, atrasDist; 
// Define variables centro, izq., drch. y atrás para la distancia
long tiempo, pulgadas, cm;  // Define variables para el sensor
char dato;

void setup() {
Serial.begin(9600);   // Inicia el monitor serial
Serial.println("Serial test!"); // Testea la comunicación al monitor serial  
PingServo.attach(10); // El servo está conectado pin 10 del módulo shield
PingServo.write(90);  // Centra la posición del servo a 90º
motor1.setSpeed(100); // Configura velocidad motor1 a 180 (de 0 (stop) a 255 (fast)
motor2.setSpeed(100); // Configura velocidad motor2 a 180 (de 0 (stop) a 255 (fast)
motor3.setSpeed(100); // Configura velocidad motor3 a 180 (de 0 (stop) a 255 (fast)
motor4.setSpeed(100); // Configura velocidad motor4 a 180 (de 0 (stop) a 255 (fast)

}

// Comienza la función para decidir qué hacer

unsigned long ping() {
pinMode(trigger, OUTPUT); // Declaramos trigger como SALIDA
digitalWrite(trigger, LOW); // Por cuestión de estabilización del sensor lo ponemos en estado BAJO
delayMicroseconds(2); // esperamos 2 microsegundos
digitalWrite(trigger, HIGH); // Envío del pulso ultrasónico, estado ALTO
delayMicroseconds(5); // esperamos 5 microsegundos
digitalWrite(trigger, LOW); // Lo ponemos en estado BAJO
pinMode(eco,INPUT); // Declaramos eco como ENTRADA
tiempo = pulseIn(eco, HIGH); /* Función para medir la longitud del pulso entrante. 
  Mide el tiempo que transcurrido entre el envío del pulso ultrasónico y cuando 
  el sensor recibe el rebote, es decir: desde que el pin 2 empieza a recibir el rebote,
  HIGH, hasta que deja de hacerlo, LOW, la longitud del pulso entrante*/

/* Convertir microsegundos a pulgadas */

pulgadas = microsegundosApulgadas(tiempo);
cm = microsegundosAcentimetros(tiempo);
}
long microsegundosApulgadas(long microsegundos) // convierte el tiempo en distancia
{
return microsegundos / 74 / 2;
}
long microsegundosAcentimetros(long microsegundos) // convierte el tiempo en distancia
{
return microsegundos / 29 / 2;
}

void MirarFrente();
Serial.print(cm);
Serial.println(" cm"); // Imprime una línea en el monitor serial
if(pulgadas >= minDistGuardada) /* Si las pulgadas delante de un objeto 
    son mayores que o iguales a la distancia mínima salva (11 pulgadas), 
    reaccionar*/

{
TodoAvance(); // Todas las ruedas adelante
delay(110); 
}
else // Si no:
{
TodoParado(); // Detener todos los motores
MirarLados(); // Compruebe su entorno para elegir la mejor ruta
if(drchDist > izqDist) // Si la distancia derecha es mayor que la distancia izquierda, girar a la derecha
{
GirarDerecha();
}
else if (izqDist > drchDist) // Si la distancia izquierda es mayor que la distancia derecha, girar a la izquierda
{
GirarIzquierda();
}
else if (izqDist&&drchDist<minDistGuardada) // Si la distancia izquierda y derecha es más pequeña que la distancia minima, marcha atrás.
{
MarchaAtras();
}




void MirarFrente() { // Servo mirar al frente
PingServo.write(90); // Posición servo a 90º para mirar al frente.
delay(175); 
ping();
}

void MirarLados(){  // Servo mira a los lados 180º y 0º
PingServo.write(180); // Posición de 180° - derecha
delay(320);  
ping();
drchDist = cm; // obtiene la distancia a la derecha
PingServo.write(0); // Posición de 0º - izquierda
delay(620);  
ping();
izqDist = cm; // obtiene la distancia a la izquierda
PingServo.write(90); // Posición de 90° (al frente)
delay(275); 

// Imprime en el Monitor Serial
Serial.print("drchDist: ");
Serial.println(drchDist);
Serial.print("izqDist: ");
Serial.println(izqDist);
Serial.print("centroDist: ");
Serial.println(centroDist);
}


 
