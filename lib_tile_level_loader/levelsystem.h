levelsystem.h
#pragma once

#include SFMLGraphics.hpp
#include memory
#include string
#include vector

#define ls LevelSystem

class LevelSystem {
public
 enum TILE { EMPTY, START, END, WALL, ENEMY, WAYPOINT };
        
 static void loadLevelFile(const stdstring&,float tileSize=100.f);
 static void render(sfRenderWindow &window);
 static sfColor getColor(TILE t);
 static void setColor(TILE t, sfColor c);
 //Get Tile at grid coordinate
 static TILE getTile(sfVector2ul);
 //Get Screenspace coordinate of tile
 static sfVector2f getTilePosition(sfVector2ul);
 //get the tile at screenspace pos
 static TILE getTileAt(sfVector2f);
 
protected
 static stdunique_ptrTILE[] _tiles; //Internal array of tiles
 static size_t _width; //how many tiles wide is level
 static size_t _height; //how many tile high is level
 static sfVector2f _offset; //Screenspace offset of level, when rendered.
 static float _tileSize; //Screenspace size of each tile, when rendered.
 static stdmapTILE, sfColor _colours; //color to render each tile type
 
 //array of sfml sprites of each tile
 static stdvectorstdunique_ptrsfRectangleShape _sprites;  
 //generate the _sprites array
 static void buildSprites();
    
private
 LevelSystem() = delete;
 ~LevelSystem() = delete;
};