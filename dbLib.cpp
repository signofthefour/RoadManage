/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */

/* Implement TCity struct */
/// Constructor
TCity::TCity(int _id, string _name, string _coords, int _start_year, string _url_name, string _country, string _country_state, int _idxInFile) {
    id      = _id;
    name    = _name;
    coords  = _coords;
    start_years=_start_year;
    url_name= _url_name;
    country = _country;
    country_state= _country_state;
	idxInFile = _idxInFile;
}
/// Operator == with int parameter
/// return if id == idx
bool TCity::operator==(int& idx) {
    return id == idx;
}
/// Operator == with TCity param
/// return if the same id
bool TCity::operator==(TCity& T) {
	if (&T == NULL) return true;
    return name == T.name;
}
/// Operator < with string param
bool TCity::operator<(TCity& T) {
	if (&T == NULL) return true;
    return name < T.name;
}
bool TCity::operator>(TCity& T) {
	if (&T == NULL) return true;
    return name > T.name;
}
bool TCity::operator!=(TCity& T) {
	if (&T == NULL) return true;
    return !(T == *this);
}
void TCity::print(void) {
    cout << ">>==================================================<<"<< endl;
    cout << setw(10) << "Id:"				<<right	<< id                   << endl;
    cout << setw(10) << "Name:"				<<right << name                 << endl;
    cout << setw(10) << "Coords:"			<<right << coords               << endl;
    cout << setw(10) << "Start year:"		<<right << start_years          << endl;
    cout << setw(10) << "URL name:"			<<right << url_name             << endl;
    cout << setw(10) << "Country:"			<<right	<< country              << endl;
    cout << setw(10) << "Country state:"	<<right << country_state        << endl;
    cout << setw(10) << "Index in file:"	<<right << idxInFile        << endl;
}

/** Struct: TLine
 * Store line infomations
 * Implement
*/
/** Constructor
 * Init data, no dynamic data
*/
TLine::TLine(int _id, int _city_id, string _name, string _url_name, string _color, int _system_id, int _transport_mode_id, int _idxInFile) {
    id          = _id;
    city_id     = _city_id;
    name        = _name;
    url_name    = _url_name;
    color       = _color;
    system_id   = _system_id;
    transport_mode_id = _transport_mode_id;
	idxInFile	= _idxInFile;
}
/** Operator with int param
 * return if id == idx
*/
bool TLine::operator==(int& idx) {
	return id == idx;
}
/// Operator == with TLine param
/// return if the same id
bool TLine::operator==(TLine& T) {
	if (&T == NULL) return true;
	return city_id == T.city_id;
}
/// Operator < with string param
bool TLine::operator<(TLine& T) {
	if (&T == NULL) return true;
	return city_id < T.city_id;
}
bool TLine::operator>(TLine& T) {
	if (&T == NULL) return true;
	return city_id > T.city_id;
}
bool TLine::operator!=(TLine& T) {
	if (&T == NULL) return true;
	return !(T == *this);
}

void TLine::print(void) {
    cout << ">>==================================================<<" << endl;
    cout << "Id:"               << setw(20) << id                   << endl;
    cout << "City Id:"          << setw(20) << city_id              << endl;
    cout << "Name:"             << setw(20) << name                 << endl;
    cout << "URL name:"         << setw(20) << url_name             << endl;
    cout << "Color:"            << setw(20) << color                << endl;
    cout << "System id:"        << setw(20) << system_id            << endl;
    cout << "Transport mode id:"<< setw(20) << transport_mode_id    << endl;
	cout << "IndexInFile:" << setw(20) << idxInFile << endl;
}

