#ifndef CSV_RENDER_TERRAINSELECTION_H
#define CSV_RENDER_TERRAINSELECTION_H

#include <osg/Vec3d>

#include <utility>
#include <vector>

namespace CSVRender
{
    class Cell;

    class TerrainSelection
    {
            typedef std::pair<int, int> TexturePos;

            typedef std::vector<TexturePos> Container;
            typedef Container::iterator Iterator;

            Container mSelection;
            Cell* mCell;

            // not implemented
            TerrainSelection(const TerrainSelection&);
            TerrainSelection& operator=(const TerrainSelection&);

        public:

            TerrainSelection(Cell*);

            ~TerrainSelection();

            bool isSelected() const;
            // const Container getSelected() const;
            void selectAll();
            void toggleSelected(); // Adds to end of vector
            void invertSelected();
            void clearSelected();
    };
}

#endif
