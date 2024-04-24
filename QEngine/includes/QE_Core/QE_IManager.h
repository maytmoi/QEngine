#pragma once

namespace QE
{
	template<class Derived>
	class IManager
	{
	public:

		static Derived& GetManager()
		{
			static Derived wInstance;
			return wInstance;
		}

	protected:

		IManager() = default;
	};
	
}