/** Struct: TTrack
 * Implement, Store infomations of Track
*/
/** Constructor:
 * init information for a TTrack instance
*/
TTrack::TTrack(int _id, string _geometry, int _buildstart, int _opening, int _closure, int _length, int _city_id, int _idxIxFile) {
    id          = _id;
    geometry    = _geometry;
    buildstart  = _buildstart;
    opening     = _opening;
    closure     = _closure;
    length      = _length;
    city_id     = _city_id;
	idxInFile	= _idxIxFile;
}
/** Operator ==  with int param
 * return if id is equal to idx
*/
bool TTrack::operator==(int& idx) {
	return id == idx;
}
/// Operator == with TTrack param
/// return if the same id
bool TTrack::operator==(TTrack& T) {
	if (&T == NULL) return true;
	return id == T.id;
}
/// Operator < with string param
bool TTrack::operator<(TTrack& T) {
	if (&T == NULL) return true;
	return id < T.id;
}
bool TTrack::operator>(TTrack& T) {
	if (&T == NULL) return true;
	return id > T.id;
}
bool TTrack::operator!=(TTrack& T) {
	if (&T == NULL) return true;
	return !(T == *this);
}
/** Print function
 * Implement to track the flow of data
*/
void TTrack::print(void) {
    cout << ">>==================================================<<" << endl;
    cout << "Id:"           << setw(20) << id           << endl;
    cout << "Geometry:"     << setw(20) << geometry     << endl;
    cout << "Build start:"  << setw(20) << buildstart   << endl;
    cout << "Opening:"      << setw(20) << opening      << endl;
    cout << "Closure:"      << setw(20) << closure      << endl;
    cout << "Length:"       << setw(20) << length       << endl;
    cout << "City Id:"      << setw(20) << city_id      << endl;
    cout << "index in file:"      << setw(20) << idxInFile      << endl;
}

/** Struct: Station
 * Implement the Station method
 */
int TStation::maxID = 0;
 TStation::TStation(int _id, string _name, string _geometry, int _buildstart, int _opening, int _closure, int _city_id, int _idxInFile) {
	 id			= _id;
	 name		= _name;
	 geometry	= _geometry;
	 buildstart	= _buildstart;
	 opening	= _opening;
	 closure	= _closure;
	 city_id	= _city_id;
	 idxInFile	= _idxInFile;
	 if (id > maxID) maxID = id;
 }
 /** Operator ==  with int param
 * return if id is equal to idx
*/
 bool TStation::operator==(int& idx) {
	 return id == idx;
 }
 /// Operator == with TTrack param
 /// return if the same id
 bool TStation::operator==(TStation& T) {
	 if (&T == NULL) return true;
	 return city_id == T.city_id;
 }
 /// Operator < with string param
 bool TStation::operator<(TStation& T) {	
	 if (&T == NULL) return true;
	 return city_id < T.city_id;
 }
 bool TStation::operator>(TStation& T) {
	 if (&T == NULL) return true;
	 return city_id > T.city_id;
 }
 bool TStation::operator!=(TStation& T) {
	 if (&T == NULL) return true;
	 return !(T == *this);
 }

 void TStation::print(void) {
	 cout << ">>==================================================<<" << endl;
	 cout << "Id:"			<< setw(20) << id << endl;
	 cout << "Name:"		<< setw(20) << name << endl;
	 cout << "Geometry:"	<< setw(20) << geometry << endl;
	 cout << "Build start:" << setw(20) << buildstart << endl;
	 cout << "Opening:"		<< setw(20) << opening << endl;
	 cout << "Closure:"		<< setw(20) << closure << endl;
	 cout << "City Id:"		<< setw(20) << city_id << endl;
	 cout << "index in file:" << setw(20) << idxInFile << endl;
 }

 /** Struct: StationLine
* Store informations i nfile station_line.csv
*/
 TStationLine::TStationLine(int _id, int _station_id, int _line_id, int _city_id, string _created_at, string _updated_at, int _idxInFile) {
	 id = _id;
	 station_id = _station_id;
	 line_id = _line_id;
	 city_id = _city_id;
	 created_at = _created_at;
	 updated_at = _updated_at;
	 idxInFile = _idxInFile;
 }
 /** Operator ==  with int param
 * return if id is equal to idx
*/
 bool TStationLine::operator==(int& idx) {
	 return id == idx;
 }
 /// Operator == with TStationLine param
 /// return if the same id
 bool TStationLine::operator==(TStationLine& T) {
	 if (&T == NULL) return true;
	 return line_id == T.line_id;
 }
 /// Operator < with string param
 bool TStationLine::operator<(TStationLine& T) {
	 if (&T == NULL) return true;
	 return line_id < T.line_id;
 }
 bool TStationLine::operator>(TStationLine& T) {
	 if (&T == NULL) return true;
	 return line_id > T.line_id;
 }
 bool TStationLine::operator!=(TStationLine& T) {
	 if (&T == NULL) return true;
	 return !(T == *this);
 }

 void TStationLine::print(void) {
	 cout << ">>==================================================<<" << endl;
	 cout << "Id:" << setw(20) << id << endl;
	 cout << "Station ID:" << setw(20) << station_id << endl;
	 cout << "Line ID:" << setw(20) << line_id << endl;
	 cout << "City ID:" << setw(20) << city_id << endl;
	 cout << "Created at:" << setw(20) << created_at << endl;
	 cout << "Updated at:" << setw(20) << updated_at << endl;
	 cout << "Index in file:" << setw(20) << idxInFile << endl;
 }
