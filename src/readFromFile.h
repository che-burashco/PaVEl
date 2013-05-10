#ifndef READFROMFILE_H
#define READFROMFILE_H

#include <fstream>
#include <memory>
#include <vector>
#include <QString>

class ifstreamWrapper : public std::ifstream
{
    std::ifstream stream;

public:

    ifstreamWrapper(const QString & filename);

    inline const std::ifstream * operator->()
    {
        return &stream;
    }

    ~ifstreamWrapper();

    template<typename T>
    ifstreamWrapper & operator>>(T & somethingToRead)
    {
        stream>>somethingToRead;
        return *this;
    }
};


std::auto_ptr< std::vector<unsigned int> > readIntVectorFromFile(const QString & filename);




#endif // READFROMFILE_H
