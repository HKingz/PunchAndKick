﻿#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <LCUI_Build.h>
#include LC_LCUI_H
#include LC_GRAPH_H
#include "game_object.h"
#include "game_resource.h"

static void test_write(void)
{
	int i,class_id;
	LCUI_Graph graph[5];
	
	GameGraphRes_Init();
	srand( time(NULL) );
	for(i=0; i<5; ++i) {
		Graph_Init( &graph[i] );
		Graph_Create( &graph[i], 320, 240 );
		Graph_FillColor( &graph[i], RGB(rand()%255,rand()%255,rand()%255));
	}
	class_id = GameGraphRes_AddClass("main-resource");
	GameGraphRes_AddGraph( class_id, "test-01", &graph[0] );
	GameGraphRes_AddGraph( class_id, "test-02", &graph[1] );
	GameGraphRes_AddGraph( class_id, "test-03", &graph[2] );
	GameGraphRes_AddGraph( class_id, "test-04", &graph[3] );
	GameGraphRes_AddGraph( class_id, "test-05", &graph[4] );
	GameGraphRes_WriteToFile( "test.data", "main-resource" );
	GameGraphRes_FreeAll();
}

static void test_read(void)
{
	int i;
	LCUI_Graph graph[5];
	char filename[256];

	GameGraphRes_Init();
	GameGraphRes_LoadFromFile( "test.data" );
	GameGraphRes_GetGraph( "main-resource", "test-01", &graph[0] );
	GameGraphRes_GetGraph( "main-resource", "test-02", &graph[1] );
	GameGraphRes_GetGraph( "main-resource", "test-03", &graph[2] );
	GameGraphRes_GetGraph( "main-resource", "test-04", &graph[3] );
	GameGraphRes_GetGraph( "main-resource", "test-05", &graph[4] );
	for(i=0; i<5; ++i) {
		sprintf( filename, "test-%02d.png", i );
		Graph_WritePNG( filename, &graph[i] );
	}
}

#define KUNI_ACTION_FILE_NUM	64
#define RIKI_ACTION_FILE_NUM	73
#define MIKE_ACTION_FILE_NUM	66
#define TORAJI_ACTION_FILE_NUM	73
#define MAIN_FILE_NUM		2
#define FONT_FILE_NUM		11

struct fileinfo {
	char *filepath;
	char *name;
};

const struct fileinfo font_file_info[FONT_FILE_NUM]={
	{"font-0.png","0"},
	{"font-1.png","1"},
	{"font-2.png","2"},
	{"font-3.png","3"},
	{"font-4.png","4"},
	{"font-5.png","5"},
	{"font-6.png","6"},
	{"font-7.png","7"},
	{"font-8.png","8"},
	{"font-9.png","9"},
	{"font-x.png","x"}
};

const struct fileinfo main_file_info[2]={
	{"LC-GAMES-175x128.png","main-logo"},
	{"shadow.png", "shadow"}
};

const struct fileinfo scenes_file_info={
	"default-scene.png","default"
};

