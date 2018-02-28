#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 8000

// HOST/PORT for Wekinator
#define HOST "localhost" // Update this IP address to the IP of the other MAC.
#define PORTTOSEND 6448
#define MESSAGE "/wek/inputs"

class Osc {
  public:
    void setup();
    void update();
  
    // Wekinator commands.
    void sendPositionToWekinator(glm::vec3 pos);
  
    // Incoming commands.
    void processTouchCommands();
    
  private:
  
    ofxOscReceiver receiver;
    // To send OSC messages to another machine.
    ofxOscSender sender;
};
