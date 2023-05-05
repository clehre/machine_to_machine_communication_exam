import Paho from "paho-mqtt";
import ImagePickerButton from "./SelectImage";
import { TextInput } from "react-native";
const destinations = [
  { topic: `${global.name}/brightness`, message: "2" },
  { topic: `${global.name}/uploadImage`, message: "String of bmparray? " },
  { topic: `${global.name}/text`, message: "" },
  { topic: `${global.name}/sleep`, message: "0" },
];
export default function action(c, n) {
  console.log(n);
  const dest = destinations[n - 1];
  if (n === 2) {
    ImagePickerButton();
    return;
  }

  if (n === 1) {
    const message = new Paho.Message(global.brightness.toString());
    message.retained = true;
    message.destinationName = `${global.name}/brightness`;
    c.send(message);
  }
  if (n == 3) {
    const message = new Paho.Message((!global.sleep).toString());
    message.retained = true;
    message.destinationName = `${global.name}/sleep`;
    c.send(message);
  }

  const menuChoice = new Paho.Message(n.toString());
  menuChoice.retained = true;
  menuChoice.destinationName = `${global.name}/menu`;
  c.send(menuChoice);
}
