#include "processData.h"

using namespace std;

void Initialization() {
}

void Finalization() {
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
	TDataset* DataTable = new TDataset;
	DataTable = (TDataset*)pData;
	string request = "";
	string param1 = "";
	string param2 = "";
	stringstream ss(pRequest);
	getline(ss, request, ' ');
	if (ss.good()) getline(ss, param1);
	ss.flush();
	if (request == "CL" && param1 == "") CountLine(DataTable->LineData, pOutput, N);
	if (request == "CL" && param1 != "") CountLineOfGivenCity(param1, DataTable, pOutput, N);
	if (request == "LSC") ListStationWithCityName(param1, DataTable, pOutput, N);
	if (request == "LLC") ListLineWithCityName(param1, DataTable, pOutput, N);
	if (request == "LSL") ListStationWithLineID(param1, DataTable, pOutput, N);
	if (request == "FC")	FindCity(param1, DataTable, pOutput, N);
	if (request == "FS") 	FindStation(param1, DataTable, pOutput, N);
	if (request == "SLP")	StationPositionInTrack(param1 + " " + param2, DataTable, pOutput, N);
	if (request == "IS")	InsertStation(param1 + " " + param2, DataTable, pOutput, N);
	if (request == "RS")	RemoveStation(param1, DataTable, pOutput, N);
	if (request == "US")	UpdateStation(param1 + ";" + param2, DataTable, pOutput, N);
	if (request == "ISL")	InsertStationLine(param1, DataTable, pOutput, N);
	if (request == "RSL")	RemoveStationLine(param1, DataTable, pOutput, N);
}

void CountLine(L1List<TLine>* LineList, void*& pOutput, int&N) {
	N = 1;
	int* data = new int;
	*data = LineList->getSize();
	pOutput = (void*)data;
}

