import { StyleSheet, Text, View, Pressable } from "react-native";
import React from "react";
import { Icon } from "@rneui/themed";
import action from "./Actions";

const MatrixScreens = (props) => {
  return (
    <View>
      <Pressable
        style={styles.MatrixBtn}
        onPress= {() => action(global.client, props.action)}
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
  Header: { fontSize: 20, color: "#555" },
  subTitle: { fontSize: 11, color: "#555", textAlign:"center" },
  btnIcon: { width: 100, fontSize: 50, aspectRatio: 1 },
});

export default MatrixScreens;
