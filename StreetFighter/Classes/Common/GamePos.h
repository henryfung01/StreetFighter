//whitebai 2014.8.10
//基于gid的pos，其实就是两个byte
#ifndef __GAME_POS_H__
#define __GAME_POS_H__
struct EntityPos
{
	unsigned char x;
	unsigned char y;
	EntityPos():
	x(0),
	y(0)
	{
	}
	EntityPos(unsigned char ux,unsigned char uy)
	{
		x = ux;
		y = uy;
	};
	EntityPos& operator= (const EntityPos& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	bool operator!=(const EntityPos& right)
	{
		return x!=right.x || y!=right.y;
	}
	bool operator == (const EntityPos& right)
	{
		return x == right.x && y == right.y;
	}
	EntityPos operator+ (const EntityPos& right)
	{
		return EntityPos(x+right.x,y+right.y);
	}
	EntityPos operator- (const EntityPos& right)
	{
		return EntityPos(x - right.x,y - right.y);
	}
};
#endif // __GAME_POS_H__
