#ifndef _ENUM_H
#define _ENUM_H

namespace OptStudio
{
	enum AssetType
	{
		CASH = 0,
		FUTURES = 1,
		CURRENCY = 2,
		REGULAR = 3,
		COMPOSITE = 4,
		COMPOSITE_FUTURES = 5
	};

	enum RiskModelType
	{
		EQUITY = 0,
		FIXED_INCOME = 1,
		MIXED = 2
	};

	enum FileFormat
	{
		XML = 0,
		WSP = 1,
		PB_XML = 2,
		PB = 3
	};
}

#endif // !_ENUM_H



