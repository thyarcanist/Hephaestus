import random

events = ["You've stumbled upon the Winged Menaces Love Club.", "Apollo requests that you listen to his lyre.",
          'You\'ve received an event from Dionysus.', "Hermes has sent you on a task."]

chosen_event = random.choice(events)
print(chosen_event)

# Will likely use a local LM to generate a random thing that happened.
# Might event do one for dreaming.
