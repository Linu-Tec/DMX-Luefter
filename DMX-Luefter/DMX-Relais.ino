void DMXsteuern(){
  #ifdef FunktionRelais
    PowerOn = DMXSerial.read(dmxBaseCh + PowerOnCh_1);     // Dmx Relais Wert auslesen
    Drehzahl = DMXSerial.read(dmxBaseCh + DrehzahlCh_2);     // Dmx Relais Wert auslesen
    
    if(PowerOn > 126){    // Größer
      AnsteuernRelais();
    }
    else{    // Wenn Kleiner dann
      RelaisStartWerte();   // Aus
    }
  #endif
}

// -------------------------------------------------------------------------------------

void AnsteuernRelais(){
  #ifdef FunktionRelais
    if(DMXDrehzahl == 0){   // Letzten Zustand abrufen und ansteuern
      RelaisStartWerte();   // Aus
    }
    if(DMXDrehzahl == 1){
      RelaisDrehzahlStellung_1();   // Stufe 1
    }
    if(DMXDrehzahl == 2){
      RelaisDrehzahlStellung_2();   // Stufe 2
    }
    if(DMXDrehzahl == 3){
      RelaisDrehzahlStellung_3();   // Stufe 3
    }

    
    if(Drehzahl >= 0 && Drehzahl < 63){    // Drehzahlstufe 0
      RelaisStartWerte();
      DMXDrehzahl = 0;
    }
    if(Drehzahl > 64 && Drehzahl < 126){    // Drehzahlstufe 1
      RelaisDrehzahlStellung_1();
      DMXDrehzahl = 1;
    }
    if(Drehzahl > 127 && Drehzahl < 189){   // Drehzahlstufe 2
      RelaisDrehzahlStellung_2();
      DMXDrehzahl = 2;
    }
    if(Drehzahl > 190 && Drehzahl < 255){   // Drehzahlstufe 3
      RelaisDrehzahlStellung_3();
      DMXDrehzahl = 3;
    }
  #endif
}
