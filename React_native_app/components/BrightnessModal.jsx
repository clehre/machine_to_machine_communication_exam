import {
  StyleSheet,
  Text,
  TextInput,
  View,
  Pressable,
  Modal,
} from "react-native";
import React, { useState } from "react";
import {  Icon } from "@rneui/themed";
import SendMsg from "./SendMsg";
const BrightnessModal = (props) => {
  const [modalVisible, setModalVisible] = useState(false);
  const prevBr = global.brightness;
  const cancelAction = () => {
    setModalVisible(false);
    global.brightness = prevBr;
    console.log("Clicked");
  };
  const confirmAction = () => {
    setModalVisible(false);
    SendMsg(global.brightness.toString(), `${global.name}/brightness`);
    console.log("Clicked");
  };
  const setBrightText = (text)=>{
    global.brightness = text;
  }
  return (
    <View>
      <Pressable
        style={styles.MatrixBtn}
        onPress={() => setModalVisible(!modalVisible)}
      >
        <Icon
          style={styles.btnIcon}
          name={props.Icon}
          color="#666"
          type="ionicon"
          size={80}
        />
        <Text style={styles.Header}>{props.Header} </Text>
        <Text style={styles.subTitle}>{props.subTitle} </Text>
        <Modal visible={modalVisible}>
          <View style={styles.conteiner}>
            <Text style={styles.Header}>Please set a brightness: </Text>
            <Text style={styles.subTitle}>Current brightness = {global.brightness} </Text>
            <TextInput
              style={styles.input}
              keyboardType="numeric"
              onChangeText={(text) => setBrightText(text)}
            /><View style ={styles.modalButtons}>
            <Pressable
              onPress={confirmAction}
              style={styles.confirmBtn}
            >
              <Text>Confirm!</Text>
            </Pressable>
            <Pressable
              onPress={cancelAction}
              style={styles.cancelBtn}
            >
              <Text>Cancel!</Text>
            </Pressable></View>
          </View>
        </Modal>
      </Pressable>
    </View>
  );
};
const styles = StyleSheet.create({
  conteiner: {
    flex: 0.3,
    alignItems: "center",
    justifyContent: "center",
    paddingTop: 150,
  },

  MatrixBtn: {
    width: 150,
    justifyContent: "center",
    alignItems: "center",
    textAlign: "center",
    padding: 5,
  },
  input: {
    justifyContent: "center",
    alignItems: "center",
    backgroundColor: "#EEE",
    padding: 20,
    paddingHorizontal: 59,
    marginBottom: 10,
    borderRadius: 4,
  },
  Header: { fontSize: 20, color: "#555" },
  subTitle: { fontSize: 11, color: "#555" , textAlign:"center"},
  btnIcon: { width: 100, fontSize: 50, aspectRatio: 1 },
  modalButtons: {
    flexDirection: "row",
  },
  confirmBtn: {
    borderRadius: 4,
    justifyContent: "center",
    alignItems: "center",
    margin: 8,
    textAlign: "center",
    backgroundColor: "#cdf",
    padding: 20,
    width: 100,
  },
  cancelBtn: {
    borderRadius: 4,
    justifyContent: "center",
    alignItems: "center",
    textAlign: "center",
    margin: 8,
    backgroundColor: "#fcd",
    padding: 20,
    width: 100,
  },
});

export default BrightnessModal;
