// What is this error
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "MFStdLib.h"
#include "memory.h"
#include "../Headers/AllToAnmConverter.h"


Gowno::Gowno()
{
}


#define	CMAT0_MASK	(0x3ff00000)
#define	CMAT1_MASK	(0x000ffc00)
#define	CMAT2_MASK	(0x000003ff)

void	uncompress_matrix2(CMatrix33* cm, Matrix33* m)
{
	SLONG v;

	v = ((cm->M[0] & CMAT0_MASK) << 2) >> 22;
	m->M[0][0] = (v << 6);

	v = ((cm->M[0] & CMAT1_MASK) << 12) >> 22;
	m->M[0][1] = (v << 6);

	v = ((cm->M[0] & CMAT2_MASK) << 22) >> 22;
	m->M[0][2] = (v << 6);

	v = ((cm->M[1] & CMAT0_MASK) << 2) >> 22;
	m->M[1][0] = (v << 6);

	v = ((cm->M[1] & CMAT1_MASK) << 12) >> 22;
	m->M[1][1] = (v << 6);

	v = ((cm->M[1] & CMAT2_MASK) << 22) >> 22;
	m->M[1][2] = (v << 6);

	v = ((cm->M[2] & CMAT0_MASK) << 2) >> 22;
	m->M[2][0] = (v << 6);

	v = ((cm->M[2] & CMAT1_MASK) << 12) >> 22;
	m->M[2][1] = (v << 6);

	v = ((cm->M[2] & CMAT2_MASK) << 22) >> 22;
	m->M[2][2] = (v << 6);
}


void Gowno::DoStuff(Anim* key_list, GameKeyFrameChunk* p_chunk, KeyFrameChunk* the_chunk)
{
	std::vector<Anim*> AnimList;
	std::map<int, int> framesCountPerAnimNo;
	signed short animCount = p_chunk->MaxAnimFrames; // -1 ?
	signed short framesCount = p_chunk->MaxKeyFrames; // -1 ?
	signed long elementsCount = p_chunk->MaxElements; // bodyPart * framesCount = 15 * 10 ? 

	extern	void	convert_keyframe_to_pointer(GameKeyFrame * p, GameKeyFrameElement * p_ele, GameFightCol * p_fight, SLONG count);
	extern	void	convert_animlist_to_pointer(GameKeyFrame * *p, GameKeyFrame * p_anim, SLONG count);
	extern	void	convert_fightcol_to_pointer(GameFightCol * p, GameFightCol * p_fight, SLONG count);
	
	convert_keyframe_to_pointer(p_chunk->AnimKeyFrames, p_chunk->TheElements, p_chunk->FightCols, p_chunk->MaxKeyFrames);
	convert_animlist_to_pointer(p_chunk->AnimList, p_chunk->AnimKeyFrames, p_chunk->MaxAnimFrames);
	convert_fightcol_to_pointer(p_chunk->FightCols, p_chunk->FightCols, p_chunk->MaxFightCols);

	// Iterate over all elements in .all
	for (int i = 0; i < p_chunk->MaxElements; ++i)
	{
		GameKeyFrameElement animList = p_chunk->TheElements[i];
		Matrix33 uncompressedMatrix;
		uncompress_matrix2(&animList.CMatrix, &uncompressedMatrix);
		//TRACE("YAY");

	}

	//for (int i = 0; i < animCount; ++i)
	//{
	//	Anim* a = new Anim();
	//	a->SetFrameCount(0);
	//	a->SetAnimFlags(0);
	//	a->SetAnimName("Dupa");
	//	a->SetNextAnim(nullptr);
	//	a->SetLastAnim(nullptr);
	//	AnimList.push_back(a);
	//}

	//for (int i = 1; i < animCount; ++i)
	//{
	//	Anim* aPointer = AnimList[i];

	//	//TRACE("Frames count in anim %d = %d\n", i, p_chunk->AnimList[i]);
	//	TRACE("First frame id in anim %d = %d\n", i, p_chunk->AnimList[i]);
	//	if (i != animCount - 1)
	//	{
	//		framesCountPerAnimNo[i] = (int)p_chunk->AnimList[i + 1] - (int)p_chunk->AnimList[i];
	//		TRACE("Frames count in anim %d = %d \n", i, framesCountPerAnimNo[i]);
	//	}
	//	else
	//	{

	//		framesCountPerAnimNo[i] = (int)framesCount - (int)p_chunk->AnimList[i];
	//		TRACE("Frames count in anim %d = %d \n", i, framesCountPerAnimNo[i]);
	//	}
	//}

	//int frameOffset = 1;
	//for (signed short i = 1; i < animCount; ++i)
	//{
	//	int framesInAnimNo = framesCountPerAnimNo[i];
	//	for (int j = frameOffset; j < framesInAnimNo+ frameOffset; ++j)
	//	{
	//		int prevFrameId = (int)p_chunk->AnimKeyFrames[j].PrevFrame;
	//		int nextFrameId = (int)p_chunk->AnimKeyFrames[j].NextFrame;
	//		TRACE("%d -> x -> %d \n", prevFrameId, nextFrameId);
	//	}
	//	frameOffset += framesInAnimNo;
	//}


	//for (int i = 0; i < elementsCount; ++i)
	//{
	//	TRACE("i = %d, %ld, %ld, %ld \n", i, p_chunk->TheElements[i].CMatrix.M[0], p_chunk->TheElements[i].CMatrix.M[1], p_chunk->TheElements[i].CMatrix.M[2]);
	//		//p_chunk->TheElements[0].CMatrix.M[0]
	//}
}

