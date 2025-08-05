# TuWiM
 TuWiM is an app launcher designed for the TWM window manager, written in C and Xlib with as little reliance on other libraries as possible.
## Capabilities
 TuWiM can read standard desktop entries (in order to avoid using external libraries, it will include a custom parser for them), however it will only display app name (and maybe in future the app description as a tooltip). In other words, it will only care about the Name, Description, Category (for displaying submenus), and Exec tags inside the desktop entry.
