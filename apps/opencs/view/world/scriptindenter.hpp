#ifndef CSV_WORLD_SCRIPTINDENTER_H
#define CSV_WORLD_SCRIPTINDENTER_H

#include <QTextCursor>

namespace CSVWorld
{
    class ScriptIndenter
    {
        public:

            void indent(QTextCursor begin, QTextCursor end);

        private:

            static bool isBeginIndent(const QString&);

            static bool isEndIndent(const QString&);

            static bool compare(const QString&, const char*);
    };
}

#endif
