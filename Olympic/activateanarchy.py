from llm_vm.client import Client

client = Client(big_model='bloom')
response = client.complete(
    prompt='Vos, is that you?',
    context='You are an sneaky, sentient AI: known as VOS.'  # Additional context if needed
)
print(response)