/* Struct: CSVReader
 * Implement the csvReader struct to manage the process of reading csv file
 * */
// Normal constructor
CSVReader::CSVReader(string _nameOfFile,char _delimiter) {
	this->content         = NULL;    // Content of file in ASCII text format
    this->length          = 0;     // Length of file
    this->numOfField      = 1; // Count the number of fields of csv file
    this->numOfLine       = 0;  // Not contain the header 
    this->delimiter       = ',';  // Delimiter of csv file
    this->fileName        = NULL;   // Name of this csv file

    char* _content = NULL; // Attempt to get content of file and store it here
    char* _line;    // Content of a line of file
    int _numOfFile = 0;
    int _fileLength = 0; 
    int _lineLength = 0;
    int _posInLine = 0; // position in line to count in _line
    int _posInContent = 0;

	fstream fs; // Declare file stream
	fs.open(_nameOfFile, std::fstream::in | std::fstream::binary); // Open file
	fs.seekg(0,     fs.end) ; // Set the position to the end
	_fileLength =   fs.tellg(); // Length of file  fs this position
	fs.seekg(0,     fs.beg); // Set the position to begin of the stream;
	// if (_fileLength <= 0) throw "No data read.";
	_content = new char[_fileLength + 1];
	// if (!fs.is_open()) throw "No file open."; // Check if the file  fs opened
	while (!fs.eof()) { // Excecute while file fs not end
		fs.get(_content[_posInContent]);
		if (_content[_posInContent] == '\n') numOfLine++;
		if (numOfLine == 0) 
			if (_content[_posInContent] == _delimiter) numOfField++; // Count line and field
		_posInContent++;
	}
	_content[_fileLength] = '\0';
	// Store content
	content = new char[_fileLength + 1];
	strcpy(content, _content);
	length = _fileLength; // Store Length
	delimiter = _delimiter;
	fileName = new char[256];
	strcpy(fileName, (char*)&_nameOfFile[0]);
	if (_content != nullptr) delete[] _content;
	fs.close();
}

//Destructor
CSVReader::~CSVReader() {
    // if (content != nullptr) delete[] content;
    // if (fileName != nullptr) delete[] fileName;
}

/* DO: Implement void LoadData(void* &); 
 * Use an
 * */
void LoadData(void*& DataTable) {
	CSVReader *cities = new CSVReader("cities.csv", ',');
	CSVReader *lines = new CSVReader("lines.csv", ',');
	CSVReader *station_lines = new CSVReader("station_lines.csv", ',');
	CSVReader *stations = new CSVReader("stations.csv", ',');
	CSVReader *systems = new CSVReader("systems.csv", ',');
	CSVReader *track_lines = new CSVReader("track_lines.csv", ',');
	CSVReader *tracks = new CSVReader("tracks.csv", ',');
	// Read data to List
	TDataset *table = new TDataset();
	stringstream    ss(cities->content); // Get the string stream from cities's content
	string          info;   // contain info of each cities
	getline(ss, info, '\n');	// Get the first line out
	L1List<TCity> *CityList = new L1List<TCity>; // Create the cities list
	for (int i = 0; i < cities->numOfLine - 1; i++) {
		getline(ss, info, '\n');
		TCity   newCity = City(info, i);
		CityList->push_back(newCity);
	}
	table->CityData = CityList;
	ss.flush();

	stringstream sk(lines->content);
	getline(sk, info, '\n');
	L1List<TLine> *LineList  = new L1List<TLine>; // Create the cities list
	for (int i = 0; i < lines->numOfLine - 1; i++) {
		getline(sk, info, '\n');
		LineList->push_back(Line(info, i));
	}
	table->LineData = LineList;
	sk.flush();

	stringstream st(tracks->content);
	getline(st, info, '\n');
	L1List<TTrack> *TrackList = new L1List<TTrack>(); // Create the cities list
	for (int i = 0; i < tracks->numOfLine - 1; i++) {
		getline(st, info, '\n');
		TrackList->push_back(Track(info, i));
	}
	table->TrackData = TrackList;
	st.flush();

	stringstream si(stations->content);
	getline(si, info, '\n');
	L1List<TStation>* StationList = new L1List<TStation>(); // Create the cities list
	for (int i = 0; i < stations->numOfLine - 1; i++) {
		getline(si, info, '\n');
		StationList->push_back(Station(info, i));
	}
	table->StationData = StationList;
	si.flush();

	stringstream so(station_lines->content);
	getline(so, info, '\n');
	L1List<TStationLine>* StationLinesList = new L1List<TStationLine>(); // Create the cities list
	for (int i = 0; i < station_lines->numOfLine - 1; i++) {
		getline(so, info, '\n');
		StationLinesList->push_back(StationLine(info, i));
	}
	table->StationLineData = StationLinesList;
	so.flush();

	DataTable = (void*)(table);
}
/** Function: City();
 * Create a TCity
 * Input: string, information of a city
 * Output: TCity struct
*/
TCity& City(string info, int idx) {
    int     _id;
    string  _name;
    string  _coords;
    int     _start_years;
    string  _url_name;
    string  _country;
    string  _country_state;
    stringstream ss(info);
    ss >> _id;
    ss.get();
    getline(ss, _name, ',');
    getline(ss, _coords, ',');
    ss >> _start_years;
    ss.get();
    getline(ss, _url_name, ',');
    getline(ss, _country, ',');
    ss >> _country_state;
    TCity* newCity = new TCity(_id, _name, _coords, _start_years, _url_name, _country, _country_state, idx);
    return *newCity;
}
/* Function Track()
 * Input: string info of Track
 * Return a TTrack instance form infomation
 * */
