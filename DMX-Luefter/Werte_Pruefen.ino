void pruefenModeMenu(){
  if(DrehzahlstufeZaehler < 1){
    DrehzahlstufeZaehler = 4;
  }
  if(DrehzahlstufeZaehler >= 5){
    DrehzahlstufeZaehler = 1;
  }
}
