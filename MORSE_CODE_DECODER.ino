const int touchPin = 3;  // Pin connected to the TTP233 touch sensor

// Morse code timing constants
const unsigned long dotDuration = 1000;      // Length of a dot
const unsigned long dashDuration = 2000;     // Length of a dash
const unsigned long decodeDuration = 500;   // Time to decode a character
const unsigned long wordGapDuration = 4000;  // Time to indicate a new word
const unsigned long printDuration = 2000;   // Time to print the whole decoded string
const unsigned long debounceDelay = 50;      // Debounce time

// Variables to store Morse code timing
unsigned long touchPressStart = 0;
unsigned long touchReleaseTime = 0;
unsigned long lastDebounceTime = 0;
String morseCode = "";
String decodedString = "";
bool lastTouchState = HIGH;
bool touchState = HIGH;
bool touchDetected = false;
bool wordGapSent = false;  // Flag to track if a word gap has been sent

void setup() {
  pinMode(touchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(touchPin);
  unsigned long currentTime = millis();

  // Debounce logic
  if (reading != lastTouchState) {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    if (reading != touchState) {
      touchState = reading;

      // Detect touch press
      if (touchState == LOW && !touchDetected) { // Touch sensor activated
        touchPressStart = currentTime;
        touchDetected = true;
      }

      // Detect touch release
      if (touchState == HIGH && touchDetected) { // Touch sensor deactivated
        unsigned long pressDuration = currentTime - touchPressStart;
        touchDetected = false;

        // Determine if it was a dot or a dash
        if (pressDuration < dotDuration) {
          morseCode += ".";
          Serial.print("Dot detected: ");
          Serial.println(morseCode);
        } else if (pressDuration < dashDuration) {
          morseCode += "-";
          Serial.print("Dash detected: ");
          Serial.println(morseCode);
        }
        touchReleaseTime = currentTime;
      }
    }
  }

  lastTouchState = reading;

  // Decode morseCode sequence
  decodeMorseCode(currentTime);
}

// Function to decode Morse code to a character
void decodeMorseCode(unsigned long currentTime) {
  // Detect touch release and start timing for decoding
  if (touchState == HIGH && touchReleaseTime != 0 && !touchDetected) {
    touchDetected = true;
    touchPressStart = touchReleaseTime;  // Start timing from the release time
  }

  // Decode Morse code sequence into characters after touch release and time delay
  if (touchDetected && (currentTime - touchPressStart) > printDuration) {
    if (morseCode.length() > 0) {
      char decodedChar = decodeMorse(morseCode);
      decodedString += decodedChar;
      Serial.print("Decoded character: ");
      Serial.println(decodedChar);
      delay(1000);
      Serial.print("Decoded String ");
      Serial.println(decodedString);
      morseCode = "";  // Reset Morse code sequence
      touchDetected = false;  // Reset touch detection flag
    } else {
      // Handle case where no Morse code was detected
      touchDetected = false;  // Reset touch detection flag
    }
  }

  // Detect gap to indicate a new word
  if (touchState == HIGH && (currentTime - touchReleaseTime) > wordGapDuration && morseCode.length() == 0 && !wordGapSent) {
    decodedString += " ";
    wordGapSent = true; // Set flag to indicate word gap has been sent
  } else if ((currentTime - touchReleaseTime) <= wordGapDuration) {
    wordGapSent = false; // Reset flag if within word gap duration
  }
}

// Function to decode Morse code to a character
char decodeMorse(String code) {
  if (code == ".-") return 'A';
  if (code == "-...") return 'B';
  if (code == "-.-.") return 'C';
  if (code == "-..") return 'D';
  if (code == ".") return 'E';
  if (code == "..-.") return 'F';
  if (code == "--.") return 'G';
  if (code == "....") return 'H';
  if (code == "..") return 'I';
  if (code == ".---") return 'J';
  if (code == "-.-") return 'K';
  if (code == ".-..") return 'L';
  if (code == "--") return 'M';
  if (code == "-.") return 'N';
  if (code == "---") return 'O';
  if (code == ".--.") return 'P';
  if (code == "--.-") return 'Q';
  if (code == ".-.") return 'R';
  if (code == "...") return 'S';
  if (code == "-") return 'T';
  if (code == "..-") return 'U';
  if (code == "...-") return 'V';
  if (code == ".--") return 'W';
  if (code == "-..-") return 'X';
  if (code == "-.--") return 'Y';
  if (code == "--..") return 'Z';
  if (code == "-----") return '0';
  if (code == ".----") return '1';
  if (code == "..---") return '2';
  if (code == "...--") return '3';
  if (code == "....-") return '4';
  if (code == ".....") return '5';
  if (code == "-....") return '6';
  if (code == "--...") return '7';
  if (code == "---..") return '8';
  if (code == "----.") return '9';
  return ' '; // Default case for spaces
}
