#include "Osc.h"

void Osc::setup() {
  // Setup OSC.
  receiver.setup(PORT);
  sender.setup(HOST, PORTTOSEND);
}

void Osc::update() {
    while (receiver.hasWaitingMessages()) {
      ofxOscMessage m;
      // Set the next message.
      #pragma warning(disable: WARNING_CODE)
      
      receiver.getNextMessage(&m);

      processTouchCommands();
    }
}

void Osc::processTouchCommands() {
  // Do something if I receive a OSC command.
  // Right now, I don't have any command. 
}

// Send the position to Wekinator.
void Osc::sendPositionToWekinator(glm::vec3 pos) {
  ofxOscMessage m;
  m.setAddress(string(MESSAGE));
  m.addFloatArg((float)pos.x);
  m.addFloatArg((float)pos.y);
  m.addFloatArg((float)pos.z);
  sender.sendMessage(m, false);
}