const struct fileinfo kuni_action_file_info[RIKI_ACTION_FILE_NUM]={
	{"start-01.png", "start-01"},
	{"start-02.png", "start-02"},
	{"ready.png","ready"},
	{"stance.png","stance"},
	{"A-attack-01.png","A-attack-01"},
	{"A-attack-02.png","A-attack-02"},
	{"A-sprint-attack.png","A-sprint-attack"},
	{"A-sprint-jump-attack.png","A-sprint-jump-attack"},
	{"B-attack-01.png","B-attack-01"},
	{"B-attack-02.png","B-attack-02"},
	{"B-sprint-attack.png","B-sprint-attack"},
	{"back-be-catch.png","back-be-catch"},
	{"kick.png","kick"},
	{"catch.png","catch"},
	{"defense.png","defense"},
	{"defense++.png","defense++"},
	{"fall.png","fall"},
	{"final-blow-01.png","final-blow-01"},
	{"final-blow-02.png","final-blow-02"},
	{"final-blow-03.png","final-blow-03"},
	{"final-blow-04.png","final-blow-04"},
	{"hit.png","hit"},
	{"hit-fly.png","hit-fly"},
	{"hit-fly-fall.png","hit-fly-fall"},
	{"jump-elbow.png","jump-elbow"},
	{"squat.png","squat"},
	{"jump.png","jump"},
	{"lift-fall.png","lift-fall"},
	{"lift-jump.png","lift-jump"},
	{"lift-run.png","lift-run"},
	{"lift-walk-01.png","lift-walk-01"},
	{"lift-walk-02.png","lift-walk-02"},
	{"lift.png","lift"},
	{"tummy.png","tummy"},
	{"tummy-hit.png","tummy-hit"},
	{"lying.png","lying"},
	{"lying-hit.png","lying-hit"},
	{"half-lying.png","half-lying"},
	{"pull.png","pull"},
	{"push.png","push"},
	{"rest-01.png","rest-01"},
	{"rest-02.png","rest-02"},
	{"roll-01.png","roll-01"},
	{"roll-02.png","roll-02"},
	{"roll-03.png","roll-03"},
	{"roll-04.png","roll-04"},
	{"roll-05.png","roll-05"},
	{"roll-06.png","roll-06"},
	{"roll-07.png","roll-07"},
	{"roll-08.png","roll-08"},
	{"run-01.png","run-01"},
	{"run-02.png","run-02"},
	{"run-03.png","run-03"},
	{"run-04.png","run-04"},
	{"run-05.png","run-05"},
	{"run-06.png","run-06"},
	{"walk-01.png","walk-01"},
	{"walk-03.png","walk-03"},
	{"weak-walk.png","weak-walk"},
	{"ride.png","ride"},
	{"ride-attack-01.png","ride-attack-01"},
	{"ride-attack-02.png","ride-attack-02"},
	{"be-push.png", "be-push"},
	{"sit.png", "sit"}
};

const struct fileinfo riki_action_file_info[RIKI_ACTION_FILE_NUM]={
	{"start-01.png", "start-01"},
	{"start-02.png", "start-02"},
	{"A-attack-01.png","A-attack-01"},
	{"A-attack-02.png","A-attack-02"},
	{"A-sprint-attack-01.png","A-sprint-attack-01"},
	{"A-sprint-attack-02.png","A-sprint-attack-02"},
	{"B-attack-01.png","B-attack-01"},
	{"B-attack-02.png","B-attack-02"},
	{"B-sprint-attack-01.png","B-sprint-attack-01"},
	{"B-sprint-attack-02.png","B-sprint-attack-02"},
	{"back-be-catch.png","back-be-catch"},
	{"catch.png","catch"},
	{"defense.png","defense"},
	{"elbow-01.png","elbow-01"},
	{"elbow-02.png","elbow-02"},
	{"elbow-03.png","elbow-03"},
	{"elbow-04.png","elbow-04"},
	{"fall.png","fall"},
	{"final-blow-01.png","final-blow-01"},
	{"final-blow-02.png","final-blow-02"},
	{"final-blow-03.png","final-blow-03"},
	{"hit-fly.png","hit-fly"},
	{"hit.png","hit"},
	{"jump-elbow.png","jump-elbow"},
	{"jump-stomp.png","jump-stomp"},
	{"jump.png","jump"},
	{"lift-fall.png","lift-fall"},
	{"lift-jump.png","lift-jump"},
	{"lift-run-01.png","lift-run-01"},
	{"lift-run-02.png","lift-run-02"},
	{"lift-walk-01.png","lift-walk-01"},
	{"lift-walk-02.png","lift-walk-02"},
	{"lift-walk-03.png","lift-walk-03"},
	{"lift-walk-04.png","lift-walk-04"},
	{"lift.png","lift"},
	{"lying-hit.png","lying-hit"},
	{"lying.png","lying"},
	{"half-lying.png","half-lying"},
	{"pull.png","pull"},
	{"push.png","push"},
	{"ready-01.png","ready-01"},
	{"rest-01.png","rest-01"},
	{"rest-02.png","rest-02"},
	{"roll-01.png","roll-01"},
	{"roll-02.png","roll-02"},
	{"roll-03.png","roll-03"},
	{"roll-04.png","roll-04"},
	{"roll-05.png","roll-05"},
	{"roll-06.png","roll-06"},
	{"roll-07.png","roll-07"},
	{"roll-08.png","roll-08"},
	{"run-01.png","run-01"},
	{"run-02.png","run-02"},
	{"run-03.png","run-03"},
	{"run-04.png","run-04"},
	{"run-05.png","run-05"},
	{"run-06.png","run-06"},
	{"squat.png","squat"},
	{"stance-01.png","stance-01"},
	{"tummy-hit.png","tummy-hit"},
	{"tummy.png","tummy"},
	{"walk-01.png","walk-01"},
	{"walk-02.png","walk-02"},
	{"walk-03.png","walk-03"},
	{"walk-04.png","walk-04"},
	{"weak-walk-01.png","weak-walk-01"},
	{"weak-walk-02.png","weak-walk-02"},
	{"ride.png","ride"},
	{"ride-attack-01.png","ride-attack-01"},
	{"ride-attack-02.png","ride-attack-02"},
	{"be-push.png", "be-push"},
	{"sit.png", "sit"},
	{"defense++.png","defense++"}
};

