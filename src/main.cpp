#include <Servo.h>
#include <pin.h>
#include <movement.h>
#include <network.h>

const char *mqtt_server = "broker.mqtt-dashboard.com";



Servo claw_a;
Servo claw_b;

void claw(int direction, int claw);

void callback(char *topic, byte *payload, unsigned int length)
{

  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  if(strcmp(topic, "command-movement") == 0)
  {
    int direction = payload[0] - '0';
    move_tire(direction);
  }

  if(strcmp(topic, "command-claw-1") == 0)
  {
    int direction = payload[0] - '0';
    claw(direction, CLAW_SERVO_A);
  }

  if(strcmp(topic, "command-claw-2") == 0)
  {
    int direction = payload[0] - '0';
    claw(direction, CLAW_SERVO_B);
  }
 


}

void setup()
{
  claw_a.attach(CLAW_SERVO_A);
  claw_b.attach(CLAW_SERVO_B);
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the LED_BUILTIN pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop()
{

  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

}

void claw(int direction, int claw)
{
  if (claw == CLAW_SERVO_A)
  {
    if (direction == CLAW_OPEN)
    {
      claw_a.write(0);
    }
    else if (direction == CLAW_CLOSE)
    {
      claw_a.write(180);
    }
  }
  else if (claw == CLAW_SERVO_B)
  {
    if (direction == CLAW_OPEN)
    {
      claw_b.write(0);
    }
    else if (direction == CLAW_CLOSE)
    {
      claw_b.write(180);
    }
  }
}
