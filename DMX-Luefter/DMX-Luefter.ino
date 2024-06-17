#define FunktionRelais
#define FunktionDMX
//#define FunktionSerial
//#define EEPROMschreiben

// ------------------library-----------------------
#include <Arduino.h>

#ifdef FunktionDMX
  #include <DMXSerial.h>
#endif

// ------------------DMX-----------------------

byte PowerOn,
     Drehzahl;

byte PowerOnCh_1        =   0,
     DrehzahlCh_2       =   1;

// ------------------TM1637Display-----------------------
#include <TM1637Display.h>
// Module connection pins (Digital Pins)
TM1637Display display(10, 11); // CLK, DIO

const uint8_t d[] = {SEG_B | SEG_C | SEG_D | SEG_E | SEG_G};
const uint8_t A[] = {SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G};
const uint8_t C[] = {SEG_A | SEG_D | SEG_E | SEG_F };
const uint8_t D[] = {SEG_A | SEG_B | SEG_C | SEG_D  | SEG_E  | SEG_F};
const uint8_t Sound[] = {SEG_A | SEG_C | SEG_D | SEG_F | SEG_G,
                         SEG_C | SEG_D | SEG_E | SEG_G,
                         SEG_C | SEG_D | SEG_E,
                         SEG_B | SEG_C | SEG_D | SEG_E | SEG_G};
const uint8_t Bindestrich[] = {SEG_G,
                               SEG_G,
                               SEG_G,
                               SEG_G};

// ------------------EEPROM-----------------------
#include <EEPROM.h>
int Adresse_0 = 0,    // Speicher DMX-Adresse
    Adresse_1 = 1,
    Adresse_2 = 2,
    Adresse_3 = 3,
    Adresse_4 = 4,
    Adresse_5 = 5,
    Adresse_6 = 6,
    Adresse_7 = 7,
    Adresse_8 = 8,
    Adresse_9 = 9,    // Speicher DMX-Adresse
    Adresse_10 = 10,    // Speicher Hauptmenü DMX-Modus oder Autoprogramm
    Adresse_11 = 11,    // Speicher Autoprogramm
    Adresse_12 = 12;    // Speicher Channel Auswahl

// ------------------Taster-----------------------
int TasteUP = 4,    // Pin vom Taster
    StatusTasteUP,    // Zustand vom Taster
    TasteDOWN = 5,
    StatusTasteDOWN,
    TasteMODE = 6,
    StatusTasteMODE,
    TasteENTER = 7,
    StatusTasteENTER;

// ------------------Relais-----------------------
int relais_1 = 8,
    relais_2 = 9,
    relais_3 = 12;

// Wert Relais schalten
int WertRelaisHigh = 200,
    WertRelaisLow = 10;

int RelaisAnAus1 = 1,
    RelaisAnAus2 = 0;

// ------------------Variabeln-----------------------
int dmxBaseCh,    // DMX-Adresse
    stelle,
    MODE = 0,
    DrehzahlstufeZaehler,    // EEprom letzter Zustand
    Hauptmenuezaehler,    // EEprom letzter Zustand
    Hauptmenue,
    DMXDrehzahl;      // Letzter Drehzahl Wert

// Zwischenspeicher Hauptmenü Funktion (in welcher Funktion er ist)
int DMX_Modus_Nix,
    DMX_Adresse_einstellen,
    Autoprogramme;


// ------------------------------------Setup-----------------------------------------
void setup() {
  #ifdef EEPROMschreiben
    EEPROMschreibenErstesMal();
  #endif
  
  #ifdef FunktionSerial
    Serial.begin(9600);
  #endif
  
  // ------------------DMX-----------------------
  #ifdef FunktionDMX
    DMXSerial.init(DMXReceiver);  // Pin 2
  #endif

  // ------------------Taster-----------------------
  pinMode(TasteUP, INPUT_PULLUP);
  pinMode(TasteDOWN, INPUT_PULLUP);
  pinMode(TasteMODE, INPUT_PULLUP);
  pinMode(TasteENTER, INPUT_PULLUP);

  // ------------------Relais-----------------------
  pinMode(relais_1, OUTPUT);
  pinMode(relais_2, OUTPUT);
  pinMode(relais_3, OUTPUT);

  RelaisStartWerte();
  
  // ------------------Display-----------------------
  display.setBrightness(0x0f);

  // ------------------EEPROM-----------------------
  eepromauslesen();

  // Werte aus dem EEPROM lesen
  Hauptmenuezaehler = EEPROM.read(Adresse_10);
  DrehzahlstufeZaehler = EEPROM.read(Adresse_11);

  // ------------------Drehzahl Wert DMX-----------------------
  DMXDrehzahl = 0;
}

// ------------------------------------Loop-----------------------------------------
void loop() {
  HauptMenu();
}
