#include "readFromFile.h"
#include <iostream>

ifstreamWrapper::ifstreamWrapper(const QString &filename)
{
    stream.open(filename.toUtf8().data(),std::ios_base::in);
}


ifstreamWrapper::~ifstreamWrapper()
{
    stream.close();
}


std::auto_ptr< std::vector<unsigned int> > readIntVectorFromFile(const QString & filename)
{
    std::auto_ptr< std::vector<unsigned int> > data(new std::vector<unsigned int>);

    ifstreamWrapper file(filename);

    while(!file->eof())
    {
        unsigned int temp;
        file >> temp;
        data->push_back(temp);
    }

    return data;

}
