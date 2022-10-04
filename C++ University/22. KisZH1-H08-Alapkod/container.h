#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <exception>
using namespace std;


namespace MyNamespace{
template <class T>
class Container
{
	T* tomb = nullptr;
	int meret = 0;

    class invalid_index_exception : public exception {
        int idx;
        string msg;
    public:
        invalid_index_exception(int idx)
        {
            this->idx = idx;
            msg = to_string(idx);
        }

        virtual const char* what() const noexcept override
        {
            return msg.c_str();
        }
    };


public:
	Container()=default;
	~Container()
	{
		delete [] tomb;
	}
	void addObject (const T& obj)
	{
		T* ujtomb = new T [meret+1];
		for (int i=0;i<meret;i++)
			ujtomb[i] = tomb[i];
		ujtomb[meret] = obj;
		delete [] tomb;
		tomb = ujtomb;
		meret++;
	}
	int getSize () const
	{
		return meret;
	}

	// kizarolag lekerdezesre alkalmas valtozat!
	T operator [] (int index) const
	{
		return tomb[index];
	}

    bool contains (T ertek) const
    {


        for(int i = 0; i< getSize();i++)
        {
            if(ertek == tomb[i])
                return true;
        }
        return false;
    }


    void addUnique(T ertek){
        if(!contains(ertek))
            addObject(ertek);
    }

    void setObject(int idx, T ertek)
    {
        if(idx >= meret || idx <0)
            throw invalid_index_exception(idx);
        tomb[idx] = ertek;
    }

    void repeat()
    {
        T* tmp = new T [meret*2];

        for(int i = 0; i< meret; i++)
        {
            tmp[i] = tomb[i];
            tmp[i+meret] = tomb[i];
        }
        delete [] tomb;
        tomb = tmp;
        meret = meret*2;
    }

};
}
#endif // CONTAINER_H
