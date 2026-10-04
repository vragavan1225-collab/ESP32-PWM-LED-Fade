const int POT_PIN = 34; // Potentiometer connected to GPIO 34 (Analog input)
const int LED_PIN = 5;  // External LED connected to GPIO 5 (PWM output)

// PWM Settings
const int PWM_FREQ = 5000;    // 5 kHz frequency
const int PWM_RES = 8;        // 8-bit resolution (0 - 255)

void setup() {
  Serial.begin(115200);
  
  // Configure LED pin for PWM output
  ledcAttach(LED_PIN, PWM_FREQ, PWM_RES);
  
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // Read 12-bit ADC value from Potentiometer (0 to 4095)
  int potValue = analogRead(POT_PIN);
  
  // Map the 12-bit analog input (0-4095) to 8-bit PWM duty cycle (0-255)
  int pwmDuty = map(potValue, 0, 4095, 0, 255);
  
  // Set LED brightness using PWM
  ledcWrite(LED_PIN, pwmDuty);
  
  // Debug output
  Serial.print("POT Raw: ");
  Serial.print(potValue);
  Serial.print(" -> PWM Duty: ");
  Serial.println(pwmDuty);
  
  delay(15); // Small delay for smooth transition updates
}
