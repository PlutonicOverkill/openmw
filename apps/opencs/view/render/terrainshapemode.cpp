#include "terrainshapemode.hpp"

#include "mask.hpp"
#include "worldspacewidget.hpp"
#include "tagbase.hpp"
#include "cell.hpp"

#include <osg/ref_ptr>
#include <osg/Vec3d>

CSVRender::TerrainShapeMode::TerrainShapeMode(WorldspaceWidget* worldspaceWidget, QWidget* parent)
    :EditMode(worldspaceWidget, QIcon(":placeholder"), Mask_Terrain, "Terrain shape editing",
        parent)
{
}

void CSVRender::TerrainShapeMode::primarySelectPressed(const WorldspaceHitResult& hit)
{
    deselectAll(hit);

    if (hit.hit)
    {
        getWorldspaceWidget().getCell(hit.worldPos)->getTerrainSelection()->select(hit.worldPos);
    }
}

void CSVRender::TerrainShapeMode::secondarySelectPressed(const WorldspaceHitResult& hit)
{
    if (hit.hit)
    {
        deselectLastSelectedCell();

        getWorldspaceWidget().getCell(hit.worldPos)->getTerrainSelection()->toggleSelect(hit.worldPos);
    }
    else
    {
        getWorldspaceWidget().getCell(hit.worldPos)->getTerrainSelection()->deselectAll();
    }
}

void CSVRender::TerrainShapeMode::deselectAll(const WorldspaceHitResult& hit)
{
    getWorldspaceWidget().getCell(hit.worldPos)->getTerrainSelection()->deselectAll();

    deselectLastSelectedCell();
}

void CSVRender::TerrainShapeMode::deselectLastSelectedCell()
{
    if (mLastSelectedCell)
    {
        mLastSelectedCell->getTerrainSelection()->deselectAll();
    }
}
