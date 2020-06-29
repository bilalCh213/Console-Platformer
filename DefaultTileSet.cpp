
/*
FUNCTIONS FOR FRAMERUNNER:
emptyTileSet();
defaultTileSet();

FUNCTIONS FOR INTERNAL USE:
* None *
*/

using namespace std;

void emptyTileSet()
{
			for (int yEmp = 0; yEmp < height -1; yEmp++)
		{
			for (int xEmp = 0; xEmp < width - 1; xEmp++)
			{
				px[xEmp][yEmp] = notSolid[0];
				
			}
		} 
}

void defaultTileSet()
{
		for (int plat1 = 0; plat1 < width; plat1++)
		{
		px[plat1][height - 2] = _floor;
		}
		
		for (int plat1a = 0; plat1a < width; plat1a++)
		{
			px[plat1a][height - 3] = _floor;
		}
		
		for (int plat2 = 0; plat2 < width; plat2++)
		{
			px[plat2][0] = roof;
		}
		
		for (int plat3 = 0; plat3 < height; plat3++)
		{
			px[width - 2][plat3] = wall;
		}
		
		for (int plat3a = 0; plat3a < height; plat3a++)
		{
			px[width - 3][plat3a] = wall;
		}
		
		for (int plat4 = 0; plat4 < height; plat4++)
		{
			px[0][plat4] = wall;
		}
		
		for (int plat4a = 0; plat4a < height; plat4a++)
		{
			px[1][plat4a] = wall;
		}
}