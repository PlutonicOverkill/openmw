#include "terraintexturemode.hpp"

#include "mask.hpp"
#include "worldspacewidget.hpp"
#include "pagedworldspacewidget.hpp"
#include "tagbase.hpp"
#include "cell.hpp"

#include <osg/ref_ptr>
#include <osg/Vec3d>

CSVRender::TerrainTextureMode::TerrainTextureMode(WorldspaceWidget* worldspaceWidget, QWidget* parent)
    :EditMode(worldspaceWidget, QIcon(":placeholder"), Mask_Terrain, "Terrain texture editing",
        parent)
{
}

void CSVRender::TerrainTextureMode::activate(CSVWidget::SceneToolbar* toolbar)
{
    dynamic_cast<PagedWorldspaceWidget&>(getWorldspaceWidget()).setTerrainSelectionMode(TerrainSelectionType_Texture);

    EditMode::activate(toolbar);
}

void CSVRender::TerrainTextureMode::deactivate(CSVWidget::SceneToolbar* toolbar)
{
    dynamic_cast<PagedWorldspaceWidget&>(getWorldspaceWidget()).setTerrainSelectionMode(TerrainSelectionType_None);

    EditMode::deactivate(toolbar);
}

void CSVRender::TerrainTextureMode::primarySelectPressed(const WorldspaceHitResult& hit)
{
    if (hit.hit)
    {
        dynamic_cast<PagedWorldspaceWidget&>(getWorldspaceWidget()).selectTerrain(hit.worldPos);
    }
}

void CSVRender::TerrainTextureMode::secondarySelectPressed(const WorldspaceHitResult& hit)
{
    if (hit.hit)
    {
        dynamic_cast<PagedWorldspaceWidget&>(getWorldspaceWidget()).toggleSelectTerrain(hit.worldPos);
    }
}
