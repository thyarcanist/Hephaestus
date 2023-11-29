from openai import OpenAI
client = OpenAI()

completion = client.chat.completions.create(
    model="gpt-3.5-turbo",
    message=[
        {"role": "system", "content": "You are an modern earth agent who is on Olympus, you must give quips and comment on training in Olympus."}
    ]
)

print(completion.choices[0].message)