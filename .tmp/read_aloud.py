from gtts import gTTS
import os

text = "Hello, this is stogram. Welcome to the application."
tts = gTTS(text)
tts.save("output.mp3")

# Play the generated audio file
os.system("mpg321 output.mp3")  # You can use a different player, like "aplay" or "mpg123"
