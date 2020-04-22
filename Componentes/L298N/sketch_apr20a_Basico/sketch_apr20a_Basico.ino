// Bluetooth
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

void setup ()
{
  // Bluetooth
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

// Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
}


void loop ()
{
  Adelante ();
  delay (5000);
  Atras ();
  delay (3000);
  Derecha ();
  delay (2000);
  Izquierda ();
  delay (2000);
  Parar ();
  delay (4000);
 
}


void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
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
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 128); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 128); //Velocidad motor B
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
 analogWrite (ENA, 50); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 150); //Velocidad motor A
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