const struct fileinfo mike_action_file_info[MIKE_ACTION_FILE_NUM]={
	{"start-01.png", "start-01"},
	{"start-02.png", "start-02"},
	{"ready.png","ready"},
	{"stance.png","stance"},
	{"A-attack-01.png","A-attack-01"},
	{"A-attack-02.png","A-attack-02"},
	{"A-sprint-attack-01.png","A-sprint-attack-01"},
	{"A-sprint-attack-02.png","A-sprint-attack-02"},
	{"B-attack-01.png","B-attack-01"},
	{"B-attack-02.png","B-attack-02"},
	{"B-sprint-attack-01.png","B-sprint-attack-01"},
	{"B-sprint-attack-02.png","B-sprint-attack-02"},
	{"back-be-catch.png","back-be-catch"},
	{"kick.png","kick"},
	{"catch.png","catch"},
	{"defense.png","defense"},
	{"defense++.png","defense++"},
	{"fall.png","fall"},
	{"final-blow-01.png","final-blow-01"},
	{"final-blow-02.png","final-blow-02"},
	{"final-blow-03.png","final-blow-03"},
	{"final-blow-04.png","final-blow-04"},
	{"final-blow-05.png","final-blow-05"},
	{"hit.png","hit"},
	{"hit-fly.png","hit-fly"},
	{"hit-fly-fall.png","hit-fly-fall"},
	{"jump-elbow.png","jump-elbow"},
	{"squat.png","squat"},
	{"jump.png","jump"},
	{"lift-fall.png","lift-fall"},
	{"lift-jump.png","lift-jump"},
	{"lift-run.png","lift-run"},
	{"lift-walk-01.png","lift-walk-01"},
	{"lift-walk-02.png","lift-walk-02"},
	{"lift.png","lift"},
	{"tummy.png","tummy"},
	{"tummy-hit.png","tummy-hit"},
	{"lying.png","lying"},
	{"lying-hit.png","lying-hit"},
	{"half-lying.png","half-lying"},
	{"pull.png","pull"},
	{"push.png","push"},
	{"rest-01.png","rest-01"},
	{"rest-02.png","rest-02"},
	{"roll-01.png","roll-01"},
	{"roll-02.png","roll-02"},
	{"roll-03.png","roll-03"},
	{"roll-04.png","roll-04"},
	{"roll-05.png","roll-05"},
	{"roll-06.png","roll-06"},
	{"roll-07.png","roll-07"},
	{"roll-08.png","roll-08"},
	{"run-01.png","run-01"},
	{"run-02.png","run-02"},
	{"run-03.png","run-03"},
	{"run-04.png","run-04"},
	{"run-05.png","run-05"},
	{"run-06.png","run-06"},
	{"walk-01.png","walk-01"},
	{"walk-02.png","walk-02"},
	{"weak-walk.png","weak-walk"},
	{"ride.png","ride"},
	{"ride-attack-01.png","ride-attack-01"},
	{"ride-attack-02.png","ride-attack-02"},
	{"be-push.png", "be-push"},
	{"sit.png", "sit"}
};

