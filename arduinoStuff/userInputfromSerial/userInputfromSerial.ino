String questions [7] = {
  "What is your name?",
  "What year were you born in?",
  "What did people call you in high school?",
  "One word to describe yourself:",
  "What's your father's name?",
  "Mother's name?",
  "Thank you, please wait while you are labelled..."};
  
String answer [6] = {"","","","","",""};

int i = 0;
int n = 0;

char n_byte = 0;
String n_str = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome");
  Serial.println(questions[0]);
}

void loop() {
    while (i<=5) {
    if (Serial.available() > 0) {    // is a character available?
      n_byte = Serial.read();       // get the character
    
      if (n_byte != '\n') {
        // a character of the string was received
        n_str += n_byte;
      }
      else {
        // end of string
        answer[i] = n_str;
        n_str = ""; // clear n string
        Serial.println(answer[i]);
        Serial.println("");
        Serial.println(questions[i+1]);
        i++;
       }
     } // end: if (Serial.available() > 0)
   }
 }
