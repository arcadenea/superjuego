#include "movie.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>


typedef struct
{

	int videoStream;
	int frameFinished;
	AVFormatContext *pFormatCtx;
	AVCodecContext *pCodecCtx;
	AVCodec *pCodec;
	AVFrame *pFrame; 
	AVPacket packet;

	AVDictionary *optionsDict = NULL;
	struct SwsContext *sws_ctx = NULL;

}SE_movie_data;

int i;


int SE_movie_init()
{

	av_register_all();


}



SE_movie *SE_movie_load(const char *path_file)
{

	SE_movie *movie;

	movie = (SE_movie*)malloc(sizeof(SE_movie));

	avformat_open_input(movie->mdata->pFormatCtx,path_file,NULL,NULL);

	if(avformat_find_stream_info(movie->mdata->pFormatCtx, NULL)<0)
    {
		printf("SE_movie: no hay informacion de stream");
	}

	movie->mdata->videoStream=-1;
	for(i=0; i<pFormatCtx->nb_streams; i++)
	{
		if(movie->mdata->pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) 
		{
			movie->mdata->videoStream=i;
			break;
		}
	}
	if(movie->mdata->videoStream==-1)printf("no se encontró stream");

	movie->mdata->pCodecCtx=movie->mdata->pFormatCtx->streams[movie->mdata->videoStream]->codec;

	movie->mdata->pCodec=avcodec_find_decoder(movie->mdata->pCodecCtx->codec_id);
	if(movie->mdata->pCodec==NULL) 
	{
		printf("SE_movie: codec no soportado");
	}
  
	if(avcodec_open2(movie->mdata->pCodecCtx, movie->mdata->pCodec, movie->mdata->optionsDict)<0)
	{	
		printf("no se puede abrir codec");		
	}  

	movie->mdata->pFrame=av_frame_alloc();

	if(movie->mdata->pFrame==NULL)
	{
		printf("SE_movie: primer frame vacio o nulo");
	}

	return movie;

}

void SE_movie_play(SE_movie *movie)
{





}
