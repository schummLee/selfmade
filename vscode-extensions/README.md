# Viscose Theme Example

This is a simple example of creating a viscose-themed GUI application using Tkinter in Python.

## Code Description

The provided Python script creates a GUI window with a label and a button. The button allows the user to change the theme of the GUI to a viscose color scheme.

### Code Snippet

```python
import tkinter as tk

def change_theme():
    # Change the background color and text color to create a viscose theme
    root.config(bg="#F5F5DC")
    label.config(bg="#F5F5DC", fg="#4B0082")
    button.config(bg="#FFD700", fg="#4B0082")

root = tk.Tk()
root.title("Viscose Theme Example")

# Create a label with some text
label = tk.Label(root, text="test 1-1)
label.pack(padx=20, pady=20)

# Create a button to change the theme
button = tk.Button(root, text="Change Theme", command=change_theme)
button.pack(pady=10)

# Set initial theme
change_theme()

root.mainloop()

