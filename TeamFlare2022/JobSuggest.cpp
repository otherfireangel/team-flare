#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "jobResult.h"
#include <math.h>
#include "nlohmann/json.hpp"
#include <array>

using json = nlohmann::json;

bool compare (jobResult job1, jobResult job2){
	return(job1.percentile > job2.percentile);
}

double percentMatch(std::array<double, 6> popMeans, std::array<double, 6> popStDevs, std::array<int, 6> userScores) {
	double zScore0 = (userScores[0] - popMeans[0]) / popStDevs[0];
	double zScore1 = (userScores[1] - popMeans[1]) / popStDevs[1];
	double zScore2 = (userScores[2] - popMeans[2]) / popStDevs[2];
	double zScore3 = (userScores[3] - popMeans[3]) / popStDevs[3];
	double zScore4 = (userScores[4] - popMeans[4]) / popStDevs[4];
	double zScore5 = (userScores[5] - popMeans[5]) / popStDevs[5];

	double avgZ = (zScore0 + zScore1 + zScore2 + zScore3 + zScore4 + zScore5) / 6;

	double percent = (0.5 - abs(erf(avgZ) / 2)) * 2;

	return percent;
}

jobResult * jobSuggest() {
	//step one: yoink all data from the json
	std::ifstream data {"MockJobCharacteristics.json"};
    json j{json::parse(data)};

	//step two: "take" an "input"
	std::array<int, 6> userScores = {8,7,6,5,4,6};

	//step three: calculate many times
	static jobResult jobMatches[11];
	for(int i = 0; i < 11; i++){
		//yoink the i-th datapoints into arrays
		std::array<double, 6> popMeans;
		popMeans[0] = j[i]["Bmean"];
		popMeans[1] = j[i]["Tmean"];
		popMeans[2] = j[i]["Cmean"];
		popMeans[3] = j[i]["Hmean"];
		popMeans[4] = j[i]["Pmean"];
		popMeans[5] = j[i]["Omean"];
		std::array<double, 6> popStDevs;
		popStDevs[0] = j[i]["Bsd"];
		popStDevs[1] = j[i]["Tsd"];
		popStDevs[2] = j[i]["Csd"];
		popStDevs[3] = j[i]["Hsd"];
		popStDevs[4] = j[i]["Psd"];
		popStDevs[5] = j[i]["Osd"];

		//chunch the arrays
		double percMatch = percentMatch(popMeans, popStDevs, userScores);

		//spit answer into jobMatches[]
		jobResult temp;
		temp.jobName = j[i]["JobName"].get<string>();
		temp.percentile = percMatch;
		jobMatches[i] = temp;
	}

	//step four: sort jobMatches
	std::sort(jobMatches, jobMatches+11, compare);

	// //step five: print some results, used for testing only
	// for(jobResult job : jobMatches){
	// 	double perc = job.percentile*100;
	// 	cout << job.jobName << ": " << perc << "%\n";
	// }

	return jobMatches;
}