import datetime

def chatbot():
    print("Hi! I'm your friendly chatbot. Type 'time' to know the current time, 'date' for today's date, or 'exit' to quit.")
    while True:
        user_input = input("You: ").strip().lower()
        now = datetime.datetime.now()

        if user_input == "time":
            print(f"Chatbot: The current time is {now.strftime('%H:%M:%S')}")
        elif user_input == "date":
            print(f"Chatbot: Today's date is {now.strftime('%Y-%m-%d')}")
        elif user_input in ["hi", "hello", "hey"]:
            print("Chatbot: Hello! How can I assist you?")
        elif user_input == "exit":
            print("Chatbot: Goodbye! Have a great day!")
            break
        else:
            print("Chatbot: I didn't understand that. Try 'time', 'date', or 'exit'.")

# Start the chatbot
chatbot()