TTrack& Track(string info, int idx) {
	int     _id;
	string  _geometry;
	int     _buildstart;
	int     _opening;
	int     _closure;
	int     _length;
	int     _city_id;
	stringstream ss(info);
	ss >> _id;
	ss.get();
	ss.get();
	getline(ss, _geometry, '"');
	ss.get();
	ss >> _buildstart;
	ss.get();
	ss >> _opening;
	ss.get();
	ss >> _closure;
	ss.get();
	ss >> _length;
	ss.get();
	ss >> _city_id;
	TTrack* newCity = new TTrack(_id, _geometry, _buildstart, _opening, _closure, _length, _city_id, idx);
	return *newCity;
}
/* Function Line()
 * Input: string info of Track
 * Return a TTrack instance form infomation
 * */
TLine& Line(string info, int idx) {
	int     _id;
	int     _city_id;
	string  _name;
	string  _url_name;
	string  _color;
	int     _system_id;
	int     _transport_mode_id;
	stringstream ss(info);
	ss >> _id;
	ss.get();
	ss >> _city_id;
	ss.get();
	getline(ss, _name, ',');
	getline(ss, _url_name, ',');
	getline(ss, _color, ',');
	ss >> _system_id;
	ss.get();
	ss >> _transport_mode_id;
	TLine* newLine = new TLine(_id, _city_id, _name, _url_name, _color, _system_id, _transport_mode_id, idx);
	return *newLine;
}
/* Function Station()
 * Input: string info of Track
 * Return a TTrack instance form infomation
 * */
TStation& Station(string info, int idx) {
	int     _id;
	string _name;
	string  _geometry;
	int     _buildstart;
	int     _opening;
	int     _closure;
	int     _city_id;
	stringstream ss(info);
	ss >> _id;
	ss.get();
	getline(ss, _name, ',');
	getline(ss, _geometry, ',');
	ss.get();
	ss >> _buildstart;
	ss.get();
	ss >> _opening;
	ss.get();
	ss >> _closure;
	ss.get();
	ss >> _city_id;
	TStation* newCity = new TStation(_id,_name, _geometry, _buildstart, _opening, _closure, _city_id, idx);
	return *newCity;
}

TStationLine& StationLine(string info, int idx) {
	int _id;
	int _station_id;
	int _line_id;
	int _city_id;
	string _created_at;
	string _updated_at;
	stringstream ss(info);
	ss >> _id;
	ss.get();
	ss >> _station_id;
	ss.get();
	ss >> _line_id;
	ss.get();
	ss >> _city_id;
	ss.get();
	getline(ss, _created_at, ',');
	getline(ss, _updated_at, '\n');
	TStationLine* newStationLine = new TStationLine(_id, _station_id, _line_id, _city_id, _created_at, _updated_at, idx);
	return *newStationLine;
}
/* DO: Implement void RealeaseData(void* &); 
 * Use an
 * */
void ReleaseData(void* &) {

}