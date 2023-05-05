import { manipulateAsync, SaveFormat } from "expo-image-manipulator";
import { decode } from "base64-arraybuffer";
import { Image } from "image-js";
import SendMsg from "./SendMsg";
global.Buffer = global.Buffer || require("buffer").Buffer;

export default async function resizeUploadImg(image) {
  const manipResult = await manipulateAsync(
    image.assets[0].uri,
    [{ resize: { width: 16, height: 16 } }],
    { format: SaveFormat.PNG, base64: true }
  );
  const arrayBuffer = decode(manipResult.base64);
  const img = await Image.load(arrayBuffer);
  const data = img.getPixelsArray();
  
  SendMsg(data.toString(), `${global.name}/imageData`);
  SendMsg("2", `${global.name}/menu`);
}
