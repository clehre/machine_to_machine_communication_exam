import { StyleSheet, Text, View, Pressable } from "react-native";
import React from "react";
import { Icon } from "@rneui/themed";

const SettingsButton = (props) => {
  return (
    <Pressable
      style={styles.settingsbtn}
      onPress={() => props.nav.navigation.navigate("Settings")}
    >
      <Icon name="settings-outline" 
      style={styles.btnIcon}          
          color="#AAA"
          type="ionicon"
          size={80} />
      <Text style={styles.Header}>Settings</Text>
    </Pressable>
  );
};

export default SettingsButton;

const styles = StyleSheet.create({
  settingsbtn: {
    width: 150,
    justifyContent: "center",
    alignItems: "center",
    textAlign: "center",
    padding: 5},
  Header: { fontSize: 20, color: "#999" },
  subTitle: { fontSize: 11, color: "#555" },
  btnIcon: { width: 100, fontSize: 50, aspectRatio: 1 },
});
