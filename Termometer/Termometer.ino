int highValueFromADconverter = 642;
int lowValueFromADconverter = 462;

int highReferenceVoltage = 278; // 278 betyr 2,78V
int lowReferenceVoltage = 234;

int highReferenceTemperature = 223; // 223 betyr 22,3 grader
int lowReferenceTemperature = 100; // 100 betyr 10,0 grader

void setup() {
  // Denne trenger vi for å få data tilbake til pc’en på serial monitor
  Serial.begin(9600);
}
void loop() {
  // Les analog verdi fra Analog Inngangsport A0
  int valueFromADConverter= analogRead(A0);
  // Skriv analog verdien til serieporten

  float temperature = map(valueFromADConverter, lowValueFromADconverter, highValueFromADconverter, lowReferenceTemperature, highReferenceTemperature)/(float)(10);
  float voltage = map(valueFromADConverter, lowValueFromADconverter, highValueFromADconverter, lowReferenceVoltage, highReferenceVoltage)/(float)100;
 
  Serial.println("Verdi lest fra AD omformer: "  + String(valueFromADConverter));
  Serial.println("Endre tekst: " + String(voltage) + " grader");
  Serial.println("Spenning: " + String(voltage) + "v");
  Serial.println();

  // Vent litt før du leser den neste verdien (valgfritt)
  delay(1000);
}
