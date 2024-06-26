# Arduino Morse Code Decoder with TTP233 Touch Sensor

This project demonstrates a Morse code decoder using an Arduino Nano and a TTP233 touch sensor. It decodes Morse code input from the touch sensor into alphanumeric characters and displays the decoded message via the Serial Monitor.

## Components Used

- Arduino Nano
- TTP233 Touch Sensor
- USB Cable for Arduino Nano (for programming and power)

## CIRCUIT DIAGRAM 

![Circuit Diagram](https://github.com/ADITYA2124/MORSE-CODE-DECODER/assets/118548905/befc7229-3103-4787-a4ee-438c08e4cc0c)

## MORSE CODE TABLE
![Morse Code](https://github.com/ADITYA2124/MORSE-CODE-DECODER/assets/118548905/e03128b3-aa36-45b3-a345-4e7c9c0cd54b)

## Setup and Wiring

### Arduino Nano Pin Connections

- **Touch Sensor (TTP233)**:
  - **VCC**: Connect to Arduino 5V or 3.3V
  - **I/O**: Connect to Arduino digital pin (e.g., D3)
  - **GND**: Connect to Arduino GND

### Arduino IDE Setup

1. Install the Arduino IDE (if not already installed).
2. Connect your Arduino Nano to your computer using the USB cable.
3. Open the `MorseCodeDecoder.ino` sketch in the Arduino IDE.
4. Select the correct board and port from the Tools menu.
5. Upload the sketch to your Arduino Nano.

## Morse Code Decoding Algorithm

The Arduino sketch implements a Morse code decoding algorithm using timing intervals to differentiate between dots (short presses) and dashes (long presses) on the touch sensor. It decodes Morse code sequences into characters and handles word gaps to construct a readable message.

## Usage

1. Ensure the Arduino Nano is powered and connected to the touch sensor.
2. Open the Serial Monitor in the Arduino IDE after uploading the sketch.
3. Touch the TTP233 sensor to input Morse code sequences.
4. The decoded characters and messages will be printed in the Serial Monitor.

## RESULT
![Result](https://github.com/ADITYA2124/MORSE-CODE-DECODER/assets/118548905/bb1994b1-151f-41d8-9432-bd9dca989ea3)

## Troubleshooting

- **No Response**: Check wiring connections and ensure the touch sensor is properly powered.
- **Incorrect Decoding**: Adjust timing constants (dotDuration, dashDuration) in the Arduino sketch as needed for accurate decoding.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to modify and expand this README.md file to include more detailed instructions, circuit diagrams, or additional features of your project. Good luck with your Arduino Morse code decoder project!
