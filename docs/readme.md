DOCUMENTAÇÃO DO PROJETO TERMÔPETS

## 1. DESCRIÇÃO DO PROJETO
As ilhas de calor são fenômenos que causam grandes problemas em muitas cidades ao redor do mundo; elas são as principais responsáveis pelos aumentos de temperaturas em determinadas superfícies como asfalto, tijolos e concreto. Essas altas temperaturas não só prejudicam a saúde do ser humano, mas também a de cães-guias, pets e cavalos da cavalaria da polícia, que ficam muitas vezes expostos a esse fenômeno por circularem neste ambiente. Visto isso, esse trabalho tem como finalidade desenvolver um sistema com base na Internet das Coisas (IoT) intitulado “TermôPets”, dedicado ao acompanhamento de temperatura em tempo real da principal superfície urbana, o asfalto.

## 2. FUNCIONAMENTO DO SISTEMA
O sistema utiliza sensores infravermelhos de temperatura, instalados em pontos estratégicos urbanos como postes, aptos a medir a temperatura do terreno sem precisar de ter uma proximidade física. As informações obtidas serão direcionadas via protocolo MQTT para uma plataforma digital que indicará a temperatura no trajeto desejado, mostrará um trajeto seguro  e enviará alertas para os tutores, se necessário. Além disso, pretendemos utilizar ícones visuais urbanos, como placas de LEDs (atuador), nos postes, que indicarão a temperatura atual. O propósito do sistema é  auxiliar na construção de uma cidade mais acessível, saudável e sustentável, impulsionando uma atividade mais segura para pessoas e animais.

## 3. HARDWARE UTILIZADO
- ESP32
- Sensor de temperatura
- LEDs 
- Fonte de alimentação

## 4. COMUNICAÇÃO MQTT
No TermôPets, o ESP32 atuará como cliente MQTT, publicando os valores de temperatura em tópicos específicos. Um broker MQTT na nuvem armazenará e distribuirá as mensagens para assinantes, como a plataforma de visualização e aplicativos móveis. A utilização de mensagens retidas permitirá que novos clientes recebam a última temperatura publicada imediatamente após a conexão.Comunicação e Broker MQTTA transmissão de dados entre o ESP32 e a plataforma digital ocorre via protocolo MQTT (Message Queuing Telemetry Transport), escolhido por sua leveza e eficiência em aplicações IoT.Conforme a necessidade de especificação do sistema, o broker utilizado é o Eclipse Mosquitto, um broker de código aberto amplamente adotado em ambientes acadêmicos e industriais pela sua confiabilidade e suporte ao protocolo MQTT v3.1/v3.1.1.

## 5. INTEGRAÇÃO DO SISTEMA
O sensor coleta os dados → o ESP32 processa → envia via MQTT → o LED é acionado conforme a temperatura.

## 6. COMO REPRODUZIR O PROJETO
1. Montar circuito
2. Configurar o código no ESP32
3. Conectar à rede Wi-Fi
4. Executar o código
5. Monitorar os dados via MQTT

## 7. PROTOCOLOS UTILIZADOS
- Comunicação Wi-Fi (TCP/IP)
- Protocolo MQTT

## 8. CONSIDERAÇÕES
O projeto se caracteriza como uma aplicação de Internet das Coisas (IoT), integrando sensores, atuadores e comunicação em rede para monitoramento remoto e tomada de decisão em tempo real.
