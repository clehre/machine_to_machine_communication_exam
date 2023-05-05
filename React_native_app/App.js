import {  useEffect } from "react";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";
import Homepage from "./pages/HomePage";
import Settings from "./pages/Settings";
import Paho from "paho-mqtt";
import getSecrets from "./components/secrets";
// https://www.npmjs.com/package/global?activeTab=readme ??
global.sleep = 0;
global.name = "d1";

global.brightness = 20;
const Stack = createNativeStackNavigator();
export default function App() {
  function onMessage(message) {
    if (message.destinationName === `${global.name}/sleep`)
      global.sleep = eval(message.payloadString);
  }
  useEffect(() => {
    const secrets = getSecrets().then((secrets) => {

    
    global.client = new Paho.Client(secrets.host, Number(9001), "global.name"); 
    global.client.connect({
      onSuccess: () => {
              console.log("Connection successful");
              client.subscribe(`${global.name}/sleep`);
              client.onMessageArrived = onMessage;
            },
            onFailure: () => {
              console.log("Connection failed");
            },}
      )
    }
    
    )}),[]



  return (
    <NavigationContainer initialRouteName="Home">
      <Stack.Navigator>
        <Stack.Screen name="Home" component={Homepage} />
        <Stack.Screen name="Settings" component={Settings} />
      </Stack.Navigator>
    </NavigationContainer>
  );
}
