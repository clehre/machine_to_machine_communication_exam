import Paho from "paho-mqtt";

export default function SendMsg(argText, argDest) {
  const message = new Paho.Message(argText);
  message.retained = true;
  message.destinationName = argDest;
  global.client.send(message);
  console.log(argText);
}
