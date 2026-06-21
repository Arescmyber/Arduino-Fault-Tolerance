#define PIN_LED_VERTE 8
#define PIN_LED_ROUGE 9
#define MAX_LATENCY_MS 5

void setup() {
    Serial.begin(9600); 
    pinMode(PIN_LED_VERTE, OUTPUT);
    pinMode(PIN_LED_ROUGE, OUTPUT);

    digitalWrite(PIN_LED_VERTE, LOW);
    digitalWrite(PIN_LED_ROUGE, LOW);
    randomSeed(analogRead(0));

    Serial.println("=== WATCHDOG MATERIEL EN LIGNE ===");
}

void loop() {
    Serial.print("Calcul en cours... ");
    int temps_calcul = random(1, 8);
    delay(1000); 

    if (temps_calcul > MAX_LATENCY_MS) {
        Serial.print("🔴 ERREUR CRITIQUE : ");
        Serial.print(temps_calcul);
        Serial.println(" ms");
        Serial.println("🛑 WATCHDOG DECLENCHE : Verrouillage du systeme.");

        digitalWrite(PIN_LED_VERTE, LOW);

        // Heartbeat de securite : prouve que le CPU contrôle son crash
        while(true) { 
            digitalWrite(PIN_LED_ROUGE, HIGH);
            Serial.println("[SYSTEM LOCKED] - En attente de reset physique...");
            delay(2000);
            digitalWrite(PIN_LED_ROUGE, LOW);
            delay(500);
        } 
        
    } else {
        Serial.print("Termine en ");
        Serial.print(temps_calcul);
        Serial.println(" ms. (OK)");

        digitalWrite(PIN_LED_VERTE, HIGH);
        delay(100);
        digitalWrite(PIN_LED_VERTE, LOW);
    }
}
