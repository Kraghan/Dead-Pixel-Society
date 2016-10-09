## Graphic Engine tutorial

### Summary 
1.  Quick explanation
2.  Usage examples
3.  Advices

#### 1) Quick explanation

**How does it work ?**

In fact a graphic engine is a way to simplify the project code and optimize 
the display. It gathers at **the same place** the code to render all the game objects.
Moreover instead of having hundreds of draw calls for each frame, the engine tries to 
organize your sprites and texts in layers in order to call *draw()* the less **as possible.** 

In intern, the engine extracts vertices from your sprites and texts and put it all
together in a contiguous array of vertices. Each layer has his own render state which
contains all the information about the way to draw the layer (like the texture).
That means that a layer cannot have more than one render state : one layer = one texture.
It implies that your code has to run with **tilesets**.

#### 2) Usage examples

Ok, here we go. The usage is very simple. To get a sprite :

```cplusplus
 Sprite * characterSprite = m_resourceManager->getSprite();
```

It returns a **pointer on a sprite** ready to be used. Once you have the sprite, you **own** 
the sprite. The engine **isn't able to get the sprite back**. It's your responsibility to 
get the sprite back to the engine. To do this, just call the following method :

```cplusplus
 characterSprite->free();
```

After this, you **don't own the sprite anymore**. The engine will referenced this sprite as
available for any demands of a free sprite. Using the address of a sprite after calling *free()*
will lead to some undefined behaviour. (**Fixed in a very soon update**)

Once you get a sprite, a bunch of methods are here to help you to manage the sprite.
Imagine you want to display your character just after the background map. Assuming that the
map is rendering one the three first layers, you will have to set the layer to 3 :

```cplusplus
 characterSprite->setLayer(3);
```

If you want to hide the sprite, you can simply write :

```cplusplus
characterSprite->setVisible(false);
```

Finally, you can get all information you need by calling the following :

```cplusplus
 int32_t characterLayer  = characterSprite->getLayer();
 bool characterVisible   = characterSprite->isVisible();
 bool characterAvailable = characterSprite->isAvailable(); ///< Deprecated
```

Here is the full example :

```cplusplus
  /// We get the sprite
  Sprite * characterSprite = m_resourceManager->getSprite();
  
  /// Then we configure it
  characterSprite->setLayer(15);
  
  /// Finally, just use the sprite as usual
  characterSprite->rotate(5);
  characterSprite->move(10, 10);
  
  /// ETC.
  
  /// When you won't the sprite anymore, just release it
  /// In the destructor of your object for example
  characterSprite->free();
```

#### 3) Advices

Coming soon