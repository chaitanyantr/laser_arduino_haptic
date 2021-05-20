#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>

//#define BUTTON 8
#define LED1 10
#define LED2 12
#define LED3 11
#define LED4 13
#define LED5 9
#define LED6 8
ros::NodeHandle node_handle;
//std_msgs::String button_msg;
std_msgs::UInt16 led_msg;

//led-1 callback//
void subscriberCallback1(const std_msgs::UInt16& led_msg) {
  if (led_msg.data  == 1) {
    digitalWrite(LED1, HIGH); 
  } else {
    digitalWrite(LED1, LOW);
  }
}
//led-2 callback//
void subscriberCallback2(const std_msgs::UInt16& led_msg) {
  if (led_msg.data  == 1) {
    digitalWrite(LED2, HIGH); 
  } else {
    digitalWrite(LED2, LOW);
  }
}
//led-3 callback//
void subscriberCallback3(const std_msgs::UInt16& led_msg) {
  if (led_msg.data  == 1) {
    digitalWrite(LED3, HIGH); 
  } else {
    digitalWrite(LED3, LOW);
  }
}
//led-4 callback//
void subscriberCallback4(const std_msgs::UInt16& led_msg) {
//  Serial.print(led_msg.data);
  if (led_msg.data  == 1) {
    digitalWrite(LED4, HIGH); 
  } else {
    digitalWrite(LED4, LOW);
  }
}
//led-5 callback//
void subscriberCallback5(const std_msgs::UInt16& led_msg) {
  if (led_msg.data  == 1) {
    digitalWrite(LED5, HIGH); 
  } else {
    digitalWrite(LED5, LOW);
  }
}
//led-6 callback//
void subscriberCallback6(const std_msgs::UInt16& led_msg) {
  if (led_msg.data  == 1) {
    digitalWrite(LED6, HIGH); 
  } else {
    digitalWrite(LED6, LOW);
  }
}
//ros::Publisher button_publisher("button_press", &button_msg);
ros::Subscriber<std_msgs::UInt16> led_subscriber1("haptic_left", &subscriberCallback1);
ros::Subscriber<std_msgs::UInt16> led_subscriber2("haptic_right", &subscriberCallback2);
ros::Subscriber<std_msgs::UInt16> led_subscriber3("haptic_front", &subscriberCallback3);
ros::Subscriber<std_msgs::UInt16> led_subscriber4("haptic_back", &subscriberCallback4);
ros::Subscriber<std_msgs::UInt16> led_subscriber5("haptic_up", &subscriberCallback5);
ros::Subscriber<std_msgs::UInt16> led_subscriber6("haptic_down", &subscriberCallback6);
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  //pinMode(BUTTON, INPUT);
  node_handle.initNode();
//  node_handle.advertise(button_publisher);
  node_handle.subscribe(led_subscriber1);
  node_handle.subscribe(led_subscriber2);
  node_handle.subscribe(led_subscriber3);
  node_handle.subscribe(led_subscriber4);
  node_handle.subscribe(led_subscriber5);
  node_handle.subscribe(led_subscriber6);
}

void loop()
{ 
//  if (digitalRead(BUTTON) == HIGH) {
//    button_msg.data = "Pressed";
//  } else {
//    button_msg.data = "NOT pressed";
//  }
//
//  button_publisher.publish( &button_msg );
  node_handle.spinOnce();
  
  delay(100);
}
