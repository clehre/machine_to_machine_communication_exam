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
const TimeControlled = (props) => {
  const [modalVisible, setModalVisible] = useState(false);
  const [morningText, setMorningText] = useState("-_-");
  const [lunchText, setLunchText] = useState("-_-");
  const [eveningText, setEveningText] = useState("-_-");
  const [happyHourText, setHappyHourText] = useState("-_-");
  const [lateEveningText, setLateEveningText] = useState("-_-");

  const confirmAction = () => {
    setModalVisible(false);
    const obj = `${morningText.replace(/;/g, ":")};${lunchText.replace(
      /;/g,
      ":"
    )};${eveningText.replace(/;/g, ":")};${happyHourText.replace(
      /;/g,
      ":"
    )};${lateEveningText.replace(/;/g, ":")};8;11;17;22;23;2;;`; // .replace(/;/g, "") to make sure we dont break logic in microcontroller
    console.log(obj);
    SendMsg(obj, `${global.name}/timeControlled`);
    console.log("Clicked");
  };
  const cancelAction = () => {
    setModalVisible(false);
  };
  return (
    <View >
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
            <Text>Morning Special 0800-1100</Text>
            <TextInput
              style={styles.input}
              onChangeText={(text) => setMorningText(text)}
            />
            <Text>Lunch Special 1100-1600</Text>
            <TextInput
              style={styles.input}
              onChangeText={(text) => setLunchText(text)}
            />
            <Text>Evening Special 1600-2200</Text>
            <TextInput
              style={styles.input}
              onChangeText={(text) => setEveningText(text)}
            />
            <Text>Happy hour 2200-2300</Text>
            <TextInput
              style={styles.input}
              onChangeText={(text) => setHappyHourText(text)}
            />
            <Text>Latenight 2300-0200</Text>
            <TextInput
              style={styles.input}
              onChangeText={(text) => setLateEveningText(text)}
            />
            <View style={styles.modalButtons}>
              <Pressable onPress={confirmAction} style={styles.confirmBtn}>
                <Text>Confirm!</Text>
              </Pressable>
              <Pressable onPress={cancelAction} style={styles.cancelBtn}>
                <Text>Cancel!</Text>
              </Pressable>
            </View>
          </View>
        </Modal>
      </Pressable>
    </View>
  );
};
const styles = StyleSheet.create({
  conteiner: {
    flex: 0.8,
    alignItems: "center",
    justifyContent: "center",
    paddingTop: 150,
  },
  colorPicker: {
    flex: 0.5,
    paddingBottom: 100,
    paddingHorizontal: 50,
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
  subTitle: { fontSize: 11, color: "#555", textAlign:"center" },
  btnIcon: { width: 100, fontSize: 50, aspectRatio: 1 },
  modalButtons: {
    flexDirection: "row",
  },
  buttonText: {},
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

export default TimeControlled;
