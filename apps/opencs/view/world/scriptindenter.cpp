#include "scriptindenter.hpp"

#include <algorithm>
#include <array>
#include <functional>
#include <vector>

#include <iostream>

void CSVWorld::ScriptIndenter::indent(QTextCursor begin, QTextCursor end)
{
    begin.beginEditBlock();

    // keeps track of indentation size (in tabstops)
    // TODO: select between tabs and spaces
    int currentIndent {0};

    // go through the document line by line
    for (; begin < end; begin.movePosition(QTextCursor::EndOfLine),
                        begin.movePosition(QTextCursor::Right))
    {
        // get current line without leading/trailing whitespace
        begin.select(QTextCursor::LineUnderCursor);
        QString currentLine {begin.selectedText().trimmed()};

        std::cout << "\nindent()\n" << std::endl;
        std::cout << "currentLine: " << currentLine.toStdString() << std::endl;

        // skip empty lines
        if (currentLine.isEmpty())
        {
            std::cout << "Current line empty, skipping" << std::endl;
            continue;
        }

        // move indent backwards
        if (isEndIndent(currentLine) && currentIndent > 0)
        {
            --currentIndent;
            std::cout << "Moving indent back to " << currentIndent << std::endl;
        }

        std::cout << "Inserting tabs" << std::endl;

        // insert correct amount of tabs
        // for (int i {0}; i != currentIndent; ++i)
        //     currentLine.push_front('\t');
        currentLine = currentLine.rightJustified(currentLine.size() +  currentIndent, '\t');

        // move indent forwards
        if (isBeginIndent(currentLine.trimmed()))
        {
            ++currentIndent;
            std::cout << "Moving indent forwards to " << currentIndent << std::endl;
        }

        std::cout << "Indented line: " << currentLine.toStdString() << std::endl;

        // put the line back
        begin.insertText(currentLine);
    }

    begin.endEditBlock();
}

bool CSVWorld::ScriptIndenter::isBeginIndent(const QString& string)
{
    static const std::array<const char*, 3> beginIndent {"if", "while", "elseif"};
    auto pred = std::bind(compare, string, std::placeholders::_1);

    return std::find_if(beginIndent.begin(), beginIndent.end(), pred)
        != beginIndent.end();
}

bool CSVWorld::ScriptIndenter::isEndIndent(const QString& string)
{
static const std::array<const char*, 3> endIndent {"endif", "endwhile", "elseif"};
    auto pred = std::bind(compare, string, std::placeholders::_1);
    return std::find_if(endIndent.begin(), endIndent.end(), pred)
        != endIndent.end();
}

bool CSVWorld::ScriptIndenter::compare(const QString& string, const char* keyword)
{
    // get first word in line
    int index;
    for (index = 0; index != string.size(); ++index) {
        if (!string[index].isLetter())
            break;
    }

    return string.left(index).compare(keyword, Qt::CaseInsensitive) == 0;
}
