#include <pin.h>
#include <Arduino.h>

void move_tire(int direction)
{
    switch (direction)
    {
    case FORWARD:
        digitalWrite(L289N_IN1, HIGH);
        digitalWrite(L289N_IN2, LOW);
        digitalWrite(L289N_IN3, HIGH);
        digitalWrite(L289N_IN4, LOW);
        break;
    case BACKWARD:
        digitalWrite(L289N_IN1, LOW);
        digitalWrite(L289N_IN2, HIGH);
        digitalWrite(L289N_IN3, LOW);
        digitalWrite(L289N_IN4, HIGH);
        break;
    case LEFT:
        digitalWrite(L289N_IN1, LOW);
        digitalWrite(L289N_IN2, HIGH);
        digitalWrite(L289N_IN3, HIGH);
        digitalWrite(L289N_IN4, LOW);
        break;
    case RIGHT:
        digitalWrite(L289N_IN1, HIGH);
        digitalWrite(L289N_IN2, LOW);
        digitalWrite(L289N_IN3, LOW);
        digitalWrite(L289N_IN4, HIGH);
        break;
    case STOP:
        digitalWrite(L289N_IN1, LOW);
        digitalWrite(L289N_IN2, LOW);
        digitalWrite(L289N_IN3, LOW);
        digitalWrite(L289N_IN4, LOW);
        break;
    }
}
