/*
    Superjuego Engine
    Copyright (C) 2011 Jorge Luís Cabral y Gabriel Ernesto Cabral

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact: baigosoft@hotmail.com
*/



#include "audio.h"

int soundEnabled=0;
int musicEnabled=0;
int musicPlaying=0;

void SE_audio_init(int rate, int bits, int stereo)
{
	

	snd_stream_init();
	sndoggvorbis_init();
	soundEnabled = 1;
	musicEnabled = 1;

}

void SE_audio_close()
{
	sndoggvorbis_shutdown();
	snd_stream_shutdown();
}

void SE_audio_enablesound()
{
	soundEnabled=1;
}

void SE_audio_disablesound()
{
	soundEnabled=0;
}

void SE_audio_enablemusic()
{
	musicEnabled=1;
}

void SE_audio_disablemusic()
{
	musicEnabled=0;

}

SE_sound *SE_audio_loadsound(char *filename)
{

}

void SE_audio_playsound(SE_sound *soundid)
{
	if(soundEnabled){

	}
}

void SE_audio_setsoundvolume(int volume)
{



}

SE_music *SE_audio_loadmusic(char *filename)
{
	SE_music *music;
	printf("Cargando audio: %s\n",filename);
	music=(SE_music *)malloc(sizeof(char)*500);
	memset(music,0,500);
	//strcpy(music,&filename);

	sprintf(music,"%s",filename);
	printf("audio: %s\n",music);


	return music;
	
}

void SE_audio_playmusic(SE_music *musicid)
{
	printf("playing: %s\n",musicid);	
	if(musicEnabled){
		
		sndoggvorbis_start(musicid,0);
	}

	musicPlaying=1;

}

int SE_audio_isplayingmusic()
{
	return musicPlaying;
}

void SE_audio_stopmusic()
{
	

	sndoggvorbis_stop();
	musicPlaying=0;

}

void SE_audio_setmusicvolume(int volume)
{


}


