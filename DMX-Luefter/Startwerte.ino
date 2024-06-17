#ifdef FunktionRelais
  void RelaisStartWerte(){
    // ------------------Relais-----------------------
    digitalWrite(relais_1, RelaisAnAus2);
    digitalWrite(relais_2, RelaisAnAus2);
    digitalWrite(relais_3, RelaisAnAus2);
  }

  void RelaisDrehzahlStellung_1(){
    digitalWrite(relais_1, RelaisAnAus1);
    digitalWrite(relais_2, RelaisAnAus2);
    digitalWrite(relais_3, RelaisAnAus2);
  }

  void RelaisDrehzahlStellung_2(){
    digitalWrite(relais_1, RelaisAnAus2);
    digitalWrite(relais_2, RelaisAnAus1);
    digitalWrite(relais_3, RelaisAnAus2);
  }

  void RelaisDrehzahlStellung_3(){
    digitalWrite(relais_1, RelaisAnAus2);
    digitalWrite(relais_2, RelaisAnAus2);
    digitalWrite(relais_3, RelaisAnAus1);
  }
#endif
