import { useState } from "react";
 //need to implement this for presistnt storage
import {
  StyleSheet,
  SafeAreaView,
  View,
  Text,
  TextInput,
  Pressable,
} from "react-native";

import  AsyncStorage  from "@react-native-async-storage/async-storage";




function Settings({ navigation }) {
  const [serverPath, onChangeServerPath] = useState("m2m.crabdance.com");
  const [serverPort, onChangeServerPort] = useState("9001");
  const [userName, onChangeUserName] = useState("");
  const [userPass, onChangeUserPass] = useState("");
  async function storeUserSession(_){
      const DATA = {_z : {
        host: serverPath,
        username: userName,
        password: userPass,
        port: serverPort,
        protocol: "ws",
        reconnectPeriod: 30 * 1000,
        connectTimeout: 30 * 950,
        qos: 2,
        clientID: "123123",}}
      try {
        const jsonValue = JSON.stringify(DATA._z);
        await AsyncStorage.setItem("@123412", jsonValue);
      } catch (e) {
        console.log("Error saving.!");
        console.log(e);

      }
      navigation.navigate("Home")
    }
  
  return (
    <SafeAreaView style={styles.conteiner}>
      <View style={styles.pads}>
        <Text style={styles.Header}>Your username</Text>
        <TextInput
          autoFocus={true}
          style={styles.input}
          onChangeText={onChangeUserName}
          value={userName}
        />
        <Text style={styles.Header}>Your password</Text>
        <TextInput
          style={styles.input}
          onChangeText={onChangeUserPass}
          value={userPass}
          secureTextEntry={true}
          textContentType="password"
          autoComplete="password"
        />
        <Text style={styles.Header}>MQTT Server (Websockets)</Text>
        <TextInput
          style={styles.input}
          onChangeText={onChangeServerPath}
          value={serverPath}
        />
        <Text style={styles.Header}>MQTT Port</Text>
        <TextInput
          style={styles.input}
          onChangeText={onChangeServerPort}
          value={serverPort}
        />
        <Pressable
          style={styles.confirmBtn}
          title="Connect"
          onPress={storeUserSession}
        >
          <Text style={styles.subTitle}>Save Settings</Text>
        </Pressable>
      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  conteiner: {
    paddingTop: 10,
    alignItems: "center",
    justifyContent: "center",
  },

  input: {
    justifyContent: "center",
    color:"#555",
    alignItems: "center",
    backgroundColor: "#EEE",
    padding: 20,
    paddingHorizontal: 59,
    marginBottom: 10,
    borderRadius: 4,
  },
  Header: { fontSize: 20, color: "#555", padding: 5 },
  subTitle: { fontSize: 11, color: "#555" , textAlign:"center"},

  confirmBtn: {
    borderRadius: 4,
    justifyContent: "center",
    alignItems: "center",
    margin: 8,
    textAlign: "center",
    backgroundColor: "#cdf",
    padding: 20
  },
 
});

export default Settings;
