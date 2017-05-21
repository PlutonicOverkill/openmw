#include "terraintexturemode.hpp"

#include "mask.hpp"
#include "worldspacewidget.hpp"
#include "tagbase.hpp"
#include "cell.hpp"

#include <osg/ref_ptr>

CSVRender::TerrainTextureMode::TerrainTextureMode(WorldspaceWidget* worldspaceWidget, QWidget* parent)
    :EditMode(worldspaceWidget, QIcon(":placeholder"), Mask_Terrain, "Terrain texture editing",
        parent), mSelection()
{
}

void CSVRender::TerrainTextureMode::primarySelectPressed(const WorldspaceHitResult& hit)
{
    if (hit.hit)
    {
        //mSelection.setSelected(toTextureCoords(hit.worldPos));
    }
    else
    {
        //mSelection.deselectAll();
    }
}

void CSVRender::TerrainTextureMode::secondarySelectPressed(const WorldspaceHitResult& hit)
{
    if (hit.hit)
    {
        //mSelection.toggleSelected(toTextureCoords(hit.worldPos));
    }
}

/* TODO: move this to CSVRender::Cell
CSVRender::TerrainTextureMode::TexturePos CSVRender::TerrainTextureMode::toTextureCoords(osg::Vec3d worldPos)
{
Cell* cell = getWorldspaceWidget().getCell(worldPos);
assert(cell);

int cellX = cell->getCoordinates().getX() * ESM::Land::REAL_SIZE;
int cellY = cell->getCoordinates().getY() * ESM::Land::REAL_SIZE;

int textureX = static_cast<int>((worldPos.x() - cellX) * ESM::Land::LAND_TEXTURE_SIZE / ESM::Land::REAL_SIZE);
int textureY = static_cast<int>((worldPos.y() - cellY) * ESM::Land::LAND_TEXTURE_SIZE / ESM::Land::REAL_SIZE);

return std::make_pair(textureX, textureY);
}
*/
