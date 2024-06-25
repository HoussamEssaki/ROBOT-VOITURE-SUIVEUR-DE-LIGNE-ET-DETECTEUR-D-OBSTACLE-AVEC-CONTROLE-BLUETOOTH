// Définir les pins
    const int trigPin = 8;
    const int echoPin = 10;

// Définir les variables
    long duration;
    int distance;

//La méthode pour calculer la distance
  void Calcul_Distance()
{
  // Effacer le trigger pin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

  // Envoyez une impulsion de 10 microsecondes pour déclencher la broche
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

  // Mesurer la durée de l'impulsion sur la broche d'écho
      duration = pulseIn(echoPin, HIGH);

  // Calcule de la distance en cm
     distance = duration * 0.034 / 2;

  // Afficher la distance jusqu'au moniteur série
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

  // Délai avant la prochaine mesure
      delay(500);
}
// 
  void setup() 
{
  // Initialiser la communication série
      Serial.begin(9600);

  // Définir les modes de broche
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
}
//
  void loop() 
{
    Calcul_Distance();
}
