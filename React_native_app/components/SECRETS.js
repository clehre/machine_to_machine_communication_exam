import  AsyncStorage  from "@react-native-async-storage/async-storage";

export default async function getSecrets() {
    const DATA = {_z : {
        host: "m2m.crabdance.com",
        username: "",
        password: "",
        port: 9001,
        protocol: "ws",
        reconnectPeriod: 30 * 1000,
        connectTimeout: 30 * 950,
        qos: 2,
        clientID: "123123",
  }};
  try {
    const jsonValue = await AsyncStorage.getItem("@123412")
    const obj = JSON.parse(jsonValue)
    if(obj[_z]?.host == undefined||obj["_z"] == null ) throw "object host is empty"
    console.log("Loaded From ram.!");

    return obj._z != null ? obj : null;
  } catch (e) {
    
    const storeData = async (_) => {
      try {
        const jsonValue = JSON.stringify(DATA._z);
        await AsyncStorage.setItem("@123412", jsonValue);
      } catch (e) {
        console.log("Error saving.!");
        console.log(e);

      }
    };
    storeData(DATA._z).then(()=>{},()=>{})
    console.log(" in storeFunc",  DATA)
    
    return DATA._z

    // error reading value
  }
};


