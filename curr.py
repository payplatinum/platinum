#!/usr/bin/env python 
# CursesExample1
#------------------------------- 
# Curses Programming Sample 1 
#------------------------------- 
import curses 
myscreen = curses.initscr() 
myscreen.border(0) 
myscreen.addstr(12, 25, "See Curses, See Curses Run!") 
myscreen.refresh() 
myscreen.getch() 
curses.endwin()

#!/usr/bin/env python 
# CursesExample2
import curses 
#========================================================== 
#                       MAIN LOOP 
#========================================================== 
try: 
    myscreen = curses.initscr() 
    myscreen.clear() 
    myscreen.addstr(0,0,"0        1         2         3         4         5         6         7") 
    myscreen.addstr(1,0,"12345678901234567890123456789012345678901234567890123456789012345678901234567890") 
    myscreen.addstr(10,0,"10") 
    myscreen.addstr(20,0,"20") 
    myscreen.addstr(23,0, "23 - Press Any Key to Continue") 
    myscreen.refresh() 
    myscreen.getch() 
finally: 
    curses.endwin()

#!/usr/bin/env python 
#------------------------------- 
# Curses Programming Template 
#------------------------------- 
import curses 

def InitScreen(Border): 
    if Border == 1: 
        myscreen.border(0) 

#========================================================== 
#                       MAIN LOOP 
#========================================================== 
myscreen = curses.initscr() 
InitScreen(1) 
try: 
    myscreen.refresh() 
    # Your Code Stuff Here... 
    myscreen.addstr(1,1, "Press Any Key to Continue") 
    myscreen.getch() 
finally: 
    curses.endwin()

===================================================
               RECIPE DATABASE
===================================================
 1 - Show All Recipes
 2 - Search for a recipe
 3 - Show a Recipe
 4 - Delete a recipe
 5 - Add a recipe
 6 - Print a recipe
 0 - Exit
===================================================
Enter a selection ->

curses.initscreen
LogicLoop
    ShowMainMenu                     # Show the main menu
    MainInKey                        # This is our main input handling routine
        While Key != 0:
            If Key == 1:
                ShowAllRecipesMenu   # Show the All Recipes Menu
                Inkey1               # Do the input routines for this
                ShowMainMenu         # Show the main menu
            If Key == 2:
                SearchForARecipeMenu # Show the Search for a Recipe Menu
                InKey2               # Do the input routines for this option
                ShowMainMenu         # Show the main menu again
            If Key == 3:
                ShowARecipeMenu      # Show the Show a recipe menu routine
                InKey3               # Do the input routine for this routine
                ShowMainMenu         # Show the main menu again
		…	               # And so on and so on
curses.endwin()                      # Restore the terminal

def DoMainMenu():
    myscreen.erase()
    myscreen.addstr(1,1,  "========================================")
    myscreen.addstr(2,1,  "           Recipe Database")
    myscreen.addstr(3,1,  "========================================")
    myscreen.addstr(4,1,  "  1 - Show All Recipes")
    myscreen.addstr(5,1,  "  2 - Search for a recipe")
    myscreen.addstr(6,1,  "  3 - Show a recipe")
    myscreen.addstr(7,1,  "  4 - Delete a recipe")
    myscreen.addstr(8,1,  "  5 - Add a recipe")
    myscreen.addstr(9,1,  "  6 - Print a recipe")
    myscreen.addstr(10,1, "  0 - Exit")
    myscreen.addstr(11,1, "========================================")
    myscreen.addstr(12,1, "  Enter a selection: ")
    myscreen.refresh()
    
#    MAIN LOOP
try:
    myscreen = curses.initscr()
    LogicLoop()
finally:
    curses.endwin()
    
def LogicLoop():
    DoMainMenu()
    MainInKey()
    
def MainInKey():
    key = 'X'
    while key != ord('0'):
        key = myscreen.getch(12,22)
        myscreen.addch(12,22,key)
        if key == ord('1'):
            ShowAllRecipesMenu()
            DoMainMenu()
        elif key == ord('2'):
            SearchForARecipeMenu()
            InKey2()
            DoMainMenu()
        elif key == ord('3'):
            ShowARecipeMenu()
            DoMainMenu()
        elif key == ord('4'):
            NotReady("'Delete A Recipe'")
            DoMainMenu()
        elif key == ord('5'):
            NotReady("'Add A Recipe'")
            DoMainMenu()
        elif key == ord('6'):
            NotReady("'Print A Recipe'")
            DoMainMenu()
        myscreen.refresh()
        
def SearchForARecipeMenu():
    myscreen.addstr(4,1, "-------------------------------")
    myscreen.addstr(5,1, " Search in")
    myscreen.addstr(6,1, "-------------------------------")
    myscreen.addstr(7,1, " 1 - Recipe Name")
    myscreen.addstr(8,1, " 2 - Recipe Source")
    myscreen.addstr(9,1, " 3 - Ingredients")
    myscreen.addstr(10,1," 0 - Exit")
    myscreen.addstr(11,1,"Enter Search Type -> ")
    myscreen.refresh()

def InKey2():
    key = 'X'
    doloop = 1
    while doloop == 1:
        key = myscreen.getch(11,22)
        myscreen.addch(11,22,key)
        tmpstr = "Enter text to search in "
        if key == ord('1'):
            sstr = "'Recipe Name' for -> "
            tmpstr = tmpstr + sstr
            retstring = GetSearchLine(13,1,tmpstr)
            break
        elif key == ord('2'):
            sstr = "'Recipe Source' for -> "
            tmpstr = tmpstr + sstr
            retstring = GetSearchLine(13,1,tmpstr)
            break
        elif key == ord('3'):
            sstr = "'Ingredients' for -> "
            tmpstr = tmpstr + sstr
            retstring = GetSearchLine(13,1,tmpstr)
            break
        else:
            retstring = ""
            break
    if retstring != "":
        myscreen.addstr(15,1,"You entered - " + retstring)
    else:
        myscreen.addstr(15,1,"You entered a blank string")
    myscreen.refresh()
    myscreen.addstr(20,1,"Press a key")
    myscreen.getch()

def GetSearchLine(row,col,strng):
    myscreen.addstr(row,col,strng)
    myscreen.refresh()
    instring = myscreen.getstr(row,len(strng)+1)
    myscreen.addstr(row,len(strng)+1,instring)
    myscreen.refresh()
    return instring
