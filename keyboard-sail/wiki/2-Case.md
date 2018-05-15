# Creating the keyboard case
We will be making sandwich cases from acrylic.
## CAD (Computer-Aided Design): _More freedom, more prone to human error._
1. [Download DraftSight](https://www.3ds.com/products-services/draftsight-cad-software/free-download/) and open it.
2. This program is text-command based. When you type, it should show up at the bottom.
3. Try the command `new` and choose the default format. That should create a new file.
4. Run `save` and save two files, one for your bottom plate and one for your top plate.
5. You are now ready to start. Get a calculater. Get your layout ready on [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/) so you know the key spacing. (1u = 19.05mm).
6. Here are some specifications and useful commands:

Part | Dimensions
--- | ---
Switch Cutout | 14.00x14.00mm
Switch Spacing | 19.05x19.05mm
Recommended Margin | 10.00mm
Screw Hole Size | 1.95mm (diameter)

Command | Description
--- | ---
`rect` | Creates a rectangle. Easiest to specify the first point and then use `D` dimensions. You may want to `F` fillet the perimeter to create rounded corners. 
`circle` | This is great for the screw holes and led holes, if you have indicator lights. Choose the center point and use `D` diameter.
`del` | Deletes the selected object(s).
`copy` | Copies the selected object(s).
`paste` | Pastes the object(s) from the clipboard. You can then type the cordinate you wish to place it at.
`undo` | Undo's your last move.
`save` | Save the file. Do this frequently.

Here is an example of numberpad's top plate. **The purple lines should not be there on the final draft, and are just shown to demonstrate the spacing.** Purple is key spacing, green is switch cutouts, blue is the outline, and yellow are the screw holes.   
![](https://i.imgur.com/aDVlqlW.png)
## KLE + Plate & Case Builder: _Less freedom, less prone to human error._   
* [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/)   
* [Plate & Case Builder](http://builder.swillkb.com/)