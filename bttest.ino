#include "BluetoothSerial.h" // incluindo a biblioteca que vamos usar 
// biblioteca oficial do ESP32 para comunicação serial via Bluetooth Clássico (não BLE).
// biblioteca fornece uma forma simples de criar uma porta serial Bluetooth, como se fosse um Serial.print, mas via Bluetooth.
// é uma função do Arduino usada para enviar dados como texto legível por humanos 
// (como inteiros, números de ponto flutuante e strings) 
// através de uma porta de comunicação serial para um computador, onde podem ser visualizados no Monitor Serial. 
// Mon. Serial é uma ferramenta de software para visualizar e controlar a comunicação através de uma porta serial.
#if !defined(CONFIG_BT_ENABLED)  || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Pls run make menuconfig to and enable it
#endif 
// #endif fecha a diretiva condicional
// se as configurações do Bluetooth não estavam habilitadas, o compilador mostrou o erro.
// Se estavam habilitadas, então ele continua daqui em diante.
       BluetoothSerial SerialBt;
// Aqui você está criando um objeto chamado SerialBt da classe BluetoothSerial. 
// A classe BluetoothSerial vem da biblioteca BluetoothSerial.h .
//sse objeto é o que você vai usar para inicializar o Bluetooth, enviar e receber dados.
       char valorRecebido;
       ///  é um tipo de dado usado para armazenar um único caractere, como letras, números ou símbolos
// #if !defined(...)
// #if inicia uma verificação condicional no pré-processador (etapa anterior à compilação).
// pre. proc - é um programa que manipula o código-fonte de um programa antes que ele seja compilado 
// ou processado pela ferramenta principal,
// CPP processor
/// Ele pode:
// Incluir arquivos: Inserir o conteúdo de outros arquivos (como arquivos de cabeçalho) no código. 
// Definir macros: Substituir trechos de código por outros, simplificando o código. 
// Compilação condicional: Compilar certas partes do código apenas sob condições específicas. 
// Geração de mensagens: Controlar a geração de mensagens de erro durante a compilação. 
// os nomes entre parenteses São configurações internas do ESP-IDF (o framework da Espressif para ESP32).
// || (OU lógico)
// #error Isso força um erro de compilação e interrompe o processo de build.
//A mensagem que aparece é:
//"Bluetooth is not enabled! Pls run make menuconfig to and enable it"

void setup() {

  //Função especial do Arduino que roda uma vez só quando o ESP32 é ligado ou reiniciado.
   // É usada para configurar tudo antes de começar o loop principal.
  Serial.begin(115200);
  //INICIA A COMUNICACAO SERIA VIA ENTRE O ESP E O PC VIA PORTA USB
  SerialBt.begin("LEDilson");
  //Inicia a comunicação Bluetooth Serial Clássica com o nome "LEDilson".
  Serial.println("LEDilson foi achado");
// Envia uma mensagem para o monitor serial (USB), apenas para indicar que o Bluetooth foi iniciado com sucesso.
 pinMode(5, OUTPUT);                 // Configura o pino falando q ele ta enviando infos da esp e no pino 5 ]

}

void loop(){

    valorRecebido = (char)SerialBt.read();
    // guarda o caractere lido dentro da variável valorRecebido,
/// Serial.br Essa função lê 1 byte de dado que foi recebido via Bluetooth Serial.
// Esse dado vem como um número (int) entre 0 e 255, representando o caractere (ex: 65 para 'A').
// Se não houver dados disponíveis, ela retorna -1
// (char) — converte o valor recebido para o tipo caractere. Se você receber 65, ele vira 'A'. Se receber 49, vira '1'.

 if(SerialBt.available()) {
  // A função SerialBt.available() verifica se há dados recebidos pelo Bluetooth prontos para serem lidos
  // Ela retorna o número de bytes disponíveis para leitura.
  SerialBt.write(Serial.read());
// Ou seja, ele pega dados que chegaram pelo USB (do PC)
// e envia pelo Bluetooth para outro dispositivo conectado ao ESP32.
// Aqui, está lendo um byte da comunicação Serial USB com o computador: Serial.read().
//Em seguida, está escrevendo (enviando) esse byte para o Bluetooth com SerialBt.write().

 }
 if(SerialBt.available()) 
 //Outra vez, verifica se há dados disponíveis para ler pelo Bluetooth.
 // Se houver, ele verifica o valor da variável valorRecebido, que foi definida antes com:
 // valorRecebido = (char)SerialBt.read();
 //lorRecebido armazena o último caractere recebido via Bluetooth.
 {
  if (valorRecebido == '1')
  //Se o caractere recebido for '1' (o número 1 como caractere, não número inteiro)
  //envia a mensagem "LEDison preso:" para o dispositivo conectado via Bluetooth com SerialBt.println()
  //ele liga o LED (ou qualquer coisa ligada ao pino 5 do ESP32) com digitalWrite(5, HIGH);
  {
    SerialBt.println("LEDison preso:");
    digitalWrite(5, HIGH);
  }

    if (valorRecebido == '2'){
    SerialBt.println("LEDison solto:");
    digitalWrite(5,LOW);
  }
  
  
 }
 delay(30);
}