#define	CMAT0_MASK	(0x3ff00000)
#define	CMAT1_MASK	(0x000ffc00)
#define	CMAT2_MASK	(0x000003ff)

void	uncompress_matrix3(CMatrix33* cm, Matrix33* m)
{
	SLONG v;

	v = ((cm->M[0] & CMAT0_MASK) << 2) >> 22;
	m->M[0][0] = (v << 6);

	v = ((cm->M[0] & CMAT1_MASK) << 12) >> 22;
	m->M[0][1] = (v << 6);

	v = ((cm->M[0] & CMAT2_MASK) << 22) >> 22;
	m->M[0][2] = (v << 6);

	v = ((cm->M[1] & CMAT0_MASK) << 2) >> 22;
	m->M[1][0] = (v << 6);

	v = ((cm->M[1] & CMAT1_MASK) << 12) >> 22;
	m->M[1][1] = (v << 6);

	v = ((cm->M[1] & CMAT2_MASK) << 22) >> 22;
	m->M[1][2] = (v << 6);

	v = ((cm->M[2] & CMAT0_MASK) << 2) >> 22;
	m->M[2][0] = (v << 6);

	v = ((cm->M[2] & CMAT1_MASK) << 12) >> 22;
	m->M[2][1] = (v << 6);

	v = ((cm->M[2] & CMAT2_MASK) << 22) >> 22;
	m->M[2][2] = (v << 6);
}
void Gowno::KeyFrameListStuff(GameKeyFrameChunk* game_chunk, struct	KeyFrameChunk* the_chunk, Anim*& OutputAnimList)
{

	GameKeyFrameElement gameChunkElement2 = game_chunk[0].TheElements[0];
	struct KeyFrame* the_key_frame;
	Matrix33 uncompressedMatrix;
	uncompress_matrix3(&gameChunkElement2.CMatrix, &uncompressedMatrix);

	//KeyFrame* keyFrames = new KeyFrame[];

	KeyFrameElement* firstElement = new KeyFrameElement[game_chunk[0].MaxElements];

	std::map<GameKeyFrameElement*, int> gameKeyFrameElementToId;
	std::map<GameKeyFrameElement*, KeyFrameElement*> gameKeyElementToKeyFrameElement;

	for (int i = 0; i < game_chunk[0].MaxElements; ++i)
	{
		GameKeyFrameElement gameChunkElement = game_chunk[0].TheElements[i];
		//Matrix33 uncompressedMatrix;
		//uncompress_matrix3(&gameChunkElement.CMatrix, &uncompressedMatrix);

		//uncompressedMatrix.M[0][0] = 32767;
		//uncompressedMatrix.M[0][1] = 0;
		//uncompressedMatrix.M[0][2] = 0;
		//uncompressedMatrix.M[1][0] = 0;
		//uncompressedMatrix.M[1][1] = 32767;
		//uncompressedMatrix.M[1][0] = 0;
		//uncompressedMatrix.M[2][0] = 0;
		//uncompressedMatrix.M[2][0] = 0;
		//uncompressedMatrix.M[2][2] = 32767;

		//for (int dx = 0; dx < 3; dx++)
		//{
		//	for (int dy = 0; dy < 3; dy++)
		//	{
		//		SATURATE(uncompressedMatrix.M[dx][dy], -32767, 32767);
		//	}
		//}
		//TRACE("YAY");

		firstElement[i].CMatrix = gameChunkElement.CMatrix;
		firstElement[i].OffsetX = gameChunkElement.OffsetX;
		firstElement[i].OffsetY = gameChunkElement.OffsetY;
		firstElement[i].OffsetZ = gameChunkElement.OffsetZ;
		firstElement[i].Matrix = uncompressedMatrix;
		firstElement[i].Parent = 0;
		firstElement[i].Next = 0;
		// Is he alive?
		// I'm not sure
		gameKeyFrameElementToId[&game_chunk[0].TheElements[i]] = i;
		gameKeyElementToKeyFrameElement[&game_chunk[0].TheElements[i]] = &firstElement[i];
	}
	//for (int frame = 0; frame < game_chunk[0].MaxKeyFrames; ++frame)
	for (int frame = 0; frame < game_chunk[0].MaxElements / 15; ++frame)
	{

		the_key_frame = &the_chunk->KeyFrames[frame];
		the_key_frame->ChunkID = 0;
		the_key_frame->FrameID = frame;
		the_key_frame->TweenStep = 4;
		the_key_frame->ElementCount = the_chunk->ElementCount;
		the_key_frame->FirstElement = &firstElement[frame * 15];
	}

	the_chunk->KeyFrameCount = game_chunk[0].MaxElements / 15;
	the_chunk->FirstElement = firstElement;
	the_chunk->LastElement = firstElement + game_chunk[0].MaxElements - 1;
	Anim* animList = new Anim[game_chunk[0].MaxAnimFrames];

	int usedKeyFramesCount = 0;

	animList[0].SetAnimName("Anim 0");
	animList[0].SetNextAnim(&animList[1]);
	for (int i = 1; i < game_chunk[0].MaxAnimFrames; ++i)
	{
		std::vector< GameKeyFrame*> v_p;
		try
		{
			int frameCountPerAnim = 1;

			GameKeyFrame* po = game_chunk[0].AnimList[i];
			GameKeyFrameElement* gkfe = po->FirstElement;
			v_p.push_back(po);
			GameKeyFrame* next = po->NextFrame;
			GameKeyFrame* previous = po->PrevFrame;
			std::string animName = "Anim " + std::to_string(i);
			char* cstr = animName.data();
			animList[i].SetAnimName(cstr);

			KeyFrame* kf = new KeyFrame;
			KeyFrame* currentKf = kf;

			kf->ChunkID = 0;
			kf->Flags = 0;
			
			kf->FrameID = gameKeyFrameElementToId[gkfe];
			
			kf->TweenStep = 4;
			kf->ElementCount = 15;
			kf->Dx = 0;
			kf->Dy = 0;
			kf->Dz = 0;
			kf->Fixed = true;
			kf->Fight = nullptr;
			kf->FirstElement = gameKeyElementToKeyFrameElement[gkfe];
			kf->NextFrame = nullptr;
			kf->PrevFrame = nullptr;

			animList[i].SetFrameList(kf);
			animList[i].SetFrameListEnd(kf);

			if (i < game_chunk[0].MaxAnimFrames - 1)
			{
				animList[i].SetNextAnim(&animList[i + 1]);
			}
			else
			{
				animList[i].SetNextAnim(nullptr);
			}
			if (i == 1)
			{
				animList[i].SetLastAnim(nullptr);
			}
			else
			{
				animList[i].SetLastAnim(&animList[i - 1]);
			}


			++usedKeyFramesCount;

			//animList[i].SetNextAnim(next);


			while (next)
			{
				if (std::find(v_p.begin(), v_p.end(), next) != v_p.end())
				{
					TRACE("i = %d \n", i);
					long frameCount = v_p.size();
					for (auto&& a : v_p)
					{
						TRACE("%d-> \n", a);

					}
					animList[i].SetFrameCount(frameCountPerAnim);
					animList[i].SetAnimFlags(0);
					animList[i].SetTweakSpeed(32);

					break;
					/* v contains x */
				}
				else
				{

					v_p.push_back(next);
					next = next->NextFrame;




					if (next && next != po)
					{
						KeyFrame* next_kf = new KeyFrame;
						GameKeyFrameElement* next_gkfe = next->FirstElement;

						next_kf->ChunkID = 0;
						next_kf->Flags = 0;

						next_kf->FrameID = gameKeyFrameElementToId[next_gkfe]/15;

						next_kf->TweenStep = 4;
						next_kf->ElementCount = 15;
						next_kf->Dx = 0;
						next_kf->Dy = 0;
						next_kf->Dz = 0;
						next_kf->Fixed = true;
						next_kf->Fight = nullptr;
						next_kf->FirstElement = gameKeyElementToKeyFrameElement[next_gkfe];

						next_kf->PrevFrame = kf;
						next_kf->NextFrame = nullptr;
						//if (animList[i].GetFrameListStart() != next_kf)
						{
							animList[i].SetFrameListEnd(next_kf);
						}

						currentKf->NextFrame = next_kf;
						currentKf = next_kf;
					}

					++usedKeyFramesCount;
					++frameCountPerAnim;

					if (!next)
					{
						animList[i].SetFrameCount(frameCountPerAnim);
						animList[i].SetAnimFlags(0);
						animList[i].SetTweakSpeed(32);

						break;
					}
					/* v does not contain x */
				}
			}
		}
		catch (...)
		{
			TRACE("i=%d is fked\n", i);
		}
	}
	TRACE("usedKeyFramesCount=%d\n", usedKeyFramesCount);
	OutputAnimList = animList;

}
