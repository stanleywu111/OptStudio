#ifndef _WORKSPACE_H
#define _WORKSPACE_H

#include <iostream>
#include <string>

#include "Asset.h"
#include "AttributeSet.h"
#include "Case.h"
#include "enum.h"
#include "Portfolio.h"
#include "IDSet.h"
#include "RiskModel.h"
#include "Solver.h"
#include "Status.h"


namespace OptStudio
{
	typedef std::string String;

	


	class WorkSpace
	{
	public:
		static WorkSpace* CreateInstance();
		static WorkSpace* DeSerialize(const String& fileName);
		static String GetVersion();

		virtual Asset* CreateAsset(const String& assetID, AssetType type = REGULAR) = 0;
		virtual ArrtibuteSet* CreateArrtibuteSe() = 0;
		virtual Case* CreateCase(const String& caseID, Portfolio* initPort,
			const Portfolio* tradeUniv, double baseValue, double cashFlowWt = 0.0) = 0;
		virtual IDSet* CreateIDSet() = 0;
		virtual Portfolio* CreatePortfolio(const String& portfolioID) = 0;
		virtual RiskModel* CreateRiskModel(const String& riskModelID, RiskModelType type = EQUITY) = 0;
		virtual Solver* CreateSolver(Case& oCase, String id = "") = 0;
		virtual Asset* GetAsset(const String& assetID) const = 0;
		virtual int GetAssetCount() const = 0;
		virtual const IDSet& GetAssetIDSet() const = 0;
		virtual Case* GetCase(const String& caseID) const = 0;
		virtual Portfolio* GetPortfolio(const String& portfolioID) const = 0;
		virtual RiskModel* GetRiskModel(const String& modelID) const = 0;
		virtual Solver* GetSolver(const String& solverID) const = 0;
		virtual const IDSet& GetSolverIDs(void) const = 0;
		virtual void Release() = 0;
		virtual bool Serialize(const String& fileName, bool binary = true) = 0;
		virtual bool Serialize(const String& fileName, FileFormat format) = 0;
		virtual const Status& LoadAssetData(const String& fileName) = 0;


	protected:
		~WorkSpace() { ; }
	};
}

#endif // !_WORKSPACE_H