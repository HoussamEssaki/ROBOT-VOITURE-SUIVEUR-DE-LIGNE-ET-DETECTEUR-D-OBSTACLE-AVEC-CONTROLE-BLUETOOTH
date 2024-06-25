  void setup() 
{
    Serial.begin(9600); // Initialise la communication série avec le moniteur série
}
//
  void loop()
{
  // Si des données sont disponibles depuis le module Bluetooth
   while (Serial.available() > 0) 
    {
        char donnee = Serial.read(); // Lire les données reçues du module Bluetooth
        Serial.print("Donnée reçue depuis Bluetooth : ");
        Serial.println(donnee);
    }
}

