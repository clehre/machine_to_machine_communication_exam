## The task:

The case made for the exam was that tgiFridays wanted to use a led matrix to give information to the customers, which was conneccted to the internet somehow. This was solved using an esp32 connected to an MQTT server, and a react native app which sent commands to that mqtt server. There were some features which the exam had to implement. The first one was the possibility to show text and images which roll past on an led matrix. Which was solved with the "text"-mode from the app. This mode pushes an state which gets the text from the mqtt server, and shows it using the adafruit neomatrix lib. There is a for loop which causes the text to scroll by, and not just be stationary.

* One possible expansion here could be to make a toggle for whether or not you want to have the text horizontal or vertically scolling by.

There was a point which said the solution would have to have a feature where the user had the possibility to show different images or text, to different times of the day. Which I didnt realize before later in the project.  But due to the modulebased app, and state based software design in the arduino code, I had the possibility to add another mode/ state and implement a solution which was satisfactory with the demands.

### Software design

#### Arduino

I've decided to implement a statemachine. I had some problems with the statemachine  not working on my previous exam. So I wanted to figure why it was crashing. I used a Vector to hold one state, and  then push another state through creating a new object. I used the way I would have done it on a full c++ program and where i'd also use smart pointers, which free automatically when no longer in scope. To mitigate this issue I decided to create the objects for all the states upon startup. This fixed the crashing.

#### MQTT -why?

When getting the led matrix, I started playing with making small games for it. During the introduction to mqtt in the course, one of the selling points of mqtt as an technology was the small packages and low latency.  This made me think about a proof of concept where you were able to play a realtime game from an app via mqtt. So as I had already done some api-solutions during the mandatory deliveries in the subject. I wanted to test mqtt. One issue I had was that I was trying to use a server which didnt have Websocket support, because the react native app is basically using a web browser, this was an issue.

#### React

As I'm not the most experienced with react, I feel like the design was a bit messy and unplanned. I tried to split the code into different components, which worked well, but some of the components might be uneccecary and only adding to the complexity of the design.

## Expanision

### Room for improvement

I am using different versions of the functions for drawing images, due to the way I am converting the images in the react app. I feel like getting the mqtt string in the same way as in the screensaver header, the program would be less prone to crashing. And I'd be able to use the drawBitMap function to draw the image.

Maybe move the image parsing to webservices to have one less copy in memory.

Using base64  for transfer of the image, I'm not sure if it would make it too hard for the microprocessor to process the images, or if it is better than what I am doing now. Raw pointers are scary though.  And can be prone to crashes. 

#### JSON

There is a really good library which I didnt think about in the start when I setup the image functions. Which is Arduino-json if I were to use JSON with mqtt i'd have a more standard way to pass the messages through the mqtt server. One negative thing with using json is that I'd have to create objects upon recieving data, which could impact both ram usage and runtime performance. I might have to use a json object for the timed features, as I have not finished this part of the task yet.

### Fancy Features:

* The Brightness is controlled by the ambient light in the room.
* WiFiManager for easy wifi config. Also for MQTT-config.
* Standby image is split into two different layers,  so that we can use less memory to save the animation. As if we were to use a single image, we would have had to make a sprite which was alot bigger.
* Snake game through MQTT.

### Things I had to adapt in the embedded solution

* MQTT-server had to have a bigger buffer for the microcontroller to not crash.
* The platformio.ini file has to have deep+ as lib dep search so all the necessary libraries are included at compile-time.

### Standby

* One possible expansion of the app and the program for the microcontroller, is being able to change the different times where the "modes" change. I ended up only chosing the times for the user. Which is not optimal. But it could be implemented through another
