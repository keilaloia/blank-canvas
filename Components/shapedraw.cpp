#include "shapedraw.h"
#include "sfwdraw.h"


void drawCircle(const Circle & C,unsigned color)
{
	
	sfw::drawCircle(C.pos.x, C.pos.y, C.radius, 12U, color);

}

void drawAABB(const AABB &E, unsigned color)
{
	

	sfw::drawLine(E.min().x, E.min().y, E.max().x, E.min().y, color);
	sfw::drawLine(E.min().x, E.min().y, E.min().x, E.max().y, color);
	sfw::drawLine(E.min().x, E.max().y, E.max().x, E.max().y, color);
	sfw::drawLine(E.max().x, E.min().y, E.max().x, E.max().y, color);


}

void drawPlane(const Plane & p, unsigned color)
{
	vec2 left = perp(p.dir);
	vec2 right = -perp(p.dir);

	sfw::drawLine(p.pos.x, p.pos.y, (p.pos.x + left.x * 50), p.pos.y + left.y * 50, RED);
	sfw::drawLine(p.pos.x, p.pos.y, (p.pos.x + right.x * 50), p.pos.y + right.y * 50, RED);

	sfw::drawLine(p.pos.x, p.pos.y,(p.pos.x + p.dir.x * 50) ,(p.pos.y + p.dir.y * 50), color);
	sfw::drawLine(p.pos.x, p.pos.y, (p.pos.x - p.dir.x * 50), (p.pos.y - p.dir.y * 50), color);


}

void drawHull(const Hull & H, unsigned color)
{
	for (int i = 0; i < H.size && i < 16; ++i)
	{
		sfw::drawLine(H.vertices[i].x, H.vertices[i].y,
					  H.vertices[(i + 1) % H.size].x,
				      H.vertices[(i + 1) % H.size].y, color);
	}
}
