boolean __ardublockDigitalReadPullup(int pinNumber)
{
  pinMode(pinNumber, INPUT_PULLUP);
  return digitalRead(pinNumber);
}


bool _ABVAR_1_0= false ;
String _ABVAR_2_name = "" ;
String _ABVAR_3_emptyStr = "" ;
String _ABVAR_4_YOB = "" ;
String _ABVAR_5_label1 = "" ;
String _ABVAR_6_label2 = "" ;
String _ABVAR_7_nameMom = "" ;
String _ABVAR_8_nameDad = "" ;

void getUserInput();
void printData();

void setup()
{
  Serial.begin(9600);
  Serial.print("coinReadBool:");
  Serial.print(" ");
  Serial.print(__ardublockDigitalReadPullup(A1));
  Serial.print(" ");
  Serial.println();

}

void loop()
{
  getUserInput();
  if (( ( __ardublockDigitalReadPullup(A1) ) == ( _ABVAR_1_0 ) ))
  {
    printData();
  }
}

void getUserInput()
{
  if (( ( ( _ABVAR_2_name ) == (_ABVAR_3_emptyStr) ) && ( ( Serial.available() ) > ( 0 ) ) ))
  {
    Serial.print("What's your name");
    Serial.print(" ");
    Serial.println();
    _ABVAR_2_name = Serial.read() ;
    Serial.print(_ABVAR_2_name);
    Serial.print(" ");
    Serial.println();
  }
  else
  {
  }
}

void printData()
{
  Serial.print("Name:");
  Serial.print(" ");
  Serial.print(_ABVAR_2_name);
  Serial.print(" ");
  Serial.print("(b.");
  Serial.print(" ");
  Serial.print(_ABVAR_4_YOB);
  Serial.print(" ");
  Serial.print("A.D.");
  Serial.print(" ");
  Serial.print(")");
  Serial.print(" ");
  Serial.println();
  Serial.print("Labels:");
  Serial.print(" ");
  Serial.print(_ABVAR_5_label1);
  Serial.print(" ");
  Serial.print(",");
  Serial.print(" ");
  Serial.print(_ABVAR_6_label2);
  Serial.print(" ");
  Serial.println();
  Serial.print("Homo Sapiens, 197982 B.C.");
  Serial.print(" ");
  Serial.println();
  Serial.print("Courtesy of");
  Serial.print(" ");
  Serial.print(_ABVAR_7_nameMom);
  Serial.print(" ");
  Serial.print("and");
  Serial.print(" ");
  Serial.print(_ABVAR_8_nameDad);
  Serial.print(" ");
  Serial.println();
}
