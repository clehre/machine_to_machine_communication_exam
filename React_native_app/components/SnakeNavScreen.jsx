import { StyleSheet, Text, View, Pressable, Modal } from "react-native";
import React, { useState } from "react";
import { Icon } from "@rneui/themed";
import SendMsg from "./SendMsg";

const SnakeDrawScreen = (props) => {
  const [modalVisible, setModalVisible] = useState(false);
  const getDir = (dir) => {
    switch (dir) {
      case "up":
        SendMsg("0", `${global.name}/snake`);
        break;
      case "down":
        SendMsg("1", `${global.name}/snake`);
        break;
      case "left":
        SendMsg("2", `${global.name}/snake`);
        break;
      case "right":
        SendMsg("3", `${global.name}/snake`);
        break;
      default:
        return;
    }
  };
  return (
    <View>
      <Pressable style={styles.MatrixBtn} onPress={() => setModalVisible(true)}>
        <Icon
          style={styles.btnIcon}
          name={props.Icon}
          color="#666"
          type="ionicon"
          size={80}
        />
        <Text style={styles.Header}>{props.Header} </Text>
        <Text style={styles.subTitle}>{props.subTitle} </Text>

        <Modal visible={modalVisible} animationType="slide">
          <Pressable
            onPressIn={() => setModalVisible(false)}
            style={styles.cancelBtn}
          >
            <Icon
              style={styles.btnIcon}
              name="caret-down-outline"
              color="#666"
              type="ionicon"
              size={80}
            />
          </Pressable>
          <View
            style={{ flex: 1, alignItems: "center", justifyContent: "center" }}
          >
            <View style={styles.modalButtons}>
              <Pressable onPressIn={() => getDir("up")} style={styles.gamebtn}>
                <Icon
                  style={styles.btnIcon}
                  name="chevron-up-outline"
                  color="#666"
                  type="ionicon"
                  size={80}
                />
              </Pressable>

              <View style={styles.gamebtnLR}>
                <Pressable
                  onPressIn={() => getDir("left")}
                  style={styles.gamebtn}
                >
                  <Icon
                    style={styles.btnIcon}
                    name="chevron-back-outline"
                    color="#666"
                    type="ionicon"
                    size={80}
                  />
                </Pressable>
                <Pressable
                  onPressIn={() => getDir("right")}
                  style={styles.gamebtn}
                >
                  <Icon
                    style={styles.btnIcon}
                    name="chevron-forward-outline"
                    color="#666"
                    type="ionicon"
                    size={80}
                  />
                </Pressable>
              </View>
              <Pressable
                onPressIn={() => getDir("down")}
                style={styles.gamebtn}
              >
                <Icon
                  style={styles.btnIcon}
                  name="chevron-down-outline"
                  color="#666"
                  type="ionicon"
                  size={80}
                />
              </Pressable>
            </View>
          </View>
        </Modal>
      </Pressable>
    </View>
  );
};
const styles = StyleSheet.create({
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
    marginBottom: 20,
    borderRadius: 4,
  },
  Header: { fontSize: 20, color: "#555" },
  subTitle: { fontSize: 11, color: "#555" , textAlign:"center"},
  btnIcon: { width: 100, fontSize: 50, aspectRatio: 1 },
  modalButtons: {
    flexWrap: "true",
    justifyContent: "center",
    alignItems: "center",
  },
  gamebtn: {
    paddingHorizontal: 50,
  },
  gamebtnLR: {
    flexDirection: "row",
    justifyContent: "space-between",
  },

  buttonText: {},

  cancelBtn: {
    borderRadius: 4,
    flex: 0.1,
    justifyContent: "center",
    alignItems: "center",
    textAlign: "center",

    marginTop: 45,
    backgroundColor: "#fcd",
  },
});

export default SnakeDrawScreen;
