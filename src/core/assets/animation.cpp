#include "animation.h"

Animation::Animation (int nframes, Spritesheet* tset, int nplays)
{
	this->nframes = nframes;
	frames = new int[nframes];
	times = new int[nframes];
	for(int i=0;i<nframes;i++) {
		times[i]=DEFAULT_ANIM_TIME;
	}
	spritesheet = tset;
	this->nplays=nplays-1;
}

Animation::~Animation ()
{
	 delete [] frames;
	 delete [] times;
}

void Animation::SetFrame(int nframe, int ntile, int time)
{
	frames[nframe] = ntile;
	times[nframe] = time;
}

void Animation::Render(
	int x, int y, SDL_Renderer* renderer,
	int nframe, double angle,
	SDL_Point* center, SDL_RendererFlip flip)
{
	spritesheet->Render(x,y,frames[nframe],renderer,angle,center,flip);


	/*
	SDL_RenderCopyEx(
		renderer,
		spritesheet->GetFrameSrc(frames[nframe]),
		frames[nframe],
		&renderquad, angle, center, flip);

	SDL_Rect renderquad = { x, y,
		GetFrameSrc(frames[nframe])->w,
		GetFrameSrc(frames[nframe])->h };
	if(nframe!=-1) {
		renderquad.w = frames[nframe].w;
		renderquad.h = frames[nframe].h;
	}
		*/
}

void Animation::Update(Data& d)
{
	//printf(">%d\n",frames[0]);
	bool play=true;
	//printf("cf:%d\n",d.currentFrame);
	if(d.currentFrame==nframes-1 && d.timer-d.last<0){ //|| d.nplays<=0) {
		if(d.nplays < 0) {
			play=true;
		} else if(d.nplays==0) {
			play=false;
		} else if(d.nplays>0) {
			play=true;
			d.nplays--;
			d.currentFrame=0;
			d.timer=times[d.currentFrame];
			//printf("TIMER!:%d\n",d.timer);
			d.last=0;
			//printf("RESTA!");
		}
	} else {
		//printf("FTW!");
	}
	if(play) {
		if(d.timer-d.last<0) {
			// advance frame & set timer
			d.currentFrame = (d.currentFrame+1)%nframes;
			d.last = SDL_GetTicks();
			d.timer = d.last + times[d.currentFrame];
		} else {
			d.timer--;
			//printf("%d\n",d.timer);
		}
	}
	//printf("cf:%d\n",d.currentFrame);
	//printf("======================");
}
