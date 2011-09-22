#ifndef imod_TModelDispatcherWrap_included
#define imod_TModelDispatcherWrap_included


// ACF includes
#include "imod/TModelDispatcher.h"


namespace imod
{


template <class Base>
class TModelDispatcherWrap: public Base
{
public:
	typedef Base BaseClass;
	typedef TModelDispatcherWrap<Base> DispatcherImpl;

	TModelDispatcherWrap();

	// TModelDispatcher shadows
	bool RegisterModel(imod::IModel* modelPtr, int modelId = 0, int relevantFlags = 0);
	void UnregisterModel(int modelId = 0);
	void UnregisterAllModels();
	template <class Object>
	Object* GetObjectPtr(int modelId) const;

	// abstract methods
	virtual void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr) = 0;

private:
	imod::TModelDispatcher<DispatcherImpl> m_modelDispatcher;
};


template <class Base>
TModelDispatcherWrap<Base>::TModelDispatcherWrap()
	:m_modelDispatcher(*this)
{
}


template <class Base>
bool TModelDispatcherWrap<Base>::RegisterModel(imod::IModel* modelPtr, int modelId, int relevantFlags)
{
	return m_modelDispatcher.RegisterModel(modelPtr, modelId, relevantFlags);
}


template <class Base>
void TModelDispatcherWrap<Base>::UnregisterModel(int modelId)
{
	m_modelDispatcher.UnregisterModel(modelId);
}


template <class Base>
void TModelDispatcherWrap<Base>::UnregisterAllModels()
{
	m_modelDispatcher.UnregisterAllModels();
}


template <class Base>
template <class Object>
Object* TModelDispatcherWrap<Base>::GetObjectPtr(int modelId) const
{
	return m_modelDispatcher.GetObjectPtr(modelId);
}


} // namespace imod


#endif // !imod_TModelDispatcherWrap_included


