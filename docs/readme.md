DOCUMENTAÇÃO DO PROJETO TERMÔPETS

1. DESCRIÇÃO DO PROJETO
O projeto TermoPets tem como objetivo monitorar a temperatura do asfalto para evitar danos à saúde de animais, utilizando Internet das Coisas (IoT).

2. FUNCIONAMENTO DO SISTEMA
O sistema funciona por meio da leitura de temperatura realizada por um sensor. Os dados são enviados para o ESP32, que processa as informações e aciona um LED conforme o nível de temperatura.

Além disso, os dados são enviados via protocolo MQTT para um broker, permitindo o monitoramento remoto em tempo real.

3. HARDWARE UTILIZADO
- ESP32
- Sensor de temperatura
- LED (atuador)
- Fonte de alimentação

4. COMUNICAÇÃO MQTT
O ESP32 se conecta a uma rede Wi-Fi e envia os dados de temperatura para um broker MQTT.

Os dados são publicados em um tópico e podem ser acessados por outras aplicações, como plataformas de monitoramento.

5. INTEGRAÇÃO DO SISTEMA
O sensor coleta os dados → o ESP32 processa → envia via MQTT → o LED é acionado conforme a temperatura.

6. COMO REPRODUZIR O PROJETO
1. Montar o circuito conforme o diagrama
2. Configurar o código no ESP32
3. Conectar à rede Wi-Fi
4. Executar o código
5. Monitorar os dados via MQTT

7. PROTOCOLOS UTILIZADOS
- Comunicação Wi-Fi (TCP/IP)
- Protocolo MQTT

8. OBSERVAÇÕES
O sistema pode ser expandido para integração com aplicativos e sistemas de monitoramento urbano.
