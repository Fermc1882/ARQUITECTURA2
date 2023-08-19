#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     50ms

UnbufferedSerial pc(USBTX, USBRX, 9600);

int main()
{
    // Initialize the RGB LEDs as outputs
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);

    ledR.period(0.01);  // Shorter period for smoother color transitions
    ledG.period(0.01);
    ledB.period(0.01);

    while (true) {
        char input[7];
        pc.read(input, sizeof(input));

        // Convert the input hex string to RGB values
        int r, g, b;
        sscanf(input, "#%02x%02x%02x", &r, &g, &b);

        // Convert RGB values to PWM duty cycle (0.0 - 1.0)
        float pwmR = static_cast<float>(r) / 255.0;
        float pwmG = static_cast<float>(g) / 255.0;
        float pwmB = static_cast<float>(b) / 255.0;

        // Set the PWM values for each color channel
        ledR.write(1-pwmR);
        ledG.write(1-pwmG);
        ledB.write(1-pwmB);

        ThisThread::sleep_for(BLINKING_RATE);
    }
}
