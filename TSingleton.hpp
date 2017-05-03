#ifndef SINGLETON
#define SINGLETON


template <class T>
class TSingleton
{
protected:
	// Membervariablen
	static T *m_pSingleton;   
public:
	virtual ~TSingleton()
	{}
	
	//gibt zeiger auf vorhandene Instanz der abgeleiteten Klasse, wenn nötig erzeugt diese
	inline static T* Get()
	{
		if (!m_pSingleton)
			m_pSingleton = new T;   
		return (m_pSingleton);
	}

	static void Del()
	{
		// vorhanden?
		if (m_pSingleton)
		{//ja->löschen
			delete (m_pSingleton);  
			m_pSingleton = NULL;    
		}

	}

};


template <class T>
T* TSingleton<T>::m_pSingleton = 0;

#endif