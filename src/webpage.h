 ///
 /// @file    webpage.h
 /// @author  mistydew(mistydew@qq.com)
 /// @date    2017-12-02 15:22:18
 ///

#ifndef __WEBPAGE_H__
#define __WEBPAGE_H__

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

namespace md
{

struct WordFreqCompare
{
    bool operator()(const std::pair<std::string, std::size_t> & lhs,
            const std::pair<std::string, std::size_t> & rhs)
    {
        if (lhs.second < rhs.second)
            return true;
        else if (lhs.second == rhs.second && lhs.first > rhs.first)
            return true;
        else
            return false;
    }
};

class WebPage
{
    friend std::ostream & operator<<(std::ostream & os, const WebPage & rhs);
public:
    WebPage(const std::string & doc = "");
    ~WebPage();

    std::string getDocTitle();
    std::string getDocUrl();
    std::string summary(const std::vector<std::string> & queryWords);
private:
    void processDoc(const std::string & doc);
    void statistic();
    std::string processWords(const std::string & word);
    void calcTopK();
private:
    const static std::size_t TOPK = 20;
    std::size_t _docId;
    std::string _docTitle;
    std::string _docUrl;
    std::string _docContent;
    std::string _docSummary;
    std::vector<std::string> _topWords;
    std::map<std::string, std::size_t> _wordsMap;
};

} // end of namespace md

#endif
