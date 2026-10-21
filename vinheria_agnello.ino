#include <Adafruit_LiquidCrystal.h>

// Pinos dos componentes
const int ldr = A0;
const int ledVermelho = 12;
const int ledAmarelo = 11;
const int ledVerde = 10;
const int buzzer = 9;

// LCD
Adafruit_LiquidCrystal lcd(0);

// Valores medidos no seu sensor
const int SEM_LUZ = 54;
const int MEIA_LUZ = 937;
const int MUITA_LUZ = 974;

// Controle do buzzer
unsigned long tempoAlarme = 0;
bool alarmeTocando = false;

void setup()
{
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledAmarelo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(buzzer, OUTPUT);

    Serial.begin(9600);
    Serial.println("ARDUINO INICIOU");

    lcd.begin(16, 2);
    lcd.setBacklight(1);

    // Mensagem inicial
    lcd.setCursor(0, 0);
    lcd.print("Bem-vindo a");
    lcd.setCursor(0, 1);
    lcd.print("Vinheria Agnello");

    delay(3000);
    lcd.clear();
}

void loop()
{
    // Leitura do sensor
    int leitura = analogRead(ldr);

    // Calcula a porcentagem usando map()
    int luz;

    if (leitura <= MEIA_LUZ)
    {
        luz = map(leitura, SEM_LUZ, MEIA_LUZ, 0, 50);
    }
    else
    {
        luz = map(leitura, MEIA_LUZ, MUITA_LUZ, 50, 100);
    }

    luz = constrain(luz, 0, 100);

    // Mostra a porcentagem no LCD
    lcd.setCursor(0, 0);
    lcd.print("Luz: ");
    lcd.print(luz);
    lcd.print("%       ");

    // Define o status e acende apenas um LED
    lcd.setCursor(0, 1);

    if (leitura < 900)
    {
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, LOW);

        lcd.print("Status: NORMAL  ");
    }
    else if (leitura < 960)
    {
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAmarelo, HIGH);
        digitalWrite(ledVermelho, LOW);

        lcd.print("Status: ALERTA  ");
    }
    else
    {
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, HIGH);

        lcd.print("Status: PROBLEMA");

        // Inicia o alarme
        if (!alarmeTocando)
        {
            tone(buzzer, 220);
            tempoAlarme = millis();
            alarmeTocando = true;
        }
    }

    // Mantém o buzzer tocando por 3 segundos completos
    // mesmo se o status mudar
    if (alarmeTocando && millis() - tempoAlarme >= 3000)
    {
        noTone(buzzer);
        alarmeTocando = false;
    }

    Serial.println(leitura);
    delay(100);
}
