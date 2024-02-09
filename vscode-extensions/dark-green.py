# set as new theme
import tkinter as tk

def change_theme():
    # Change the background color and text color to create a dark green theme
    root.config(bg="#003300")
    label.config(bg="#003300", fg="#00FF00")
    button.config(bg="#006600", fg="#FFFFFF")

root = tk.Tk()
root.title("Dark Green Theme Example")

# Create a label with some text
label = tk.Label(root, text="dark-green set as theme")
label.pack(padx=20, pady=20)

# Create a button to change the theme
button = tk.Button(root, text="Change Theme", command=change_theme)
button.pack(pady=10)

# Set initial theme
change_theme()

root.mainloop()
