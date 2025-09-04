void setup() { // INICIA O CODIGO
  //  
  pinMode(5, OUTPUT);  // insira o pino. OUTPUT/INPUT out- esp32 mnd infos, input - esp32 recebe infos
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5,  HIGH); //esp  manda infos //pino, ligado, desligado
  delay(500); // delay atrasa sempre em milissegundos  mas se por delaymicroseconds ou etc vc pode mudar
  digitalWrite(5, LOW); // liga e desliga apos um delay de 500 milissegundos 

  //"high" e "low" dois estados de um pino digital, representando, por exemplo, 5 V (high) ou 0 V (low), como se fosse um interruptor de liga/desliga
  delay(500); // this speeds up the simulation
}
// loop para n parar o codigo
