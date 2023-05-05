import { StyleSheet, View, TextInput } from "react-native";
import SettingsButton from "../components/SettingsButton";
import MatrixScreens from "../components/MatrixScreens";
import TextScreen from "../components/TextScreen";
import SnakeDrawScreen from "../components/SnakeNavScreen";
import TimeConrolled from "../components/TimeControlled";
import BrightnessModal from "../components/BrightnessModal";
const data = [
  {
    Icon: "camera-outline",
    Header: "Upload Image",
    subTitle: "",
    id: "2",
    action: 2,
  },

  {
    Icon: "bed-outline",
    Header: "Sleep",
    subTitle: "activate screensaver",
    id: "3",
    action: 3,
  },
];
const brightnessData = {
  Icon: "bulb-outline",
  Header: "Brightness",
  subTitle: "Use this mode to change the brightness of the Matrix",
  id: "1",
  action: 1,
};

const textData = {
  Icon: "text-outline",
  Header: "Text",
  subTitle: "Upload a scrolling text",
  id: "4",
  action: 4,
};

const SnakebtnData = {
  Icon: "game-controller-outline",
  Header: "Snake",
  subTitle: "take a break and play outside",
  id: "5",
  action: 5,
};
const timeControlledData = {
  Icon: "time-outline",
  Header: "Time",
  subTitle: "Set planned views by time of day",
  id: "6",
  action: 6,
};
let id = 0;

const Homepage = (props) => {
  const links = data.map((scr) => (
    <MatrixScreens
      Icon={scr.Icon}
      Header={scr.Header}
      subTitle={scr.subTitle}
      action={scr.action}
      key={(id += 1)}
      nav={props}
    />
  ));

  return (
    <View style={styles.container}>
      <View style={styles.scrView}>
        <BrightnessModal
          Icon={brightnessData.Icon}
          Header={brightnessData.Header}
          subTitle={brightnessData.subTitle}
          action={brightnessData.action}
          key={(id += 1)}
        />
        {links}
        <TextScreen
          Icon={textData.Icon}
          Header={textData.Header}
          subTitle={textData.subTitle}
          action={textData.action}
          key={(id += 1)}
        />
        <SnakeDrawScreen
          Icon={SnakebtnData.Icon}
          Header={SnakebtnData.Header}
          subTitle={SnakebtnData.subTitle}
          action={SnakebtnData.action}
          key={(id += 1)}
        />
        <TimeConrolled
          Icon={timeControlledData.Icon}
          Header={timeControlledData.Header}
          subTitle={timeControlledData.subTitle}
          action={timeControlledData.action}
          key={(id += 1)}
        />
        <BrightnessModal />
      <SettingsButton style={styles.settingsbtn} nav={props} />
      </View>

    </View>
  );
};
const styles = StyleSheet.create({
  container: { flex: 1, alignItems: "center", justifyContent: "center" },
  scrView: {
    flex: 1,
    flexDirection: "row",
    flexWrap: "wrap",
    justifyContent: "space-around",
    width: "100%",
    padding: 20,
  },
  settingsbtn: { 
    position: "absolute",
    right:5,
    color:"#555" 
   },full:{
    flex: 0.9
   }
});

export default Homepage;
