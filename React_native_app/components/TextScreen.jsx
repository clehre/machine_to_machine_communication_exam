import {
  StyleSheet,
  Text,
  TextInput,
  View,
  Pressable,
  Modal,
} from "react-native";
import React, { useState } from "react";
import { Icon } from "@rneui/themed";
import action from "./Actions";
import SendMsg from "./SendMsg";
import { ColorPicker } from "react-native-color-picker";
import toRgbString from "tinycolor2";
const TextScreen = (props) => {
  const [modalVisible, setModalVisible] = useState(false);
  const [intext, setInText] = useState("Preview");
  const confirmAction = () => {
    setModalVisible(false);
    action(global.client, 4);
    SendMsg(
      `${Math.floor(color._r)},${Math.floor(color._g)},${Math.floor(
        color._b
      )},`,
      `${global.name}/TextColor`
    );
    SendMsg(intext, `${global.name}/Text`);
    console.log("Clicked");
  };
  const [color, setColor] = useState({_r: 80, _g : 80, _b: 80});
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
        <Modal visible={modalVisible} >
          <View style={styles.conteiner}>
            <Text
              style={{
                color: `rgb(${color._r},${color._g},${color._b})`,
                fontSize: 40,
                fontWeight: "600",
              }}
            >
              {intext}
            </Text>

            <TextInput
              style={styles.input}
              onChangeText={(text) => setInText(text)}
              placeholder="Input text here! "
            />
            <View style={styles.modalButtons}>
              <Pressable
                onPressIn={() => confirmAction()}
                style={styles.confirmBtn}
              >
                <Text style={styles.buttonText}>Confirm</Text>
              </Pressable>
              <Pressable
                onPressIn={() => setModalVisible(false)}
                style={styles.cancelBtn}
              >
                <Text style={styles.buttonText}>Cancel</Text>
              </Pressable>
            </View>
          </View>
          <ColorPicker
            onColorChange={(color) => setColor(toRgbString(color))}
            style={styles.colorPicker}
          />
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
  subTitle: { fontSize: 11, color: "#555" },
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

export default TextScreen;
