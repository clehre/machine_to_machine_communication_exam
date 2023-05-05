import React, { useState } from "react";
import { Button,  StyleSheet, View } from "react-native";
import DateTimePickerModal from "react-native-modal-datetime-picker";


const TimePickerModal = () => {  const [pickerMode, setPickerMode] = useState(null);
  

  
    const showTimePicker = () => {
      setPickerMode("time");
    };
  
  
  
    const hidePicker = () => {
      setPickerMode(null);
    };
  
    const handleConfirm = (date) => {
      // In order to prevent the double-shown popup bug on Android, picker has to be hidden first (https://github.com/react-native-datetimepicker/datetimepicker/issues/54#issuecomment-618776550)
      hidePicker();
      console.warn("A date has been picked: ", date);
    };
  
    return (
      <View style={style.root}>
        <Button title="Select a time to show the text:" onPress={showTimePicker} />

        <DateTimePickerModal
          isVisible={pickerMode !== null}
          mode={pickerMode}
          onConfirm={handleConfirm}
          onCancel={hidePicker}
          display={"inline" }
        />
      </View>
    );
  };
  
  const style = StyleSheet.create({
    root: {
      flex: 1,
      justifyContent: "center",
      alignItems: "center",
    },

  });

export default TimePickerModal;