#include "Map.hpp"



void CMap::Generate()
{

	///STEP 1///////////////////////
	///Map mit leerem Gras füllen///
	////////////////////////////////
	for (int i = 0; i < MapsizeX; i++)
	{
		for (int j = 0; j < MapsizeY; j++)
		{

			TileMap[i][j].Set(g_pFramework->getRand(Grass1, Grass3), 0, 0);
		}
	}


	///STEP 2///////////////////////
	///Map mit leerem Gras füllen///
	////////////////////////////////
	for (int i = 0; i < MapsizeX; i++)
	{
		for (int j = 0; j < MapsizeY; j++)
		{
			int a = g_pFramework->getRand(FoodFull, TreeEmpty + 20);
			int max = g_pFramework->getRand(500, 2000);

			switch (a){
			case FoodFull:
				UpperMap[i][j].Set(a, max, g_pFramework->getRand(8 * (max / 10), (max)));
				break;

			case FoodHalf:
				UpperMap[i][j].Set(a, max, g_pFramework->getRand(2 * (max / 10), 8 * (max / 10)));
				break;
			case FoodLow:
				UpperMap[i][j].Set(a, max, g_pFramework->getRand(8 * (max / 10), 2 * (max / 10)));
				break;
			case TreeFull:
				UpperMap[i][j].Set(a, max, g_pFramework->getRand(8 * (max / 10), (max)));
				break;

			case TreeHalf:
				UpperMap[i][j].Set(a, max, g_pFramework->getRand(2 * (max / 10), 8 * (max / 10)));
				break;
			case TreeEmpty:
				UpperMap[i][j].Set(a, max, g_pFramework->getRand(8 * (max / 10), 2 * (max / 10)));
				break;

			default:
				UpperMap[i][j].Set(Empty, 0, 0);


			}//switch

			UpperMap[0][j].Set(Border, -1, -1);
			UpperMap[i][0].Set(Border, -1, -1);
			UpperMap[MapsizeX - 1][j].Set(Border, -1, -1);
			UpperMap[i][MapsizeY - 1].Set(Border, -1, -1);



		}//For
	}//For

	///STEP 3///////////////////////
	///Map mit Flüssen füllen///////
	////////////////////////////////
	int Rivers = g_pFramework->getRand(1, 7);
	int addition = 0;

	for (int i = 0; i < Rivers; i++)
	{





		if (g_pFramework->getRand(1, 2) == 1)
		{//Nord-Süd
			//start X
			int x = g_pFramework->getRand(10, MapsizeX - 1);

			for (int j = 1; j < MapsizeY; j++)
			{
				UpperMap[x][j].Set(Water, -1, -1);
				TileMap[x][j].Set(Grass1, -1, -1);


				//where next tile to?
				if (j % 2==0)
				addition = g_pFramework->getRand(1, 3) - 2;
				else addition = 0;

				///STEP 3.1/////////////////////
				///Fluss glätten////////////////
				////////////////////////////////
				if (addition == 1)
				{
					UpperMap[x+1][j].Set(WaterRightT, -1, -1);
					TileMap[x+1][j].Set(Grass1, -1, -1);

					UpperMap[x][j+1].Set(WaterRightD, -1, -1);
					TileMap[x][j+1].Set(Grass1, -1, -1);

				}
				else if (addition == -1)
				{
					UpperMap[x - 1][j].Set(WaterLeftT, -1, -1);
					TileMap[x - 1][j].Set(Grass1, -1, -1);

					UpperMap[x][j + 1].Set(WaterLeftD, -1, -1);
					TileMap[x][j + 1].Set(Grass1, -1, -1);

				}

				x += addition;
			}//For y Felder

		}else
		{//West-Ost

			int y = g_pFramework->getRand(10, MapsizeY - 1);

			for (int j = 1; j < MapsizeX; j++)
			{
				TileMap[j][y].Set(Water, -1, -1);
				UpperMap[j][y].Set(Empty, -1, -1);

				if (j % 2 == 0)
					addition = g_pFramework->getRand(1, 3) - 2;
				else addition = 0;


				///STEP 3.1/////////////////////
				///Fluss glätten////////////////
				////////////////////////////////
				if (addition == 1)
				{
					UpperMap[j+1][y].Set(WaterRightT, -1, -1);
					TileMap[j+1][y].Set(Grass1, -1, -1);

					UpperMap[j][y+1].Set(WaterRightD, -1, -1);
					TileMap[j][y+1].Set(Grass1, -1, -1);
					
				}
				else if (addition == -1)
				{
					UpperMap[j][y-1].Set(WaterLeftT, -1, -1);
					TileMap[j][y-1].Set(Grass1, -1, -1);

					UpperMap[j+1][y].Set(WaterLeftD, -1, -1);
					TileMap[j+1][y].Set(Grass1, -1, -1);

				}




				y += addition;

			}

			

		}//else Ost-West
	}//For Flüsscount
}
//Generate