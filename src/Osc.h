#pragma once
#include "ofMain.h"
#include "ofxOsc.h"
#include "Midi.h"

// HOST/PORT for Wekinator
#define HOST "localhost" // Update this IP address to the IP of the other MAC.
#define SENDMESSAGE "/wek/inputs"
#define RECEIVEPORT 8000

class Osc {
  public:
    void setup();
    void update();
  
    // Setup the pitch array.
    void setupPitchSpace();
  
    // Wekinator commands.
    void sendPositionToWekinator(int idx, glm::vec3 pos);
  
    // Incoming commands.
    void processIncomingCommands(ofxOscMessage &m);
  
    // Channels.
    const int userAChannel = 3;
    const int userBChannel = 4;
    const int perimeterChannel = 5;
    
  private:
  
    // Receive OSC messages from Wekinator. 
    ofxOscReceiver receiver;
  
    // Send OSC messages to Ableton. Since there are
    // multiple people whom we want to send OSC messages for. 
    vector<ofxOscSender> senders;
    vector<int> sendPorts { 6448, 6449 };
  
    // Track previous notes so as to not send the same note again. 
    int previousUserANote;
    int previousUserBNote;
  
    // Pitch map
    vector<int> pitchSpace;
};