const struct fileinfo toraji_action_file_info[TORAJI_ACTION_FILE_NUM]={
	{"start-01.png", "start-01"},
	{"start-02.png", "start-02"},
	{"ready.png","ready"},
	{"stance.png","stance"},
	{"half-lying.png","half-lying"},
	{"walk-01.png","walk-01"},
	{"walk-02.png","walk-02"},
	{"walk-03.png","walk-03"},
	{"walk-04.png","walk-04"},
	{"run-01.png","run-01"},
	{"run-02.png","run-02"},
	{"run-03.png","run-03"},
	{"run-04.png","run-04"},
	{"run-05.png","run-05"},
	{"run-06.png","run-06"},
	{"A-attack-01.png","A-attack-01"},
	{"A-attack-02.png","A-attack-02"},
	{"B-attack-01.png","B-attack-01"},
	{"B-attack-02.png","B-attack-02"},
	{"A-sprint-attack-01.png","A-sprint-attack-01"},
	{"A-sprint-attack-02.png","A-sprint-attack-02"},
	{"A-sprint-attack-03.png","A-sprint-attack-03"},
	{"A-sprint-attack-04.png","A-sprint-attack-04"},
	{"A-sprint-attack-05.png","A-sprint-attack-05"},
	{"A-sprint-attack-06.png","A-sprint-attack-06"},
	{"jump.png","jump"},
	{"squat.png","squat"},
	{"defense.png","defense"},
	{"hit-fly-fall.png","hit-fly-fall"},
	{"final-blow-01.png","final-blow-01"},
	{"final-blow-02.png","final-blow-02"},
	{"hit-fly.png","hit-fly"},
	{"hit.png","hit"},
	{"lying-hit.png","lying-hit"},
	{"lying.png","lying"},
	{"tummy.png","tummy"},
	{"tummy-hit.png","tummy-hit"},
	{"stomp.png","stomp"},
	{"kick.png","kick"},
	{"roll-01.png","roll-01"},
	{"roll-02.png","roll-02"},
	{"roll-03.png","roll-03"},
	{"roll-04.png","roll-04"},
	{"roll-05.png","roll-05"},
	{"roll-06.png","roll-06"},
	{"roll-07.png","roll-07"},
	{"roll-08.png","roll-08"},
	{"spin-up-01.png","spin-up-01"},
	{"spin-up-02.png","spin-up-02"},
	{"spin-up-03.png","spin-up-03"},
	{"catch.png","catch"},
	{"B-sprint-attack.png","B-sprint-attack"},
	{"rest-01.png","rest-01"},
	{"rest-02.png","rest-02"},
	{"push.png","push"},
	{"pull.png","pull"},
	{"back-be-catch.png","back-be-catch"},
	{"weak-walk.png","weak-walk"},
	{"fall.png","fall"},
	{"defense++.png","defense++"},
	{"ride.png","ride"},
	{"ride-attack-01.png","ride-attack-01"},
	{"ride-attack-02.png","ride-attack-02"},
	{"lift-fall.png","lift-fall"},
	{"lift.png","lift"},
	{"lift-jump.png","lift-jump"},
	{"lift-run-01.png","lift-run-01"},
	{"lift-walk-01.png","lift-walk-01"},
	{"lift-walk-02.png","lift-walk-02"},
	{"lift-walk-03.png","lift-walk-03"},
	{"sit.png","sit"},
	{"jump-elbow.png","jump-elbow"},
	{"be-push.png","be-push"}
};

static void ActionRes_WirteToFile(	const char *class_name,
					const struct fileinfo *filelist,
					int n_file,
					const char *outputfile )
{
	int i, class_id;
	LCUI_Graph graph_buff;

	GameGraphRes_Init();
	class_id = GameGraphRes_AddClass(class_name);
	for(i=0; i<n_file; ++i) {
		Graph_Init( &graph_buff );
		Graph_LoadImage( filelist[i].filepath, &graph_buff );
		GameGraphRes_AddGraph( class_id, filelist[i].name, &graph_buff );
	}
	GameGraphRes_WriteToFile( outputfile, class_name );
	GameGraphRes_FreeAll();
}


static void ActionRes_Toraji_ReadFromFile(void)
{
	int i;
	LCUI_Graph graph_buff;

	GameGraphRes_Init();
	GameGraphRes_LoadFromFile( "action-toraji.data" );
	for(i=0; i<TORAJI_ACTION_FILE_NUM; ++i) {
		Graph_Init( &graph_buff );
		GameGraphRes_GetGraph( 
			ACTION_RES_CLASS_TORAJI, 
			toraji_action_file_info[i].name,
			&graph_buff 
		);
		Graph_WritePNG( toraji_action_file_info[i].filepath, &graph_buff );
		_DEBUG_MSG("[%d/%d]: %s\n", i, TORAJI_ACTION_FILE_NUM, toraji_action_file_info[i].filepath);
	}
	GameGraphRes_FreeAll();
}

