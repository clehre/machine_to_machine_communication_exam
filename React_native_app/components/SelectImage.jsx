import * as ImagePicker from "expo-image-picker"; // not react-image-picker
import resizeUploadImg from "./resizeImg";

export default async function ImagePickerButton() {
  // No permissions request is necessary for launching the image library
  await ImagePicker.launchImageLibraryAsync({
    mediaTypes: ImagePicker.MediaTypeOptions.Images,
    width: "16",
    allowsEditing: true,
    aspect: [1, 1],
    quality: 1,
    base64: true,
  }).then(
    (res) => {
      resizeUploadImg(res);
    },
    (err) => console.log(err)
  );
}
