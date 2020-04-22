/*
 * MUY IMPORTANTE - Al enviar a Arduino DESCONECTAR TX y RX del bluetooth.
 */

const int LED = 13;
const int BTPWR = 10;

char nombreBT[11] = "Car_San";
char pin[5] = "0000";
char velocidad = '4'; // la velocidad 9600 se corresponde con el num. 4
char modo='1';        // '0' para esclavo y '1' para maestro

// Motor A
int ENA = 3;
int IN1 = 2;
int IN2 = 5;

// Motor B
int ENB = 9;
int IN3 = 7;
int IN4 = 8;
int estado = 'p';

void setup() {
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
  delay(3000);
  digitalWrite(LED, LOW);
  
}

void loop (){
  
  /* if (Serial.available())
  {
    estado = Serial.read();

    if (estado == 'w')
    {
      Adelante();
    }
    if (estado == 's')
    {
      Atras();
    }
    if (estado == 'm')
    {
      Derecha();
    }
    if (estado == 'n')
    {
      Izquierda();
    }
    if (estado == 'q')
    {
      Parar();
    }
    if (estado == 'l')
    {
      digitalWrite(LED, HIGH);
    }
    if (estado == 'k')
    {
      digitalWrite(LED, LOW);
    }
  }
*/



//  Adelante ();
//  delay (5000);
  Atras ();
  delay (3000);
//  Derecha ();
//  delay (2000);
//  Izquierda ();
//  delay (2000);
  Parar ();
  delay (4000);

}
void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 255); //Velocidad motor A
  
  //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 255); //Velocidad motor B
 }

void Atras ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 255); //Velocidad motor A
 // Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 255); //Velocidad motor B
}

void Derecha ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 200); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 100); //Velocidad motor A
}

void Izquierda ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 100); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 200); //Velocidad motor A
}


void Parar ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor A
}