static void ActionRes_Riki_WirteToFile( void )
{
	int i, class_id;
	LCUI_Graph graph_buff;

	GameGraphRes_Init();
	class_id = GameGraphRes_AddClass(ACTION_RES_CLASS_RIKI);
	for(i=0; i<RIKI_ACTION_FILE_NUM; ++i) {
		Graph_Init( &graph_buff );
		Graph_LoadImage( riki_action_file_info[i].filepath, &graph_buff );
		GameGraphRes_AddGraph( class_id, riki_action_file_info[i].name, &graph_buff );
	}
	GameGraphRes_WriteToFile( "action-riki.data", ACTION_RES_CLASS_RIKI );
	GameGraphRes_FreeAll();
}

/** 将战斗场景的图形资源写入至文件 */
static void ScenesGraphRes_WirteToFile( void )
{
	int class_id;
	LCUI_Graph graph_buff;

	GameGraphRes_Init();
	class_id = GameGraphRes_AddClass( SCENES_RES );
	Graph_Init( &graph_buff );
	Graph_LoadImage( scenes_file_info.filepath, &graph_buff );
	GameGraphRes_AddGraph( class_id, scenes_file_info.name, &graph_buff );
	GameGraphRes_WriteToFile( "scenes.data", SCENES_RES );
	GameGraphRes_FreeAll();
}

/** 将字体的图形资源写入至文件 */
static void FontGraphRes_WirteToFile( void )
{
	int class_id, i;
	LCUI_Graph graph_buff;

	GameGraphRes_Init();
	class_id = GameGraphRes_AddClass( FONT_RES );
	for( i=0; i<FONT_FILE_NUM; ++i ) {
		Graph_Init( &graph_buff );
		Graph_LoadImage( font_file_info[i].filepath, &graph_buff );
		GameGraphRes_AddGraph( class_id, font_file_info[i].name, &graph_buff );
	}
	GameGraphRes_WriteToFile( "font.data", FONT_RES );
	GameGraphRes_FreeAll();
}

static void ActionRes_Riki_ReadFromFile(void)
{
	int i;
	LCUI_Graph graph_buff;

	GameGraphRes_Init();
	GameGraphRes_LoadFromFile( "action-riki.data" );
	for(i=0; i<RIKI_ACTION_FILE_NUM; ++i) {
		Graph_Init( &graph_buff );
		GameGraphRes_GetGraph( 
			ACTION_RES_CLASS_RIKI, 
			riki_action_file_info[i].name,
			&graph_buff 
		);
		Graph_WritePNG( riki_action_file_info[i].filepath, &graph_buff );
		_DEBUG_MSG("[%d/%d]: %s\n", i, RIKI_ACTION_FILE_NUM, riki_action_file_info[i].filepath);
	}
	GameGraphRes_FreeAll();
}

int main(int argc, char** argv)
{
#ifdef TEST
	if( argc == 2 ) {
		test_read();
	} else {
		test_write();
	}
#endif
	if( argc == 2 ) {
		//ActionRes_Kuni_ReadFromFile();
		//ActionRes_Riki_ReadFromFile();
		//ActionRes_Toraji_ReadFromFile();
		return 0;
	}
	//FontGraphRes_WirteToFile();
	//ScenesGraphRes_WirteToFile();
	//MainGraphRes_WirteToFile();
#define need_mike
#ifdef need_kuni
	ActionRes_WirteToFile(	ACTION_RES_CLASS_KUNI,
				kuni_action_file_info,
				KUNI_ACTION_FILE_NUM, 
				"action-kuni.data" );
#elif defined(need_riki)
	ActionRes_WirteToFile(	ACTION_RES_CLASS_RIKI,
				riki_action_file_info,
				RIKI_ACTION_FILE_NUM, 
				"action-riki.data" );
#elif defined(need_toraji)
	ActionRes_WirteToFile(	ACTION_RES_CLASS_TORAJI,
				toraji_action_file_info,
				TORAJI_ACTION_FILE_NUM, 
				"action-toraji.data" );
#elif defined(need_mike)
	ActionRes_WirteToFile(	ACTION_RES_CLASS_MIKE,
				mike_action_file_info,
				MIKE_ACTION_FILE_NUM, 
				"action-mike.data" );
#endif
	return 0;
}
