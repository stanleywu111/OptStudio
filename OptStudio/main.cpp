#include <iostream>
#include <string>
#include <vector>
#include <random>

int main()
{
	using namespace std;



	const string id[] = { "CASH", "USA11I1", "USA13Y1", "USA1LI1", "USA1TY1", "USA2ND1", "USA3351","USA37C1", "USA39K1", "USA45V1", "USA4GF1" };
	const string GICS_Sector[] = { "", "Financials", "Information Technology", "Information Technology", "Industrials", "Minerals", "Utilities", "Minerals", "Health Care", "Utilities", "Information Technology" };
	const string issuer[] = { "1", "2", "2", "2", "3", "3", "4", "4", "5", "5", "6" };
	const string factor[] = { "Factor_1A", "Factor_1B", "Factor_1C", "Factor_1D","Factor_1E","Factor_1F","Factor_1G","Factor_1H",
							  "Factor_2A", "Factor_2B", "Factor_2C", "Factor_2D","Factor_2E","Factor_2F","Factor_2G","Factor_2H",
		                      "Factor_3A", "Factor_3B", "Factor_3C", "Factor_3D","Factor_3E","Factor_3F","Factor_3G","Factor_3H",
							  "Factor_4A", "Factor_4B", "Factor_4C", "Factor_4D","Factor_4E","Factor_4F","Factor_4G","Factor_4H",
							  "Factor_5A", "Factor_5B", "Factor_5C", "Factor_5D","Factor_5E","Factor_5F","Factor_5G","Factor_5H",
		                      "Factor_6A", "Factor_6B", "Factor_6C", "Factor_6D","Factor_6E","Factor_6F","Factor_6G","Factor_6H",
		                      "Factor_7A", "Factor_7B", "Factor_7C", "Factor_7D","Factor_7E","Factor_7F","Factor_7G","Factor_7H",
							  "Factor_8A", "Factor_8B", "Factor_8C", "Factor_8D","Factor_8E","Factor_8F","Factor_8G","Factor_8H",
		                      "Factor_9A", "Factor_9B", "Factor_9C", "Factor_9D" };

	// Initial weights (holding) for all the assets and cash. Each element should be a
	// decimal instead of percentage, for example, 30% holding should be entered as 0.3.
	// In this asset array, the first item is cash, and only the index 0,1,10 assets 
	// have non-zero initial weight.
	vector<double> initWeight = { 0.0000000, 0.169809, 0.0658566, 0.160816, 0.0989991,
		                          0.0776341, 0.0768613, 0.0725244, 0.2774998, 0.0000000,0.0000000 };

	// Benchmark Portofolio Weight
	vector<double> bmWeight = { 0.0000000, 0.169809, 0.0658566, 0.160816, 0.0989991,
								0.0776341, 0.0768613, 0.0725244, 0.2774998, 0.0000000, 0.0000000 };

	// Benchmark 2 Portofolio Weight
	vector<double> bm2Weight = { 0.0000000, 0.0000000, 0.2500000, 0.0000000, 0.0000000,
								 0.0000000, 0.5000000, 0.0000000, 0.0000000, 0.2500000, 0.0000000 };

	const int AssetNum = 11;
	const int FactorMum = 68;

	vector<vector<double>> ExpData(AssetNum, vector<double>(FactorMum));
	
	//Generate Exposure Matrix with random numbers
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);

	for (auto &i : ExpData)
	{
		for (auto &j : i)
		{
			j = dis(gen);
		}
	}

	vector<double> CovData(FactorMum);

	for (auto &i : CovData)
	{
		i = dis(gen);
	}
		
	
	
	
	cout <<  1 << endl;

	return 0;

}