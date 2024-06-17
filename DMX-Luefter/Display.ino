void dmxwertzeigen(){     // DMX Wert anzeigen d001
  display.showNumberDec(dmxBaseCh, false, 4, 0);
  display.setSegments(d, 1, 0);
}

// -------------------------------------------------------------------------------------

void ModeMenue(){     // Autoprogramm Wert zeigen D001
  display.showNumberDec(DrehzahlstufeZaehler, false, 4, 0);
  display.setSegments(A, 1, 0);
  
  #ifdef FunktionSerial
    Serial.print("Mode Menu: ");
    Serial.println(DrehzahlstufeZaehler);
  #endif
}
