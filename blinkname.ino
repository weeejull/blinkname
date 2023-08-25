const int ledPin = 13;    
const int buttonPin = 2;  
const long dotDuration = 200;  
const long dashDuration = 3 * dotDuration; //dot dash time duration in the ratio 1:3

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
  digitalWrite(ledPin, LOW);  
  Serial.begin(9600);  
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    blinkname("VIJUL");  //one can customise their name here
    delay(1000);  
  }
}

// procedure to blink the morse code in the form of a dot and dash
void blinkname(String name) {
  String morseCode = morsecode(name);
  
  for (int i = 0; i < morseCode.length(); i++) {
    char symbol = morseCode.charAt(i);
    if (symbol == '.') {
      digitalWrite(ledPin, HIGH);
      delay(dotDuration);
    } else if (symbol == '-') {
      digitalWrite(ledPin, HIGH);
      delay(dashDuration);
    } else if (symbol == ' ') {
      digitalWrite(ledPin, LOW);  
      delay(dashDuration);
    }
    digitalWrite(ledPin, LOW);
    delay(dotDuration);  
  }
}

String morsecode(String name) {
  // morse code for each letter
  String morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
  String morseName = "";

  for (int i = 0; i < name.length(); i++) {
    char letter = name.charAt(i);
    if (letter == ' ') {
      morseName += " ";  
    } else if (letter >= 'A' && letter <= 'Z') {
      int index = letter - 'A';
      morseName += morseCodes[index];
      morseName += " "; 
    }
  }

  return morseName;
}
