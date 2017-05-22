#include "terraintexturemode.hpp"

#include "mask.hpp"
#include "worldspacewidget.hpp"
#include "tagbase.hpp"
#include "cell.hpp"

#include <osg/ref_ptr>

CSVRender::TerrainTextureMode::TerrainTextureMode(WorldspaceWidget* worldspaceWidget, QWidget* parent)
    :EditMode(worldspaceWidget, QIcon(":placeholder"), Mask_Terrain, "Terrain texture editing",
        parent), mLastSelectedCell(0)
{
}

void CSVRender::TerrainTextureMode::primarySelectPressed(const WorldspaceHitResult& hit)
{
    deselectAll(hit);

    if (hit.hit)
    {
        // select the activated item
        // mSelection.setSelected(toTextureCoords(hit.worldPos));
    }
}

void CSVRender::TerrainTextureMode::secondarySelectPressed(const WorldspaceHitResult& hit)
{
    if (hit.hit)
    {
        deselectLastSelectedCell();
        // toggle selection of activated item

        // mSelection.toggleSelected(toTextureCoords(hit.worldPos));
    }
    else
    {
        deselectAll(hit);
    }
}

void CSVRender::TerrainTextureMode::deselectAll(const WorldspaceHitResult& hit)
{
    getWorldspaceWidget().getCell(hit.worldPos)->getTerrainSelection(TerrainSelectionType_Texture)->deselectAll();

    deselectLastSelectedCell();
}

void CSVRender::TerrainTextureMode::deselectLastSelectedCell()
{
    if (mLastSelectedCell)
    {
        mLastSelectedCell->getTerrainSelection(TerrainSelectionType_Texture)->deselectAll();
    }
}
