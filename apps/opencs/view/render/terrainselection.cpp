#include "terrainselection.hpp"

#include "cell.hpp"

#include <components/esm/loadland.hpp>

CSVRender::TerrainSelection::TerrainSelection(Cell* cell)
    :mCell(cell), mSelectionState(TerrainSelectionType_None)
{
}

CSVRender::TerrainSelection::~TerrainSelection()
{
    // deselectAll();
}

void CSVRender::TerrainSelection::setSelectionMode(TerrainSelectionType type)
{
    /*
    mCurrentSelection->hide(); // is this needed if delete is used?

    switch(type){
        case Terrain:
            mCurrentSelection = &mTerrainSelection;
            break;
        case Texture:
            mCurrentSelection = &mTextureSelection;
            break;
    }

    ...

    if(mCurrentSelection != mLastSelected)
    {
        delete mCurrentSelection;
        mCurrentSelection = mLastSelection->clone();
    }

    mCurrentSelection->show();

    */
}

void CSVRender::TerrainSelection::select(osg::Vec3d worldPos)
{

}

void CSVRender::TerrainSelection::toggleSelect(osg::Vec3d worldPos)
{

}

void CSVRender::TerrainSelection::deselectAll()
{

}

CSVRender::TerrainSelection::TerrainPos CSVRender::TerrainSelection::toTextureCoords(osg::Vec3d worldPos)
{
    int cellX = mCell->getCoordinates().getX() * ESM::Land::REAL_SIZE;
    int cellY = mCell->getCoordinates().getY() * ESM::Land::REAL_SIZE;

    int textureX = static_cast<int>((worldPos.x() - cellX) * ESM::Land::LAND_TEXTURE_SIZE / ESM::Land::REAL_SIZE);
    int textureY = static_cast<int>((worldPos.y() - cellY) * ESM::Land::LAND_TEXTURE_SIZE / ESM::Land::REAL_SIZE);

    return std::make_pair(textureX, textureY);
}