void CountLineOfGivenCity(string city_name, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream ss(city_name);
	ss >> city_name;
	char* cityName = (char*)city_name.c_str();
	void (*compareName)(TCity&, void*) = (void (*)(TCity&, void*))CompareName<TCity>;
	DataTable->CityData->traverse(compareName, (void*&)cityName);
	L1List<TCity>* cityList = (L1List<TCity>*)cityName;
	if (cityList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	else {
		int cityID = cityList->getHead()->data.getID();
		int* pData = new int;
		*pData = cityID;
		void (*op)(TLine&, void*) = (void (*)(TLine&, void*))CompareCityID<TLine>;
		DataTable->LineData->traverse(op, (void*&)pData);
		L1List<TLine>* resultList = (L1List<TLine>*)pData;
		if (resultList == NULL) {
			N = 1;
			int* data = new int;
			*data = -1;
			pOutput = (void*)data;
			return;
		}
		int* numOfLine = new int(resultList->getSize());
		pOutput = (void*)numOfLine;
		N = 1;
	}
}

void ListStationWithCityName(string city_name, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream ss(city_name);
	ss >> city_name;
	char* cityName = (char*)city_name.c_str();
	void (*compareName)(TCity&, void*) = (void (*)(TCity&, void*))CompareName<TCity>;
	DataTable->CityData->traverse(compareName, (void*&)cityName);
	L1List<TCity>* cityList = (L1List<TCity>*)cityName;
	if (cityList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	else {
		int cityID = cityList->getHead()->data.getID();
		int* pData = new int;
		*pData = cityID;
		void (*op)(TStation&, void*) = (void (*)(TStation&, void*))CompareCityID<TStation>;
		DataTable->StationData->traverse(op, (void*&)pData);
		L1List<TStation>* resultList = (L1List<TStation>*)pData;
		if (resultList == NULL) {
			N = 1;
			int* data = new int;
			*data = -1;
			pOutput = (void*)data;
			return;
		}
		N = resultList->getSize();
		int* pListStation = new int[N];
		L1Item<TStation>* pCurr = resultList->getHead();
		for (int i = 0; i < N; i++) {
			pListStation[i] = pCurr->data.getID();
			pCurr = pCurr->pNext;
		}
		pOutput = (void*)pListStation;
	}
}

void ListLineWithCityName(string city_name, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream ss(city_name);
	ss >> city_name;
	char* cityName = (char*)city_name.c_str();
	void (*compareName)(TCity&, void*) = (void (*)(TCity&, void*))CompareName<TCity>;
	DataTable->CityData->traverse(compareName, (void*&)cityName);
	L1List<TCity>* cityList = (L1List<TCity>*)cityName;
	if (cityList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	else {
		int cityID = cityList->getHead()->data.getID();
		int* pData = new int;
		*pData = cityID;
		void (*op)(TLine&, void*) = (void (*)(TLine&, void*))CompareCityID<TLine>;
		DataTable->LineData->traverse(op, (void*&)pData);
		L1List<TLine>* resultList = (L1List<TLine>*)pData;
		if (resultList == NULL) {
			N = 1;
			int* data = new int;
			*data = -1;
			pOutput = (void*)data;
			return;
		}
		N = resultList->getSize();
		int* pListStation = new int[N];
		L1Item<TLine>* pCurr = resultList->getHead();
		for (int i = 0; i < N; i++) {
			pListStation[i] = pCurr->data.getID();
			pCurr = pCurr->pNext;
		}
		pOutput = (void*)pListStation;
	}
}

void ListStationWithLineID(string line_id, TDataset*& DataTable, void*& pOutput, int& N) {
	int lineID;
	stringstream ss(line_id);
	ss >> lineID;
	ss.flush();

	int* pData = new int;
	*pData = lineID;
	void (*op)(TStationLine&, void*) = (void (*)(TStationLine&, void*))CompareLineID<TStationLine>;
	DataTable->StationLineData->traverse(op, (void*&)pData);
	L1List<TStationLine>* resultList = (L1List<TStationLine> * )pData;
	if (resultList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	N = resultList->getSize();
	int* pListStation = new int[N];
	L1Item<TStationLine>* pCurr = resultList->getHead();
	for (int i = 0; i < N; i++) {
		pListStation[i] = pCurr->data.station_id;
		pCurr = pCurr->pNext;
	}
	pOutput = (void*)pListStation;
}

void FindCity(string city_name, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream ss(city_name);
	getline(ss, city_name, '\0');
	char* cityName = (char*)city_name.c_str();
	void (*compareName)(TCity&, void*) = (void (*)(TCity&, void*))CompareName<TCity>;
	DataTable->CityData->traverse(compareName, (void*&)cityName);
	L1List<TCity>* cityList = (L1List<TCity>*)cityName;
	if (cityList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	else {
		int cityID = cityList->getHead()->data.getID();
		int* pData = new int(cityID);
		pOutput = (void*)pData;
		N = 1;
		return;
	}
}

void FindStation(string station_name, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream ss(station_name);
	getline(ss, station_name, '\0');
	char* cityName = (char*)station_name.c_str();
	void (*compareName)(TStation&, void*) = (void (*)(TStation&, void*))CompareName<TStation>;
	DataTable->StationData->traverse(compareName, (void*&)cityName);
	L1List<TStation>* stationList = (L1List<TStation>*)cityName;
	if (stationList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	else {
		int cityID = stationList->getHead()->data.getID();
		int* pData = new int(cityID);
		pOutput = (void*)pData;
		N = 1;
		return;
	}
}

void StationPositionInTrack(string info, TDataset*& DataTable, void*& pOutput, int& N) {
	int		stationID, trackID;
	stringstream inf(info);
	inf >> stationID >> trackID;
	int* 	pStationID = new int(stationID);
	int* 	pTrackID = new int(trackID);
	void (*compareStationID)(TStation&, void*) = (void (*)(TStation&, void*))CompareID<TStation>;
	DataTable->StationData->traverse(compareStationID, (void*&)pStationID);
	L1List<TStation>* stationList = (L1List<TStation>*)pStationID;
	if (stationList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	string stationGeometry = stationList->getHead()->data.getGeometry();
	stringstream ss(stationGeometry);
	getline(ss, stationGeometry, '(');
	getline(ss, stationGeometry, ')');
	// Find track
	void (*compareTrackID)(TTrack&, void*) = (void (*)(TTrack&, void*))CompareID<TTrack>;
	DataTable->TrackData->traverse(compareTrackID, (void*&)pTrackID);
	L1List<TTrack>* trackList = (L1List<TTrack>*)pTrackID;
	if (trackList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	string	trackLineString = trackList->getHead()->data.getGeometry();
	stringstream	ts(trackLineString);
	getline(ts, trackLineString, '(');
	getline(ts, trackLineString, ')');
	int pos = 0;
	stringstream 	extractLinestring(trackLineString);
	getline(extractLinestring, trackLineString, ',');
	while (trackLineString != stationGeometry) {
		if (ts.eof()) {
			int* pData = new int(-1);
			pOutput = (void*)pData;
			N = 1;
			return;
		}
		pos++;
		getline(extractLinestring, trackLineString, ',');
	}
	int* pData = new int(pos);
	pOutput = (void*)pData;
	N = 1;
	return;
}

void InsertStation(string info, TDataset*& DataTable, void*& pOutput, int& N) {
	int		_maxID = DataTable->StationData->getHead()->data.maxID;
	string id 	= to_string(_maxID + 1);
	info		= id + ',' + info + ",0";
	if (DataTable->StationData->push_back(Station(info, 0)) == 0) {
		int* pData = new int(_maxID + 1);
		pOutput = (void*)pData;
		N = 1;
		return;
	}
}

void RemoveStation(string station_id, TDataset*& DataTable, void*& pOutput, int& N) {
	int		stationID;
	stringstream inf(station_id);
	inf >> stationID;
	int* 	pStationID = new int(stationID);
	void (*compareStationID)(TStation&, void*) = (void (*)(TStation&, void*))CompareID<TStation>;
	DataTable->StationData->traverse(compareStationID, (void*&)pStationID);
	L1List<TStation>* stationList = (L1List<TStation>*)pStationID;
	if (stationList == NULL) {
		N = 1;
		int* data = new int;
		*data = -1;
		pOutput = (void*)data;
		return;
	}
	// Hand
	string	delGeometry = stationList->getHead()->data.getGeometry();
	stringstream dg(delGeometry);
	getline(dg, delGeometry, '(');
	getline(dg, delGeometry, ')');
	dg.flush();
	L1Item<TStationLine> * pCur = DataTable->StationLineData->getHead();
	while (pCur != NULL) {
		if (pCur->data.station_id == stationID) DataTable->StationLineData->DeleteNode(pCur);
		pCur = pCur->pNext;
	}
	L1Item<TTrack> * pCurT = DataTable->TrackData->getHead();
	while (pCurT != NULL) {
		stringstream	ss(pCurT->data.getGeometry());
		string temp; getline(ss, temp, '(');
		string point;
		string lineString = "";
		lineString += temp;
		getline(ss, temp, ')');
		ss.flush();
		stringstream	st(temp);
		while (!st.eof()) {
			getline(st, point, ',');
			if (point != delGeometry) {
				lineString += point;
			}
		}
		lineString += ")\"";
		pCurT->data.geometry = lineString;
		pCurT = pCurT->pNext;
		st.flush();
		ss.flush();
	}
	L1Item<TStation>* delStation = DataTable->StationData->getHead();
	while (delStation->data.id != stationID) {
		delStation = delStation->pNext;
	}
	DataTable->StationData->DeleteNode(delStation);
	L1Item<TStation>* pCurS = DataTable->StationData->getHead();
	int _maxID = 0;
	while (pCurS != NULL) {
		if (pCurS->data.getID() > _maxID) _maxID = pCurS->data.getID();
		DataTable->StationData->getHead()->data.maxID = _maxID;
		pCurS = pCurS->pNext;
	}
	int* pData = new int(0);
	pOutput = (void*)pData;
	N = 1;
	return;
}

void	UpdateStation(string info, TDataset*& DataTable, void*& pOutput, int& N) {
	int		stationID;
	string	name;
	string 	geometry;
	int		buildStart;
	int		opening;
	int 	closure;
	stringstream	ss(info);
	ss >> stationID;
	ss.ignore(1);
	getline(ss, name, ',');
	//  FIXED
	// : Something wrong with name which contain space
	// DONE
	getline(ss, geometry, ',');
	ss >> buildStart; 	ss.ignore(1);
	ss >> opening;		ss.ignore(1);
	ss >> closure;		ss.ignore(1);
	L1Item<TStation> * pCur = DataTable->StationData->getHead();
	while (pCur != NULL) {
		if (pCur->data.id == stationID) {
			pCur->data.name 		= name;
			pCur->data.geometry 	= geometry;
			pCur->data.buildstart 	= buildStart;
			pCur->data.opening 		= opening;
			pCur->data.closure 		= closure;
			break;
		}
		pCur = pCur->pNext;
	}
	int* pData = new int;
	if (pCur == NULL) *pData = -1;
	else *pData = 0;
	pOutput = (void*)pData;
	N = 1;
	return;
}

void InsertStationLine(string info, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream	ss(info);
	int stationID, lineID, pos;
	ss >> stationID >> lineID >> pos;
	L1Item<TStationLine> * pCur = DataTable->StationLineData->getHead();
	while (pCur != NULL) {
		if (pCur->data.getLineID() == lineID) {
			pos--;
		}
		if (pos == 0) {
			TStationLine * pNew = new TStationLine(0, stationID, lineID, 0, " ", " ", 0);
			L1Item<TStationLine> * pNewStation = new L1Item<TStationLine>(*pNew);
			pNewStation->pNext = pCur->pNext;
			pCur->pNext = pNewStation;
			int* pData = new int(0);
			pOutput = (void*)pData;
			N = 1;
			return;
		}
		pCur = pCur->pNext;
	}
	int* pData = new int(-1);
	pOutput = (void*)pData;
	N = 1;
	return;
}

void	RemoveStationLine(string info, TDataset*& DataTable, void*& pOutput, int& N) {
	stringstream	ss(info);
	int 		stationID, lineID;
	ss >> stationID >> lineID;
	L1Item<TStationLine> * pCur = DataTable->StationLineData->getHead();
	L1Item<TStationLine> * pTmp = pCur;
	while (pCur != NULL) {
		if (pCur->data.line_id == lineID) {
			if (pCur->data.station_id == stationID) {
				pTmp = pCur;
				DataTable->StationLineData->DeleteNode(pCur);
				pCur = pTmp;
				int * pData = new int(0);
				pOutput = (void*)pData;
				N = 1;
				return;
			}
		}
		pCur = pCur->pNext;
	}
	int* pData = new int(-1);
	pOutput = (void*)pData;
	N = 1;
	return;
}