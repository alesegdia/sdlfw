#include "tilequeue.h"

TileQueue::TileQueue ()
{
	tail=0;
	head=-1;
}

TileQueue::~TileQueue ()
{
	 // dtor
}

void TileQueue::Initialize(Spritesheet* tileset, size_t capacity, const Vec2& range, const Vec2& offset, float speed)
{
	this->tileset=tileset;
	this->capacity = capacity;
	this->range.Set(range);
	printf("cargando offset->%f,%f\n",this->offset.x,this->offset.y);
	printf("cargando range->%f,%f\n",this->range.x,this->range.y);
	this->offset.Set(offset);
	printf("cargando offset->%f,%f\n",this->offset.x,this->offset.y);
	this->speed=speed;

	for(size_t i=0;i<capacity;i++) {
		int tile = PickupTile();
		printf("tile: %d, range: %d,%d\n",tile,static_cast<int>(range.x),static_cast<int>(range.y));
		Add(offset.x+i*tileset->GetTileSize().x,tile); //PickupTile());
	}

	head_=head;
	tail_=tail;
}

void TileQueue::Debug()
{
	for(int i=tail;i!=norm(head+1);i=norm(i+1))
		printf(", [x:%f,n:%d]",q[i].x,q[i].n);
}

void TileQueue::Step()
{
	if(q[tail].x<=offset.x-tileset->GetTileSize().x) {
		Add(offset.x + (capacity-1)*tileset->GetTileSize().x,PickupTile());
		tail=norm(tail+1);
	}

	for(size_t i=tail;i!=norm(head+1);i=norm(i+1)) {
		q[i].x -= speed;
	}
}

void TileQueue::Draw(SDL_Renderer* sdlrenderer)
{
	for(size_t i=tail;i!=norm(head+1);i=norm(i+1)) {
		int offsetx = q[i].x;
		int offsety = offset.y;
		tileset->Render(offsetx,offsety,this->q[i].n,sdlrenderer);
	}
}

void TileQueue::Add(float x, int n)
{
	head=norm(head+1);
	q[head].x=x;
	q[head].n=n;
}
