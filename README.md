# TermoPets-IoT

# Descrição 
Esse trabalho tem como finalidade desenvolver um sistema com base na Internet das Coisas (IoT) intitulado “TermôPets”, dedicado ao acompanhamento de temperatura em tempo real da principal superfície urbana, o asfalto. 

# Funcionamento 
O sistema utiliza sensores infravermelhos de temperatura, instalados em pontos estratégicos urbanos como postes, aptos a medir a temperatura do terreno sem precisar de ter uma proximidade física. As informações obtidas serão direcionadas para uma plataforma digital que indicará a temperatura no trajeto desejado, mostrará um trajeto seguro  e enviará alertas para os tutores, se necessário. Além disso, pretendemos utilizar ícones visuais urbanos, como placas de LEDs nos postes, que indicarão a temperatura atual. O propósito do sistema é auxiliar na construção de uma cidade mais acessível, saudável e sustentável, impulsionando uma atividade mais segura para pessoas e animais.

# Hardware escolhido
- ESP32
- Sensor de tempertura chamado MLX90614
- Módulo de LEDs
- Fonte de alimentação

# Comunicação MQTT
No TermôPets, o ESP32 atuará como cliente MQTT, publicando os valores de temperatura em tópicos específicos. Um broker MQTT na nuvem armazenará e distribuirá as mensagens para assinantes, como a plataforma de visualização e aplicativos móveis. A utilização de mensagens retidas permitirá que novos clientes recebam a última temperatura publicada imediatamente após a conexão.

# Como executar ?
1. Configurar Wi-fi no código
2. Configurar o broker MQTT
3. Fazer upload do código no ESP32
4. Monitorar os dados

# Imagens


# Vídeo

