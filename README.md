CODIGO PARA LEER CODIGOS HEXADECIMALES EN CONSOLA PARA DAR VALORES DE RGB A LA TARJETA CONTROLADORA 

Librerías Utilizadas: #include "mbed.h": Incluye la librería "mbed" que proporciona una abstracción para interactuar con el hardware, en este caso la tarjeta

2. Define una constante llamada BLINKING_RATE con un valor de 50ms, que será el intervalo entre actualizaciones de los colores de los LEDs.
3. inicializa la comunicación a través del puerto USB de la placa con una velocidad de transmisión de 9600 bps. Esto se hace mediante la línea UnbufferedSerial pc(USBTX, USBRX, 9600);. Esta comunicación serie se utiliza para recibir comandos de cambio de color para los LEDs.
4. MAIN()
  a. Inicializa tres objetos PwmOut llamados ledR, ledG y ledB para controlar los LEDs rojo, verde y azul, respectivamente. Estos objetos permiten generar señales de modulación por ancho de pulso (PWM) para ajustar la    intensidad luminosa de los LEDs.
   b. Establece el período de la señal PWM para cada LED mediante los métodos period().
   c. Lee una cadena de entrada de longitud 7 desde la comunicación serie utilizando pc.read(input, sizeof(input));. Esto se hace para recibir comandos de cambio de color en formato hexadecimal (#RRGGBB).
   d. Utiliza la función sscanf() para convertir la cadena hexadecimal en tres valores enteros: r (rojo), g (verde) y b (azul). Cada valor se convierte desde su representación hexadecimal de dos dígitos a su valor decimal      correspondiente. 
   g. Ajusta las señales PWM de los LEDs utilizando el método write() en los objetos ledR, ledG y ledB. La inversión (1 - valor) se utiliza porque se leen las señales (binario) al contrario, una señal PWM de 1.0 apaga el LED y una señal de 0.0 lo enciende.
